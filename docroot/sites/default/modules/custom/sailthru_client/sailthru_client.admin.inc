<?php

/**
 * Form builder; Displays Sailthru API administration settings
 * page.
 *
 * @see system_settings_form()
 */
function sailthru_client_admin_settings() {
  $form = array();

  $form['sailthru_client_api_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Sailthru API key'),
    '#description'   => t('The API key provided by Sailthru'),
    '#required'      => TRUE,
    '#size'          => 32,
    '#maxlength'   => 255,
    '#default_value' => variable_get('sailthru_client_api_key', ''),
  );

  $form['sailthru_client_api_secret'] = array(
    '#type'        => 'textfield',
    '#title'       => t('Sailthru Secret'),
    '#description' => t('The secret provided by Sailthru'),
    '#required'    => TRUE,
    '#size'        => 32,
    '#maxlength'   => 255,
    '#default_value' => variable_get('sailthru_client_api_secret', ''),
  );

  $form['sailthru_client_api_uri'] = array(
    '#type'        => 'textfield',
    '#title'       => t('Sailthru URI'),
    '#description' => t('The URI to use for the Sailthru API'),
    '#required'    => TRUE,
    '#size'        => 32,
    '#maxlength'   => 255,
    '#default_value' => variable_get('sailthru_client_api_uri', 'https://api.sailthru.com'),
  );
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('TEST API KEY/SECRET'),
      '#submit' => array('sailthru_client_test'),
  );

  return system_settings_form($form);
}

function sailthru_client_test($form, &$form_state) {
  $api_key = $form_state['input']['sailthru_client_api_key'];
  $api_secret = $form_state['input']['sailthru_client_api_secret'];
  $sailthru_client_api_uri = $form_state['input']['sailthru_client_api_uri'];
  
  $vars  = array(
    'first_name' => 'John',
    'last_name' => 'Doe',
  );

  $lists   = array(
    'newly_created_list' => 1
  );
  
  try {
    sailthru_client_get_client();
    $sailthruClient = new Sailthru_Client($api_key, $api_secret, $sailthru_client_api_uri);
    $sailthruClient->setEmail('test@testemail.com', $vars, $lists);
  } catch (Exception $exc) {
    drupal_set_message(t('The API functionality did not work as expected'));
  }
  
  drupal_set_message(t('The API functionality works'));
}
