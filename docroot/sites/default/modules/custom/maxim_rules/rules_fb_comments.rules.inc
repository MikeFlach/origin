<?php

/**
 * Implements hook_rules_action_info().
 */
function rules_fb_comments_rules_action_info() {
  return array(
    'facebook_comments_control' => array(
      'label' => t('Control Facebook comments'),
      'group' => t('Maxim Rules'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node')
        ),
        'enabled' => array(
          'type' => 'boolean',
          'label' => t('Enable comments')
        ),
      )
    ),
  );
}

function facebook_comments_control($node, $enabled) {
  $node->facebook_comments_enabled = $enabled ? 1 : 0;
}
