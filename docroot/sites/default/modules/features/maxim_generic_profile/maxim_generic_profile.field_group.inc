<?php
/**
 * @file
 * maxim_generic_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function maxim_generic_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group__profile_contest_data|node|gereric_profile|form';
  $field_group->group_name = 'group__profile_contest_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contest Data',
    'weight' => '16',
    'children' => array(
      0 => 'field_hotties_contest_status',
      1 => 'field_hotties_contest_year',
      2 => 'field_hotties_finalist_place',
      3 => 'field_gen_profile_contest_round',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group__profile_contest_data|node|gereric_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gen_profile_school|node|generic_profile|form';
  $field_group->group_name = 'group_gen_profile_school';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'School',
    'weight' => '18',
    'children' => array(
      0 => 'field_gen_profile_college',
      1 => 'field_gen_profile_major',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gen_profile_school|node|generic_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gen_profile_sports|node|generic_profile|form';
  $field_group->group_name = 'group_gen_profile_sports';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sports',
    'weight' => '58',
    'children' => array(
      0 => 'field_group_gen_fav_team',
      1 => 'field_gen_profile_fav_sport',
      2 => 'field_gen_profile_mascot',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gen_profile_sports|node|generic_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_physical_attributes|node|generic_profile|form';
  $field_group->group_name = 'group_physical_attributes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Physical Attributes',
    'weight' => '14',
    'children' => array(
      0 => 'field_profile_height',
      1 => 'field_profile_weight',
      2 => 'field_gen_profile_weight',
      3 => 'field_gen_profile_gender',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_physical_attributes|node|generic_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_location|node|gereric_profile|form';
  $field_group->group_name = 'group_profile_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location/Contact Info',
    'weight' => '15',
    'children' => array(
      0 => 'field_profile_city',
      1 => 'field_profile_country',
      2 => 'field_profile_state',
      3 => 'field_profile_address1',
      4 => 'field_profile_address2',
      5 => 'field_profile_email',
      6 => 'field_profile_phone',
      7 => 'field_profile_twitter',
      8 => 'field_profile_facebook',
      9 => 'field_profile_hometown',
      10 => 'field_profile_zipcode',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_location|node|gereric_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_ref_nodes|node|generic_profile|form';
  $field_group->group_name = 'group_profile_ref_nodes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slideshows/Videos',
    'weight' => '17',
    'children' => array(
      0 => 'field_profile_ref_slideshow',
      1 => 'field_profile_ref_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_ref_nodes|node|generic_profile|form'] = $field_group;

  return $export;
}
