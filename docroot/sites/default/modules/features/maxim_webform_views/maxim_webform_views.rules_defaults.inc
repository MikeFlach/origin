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
        { "component_rules_publish_profile_slideshows" : { "profile" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_publish_profile_slideshows'] = entity_import('rules_config', '{ "rules_publish_profile_slideshows" : {
      "LABEL" : "Publish Profile Slideshows",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "rules_xmlsitemap", "rules_redirect_url" ],
      "USES VARIABLES" : { "profile" : { "label" : "Profile", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "profile" ],
            "type" : { "value" : { "hotties_profile" : "hotties_profile" } }
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "profile:field-profile-ref-slideshow" ] },
            "ITEM" : { "slideshow" : "Current slideshow" },
            "DO" : [
              { "xmlsitemap_control" : { "node" : [ "slideshow" ], "enabled" : 0 } },
              { "add_url_redirect_action" : {
                  "source_path" : "[site:url]node\\/[slideshow:nid]",
                  "redirect_path" : "[site:url]node\\/[profile:nid]"
                }
              },
              { "node_publish" : { "node" : [ "slideshow" ] } },
              { "drupal_message" : { "message" : "Slideshow [slideshow:title] published for profile [profile:title].\\r\\nRedirect created from node\\/[slideshow:nid] to node\\/[profile:nid]" } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
