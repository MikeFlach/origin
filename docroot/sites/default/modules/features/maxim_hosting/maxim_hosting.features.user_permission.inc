<?php
/**
 * @file
 * maxim_hosting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function maxim_hosting_user_default_permissions() {
  $permissions = array();

  // Exported permission: stick to Acquia web node.
  $permissions['stick to Acquia web node'] = array(
    'name' => 'stick to Acquia web node',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'acquia_cloud_sticky_session',
  );

  return $permissions;
}
