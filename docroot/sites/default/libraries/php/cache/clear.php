<?php
  $path = '';
  $email = '';
  if (isset($_POST['path'])) { 
    $path = $_POST['path'];
  }
  if (isset($_POST['email'])) {
    $email = $_POST['email'];
  }
?>
<html>
<head>
<title>Cache Clear</title>
</head>
<style>
body {font-family: arial, helvetica;}
</style>
<body>
<h1>Cache Clear</h1>
<form method="POST">
  <p><strong>URL: http://www.maxim.com/</strong><input type="text" name="path" value="<?php echo $path; ?>" size="60" /><br />
  <small>Use &lt;front&gt; for homepage</small></p>
  <p><strong>Email:</strong> <input type="text" name="email" value= "<?php echo $email; ?>" /><br /><small>For Akamai notification</small></p>
  <p><input type="submit" name="cache-submit" value="Clear Cache" /></p>
</form>
</body>
</html>

<?php

if (strlen($path)) {
  if ($path == '<front>') {
    $path = '';
  }
  $cacheObj = new CacheClear($path, $email);

  if ($cacheObj->get_type() == 'page') {
    // if page, clear varnish
    $cacheObj->clear_varnish();
  } 
  // Clear Akamai
  $cacheObj->clear_akamai();
}

class CacheClear {
  private $host_domain = 'www.maxim.com';
  private $origin_url = 'http://origin2-www.maxim.com';
  private $cdn_url = 'http://cdn2.maxim.com';
  private $this_cache = array();
  private $email = '';

  function __construct($path, $email = '') {
    $this->parse_path($path);
    $this->email = $email;
  }

  public function get_type() {
    return $this->this_cache['type'];
  }

  /*
   * Parse Path
   */
  public function parse_path($path) {
    $url = array();
    $url['path'] = $path;
    // Test to see if URL is an image
    if (strpos($path, '.png') !== FALSE || strpos($path, '.jpg') !== FALSE || strpos($path, '.gif') !== FALSE) {
      $url['type'] = 'image';
    } else {
      $url['type'] = 'page';
    }

    if ($url['type'] == 'image') {
      $url['cache_url'] = $this->cdn_url . str_replace('maxim/sites/', 'sites/', $path);
    } else {
      $url['cache_url'] = $this->origin_url . '/' . $path;
    }

    $this->this_cache = $url;
    return $url;
  }

  /**
   * Clear Varnish Cache
   */
  public function clear_varnish($cacheObj = null) {
    if (null == $cacheObj) {
      $cacheObj = $this->this_cache;
    }

    $curl = curl_init($cacheObj['cache_url']);
    curl_setopt($curl, CURLOPT_CUSTOMREQUEST, "PURGE");
    curl_setopt ($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl, CURLOPT_HTTPHEADER, array(
      'X-Acquia-Purge:maxim',
      'Accept-Encoding: gzip',
      'Host:' . $this->host_domain
      ));
    $response = curl_exec($curl);
    $response = preg_replace('/<h1[^>]*>([\s\S]*?)<\/h1[^>]*>/', '<h3>Varnish Cache clear: http://' . $this->host_domain . '/' . $cacheObj['path'] .'</h3>', $response);
    echo $response;
  }

  /**
   * Clear Akamai Cache
   */
  public function clear_akamai($cacheObj = null) {
    if (null == $cacheObj) {
      $cacheObj = $this->this_cache;
    }

    // Include Drupal bootstrap
    chdir($_SERVER['DOCUMENT_ROOT']);
    define('DRUPAL_ROOT', getcwd());
    require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
    drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

    switch ($cacheObj['type']) {
      case 'image':
        $base_path = $this->cdn_url;
        $cache_path = 'maxim/' . str_replace('maxim/sites/', 'sites/', $cacheObj['path']);
      break;
      default:
        $base_path = $this->origin_url;
        $cache_path = $cacheObj['path'];
      break;
    }

    // Include akamai module file
    if (module_exists('akamai')) {
      echo '<h3>Akamai cache clear: ' . $base_path . '/'. $cache_path .  '</h3>';
      akamai_clear_url($cache_path, array('email' => $this->email, 'basepath' => $base_path));
      echo '<p>It will take a few minutes.';
      if (strlen($this->email)) {
        echo ' You will receive an e-mail at ' . $this->email . ' when cache is cleared';
      }
      echo '</p>';
    }
  }

}
