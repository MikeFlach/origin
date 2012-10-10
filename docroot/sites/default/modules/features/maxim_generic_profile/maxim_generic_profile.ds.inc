<?php
/**
 * @file
 * maxim_generic_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function maxim_generic_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|generic_profile|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'generic_profile';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'general_profile_previous_next' => array(
      'weight' => '19',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'vote_button' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'city_state_comma_separated' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'latest_tweet' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'read_my_full_profile_link' => array(
      'weight' => '19',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_links' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_profile_first_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_profile_profession_misc' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Profession',
        ),
      ),
    ),
  );
  $export['node|generic_profile|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function maxim_generic_profile_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'general_profile_previous_next';
  $ds_field->label = 'General Profile - Previous/Next';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="clearfix">
  <div class="gprofile-prev-btn"></div>
  <div class="gprofile-next-btn"></div>
</div>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['general_profile_previous_next'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function maxim_generic_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|generic_profile|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'generic_profile';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_profile_ref_video',
        1 => 'body',
        2 => 'field_profile_zipcode',
      ),
    ),
    'fields' => array(
      'field_profile_ref_video' => 'ds_content',
      'body' => 'ds_content',
      'field_profile_zipcode' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|generic_profile|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|generic_profile|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'generic_profile';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_gen_profile_contest_round',
      ),
      'generic_profile_information' => array(
        2 => 'group_gprofile_info',
        3 => 'field_profile_first_name',
        4 => 'city_state_comma_separated',
        5 => 'social_links',
        6 => 'field_gen_profile_weight',
        7 => 'field_gen_profile_gender',
        8 => 'field_profile_profession_misc',
        9 => 'field_gen_military_status',
        10 => 'latest_tweet',
        11 => 'field_gen_profile_major',
        12 => 'field_profile_height',
        13 => 'field_profile_weight',
        14 => 'field_gen_profile_college',
        15 => 'field_group_gen_fav_team',
        17 => 'field_gen_profile_fav_sport',
        18 => 'field_gen_profile_mascot',
        20 => 'read_my_full_profile_link',
      ),
      'generic_slideshow' => array(
        16 => 'field_profile_ref_slideshow',
      ),
      'generic_vote' => array(
        19 => 'vote_button',
      ),
      'generic_previous_next' => array(
        21 => 'general_profile_previous_next',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_gen_profile_contest_round' => 'ds_content',
      'group_gprofile_info' => 'generic_profile_information',
      'field_profile_first_name' => 'generic_profile_information',
      'city_state_comma_separated' => 'generic_profile_information',
      'social_links' => 'generic_profile_information',
      'field_gen_profile_weight' => 'generic_profile_information',
      'field_gen_profile_gender' => 'generic_profile_information',
      'field_profile_profession_misc' => 'generic_profile_information',
      'field_gen_military_status' => 'generic_profile_information',
      'latest_tweet' => 'generic_profile_information',
      'field_gen_profile_major' => 'generic_profile_information',
      'field_profile_height' => 'generic_profile_information',
      'field_profile_weight' => 'generic_profile_information',
      'field_gen_profile_college' => 'generic_profile_information',
      'field_group_gen_fav_team' => 'generic_profile_information',
      'field_profile_ref_slideshow' => 'generic_slideshow',
      'field_gen_profile_fav_sport' => 'generic_profile_information',
      'field_gen_profile_mascot' => 'generic_profile_information',
      'vote_button' => 'generic_vote',
      'read_my_full_profile_link' => 'generic_profile_information',
      'general_profile_previous_next' => 'generic_previous_next',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'article',
    ),
    'layout_wrapper' => 'article',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|generic_profile|full'] = $ds_layout;

  return $export;
}
