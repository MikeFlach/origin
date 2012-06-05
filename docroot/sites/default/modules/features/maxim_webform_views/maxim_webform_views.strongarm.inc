<?php
/**
 * @file
 * maxim_webform_views.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function maxim_webform_views_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hth_contest_week';
  $strongarm->value = '3';
  $export['hth_contest_week'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hth_contest_year';
  $strongarm->value = '2013';
  $export['hth_contest_year'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'location_defaultnum_hotties_profile';
  $strongarm->value = '1';
  $export['location_defaultnum_hotties_profile'] = $strongarm;

  return $export;
}
