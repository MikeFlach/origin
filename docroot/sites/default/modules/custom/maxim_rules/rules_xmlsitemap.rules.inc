<?php

/**
 * Implements hook_rules_action_info().
 */
function rules_xmlsitemap_rules_action_info() {
  return array(
    'xmlsitemap_control' => array(
      'label' => t('Control Xmlsitemap inclusion'),
      'group' => t('Maxim Rules'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node')
        ),
        'enabled' => array(
          'type' => 'boolean',
          'label' => t('Enable Xmlsitemap inclusion')
        ),
      )
    ),
  );
}

function xmlsitemap_control($node, $enabled) {
  $node->xmlsitemap[status] = $enabled ? 1 : 0;
  $node->xmlsitemap[status_override] = 1;
}
