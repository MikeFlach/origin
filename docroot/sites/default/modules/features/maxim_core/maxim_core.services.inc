<?php
/**
 * @file
 * maxim_core.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function maxim_core_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'maxim_voting';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'js-api';
  $endpoint->authentication = array();
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'multi-vote' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['maxim_voting'] = $endpoint;

  return $export;
}
