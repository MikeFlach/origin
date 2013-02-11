<?php
/**
 * @file
 * maxim_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function maxim_core_default_rules_configuration() {
  $items = array();
  $items['rules_syndication_publish'] = entity_import('rules_config', '{ "rules_syndication_publish" : {
      "LABEL" : "syndication publish",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "syndication" ],
      "REQUIRES" : [ "rules", "rules_fb_comments", "rules_xmlsitemap" ],
      "ON" : [ "node_presave" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_channel" } },
        { "data_is" : { "data" : [ "node:field-channel:tid" ], "value" : "21151" } }
      ],
      "DO" : [
        { "facebook_comments_control" : { "node" : [ "node" ], "enabled" : 0 } },
        { "xmlsitemap_control" : { "node" : [ "node" ], "enabled" : 0 } },
        { "data_set" : { "data" : [ "node:promote" ], "value" : 0 } },
        { "data_set" : { "data" : [ "node:sticky" ], "value" : 0 } }
      ]
    }
  }');
  return $items;
}
