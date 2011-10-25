<?php
/**
 * @file
 * maxim_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function maxim_core_user_default_roles() {
  $roles = array();

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '1',
  );
  
  // Exported role: developer
  $roles['developer'] = array(
  	'name' => 'developer',
    'weight' => '2',
  );
  
  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  return $roles;
}
