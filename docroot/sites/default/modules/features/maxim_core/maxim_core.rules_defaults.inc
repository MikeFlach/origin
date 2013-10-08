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
      "ON" : { "node_presave" : [] },
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
  $items['rules_uk_content'] = entity_import('rules_config', '{ "rules_uk_content" : {
      "LABEL" : "uk content",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "International" ],
      "REQUIRES" : [ "rules", "context_rules" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "text_matches" : { "text" : [ "site:current-page:url" ], "match" : "view_src=uk" } }
      ],
      "DO" : [
        { "rules_action_context_rules_set_context" : { "context" : "uk_content_page" } }
      ]
    }
  }');
  return $items;
}
