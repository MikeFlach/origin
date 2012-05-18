<?php
/**
 * @file
 * maxim_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function maxim_fields_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|article|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_is_feature',
      3 => 'field_tags',
      4 => 'field_ppt',
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
  $export['group_content_organization|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|article|full';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '15',
    'children' => array(
      0 => 'field_is_feature',
      1 => 'field_tags',
      2 => 'field_ppt',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_content_organization|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|blog|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_is_feature',
      3 => 'field_tags',
      4 => 'field_ppt',
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
  $export['group_content_organization|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|list|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_is_feature',
      3 => 'field_tags',
      4 => 'field_ppt',
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
  $export['group_content_organization|node|list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|review|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '4',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_is_feature',
      3 => 'field_tags',
      4 => 'field_ppt',
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
  $export['group_content_organization|node|review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|review|full';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '18',
    'children' => array(
      0 => 'field_column',
      1 => 'field_is_feature',
      2 => 'field_tags',
      3 => 'field_ppt',
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
  $export['group_content_organization|node|review|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|slideshow|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_is_feature',
      3 => 'field_tags',
      4 => 'field_todays_girl',
      5 => 'field_ppt',
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
  $export['group_content_organization|node|slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_organization|node|video|form';
  $field_group->group_name = 'group_content_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_column',
      2 => 'field_tags',
      3 => 'field_ppt',
      4 => 'field_media_5min_id',
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
  $export['group_content_organization|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_org|node|joke|form';
  $field_group->group_name = 'group_content_org';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'joke';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_channel',
      1 => 'field_joke_category',
      2 => 'field_tags',
      3 => 'field_ppt',
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
  $export['group_content_org|node|joke|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_org|node|page|form';
  $field_group->group_name = 'group_content_org';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Organization',
    'weight' => '2',
    'children' => array(
      0 => 'field_ppt',
      1 => 'field_channel',
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
  $export['group_content_org|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filemobile|file|image|form';
  $field_group->group_name = 'group_filemobile';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FileMobile Data',
    'weight' => '12',
    'children' => array(
      0 => 'field_media_filemobile_id',
      1 => 'field_media_filemobile_user_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'FileMobile Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_filemobile|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filemobile|file|video|form';
  $field_group->group_name = 'group_filemobile';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FileMobile Data',
    'weight' => '7',
    'children' => array(
      0 => 'field_media_filemobile_id',
      1 => 'field_media_filemobile_user_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'FileMobile Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_filemobile|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filemobile|node|hotties_profile|form';
  $field_group->group_name = 'group_filemobile';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FileMobile Data',
    'weight' => '15',
    'children' => array(
      0 => 'field_media_filemobile_user_id',
      1 => 'field_filemobile_user_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'FileMobile Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_filemobile|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filemobile|node|slideshow|form';
  $field_group->group_name = 'group_filemobile';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FileMobile Data',
    'weight' => '7',
    'children' => array(
      0 => 'field_media_filemobile_user_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'FileMobile Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_filemobile|node|slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hottie_hometown|node|hotties_profile|default';
  $field_group->group_name = 'group_hottie_hometown';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hometown',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hometown',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_hottie_hometown|node|hotties_profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hottie_location|node|hotties_profile|default';
  $field_group->group_name = 'group_hottie_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '9',
    'children' => array(
      0 => 'field_profile_city',
      1 => 'field_profile_country',
      2 => 'field_profile_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_hottie_location|node|hotties_profile|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hottie_profile_info|node|hotties_profile|full';
  $field_group->group_name = 'group_hottie_profile_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hottie Profile Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_profile_first_name',
      1 => 'field_profile_height',
      2 => 'field_profile_measurements',
      3 => 'field_profile_weight',
      4 => 'field_profile_profession_misc',
      5 => 'city_state_comma_separated',
      6 => 'social_links',
      7 => 'year_week_competed',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hottie Profile Info',
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
  $export['group_hottie_profile_info|node|hotties_profile|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hotties_contest_data|node|hotties_profile|form';
  $field_group->group_name = 'group_hotties_contest_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contest Data',
    'weight' => '9',
    'children' => array(
      0 => 'field_hotties_contest_status',
      1 => 'field_hotties_contest_week',
      2 => 'field_hotties_contest_year',
      3 => 'field_hotties_finalist_place',
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
  $export['group_hotties_contest_data|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_credits|file|image|form';
  $field_group->group_name = 'group_image_credits';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Source/Credits',
    'weight' => '10',
    'children' => array(
      0 => 'field_image_origin',
      1 => 'field_image_aquired_from',
      2 => 'field_image_clothing_credit',
      3 => 'field_image_creator',
      4 => 'field_image_promotional',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image Source/Credits',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_image_credits|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image_rights|file|image|form';
  $field_group->group_name = 'group_image_rights';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Rights and Usage',
    'weight' => '9',
    'children' => array(
      0 => 'field_media_copyright',
      1 => 'field_online_rights_expire',
      2 => 'field_online_expiration_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Rights and Usage',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_image_rights|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|article|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_jumbo_image',
      1 => 'field_main_image',
      2 => 'field_feature_subtitle',
      3 => 'field_feature_title',
      4 => 'field_display_main_image',
      5 => 'field_filter_jumbotron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|article|full';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '13',
    'children' => array(
      0 => 'field_jumbo_image',
      1 => 'field_feature_subtitle',
      2 => 'field_feature_title',
      3 => 'field_display_main_image',
      4 => 'field_filter_jumbotron',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|blog|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_main_image',
      4 => 'field_display_main_image',
      5 => 'field_filter_jumbotron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|list|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_main_image',
      4 => 'field_display_main_image',
      5 => 'field_filter_jumbotron',
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
  $export['group_images|node|list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|review|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '5',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_main_image',
      4 => 'field_display_main_image',
      5 => 'field_filter_jumbotron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|review|full';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '19',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_display_main_image',
      4 => 'field_filter_jumbotron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|review|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|slideshow|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '5',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_main_image',
      4 => 'field_filter_jumbotron',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|node|slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|video|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_feature_subtitle',
      1 => 'field_feature_title',
      2 => 'field_jumbo_image',
      3 => 'field_main_image',
      4 => 'field_media_thumbnail_path',
      5 => 'field_filter_jumbotron',
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
  $export['group_images|node|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_physical_attributes|node|hotties_profile|form';
  $field_group->group_name = 'group_physical_attributes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Physical Attributes',
    'weight' => '7',
    'children' => array(
      0 => 'field_profile_eye_color',
      1 => 'field_profile_hair_color',
      2 => 'field_profile_height',
      3 => 'field_profile_measurements',
      4 => 'field_profile_weight',
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
  $export['group_physical_attributes|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_location|node|hotties_profile|form';
  $field_group->group_name = 'group_profile_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location/Contact info',
    'weight' => '8',
    'children' => array(
      0 => 'field_profile_city',
      1 => 'field_profile_country',
      2 => 'field_profile_state',
      3 => 'field_profile_address1',
      4 => 'field_profile_address2',
      5 => 'field_profile_email',
      6 => 'field_profile_geo_latitude',
      7 => 'field_profile_phone',
      8 => 'field_profile_geo_longitude',
      9 => 'field_profile_twitter',
      10 => 'field_profile_hometown',
      11 => 'field_profile_facebook',
      12 => 'field_profile_zipcode',
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
  $export['group_profile_location|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_ref_nodes|node|hotties_profile|form';
  $field_group->group_name = 'group_profile_ref_nodes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slideshows/Videos',
    'weight' => '10',
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
  $export['group_profile_ref_nodes|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reviews_data|node|review|default';
  $field_group->group_name = 'group_reviews_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Review Data',
    'weight' => '1',
    'children' => array(
      0 => 'field_reviews_air_date',
      1 => 'field_reviews_artist',
      2 => 'field_reviews_game_platform',
      3 => 'field_reviews_mpaa_rating',
      4 => 'field_reviews_release_date',
      5 => 'field_reviews_star_rating',
      6 => 'field_reviews_tv_network',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Review Data',
      'instance_settings' => array(
        'classes' => 'clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_reviews_data|node|review|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reviews_data|node|review|form';
  $field_group->group_name = 'group_reviews_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Review Fields',
    'weight' => '7',
    'children' => array(
      0 => 'field_reviews_air_date',
      1 => 'field_reviews_artist',
      2 => 'field_reviews_game_platform',
      3 => 'field_reviews_mpaa_rating',
      4 => 'field_reviews_price',
      5 => 'field_reviews_release_date',
      6 => 'field_reviews_source',
      7 => 'field_reviews_star_rating',
      8 => 'field_reviews_tv_network',
      9 => 'field_reviews_website',
      10 => 'field_affiliate_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Review Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_reviews_data|node|review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reviews_data|node|review|full';
  $field_group->group_name = 'group_reviews_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Review Data',
    'weight' => '1',
    'children' => array(
      0 => 'field_reviews_air_date',
      1 => 'field_reviews_artist',
      2 => 'field_reviews_game_platform',
      3 => 'field_reviews_mpaa_rating',
      4 => 'field_reviews_release_date',
      5 => 'field_reviews_star_rating',
      6 => 'field_reviews_tv_network',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Review Data',
      'instance_settings' => array(
        'classes' => 'clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_reviews_data|node|review|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|file|image|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '11',
    'children' => array(
      0 => 'field_media_cdn_url',
      1 => 'field_media_source_path',
      2 => 'field_media_source_url',
      3 => 'field_media_thumbnail_path',
      4 => 'field_media_vgn_image_id',
      5 => 'field_media_vgn_record_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|file|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|file|video|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '6',
    'children' => array(
      0 => 'field_media_cdn_url',
      1 => 'field_media_source_path',
      2 => 'field_media_source_url',
      3 => 'field_media_thumbnail_path',
      4 => 'field_media_vgn_image_id',
      5 => 'field_media_vgn_record_id',
      6 => 'field_vgn_channel',
      7 => 'field_vgn_vanity_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|file|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|article|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '5',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_guid',
      2 => 'field_vgn_image_id',
      3 => 'field_vgn_vanity_url',
      4 => 'field_vgn_channel',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|article|full';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '14',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_guid',
      2 => 'field_vgn_image_id',
      3 => 'field_vgn_vanity_url',
      4 => 'field_vgn_channel',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|blog|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '5',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_guid',
      2 => 'field_vgn_image_id',
      3 => 'field_vgn_vanity_url',
      4 => 'field_vgn_channel',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|blog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|hotties_profile|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hotties_profile';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '14',
    'children' => array(
      0 => 'field_vgn_guid',
      1 => 'field_vgn_image_id',
      2 => 'field_vgn_profile_id',
      3 => 'field_vgn_vanity_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|hotties_profile|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|joke|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'joke';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '6',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_guid',
      2 => 'field_vgn_vanity_url',
      3 => 'field_vgn_channel',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|joke|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|list|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '5',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_channel',
      2 => 'field_vgn_guid',
      3 => 'field_vgn_image_id',
      4 => 'field_vgn_vanity_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|review|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '8',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_channel',
      2 => 'field_vgn_guid',
      3 => 'field_vgn_image_id',
      4 => 'field_vgn_vanity_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|review|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|review|full';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '20',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_channel',
      2 => 'field_vgn_guid',
      3 => 'field_vgn_image_id',
      4 => 'field_vgn_vanity_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|review|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|slideshow|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'slideshow';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '6',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_channel',
      2 => 'field_vgn_guid',
      3 => 'field_vgn_vanity_url',
      4 => 'field_vgn_image_id',
      5 => 'field_media_vgn_image_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|slideshow|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vignette_data|node|video|form';
  $field_group->group_name = 'group_vignette_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vignette Data',
    'weight' => '5',
    'children' => array(
      0 => 'field_freeform_tags',
      1 => 'field_vgn_channel',
      2 => 'field_vgn_guid',
      3 => 'field_vgn_image_id',
      4 => 'field_vgn_vanity_url',
      5 => 'field_media_vgn_record_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vignette Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_vignette_data|node|video|form'] = $field_group;

  return $export;
}
