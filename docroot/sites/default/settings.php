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

// set the right $base_url
switch ($_SERVER['HTTP_HOST']){
  case 'prod.maxim.com':
  case 'www.maxim.com':
  case 'origin2-www.maxim.com':
  case 'maxim.prod.acquia-sites.com':
  case 'maximstg.prod.acquia-sites.com':
    $base_url = 'http://www.maxim.com';
    break;
  default:
    $base_url = 'http://' . $_SERVER['HTTP_HOST'];
    break;
}

// Add Varnish as the page cache handler.
// Drupal 7 does not cache pages when we invoke hooks during bootstrap. This needs to be disabled.
$conf['page_cache_invoke_hooks'] = false;
$conf['cache'] = 1;
$conf['cache_lifetime'] = 300;
$conf['page_cache_maximum_age'] = 3600;
$conf['omit_vary_cookie'] = true;
//$con['reverse_proxy'] = true;

if (file_exists('/var/www/site-php/maxim/maxim-settings.inc')){
  require('/var/www/site-php/maxim/maxim-settings.inc');
} else {
  require('local.settings.php');
}
