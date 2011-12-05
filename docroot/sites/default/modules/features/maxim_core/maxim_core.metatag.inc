<?php
/**
 * @file
 * maxim_core.metatag.inc
 */

/**
 * Implements hook_metatag_config_default().
 */
function maxim_core_metatag_config_default() {
  $export = array();

  $config = new stdClass;
  $config->disabled = FALSE; /* Edit this to true to make a default config disabled initially */
  $config->api_version = 1;
  $config->cid = '1';
  $config->instance = 'global';
  $config->config = array(
    'description' => array(
      'value' => 'Maxim.com - the Ultimate Guys Guide - check out sexy photos and videos of celebrities, Hometown Hotties, and our Hot 100. Maxim is your source of funny lists, jokes, sexy women, and movies online.',
    ),
    'keywords' => array(
      'value' => 'hot girls, sexy photos, sexy videos, celebrities, gaming, hot 100, entertainment, maxim, cars, sports, babes, funny jokes, funny lists, maxim, maxim.com',
    ),
    'title' => array(
      'value' => '[current-page:title] | [site:name]',
    ),
    'copyright' => array(
      'value' => '"Maxim Digital", "MAXIM", "MAXIM ONLINE", "Maximonline.com", "Maxim.com" and the "M" Logo" are registered trademarks owned by Alpha Media Group Inc. "Maxim.com" and "MAXIM TO GO" are trademark owned by Alpha Media Group Inc.',
    ),
    'canonical' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'shortlink' => array(
      'value' => '[current-page:url:relative]',
    ),
    'og:title' => array(
      'value' => '[current-page:title]',
    ),
    'og:type' => array(
      'value' => 'article',
    ),
    'og:image' => array(
      'value' => 'http://cdn2.maxim.com/maxim/files/maxim2/Maxim/static_files/images/footerlogo.jpg',
    ),
    'og:url' => array(
      'value' => '[current-page:url]',
    ),
    'og:site_name' => array(
      'value' => '[site:name]',
    ),
    'og:description' => array(
      'value' => 'Maxim.com - the Ultimate Guys Guide - check out sexy photos and videos of celebrities, Hometown Hotties, and our Hot 100. Maxim is your source of funny lists, jokes, sexy women, and movies online.',
    ),
  );
  $export['global'] = $config;

  return $export;
}
