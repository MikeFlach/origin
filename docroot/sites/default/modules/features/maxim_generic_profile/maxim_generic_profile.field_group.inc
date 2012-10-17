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
    'weight' => '15',
    'children' => array(
      0 => 'field_gen_profile_contest_round',
      1 => 'field_gen_profile_contest_status',
      2 => 'field_gen_profile_contest_year',
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
  $field_group->identifier = 'group_gen_military|node|generic_profile|form';
  $field_group->group_name = 'group_gen_military';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Military',
    'weight' => '20',
    'children' => array(
      0 => 'field_gen_military_status',
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
  $export['group_gen_military|node|generic_profile|form'] = $field_group;

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
    'weight' => '19',
    'children' => array(
      0 => 'field_gen_profile_fav_sport',
      1 => 'field_gen_profile_mascot',
      2 => 'field_group_gen_fav_team',
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
  $field_group->identifier = 'group_gprofile_info|node|generic_profile|full';
  $field_group->group_name = 'group_gprofile_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Profile Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_gen_profile_college',
      1 => 'field_gen_profile_fav_sport',
      2 => 'field_gen_profile_major',
      3 => 'field_gen_profile_mascot',
      4 => 'field_group_gen_fav_team',
      5 => 'field_profile_first_name',
      6 => 'field_profile_height',
      7 => 'field_profile_profession_misc',
      8 => 'field_profile_weight',
      9 => 'field_gen_military_status',
      10 => 'city_state_comma_separated',
      11 => 'latest_tweet',
      12 => 'read_my_full_profile_link',
      13 => 'social_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'General Profile Info',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gprofile_info|node|generic_profile|full'] = $field_group;

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
    'weight' => '13',
    'children' => array(
      0 => 'field_gen_profile_gender',
      1 => 'field_profile_height',
      2 => 'field_profile_weight',
      3 => 'field_gen_profile_age',
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
    'weight' => '14',
    'children' => array(
      0 => 'field_profile_address1',
      1 => 'field_profile_address2',
      2 => 'field_profile_city',
      3 => 'field_profile_country',
      4 => 'field_profile_email',
      5 => 'field_profile_facebook',
      6 => 'field_profile_hometown',
      7 => 'field_profile_phone',
      8 => 'field_profile_state',
      9 => 'field_profile_twitter',
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
    'weight' => '16',
    'children' => array(
      0 => 'field_profile_ref_slideshow',
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
