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
    'hotties_previous_next' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'city_state_comma_separated' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'read_my_full_profile_anchor' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'read_my_full_profile_link' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'social_links' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'vote_button' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'year_week_competed' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_profile_first_name' => array(
      'formatter_settings' => array(
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
    ),
    'field_profile_profession_misc' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Profession',
        ),
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
  $ds_field->label = 'City State comma separated';
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
          count: 20,
          showTweetFeed: {
            showProfileImages: true,
            showUserScreenNames: true,
            showUserFullNames: true,
            showActionReply: false,
            showActionRetweet: false,
            showActionFavorite: false,
            paging: { mode: \'endless-scroll\'},
            expandHovercards: true
        },
        onDataRequestHandler: function(stats) {
          if (stats.dataRequestCount < 11) { return true; }
          else { alert(\\"To avoid struggling with Twitter\'s rate limit, we stop loading data after 10 API calls.\\");}},
        showFollowButton: true,
      });
    });
  })(jQuery)";
}else{
    $jta_js = "(function($){
      $(document).ready(function(){
        $(\'#tweetLatest\').jTweetsAnywhere({
          username: \'maximmag\',
          searchParams: [\'q=hometownhotties\'],
          count: 2,
          showTweetFeed: {
            showProfileImages: true,
            showUserScreenNames: true,
            showUserFullNames: true,
            showActionReply: false,
            showActionRetweet: false,
            showActionFavorite: false,
            paging: { mode: \'endless-scroll\'},
            expandHovercards: true
        },
        onDataRequestHandler: function(stats) {
          if (stats.dataRequestCount < 11) { return true; }
          else { alert(\\"To avoid struggling with Twitter\'s rate limit, we stop loading data after 10 API calls.\\");}},
          showFollowButton: true,
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
  $ds_field->field = 'read_my_full_profile_anchor';
  $ds_field->label = 'Read My Full Profile Anchor';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a name=\'full_profile\'></a>',
      'format' => 'filtered_html',
    ),
    'use_token' => 0,
  );
  $export['read_my_full_profile_anchor'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'read_my_full_profile_link';
  $ds_field->label = 'Read My Full Profile Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="#full_profile" style="color: #0074a4; font-weight:bold;">Read my full profile</a>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['read_my_full_profile_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'social_links';
  $ds_field->label = 'Social Links';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$fb_link = \'<div class="fb-like" data-send="true" data-layout="button_count" data-width="110" data-show-faces="false"></div>\';
$twitter_link = \'<a href="https://twitter.com/share" class="twitter-share-button" data-via="MaximMag">Tweet</a>\';

$twitter_js = \'!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs")\';
drupal_add_js($twitter_js, array(\'type\' => \'inline\', \'scope\' => \'footer\'));

$add_class = \'social-links\';
print \'<div class="\'.$add_class.\'">\'.$twitter_link.$fb_link.\'</div>\';
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['social_links'] = $ds_field;

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
      'value' => '<div id="hth_vote">Vote For Me!</div><div id="hth_no_vote_msg" style="display:none"></div><iframe id="vote_UUID" width="1" height="1" src="about:blank"></iframe>
<script>jQuery("#vote_UUID").attr("src","/sites/default/libraries/php/hth_vote/set_uuid.php?" + Math.floor(Math.random()*1000000000));</script>',
      'format' => 'full_html',
    ),
    'use_token' => 0,
  );
  $export['vote_button'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'year_week_competed';
  $ds_field->label = 'Year Week Competed';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class=\'field-label\'>[node:field_hotties_contest_year]: Week [node:field_hotties_contest_week]</div>',
      'format' => 'filtered_html',
    ),
    'use_token' => 1,
  );
  $export['year_week_competed'] = $ds_field;

  return $export;
}
