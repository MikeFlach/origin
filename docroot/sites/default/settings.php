<?php
/**
 * This settings.php file was created by the Acquia Cloud ah-site-archive-import
 * Drush command. The imported archive did not contain a settings.php file, so
 * the import process created this file by default. You can replace this file
 * with the standard default settings.php file for your version of Drupal.
 * However, be sure to keep the last line that loads the "Acquia Cloud settings
 * include file", which provides the correct database credentials for your site.
 */
$update_free_access = FALSE;
$drupal_hash_salt = '';
ini_set('arg_separator.output',     '&amp;');
ini_set('magic_quotes_runtime',     0);
ini_set('magic_quotes_sybase',      0);
ini_set('session.cache_expire',     200000);
ini_set('session.cache_limiter',    'none');
ini_set('session.cookie_lifetime',  2000000);
ini_set('session.gc_divisor',       100);
ini_set('session.gc_maxlifetime',   200000);
ini_set('session.gc_probability',   1);
ini_set('session.save_handler',     'user');
ini_set('session.use_cookies',      1);
ini_set('session.use_only_cookies', 1);
ini_set('session.use_trans_sid',    0);
ini_set('url_rewriter.tags',        '');

// Change URLs to lower case, if not in files directory
if (strpos($_GET['q'], 'sites/default/files') === false) {
  $_GET['q'] = strtolower($_GET['q']);
}

// set the right $base_url
switch ($_SERVER['HTTP_HOST']){
  case 'dev.maxim.com':
  case 'stage.maxim.com':
  case 'edit.maxim.com':
    if (strpos($_GET['q'], 'admin') === 0) {
      ini_set('memory_limit', '256M');
    } else if (preg_match('/node\/([0-9])+\/edit/', $_GET['q']) === 1){
      ini_set('memory_limit', '192M');
    } else if (strpos($_GET['q'], 'hometown-hotties') === 0) {
      ini_set('memory_limit', '192M');
    }
    break;
  case 'maxim.com':
  case 'www.maxim.com':
  case 'prod.maxim.com':
  case 'origin2-www.maxim.com':
  case 'maxim.prod.acquia-sites.com':
    $base_url = 'http://www.maxim.com';
    break;
  default:
    $base_url = 'http://' . $_SERVER['HTTP_HOST'];
    break;
}

// Increase memory for HTH map
if (strpos($_GET['q'], 'hth-map') > 0) {
  ini_set('memory_limit', '256M');
}

// Add more memory for cron jobs
if (php_sapi_name() == 'cli') {
  ini_set('memory_limit', '512M');
}

// Add Varnish as the page cache handler.
// Drupal 7 does not cache pages when we invoke hooks during bootstrap. This needs to be disabled.
$conf['page_cache_invoke_hooks'] = false;
$conf['cache'] = 1;
$conf['cache_lifetime'] = 300;
$conf['page_cache_maximum_age'] = 3600;
$conf['omit_vary_cookie'] = true;

if (file_exists('/var/www/site-php/maxim/maxim-settings.inc')){
  require('/var/www/site-php/maxim/maxim-settings.inc');
  $conf['cache_inc'] = './sites/all/modules/contrib/memcache/memcache.inc';
  include_once('./includes/cache.inc');
  include_once('./sites/all/modules/contrib/memcache/memcache.inc');
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';

  // Set apachesolr to readonly if not on prod
  if ($_ENV['AH_SITE_ENVIRONMENT'] != 'prod') {
    $conf['apachesolr_environments']['acquia_search_server_1']['conf']['apachesolr_read_only'] = 1;
  } else {
    $conf['apachesolr_environments']['acquia_search_server_1']['conf']['apachesolr_read_only'] = 0;
  }

//   $conf['memcache_key_prefix'] = 'maxim';
//   $conf['server_msg'] = array('msg' => $msg, 'check_access' => TRUE);
// //Always operate assuming that we are behind a trusted reverse proxy.
  $conf['reverse_proxy'] = TRUE;
  $conf['reverse_proxy_addresses'] = isset($_SERVER['REMOTE_ADDR']) ? array($_SERVER['REMOTE_ADDR']) : array();
  $conf['reverse_proxy_header'] = isset($_SERVER['HTTP_TRUE_CLIENT_IP']) ? 'HTTP_TRUE_CLIENT_IP' : 'HTTP_X_FORWARDED_FOR';
//   $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';

} else {
  require('local.settings.php');
  $conf['apachesolr_environments']['acquia_search_server_1']['conf']['apachesolr_read_only'] = 1;
}

