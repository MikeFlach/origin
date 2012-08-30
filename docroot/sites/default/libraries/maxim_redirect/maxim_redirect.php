<?php
/*
 * Check to see if redirect exists.  Dependent on the redirect module.  Used in settings.php.
 */
function maxim_redirect($path, $databases) {
  $redirect_url = '';
  $path_hash = maxim_redirect_hash($path);
  if ($databases['default']['default']['driver'] == 'mysql') {
    $db = $databases['default']['default'];
    if (isset($db['port'])) {
      $db['host'] = $db['host'] . ':' . $db['port'];
    }
    $conn = mysql_connect($db['host'], $db['username'], $db['password']);
    mysql_select_db($db['database'], $conn);

    // Check if path_redirect module is installed.
    if (mysql_fetch_row(mysql_query("SELECT name FROM system WHERE type = 'module' AND status = 1 AND name = 'redirect'"))) {
      $redirect_sql = "SELECT a.alias FROM redirect r LEFT JOIN url_alias a ON r.redirect = a.source WHERE r.hash='" . $path_hash . "'";
      $redirect_row = mysql_fetch_array(mysql_query($redirect_sql));
      if (is_array($redirect_row) && strlen($redirect_row['alias']) > 0)  {
        $redirect_url = $redirect_row['alias'];
      }
    }

    if (strlen($redirect_url) > 0) {
      header('HTTP/1.1 301 Moved Permanently');
      header('Location: ' . '/' . $redirect_url);
      die();
    }
  }
}

function maxim_redirect_hash($source){
  $hash = array(
    'source' => $source,
    'language' =>'und'
  );
  maxim_redirect_sort_recursive($hash, 'ksort');
  return drupal_hash_base64(serialize($hash));
}

function maxim_redirect_sort_recursive(&$array, $callback = 'sort'){
  $result = $callback($array);
  foreach ($array as $key => $value){
    if (is_array($value)){
      $result &= maxim_redirect_sort_recursive($array[$key], $callback);
    }
  }
  return $result;
}
