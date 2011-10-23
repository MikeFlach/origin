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

require('/var/www/site-php/maxim/maxim-settings.inc');

/*switch ($_SERVER['SERVER_NAME']) {
  case 'www.maxim.com':
  case 'maxim.com':
	case 'dev.maxim.com':
	case 'stage.maxim.com':
  case 'maxim.prod.acquia-sites.com':
  case 'maximstg.prod.acquia-sites.com':
  case 'maximdev.prod.acquia-sites.com':
  case 'staging-1047.prod.hosting.acquia.com':
    require('/var/www/site-php/maxim/maxim-settings.inc');
    break;
  default:
  	if (file_exists('local.settings.php')){
  	  require('local.settings.php');
  	}
}*/
