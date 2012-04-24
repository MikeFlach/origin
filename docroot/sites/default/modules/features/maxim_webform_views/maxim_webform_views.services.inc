<?php
/**
 * @file
 * maxim_webform_views.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function maxim_webform_views_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'hth_voting';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'js-api';
  $endpoint->authentication = array();
  $endpoint->server_settings = '';
  $endpoint->resources = array(
    'vote' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
        'create' => array(
          'enabled' => 1,
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => 1,
        ),
        'create' => array(
          'enabled' => 1,
        ),
        'update' => array(
          'enabled' => 1,
        ),
        'delete' => array(
          'enabled' => 1,
        ),
        'index' => array(
          'enabled' => 1,
        ),
      ),
      'relationships' => array(
        'files' => array(
          'enabled' => 1,
        ),
        'comments' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['hth_voting'] = $endpoint;

  return $export;
}
