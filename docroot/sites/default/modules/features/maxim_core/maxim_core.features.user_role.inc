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

  // Exported role: SEO.
  $roles['SEO'] = array(
    'name' => 'SEO',
    'weight' => '4',
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '9',
  );

  // Exported role: audience development.
  $roles['audience development'] = array(
    'name' => 'audience development',
    'weight' => '3',
  );

  // Exported role: contibutor.
  $roles['contibutor'] = array(
    'name' => 'contibutor',
    'weight' => '6',
  );

  // Exported role: developer.
  $roles['developer'] = array(
    'name' => 'developer',
    'weight' => '8',
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '7',
  );

  // Exported role: media creator.
  $roles['media creator'] = array(
    'name' => 'media creator',
    'weight' => '5',
  );

  // Exported role: talent scout.
  $roles['talent scout'] = array(
    'name' => 'talent scout',
    'weight' => '2',
  );

  return $roles;
}
