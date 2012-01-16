<?php
/**
 * @file akamai.class.inc
 *    Akamai is a registered trademark of Akamai Technologies, Inc.
 *    This class is an abstraction around the Akamai Cache Control API.
 */

interface AkamaiCacheControl {
  /**
   * Clears the provided URLs from the Akamai Content Cache.
   *
   * @param $paths
   *    A path (or array of paths) to clear from Akamai
   * @return
   *    An array with 2 keys:
   *       success: TRUE or FALSE indicating cache clearing success
   *       message: Blank if successful, the error message if not successful.
   */
  function clear_url($paths);
}

/**
 * Default implementation of the AkamaiCacheControl interface
 */
class AkamaiCacheControlClient implements AkamaiCacheControl {

  private $defaults; //akamai_get_defaults();

  public $parameters;

  /**
   * Constructs an instance of the Akamai Cache Control facade.
   *
   * Valid parameters are specified in the options array as key/value pairs with the
   * parameter name being the key and the parameter setting being the value
   *
   * @param options  An array of parameter options for the Akamae Cache Control
   *                  Web Service. These will override the defaults.
   */
  function __construct($options = array()) {
    $this->defaults =  array(
      'basepath'  => variable_get("akamai_basepath", ""),
      'name'      => variable_get("akamai_username", ""),
      'pwd'       => variable_get("akamai_password", ""),
      'action'    => variable_get("akamai_action", ""),
      'type'      => "arl",
      'domain'    => variable_get("akamai_domain", ""),
      'ccu_soap_wsdl' => variable_get("akamai_ccu_wsdl", ""),
      'eccu_soap_wsdl' => variable_get("akamai_eccu_wsdl", ""),
      'email'     => variable_get("akamai_email", ""),
    );

    $this->parameters = array_merge($this->defaults, $options);
  }

  /**
   * Clears the provided URLs from the Akamai Content Cache.
   *
   * @param $paths
   *    A path (or array of paths) to clear from Akamai
   * @return
   *    An array with 2 keys:
   *       success: TRUE or FALSE indicating cache clearing success
   *       message: Blank if successful, the error message if not successful.
   */
  function clear_url($paths) {

    // Grab params
    extract($this->parameters);

    // make paths an array
    if (!is_array($paths)) {
      $url = array($paths);
    }

    // prepend base path to paths to make URIs
    $uris = array();
    foreach ($paths as $path) {
      $path= rtrim(preg_match("/^\//", $path) ? $path : "/$path");
      array_push($uris, $basepath . $path);
    }

    $opt = array(
      "action=$action",
      "domain=$domain",
      "type=$type",
    );

    if (!empty($email) && $email != AKAMAI_EMAIL_DISABLE) {
      $opt[] = "email-notification=$email";
    }

    try {
      $ccuapi = new SoapClient($ccu_soap_wsdl,
        array(
          'trace' => 1,
          'features' => SOAP_USE_XSI_ARRAY_TYPE,
        )
      );

      $response = $ccuapi->purgeRequest($name, $pwd, '', $opt, $uris);
      $is_success = ($response->resultCode < 300);
      if (!$is_success) {
        throw new Exception($response->resultMsg);
      }
      foreach ($uris as $uri) {
        watchdog('Akamai', t("Akamai %action of %uri: %message"),
          array('%uri' => $uri, '%action' => $action, '%message' => $response->resultMsg), WATCHDOG_NOTICE);
      }

      return array(
        'success' => TRUE,
        'code' => $response->resultCode,
        'message' => $response->resultMsg,
      );
    }
    catch (Exception $e) {
      watchdog('Akamai', t("Error Clearing Akamai Cache: %msg"), array('%msg' => $e->getMessage()));
      throw $e;
    }
  }
}

/**
 * Implementation of the AkamaiCacheControl interface that records what was sent to it.
 * Hint: This is only useful for testing.
 */
class RecordingCacheControlClient implements AkamaiCacheControl {

  public $paths;
  public $options;

  /**
   * Constructs an instance of the Akamai Cache Control facade.
   */
  function __construct($options = array()) {
    $this->options = $options;
  }

