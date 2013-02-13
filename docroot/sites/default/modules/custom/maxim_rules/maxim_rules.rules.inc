<?php

/**
 * Implements hook_rules_event_info()
 * Define our new custom rules event
 **/
function maxim_rules_rules_event_info() {
  return array(
    'maxim_page_render' => array(
      'label' => 'A page is rendered',
      'group' => 'Maxim Rules'
    )
  );
}

