<?php
/**
 * Implements hook_drush_help().
 */
function brightcove_manager_drush_help($command) {
  switch ($command) {
    case 'drush:brightcove-manager':
      return dt('Brightcove Manager - update video data');
    case 'drush:brightcove-manager-assets':
      return dt('Brightcove Manager - update all video and image asset URLs');
    case 'drush:brightcove-manager-api-cache':
      return dt('Brightcove Manager - update Brightcove API cache');
    case 'drush:brightcove-manager-update-metadata':
      return dt('Brightcove Manager - get updates from brightcove');
  }
}

/**
 * Implements hook_drush_command().
 */
function brightcove_manager_drush_command() {
  $items = array();
  $items['brightcove-manager'] = array(
    'description' => 'Brightcove Manager - manage video data',
    'arguments' => array(
      'cmd' => dt('Optional. Command to perform.'),
    ),
    'examples' => array(
      'Update all (Brightcove metadata and API cache)' => 'drush brightcove-manager all, drush bm all',
      'Update asset URLs (images and videos).  Run nightly.' => 'drush brightcove-manager assets, drush bm assets, drush bma',
      'Update Brightcove API cache' => 'drush brightcove-manager api, drush bm api, drush bmc',
      'Update Brightcove metadata' => 'drush brightcove-manager metadata, drush bm metadata, drush bmu',
    ),
    'aliases' => array('bm'),
  );
  $items['brightcove-manager-api-cache'] = array(
    'description' => 'Brightcove Manager update api cache',
    'examples' => array(
      'Update Brightcove API cache' => 'drush brightcove-manager-api-cache, drush bmc',
    ),
    'aliases' => array('bmc'),
  );
  $items['brightcove-manager-update-metadata'] = array(
    'description' => 'Brightcove Manager - update brightcove metadata',
    'arguments' => array(
      'date' => dt('Optional. Changes made since date specified.  By default, it uses yesterday.'),
      'override' => dt('Optional. Override cache.  By default, it does not override cache if it has been updated previously.'),
    ),
    'examples' => array(
      'Update Brightcove API cache' => 'drush brightcove-manager-update-metadata, drush bmu',
    ),
    'aliases' => array('bmu'),
  );
  $items['brightcove-manager-assets'] = array(
    'description' => 'Brightcove Manager update video and image asset URLs',
    'examples' => array(
      'Update asset URLs (images and videos)' => 'drush brightcove-manager-assets, drush bma',
    ),
    'aliases' => array('bma'),
  );
  return $items;
}

function drush_brightcove_manager() {
  $args = func_get_args();
  if (count($args) > 0) {
    switch($args[0]) {
      case 'all':
      drush_brightcove_manager_update_metadata('yesterday', FALSE);
      echo "\n";
      drush_brightcove_manager_api_cache();
      break;
      case 'assets':
      drush_brightcove_manager_assets();
      break;
      case 'api':
      drush_brightcove_manager_api_cache();
      break;
      case 'metadata':
      $date = 'yesterday';
      $override = FALSE;
      if (count($args) > 1) {
        $date = $args[1];
        if (count($args) > 2) {
          $override = $args[2];
        }
      }

      drush_brightcove_manager_update_metadata($date, $override);
      break;
    }
  } else {
    drush_log(dt('No command defined. For help: drush help bm'), 'error');
  }
}

function drush_brightcove_manager_api_cache() {
  module_load_include('inc', 'brightcove_manager', 'brightcove_manager.update');
  echo '*** Updating Brightcove API calls ***' . "\n";
  $results = brightcove_manager_update_api_cache();

  drush_log(dt('Updated ' . $results['num_updated'] . ' api caches. ' . "\n" . $results['msg']), 'ok');
}

function drush_brightcove_manager_assets() {
  module_load_include('inc', 'brightcove_manager', 'brightcove_manager.update');
  echo '*** Updating asset URLs in database ***' . "\n";
  $results = brightcove_manager_update_assets();

  drush_log(dt('Updated video assets'), 'ok');
}

function drush_brightcove_manager_update_metadata($fromdate = NULL, $override = NULL) {
  module_load_include('inc', 'brightcove_manager', 'brightcove_manager.update');
  $args = func_get_args();

  if (strlen($fromdate) > 0) {
    $date = $fromdate;
  } else {
    if (count($args) > 0) {
      $date = $args[0];
      if ($overide == NULL && count($args) > 1) {
        $override = $args[1];
      }
    } else {
      $date = 'yesterday';
    }
  }

  $overrideUpdate = filter_var($override, FILTER_VALIDATE_BOOLEAN);

  echo '*** Updating video metadata in database since ' . $date . ' ***' . "\n";
  $results = brightcove_manager_update_metadata($date, $overrideUpdate);
  drush_log(dt('Updated metadata from brightcove'), 'ok');
}


