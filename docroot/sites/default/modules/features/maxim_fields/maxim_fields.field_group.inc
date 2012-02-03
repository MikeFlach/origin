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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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

  $field_group = new stdClass;
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

  return $export;
}
