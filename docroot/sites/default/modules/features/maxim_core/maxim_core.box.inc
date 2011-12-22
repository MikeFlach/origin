<?php
/**
 * @file
 * maxim_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function maxim_core_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'facebookrecentactivity';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Facebook Recent Activiy';
  $box->options = array(
    'body' => array(
      'value' => '<div class="module"><iframe allowtransparency="true" frameborder="0" scrolling="no" src="http://www.facebook.com/plugins/activity.php?site=maxim.com&amp;width=300&amp;height=340&amp;header=true&amp;colorscheme=light&amp;recommendations=true" style="background-color: rgb(255, 255, 255); border: medium none; overflow: hidden; width: 300px; height: 340px;"></iframe></div>',
      'format' => 'full_html',
    ),
  );
  $export['facebookrecentactivity'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'in_this_issue';
  $box->plugin_key = 'simple';
  $box->title = 'In This Issue';
  $box->description = 'In this issue';
  $box->options = array(
    'body' => array(
      'value' => '<div id="in-this-issue-content">
  [[{"type":"media","view_mode":"media_original","fid":"82302","attributes":{"alt":"","class":"media-image"}}]]
  <div id="in-this-issue-items">
      <ul>
          <li><a href="#">Cover model: Rosie Huntington Whiteley</a></li>
          <li><a href="#">Top Article Story</a></li>
          <li><a href="#">Annother Featured Aritcle from the Mag</a></li>
      </ul>
      <form>
          <input type="button" id="submitSubscribe" VALUE="SUBSCRIBE">
      </form>
  </div>
</div>',
      'format' => 'full_html',
    ),
  );
  $export['in_this_issue'] = $box;

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'mostrecenttweets';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Most Recent Tweets';
  $box->options = array(
    'body' => array(
      'value' => '<div class="module module-twitter"><script src="http://widgets.twimg.com/j/2/widget.js"></script><script>new TWTR.Widget({version: 2, type: \'search\', search: \'maximmag\', interval: 30000, title: \'Maxim Magazine\', subject: \'\', width: 300, height: 195, theme: {	shell: { background: \'#8ec1da\',  color: \'#ffffff\' },tweets: { background: \'#ffffff\', color: \'#444444\', links: \'#1985b5\' } }, features: { scrollbar: false, loop: true,	live: true,	hashtags: true,	timestamp: true, avatars: true,	toptweets: true, behavior: \'default\' }}).render().start();</script></div>',
      'format' => 'full_html',
    ),
  );
  $export['mostrecenttweets'] = $box;

  return $export;
}
