<?php
/**
 * @file
 * maxim_webform_views.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function maxim_webform_views_default_rules_configuration() {
  $items = array();
  $items['rules_hth_publish2'] = entity_import('rules_config', '{ "rules_hth_publish2" : {
      "LABEL" : "hth_publish",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "hotties_profile" : "hotties_profile" } }
          }
        },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "node_publish" : { "node" : [ "node:field-profile-ref-slideshow:0" ] } },
        { "drupal_message" : { "message" : "slideshow is published" } }
      ]
    }
  }');
  return $items;
}
