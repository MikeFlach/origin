<?php
/**
 * @file
 * maxim_webform_views.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function maxim_webform_views_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|hotties_profile|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'hotties_profile';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'city_state_comma_separated' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'latest_tweet' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'vote_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_profile_first_name' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h2',
        'fi-cl' => '',
        'fi-at' => '',
        'fi-def-at' => FALSE,
        'fi-odd-even' => FALSE,
      ),
    ),
    'field_profile_profession_misc' => array(
      'ft' => array(
        'func' => NULL,
        'lb' => 'Profession',
      ),
    ),
  );
  $export['node|hotties_profile|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function maxim_webform_views_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'city_state_comma_separated';
  $ds_field->label = 'city state comma separated';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field_profile_city], [node:field_profile_state]',
      'format' => 'plain_text',
    ),
    'use_token' => 1,
  );
  $export['city_state_comma_separated'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'latest_tweet';
  $ds_field->label = 'Latest Tweet';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
if (!empty($entity->field_profile_twitter[LANGUAGE_NONE][0][\'safe_value\'])) {
  $handle = $entity->field_profile_twitter[LANGUAGE_NONE][0][\'safe_value\'];
  preg_match( \'/(\\w+)#?\\s?$/\', $handle, $handle);
  $handle = $handle[1];
  $jta_js = "(function($){
      $(document).ready(function(){
        $(\'#tweetLatest\').jTweetsAnywhere({
          username: \'{$handle}\',
          count: 1,
          showTweetFeed: {
            showProfileImages: true,
            showUserScreenNames: true,
            showUserFullNames: true,
            showActionReply: false,
            showActionRetweet: false,
            showActionFavorite: false
        },
        autorefresh: {
          mode: \'auto-insert\',
          interval: 30,
          duration: -1
        }
      });
    });
  })(jQuery)";
}else{
    $jta_js = "(function($){
      $(document).ready(function(){
        $(\'#tweetLatest\').jTweetsAnywhere({
          searchParams: [\'q=hometownhotties\'],
          count: 1,
          showTweetFeed: {
            showProfileImages: true,
            showUserScreenNames: true,
            showUserFullNames: true,
            showActionReply: false,
            showActionRetweet: false,
            showActionFavorite: false
        },
          autorefresh: {
            mode: \'auto-insert\',
            interval: 30,
            duration: -1
          }
        });
      });
    })(jQuery)";
    
}
print \'<div id="tweetLatest"></div>\';
drupal_add_js($jta_js, \'inline\');
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['latest_tweet'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'vote_button';
  $ds_field->label = 'Vote Button';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div id="hth_vote">Vote For Me!</div><iframe width=1 height=1 src="/sites/default/libraries/php/hth_vote/set_uuid.php"></iframe>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['vote_button'] = $ds_field;

  return $export;
}
