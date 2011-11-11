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

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '3',
  );

  // Exported role: audience development
  $roles['audience development'] = array(
    'name' => 'audience development',
    'weight' => '4',
  );

  // Exported role: contibutor
  $roles['contibutor'] = array(
    'name' => 'contibutor',
    'weight' => '3',
  );

  // Exported role: developer
  $roles['developer'] = array(
    'name' => 'developer',
    'weight' => '2',
  );

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '1',
  );

  // Exported role: mediaCreator
  $roles['mediaCreator'] = array(
    'name' => 'mediaCreator',
    'weight' => '2',
  );

  return $roles;
}
