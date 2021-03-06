<?php

/**
 * Implements hook_rules_action_info().
 */
function rules_redirect_url_rules_action_info() {
  return array(
    'add_url_redirect_action' => array(
      'label' => t('Control url redirect'),
      'group' => t('Maxim Rules'),
      'parameter' => array(
        'source_path' => array(
          'type' => 'uri',
          'label' => t('Source URL')
        ),
        'redirect_path' => array(
          'type' => 'uri',
          'label' => t('Dest URL')
        ),
      )
    ),
  );
}

/*
 *  Function was lifted from the Rules module test suite.
 */
function add_url_redirect_action($source_path, $redirect_path, array $redirect = array()) {
  $source_parsed = redirect_parse_url($source_path);
  $redirect['source'] = $source_parsed['url'];
  if (isset($source_parsed['query'])) {
    $redirect['source_options']['query'] = $source_parsed['query'];
  }

  $redirect_parsed = redirect_parse_url($redirect_path);
  $redirect['redirect'] = $redirect_parsed['url'];
  if (isset($redirect_parsed['query'])) {
    $redirect['redirect_options']['query'] = $redirect_parsed['query'];
  }
  if (isset($redirect_parsed['fragment'])) {
    $redirect['redirect_options']['fragment'] = $redirect_parsed['fragment'];
  }

  $redirect_object = new stdClass();
  redirect_object_prepare($redirect_object, $redirect);
  try{
    redirect_save($redirect_object);
  } catch (Exception $e) {
    echo 'Caught exception: ',  $e->getMessage(), "\n";
  }
  //return $redirect_object;
}