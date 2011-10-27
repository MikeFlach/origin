<?php
/**
 * @file
 * maxim_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function maxim_core_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'maxim_homepage';
  $context->description = '';
  $context->tag = 'maxim';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('maxim');
  $export['maxim_homepage'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'maxim_sitewide';
  $context->description = '';
  $context->tag = 'maxim';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('maxim');
  $export['maxim_sitewide'] = $context;

  return $export;
}
