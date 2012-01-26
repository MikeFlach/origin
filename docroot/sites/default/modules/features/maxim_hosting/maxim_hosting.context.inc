<?php
/**
 * @file
 * maxim_hosting.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function maxim_hosting_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'vary_headers';
  $context->description = 'Set vary header to bust akamai for authenticated users';
  $context->tag = 'Headers';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'audience development' => 'audience development',
        'contibutor' => 'contibutor',
        'developer' => 'developer',
        'editor' => 'editor',
        'media creator' => 'media creator',
      ),
    ),
  );
  $context->reactions = array(
    'http_header' => array(
      'http_header' => array(
        'extra_headers' => 'Vary:Cookie',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Headers');
  t('Set vary header to bust akamai for authenticated users');
  $export['vary_headers'] = $context;

  return $export;
}