/**
 * Fast 404 settings:
 *
 * Fast 404 will do two separate types of 404 checking.
 *
 * The first is to check for URLs which appear to be files or images. If Drupal
 * is handling these items, then they were not found in the file system and are
 * a 404.
 *
 * The second is to check whether or not the URL exists in Drupal by checking
 * with the menu router, aliases and redirects. If the page does not exist, we
 * will server a fast 404 error and exit.
 */

# Load the fast_404.inc file. This is needed if you wish to do extension
# checking in settings.php.
include_once('./sites/all/modules/patched/fast_404/fast_404.inc');

# Disallowed extensions. Any extension in here will not be served by Drupal and
# will get a fast 404.
# Default extension list, this is considered safe and is even in queue for
# Drupal 8 (see: http://drupal.org/node/76824).
$conf['fast_404_exts'] = '/\.(txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';

# Allow anonymous users to hit URLs containing 'imagecache' even if the file
# does not exist. TRUE is default behavior. If you know all imagecache
# variations are already made set this to FALSE.
$conf['fast_404_allow_anon_imagecache'] = FALSE;

# Extension list requiring whitelisting to be activated **If you use this
# without whitelisting enabled your site will not load!
//$conf['fast_404_exts'] = '/\.(txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp|php|html?|xml)$/i';

# Default fast 404 error message.
$conf['fast_404_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

# Default fast 404 error page.
$conf['fast_404_HTML_error_page'] = realpath(dirname(__FILE__)) . '/404.html';

# Check paths during bootstrap and see if they are legitimate.
if (strpos($_GET['q'], 'amg/') !== FALSE) {
  $_GET['q'] = preg_replace('/amg\//', '', $_GET['q'], 1);
  $conf['fast_404_path_check'] = TRUE;
} else if (strpos($_GET['q'], '.html') !== FALSE) {
  $conf['fast_404_path_check'] = TRUE;
} else {
  # Set to true to test if page exists in DB
  $conf['fast_404_path_check'] = TRUE;
}

# If enabled, you may add extensions such as xml and php to the
# $conf['fast_404_exts'] above. BE CAREFUL with this setting as some modules
# use their own php files and you need to be certain they do not bootstrap
# Drupal. If they do, you will need to whitelist them too.
$conf['fast_404_url_whitelisting'] = FALSE;

# Array of whitelisted files/urls. Used if whitelisting is set to TRUE.
$conf['fast_404_whitelist'] = array('index.php', 'rss.xml', 'install.php', 'cron.php', 'update.php', 'xmlrpc.php');

# Call the extension checking now. This will skip any logging of 404s.
# Extension checking is safe to do from settings.php. There are many
# examples of this on Drupal.org.
fast_404_ext_check();

# Path checking. USE AT YOUR OWN RISK (only works with MySQL).
# Path checking at this phase is more dangerous, but faster. Normally
# Fast_404 will check paths during Drupal boostrap via hook_boot. Checking
# paths here is faster, but trickier as the Drupal database connections have
# not yet been made and the module must make a separate DB connection. Under
# most configurations this DB connection will be reused by Drupal so there
# is no waste.
# While this setting finds 404s faster, it adds a bit more load time to
# regular pages, so only use if you are spending too much CPU/Memory/DB on
# 404s and the trade-off is worth it.
# This setting will deliver 404s with less than 2MB of RAM.
fast_404_path_check();

