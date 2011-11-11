<?php
/**
 * @file
 * maxim_core.dart_tag_default.inc
 */

/**
 * Implements hook_default_dart_tag().
 */
function maxim_core_default_dart_tag() {
  $export = array();

  $tag = new stdClass;
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'dart_banner';
  $tag->name = 'DART Ad: Banner';
  $tag->pos = 'top';
  $tag->sz = '970x418';
  $tag->active = 1;
  $tag->block = 1;
  $tag->settings = array(
    'overrides' => array(
      'site' => '',
      'zone' => '',
      'slug' => '',
    ),
    'options' => array(
      'scriptless' => 0,
      'method' => 'adj',
      'include_terms' => 0,
    ),
    'key_vals' => array(),
    'scheduler' => array(),
  );
  $export['dart_banner'] = $tag;

  $tag = new stdClass;
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'dart_big_box';
  $tag->name = 'DART Ad: Big Box';
  $tag->pos = 'rhs_pos1';
  $tag->sz = '300x250,300x600';
  $tag->active = 1;
  $tag->block = 1;
  $tag->settings = array(
    'overrides' => array(
      'site' => '',
      'zone' => '',
      'slug' => '',
    ),
    'options' => array(
      'scriptless' => 0,
      'method' => 'adj',
      'include_terms' => 0,
    ),
    'key_vals' => array(),
    'scheduler' => array(),
  );
  $export['dart_big_box'] = $tag;

  $tag = new stdClass;
  $tag->disabled = FALSE; /* Edit this to true to make a default tag disabled initially */
  $tag->api_version = 1;
  $tag->machinename = 'dart_leaderboard';
  $tag->name = 'DART Ad: Leaderboard';
  $tag->pos = 'sub_top';
  $tag->sz = '728x90';
  $tag->active = 1;
  $tag->block = 1;
  $tag->settings = array(
    'overrides' => array(
      'site' => '',
      'zone' => '',
      'slug' => '',
    ),
    'options' => array(
      'scriptless' => 0,
      'method' => 'adj',
      'include_terms' => 0,
    ),
    'key_vals' => array(),
    'scheduler' => array(),
  );
  $export['dart_leaderboard'] = $tag;

  return $export;
}