  /**
   * Records the paths passed in.
   */
  function clear_url($paths) {
    if (!is_array($paths)) {
      $paths = array($paths);
    }
    $this->paths = $paths;

    return array(
      'success' => TRUE,
      'code' => '',
      'message' => '',
    );
  }
}

/**
 * Implementation of the AkamaiCacheControl interface that throws Exceptions.
 * Hint: This is only useful for testing.
 */
class ErrorCacheControlClient implements AkamaiCacheControl {

  /**
   * Constructs an instance of the Akamai Cache Control facade.
   */
  function __construct($options = array()) {
  }

  /**
   * Records the paths passed in.
   */
  function clear_url($paths) {
    throw new Exception(t('Akamai Failure Condition Test'));
  }
}
/**
 *
 */
class AkamaiEnhancedCacheControlClient extends AkamaiCacheControlClient {
  function clear_url($paths) {

    // Grab params
    extract($this->parameters);

    // make paths an array
    if (!is_array($paths)) {
      $url = array($paths);
    }

    // prepend base path to paths to make URIs
    $uris = array();
    foreach ($paths as $path) {
      $path= rtrim(preg_match("/^\//", $path) ? $path : "/$path");
      array_push($uris, $basepath . $path);
    }

    // Download the wsdl and reference it locally, because even though we're
    // specifying basic auth info, php won't use it to actually fetch the wsdl to begin with…
    $wsdl_parts = parse_url($eccu_soap_wsdl);
    $eccu_soap_wsdl = $wsdl_parts['scheme'] . '://' . urlencode($name) . ':' . urlencode($pwd) . '@' . $wsdl_parts['host'] . $wsdl_parts['path'] . '?' . $wsdl_parts['query'];
    $wsdl_destination = file_directory_temp() . '/eccu.wsdl';
    if (!file_exists($wsdl_destination)) {
      $result = drupal_http_request($eccu_soap_wsdl);
      if ($result->code == 200) {
        file_unmanaged_save_data($result->data, $wsdl_destination, FILE_EXISTS_REPLACE);
      }
    }

    try {
      $eccuapi = new SoapClient('file://' . $wsdl_destination,
        array(
          'trace' => 1,
          'features' => SOAP_USE_XSI_ARRAY_TYPE,
          'login' => $name,
          'password' => $pwd,
        )
      );

      $filename = 'eccu_cache_clear-' . time();
      $notes = '';
      $version_string = time();
      $base_parts = parse_url($basepath);
      $content = $this->__buildEccuXML($paths);
      $property_name_exact_match = 0;
      $response = $eccuapi->upload($filename, $content, $notes, $version_string, $base_parts['host'], 'hostheader', $property_name_exact_match, $email);
      $is_success = ($response->resultCode < 300);
      if (!$is_success) {
        throw new Exception($response->resultMsg);
      }
      foreach ($uris as $uri) {
        watchdog('Akamai', t("Akamai %action of %uri: %message"),
          array('%uri' => $uri, '%action' => $action, '%message' => $response->resultMsg), WATCHDOG_NOTICE);
      }
      return array(
        'success' => TRUE,
        'code' => $response->resultCode,
        'message' => $response->resultMsg,
      );
    }
    catch (Exception $e) {
      watchdog('Akamai', t("Error Clearing Akamai Cache: %msg"), array('%msg' => $e->getMessage()));
      throw $e;
    }
  }

  public function __buildEccuXML($paths) {
    $regex = '/(?<path>[\w\/]+\/)?(?<wildcard>\*)(?:\.(?<ext>\w+))?$/';

    $xml = '<eccu>';
    foreach ($paths as $pattern) {
      preg_match($regex, $pattern, $matches);
      $recursive_dirs = FALSE;
      if (!empty($matches['path'])) {
        $xml .= '<match:recursive-dirs value="' . $matches['path'] . '">';
        $recursive_dirs = TRUE;

      }

      if (isset($matches['wildcard']) && isset($matches['ext'])) {
        $xml .= '<match:ext value="' . $matches['ext'] . '"><revalidate>now</revalidate></match:ext>';
      }
      elseif ($matches['path'] && $recursive_dirs) {
       $xml .= '<revalidate>now</revalidate>';
      }

      if ($recursive_dirs) {
        $xml .= '</match:recursive-dirs>';
      }
    }
    $xml .= '</eccu>';

    return $xml;
  }
}
