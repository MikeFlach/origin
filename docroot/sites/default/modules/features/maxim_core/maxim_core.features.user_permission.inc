<?php
/**
 * @file
 * maxim_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function maxim_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access all webform results
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'contibutor',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access own webform results
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: access own webform submissions
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: access site in maintenance mode
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: access toolbar
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer DART tags
  $permissions['administer DART tags'] = array(
    'name' => 'administer DART tags',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
    ),
    'module' => 'dart',
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'system',
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'block',
  );

  // Exported permission: administer boxes
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'boxes',
  );

  // Exported permission: administer consumers
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: administer contact forms
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'contact',
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'node',
  );

  // Exported permission: administer delta blocks
  $permissions['administer delta blocks'] = array(
    'name' => 'administer delta blocks',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'delta_blocks',
  );

  // Exported permission: administer facebook comments
  $permissions['administer facebook comments'] = array(
    'name' => 'administer facebook comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'facebook_comments',
  );

  // Exported permission: administer facets
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer fieldgroups
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: administer files
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer image styles
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'image',
  );

  // Exported permission: administer imagecrop
  $permissions['administer imagecrop'] = array(
    'name' => 'administer imagecrop',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'imagecrop',
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer meta tags
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'metatag',
  );

  // Exported permission: administer module filter
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: administer modules
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer nodequeue
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer oauth
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: administer search
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: administer shortcuts
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'path',
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: administer xmlsitemap
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: block IP addresses
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass node access
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: cancel account
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: cancel own vote
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'poll',
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: create article content
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create blog content
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create hotties_profile content
  $permissions['create hotties_profile content'] = array(
    'name' => 'create hotties_profile content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: create joke content
  $permissions['create joke content'] = array(
    'name' => 'create joke content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create link_stub content
  $permissions['create link_stub content'] = array(
    'name' => 'create link_stub content',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create list content
  $permissions['create list content'] = array(
    'name' => 'create list content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create poll content
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create review content
  $permissions['create review content'] = array(
    'name' => 'create review content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create slideshow content
  $permissions['create slideshow content'] = array(
    'name' => 'create slideshow content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
    ),
    'module' => 'path',
  );

  // Exported permission: create video content
  $permissions['create video content'] = array(
    'name' => 'create video content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: crop any image
  $permissions['crop any image'] = array(
    'name' => 'crop any image',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'imagecrop',
  );

  // Exported permission: crop own images
  $permissions['crop own images'] = array(
    'name' => 'crop own images',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'imagecrop',
  );

  // Exported permission: customize shortcut links
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: delete all webform submissions
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'webform',
  );

  // Exported permission: delete any article content
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any blog content
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any hotties_profile content
  $permissions['delete any hotties_profile content'] = array(
    'name' => 'delete any hotties_profile content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any joke content
  $permissions['delete any joke content'] = array(
    'name' => 'delete any joke content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any link_stub content
  $permissions['delete any link_stub content'] = array(
    'name' => 'delete any link_stub content',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any list content
  $permissions['delete any list content'] = array(
    'name' => 'delete any list content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any poll content
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any review content
  $permissions['delete any review content'] = array(
    'name' => 'delete any review content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any slideshow content
  $permissions['delete any slideshow content'] = array(
    'name' => 'delete any slideshow content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any video content
  $permissions['delete any video content'] = array(
    'name' => 'delete any video content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own article content
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own blog content
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own hotties_profile content
  $permissions['delete own hotties_profile content'] = array(
    'name' => 'delete own hotties_profile content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own joke content
  $permissions['delete own joke content'] = array(
    'name' => 'delete own joke content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own link_stub content
  $permissions['delete own link_stub content'] = array(
    'name' => 'delete own link_stub content',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own list content
  $permissions['delete own list content'] = array(
    'name' => 'delete own list content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own poll content
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own review content
  $permissions['delete own review content'] = array(
    'name' => 'delete own review content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own slideshow content
  $permissions['delete own slideshow content'] = array(
    'name' => 'delete own slideshow content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own video content
  $permissions['delete own video content'] = array(
    'name' => 'delete own video content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own webform submissions
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 10
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 12
  $permissions['delete terms in 12'] = array(
    'name' => 'delete terms in 12',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 13
  $permissions['delete terms in 13'] = array(
    'name' => 'delete terms in 13',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 14
  $permissions['delete terms in 14'] = array(
    'name' => 'delete terms in 14',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 15
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(),
  );

  // Exported permission: delete terms in 16
  $permissions['delete terms in 16'] = array(
    'name' => 'delete terms in 16',
    'roles' => array(),
  );

  // Exported permission: delete terms in 17
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(),
  );

  // Exported permission: delete terms in 18
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(),
  );

  // Exported permission: delete terms in 19
  $permissions['delete terms in 19'] = array(
    'name' => 'delete terms in 19',
    'roles' => array(),
  );

  // Exported permission: delete terms in 2
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 20
  $permissions['delete terms in 20'] = array(
    'name' => 'delete terms in 20',
    'roles' => array(),
  );

  // Exported permission: delete terms in 21
  $permissions['delete terms in 21'] = array(
    'name' => 'delete terms in 21',
    'roles' => array(),
  );

  // Exported permission: delete terms in 22
  $permissions['delete terms in 22'] = array(
    'name' => 'delete terms in 22',
    'roles' => array(),
  );

  // Exported permission: delete terms in 23
  $permissions['delete terms in 23'] = array(
    'name' => 'delete terms in 23',
    'roles' => array(),
  );

  // Exported permission: delete terms in 24
  $permissions['delete terms in 24'] = array(
    'name' => 'delete terms in 24',
    'roles' => array(),
  );

  // Exported permission: delete terms in 25
  $permissions['delete terms in 25'] = array(
    'name' => 'delete terms in 25',
    'roles' => array(),
  );

  // Exported permission: delete terms in 3
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit all webform submissions
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: edit any article content
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any blog content
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any hotties_profile content
  $permissions['edit any hotties_profile content'] = array(
    'name' => 'edit any hotties_profile content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any joke content
  $permissions['edit any joke content'] = array(
    'name' => 'edit any joke content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any link_stub content
  $permissions['edit any link_stub content'] = array(
    'name' => 'edit any link_stub content',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any list content
  $permissions['edit any list content'] = array(
    'name' => 'edit any list content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any poll content
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any review content
  $permissions['edit any review content'] = array(
    'name' => 'edit any review content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any slideshow content
  $permissions['edit any slideshow content'] = array(
    'name' => 'edit any slideshow content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any video content
  $permissions['edit any video content'] = array(
    'name' => 'edit any video content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit boxes
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'boxes',
  );

  // Exported permission: edit file
  $permissions['edit file'] = array(
    'name' => 'edit file',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit meta tags
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'metatag',
  );

  // Exported permission: edit own article content
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own blog content
  $permissions['edit own blog content'] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own hotties_profile content
  $permissions['edit own hotties_profile content'] = array(
    'name' => 'edit own hotties_profile content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own joke content
  $permissions['edit own joke content'] = array(
    'name' => 'edit own joke content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own link_stub content
  $permissions['edit own link_stub content'] = array(
    'name' => 'edit own link_stub content',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own list content
  $permissions['edit own list content'] = array(
    'name' => 'edit own list content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own poll content
  $permissions['edit own poll content'] = array(
    'name' => 'edit own poll content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own review content
  $permissions['edit own review content'] = array(
    'name' => 'edit own review content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own slideshow content
  $permissions['edit own slideshow content'] = array(
    'name' => 'edit own slideshow content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own video content
  $permissions['edit own video content'] = array(
    'name' => 'edit own video content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform submissions
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'webform',
  );

  // Exported permission: edit terms in 1
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 10
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 12
  $permissions['edit terms in 12'] = array(
    'name' => 'edit terms in 12',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 13
  $permissions['edit terms in 13'] = array(
    'name' => 'edit terms in 13',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 14
  $permissions['edit terms in 14'] = array(
    'name' => 'edit terms in 14',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 15
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 16
  $permissions['edit terms in 16'] = array(
    'name' => 'edit terms in 16',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 17
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 18
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 19
  $permissions['edit terms in 19'] = array(
    'name' => 'edit terms in 19',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 20
  $permissions['edit terms in 20'] = array(
    'name' => 'edit terms in 20',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 21
  $permissions['edit terms in 21'] = array(
    'name' => 'edit terms in 21',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 22
  $permissions['edit terms in 22'] = array(
    'name' => 'edit terms in 22',
    'roles' => array(
      0 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 23
  $permissions['edit terms in 23'] = array(
    'name' => 'edit terms in 23',
    'roles' => array(
      0 => 'editor',
      1 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 24
  $permissions['edit terms in 24'] = array(
    'name' => 'edit terms in 24',
    'roles' => array(
      0 => 'editor',
      1 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 25
  $permissions['edit terms in 25'] = array(
    'name' => 'edit terms in 25',
    'roles' => array(
      0 => 'editor',
      1 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
      2 => 'editor',
      3 => 'media creator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: import media
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'media',
  );

  // Exported permission: inspect all votes
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'editor',
    ),
    'module' => 'poll',
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: manipulate all queues
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: moderate facebook comments
  $permissions['moderate facebook comments'] = array(
    'name' => 'moderate facebook comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'facebook_comments',
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: oauth authorize any consumers
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: oauth register any consumers
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: switch shortcut sets
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: use text format filtered_html
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'administrator',
      1 => 'developer',
    ),
    'module' => 'filter',
  );

  // Exported permission: view advanced help index
  $permissions['view advanced help index'] = array(
    'name' => 'view advanced help index',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help popup
  $permissions['view advanced help popup'] = array(
    'name' => 'view advanced help popup',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view advanced help topic
  $permissions['view advanced help topic'] = array(
    'name' => 'view advanced help topic',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'advanced_help',
  );

  // Exported permission: view file
  $permissions['view file'] = array(
    'name' => 'view file',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own unpublished content
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'administrator',
      1 => 'contibutor',
      2 => 'developer',
      3 => 'editor',
      4 => 'media creator',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'administrator',
      1 => 'audience development',
      2 => 'contibutor',
      3 => 'developer',
      4 => 'editor',
      5 => 'media creator',
    ),
    'module' => 'system',
  );

  // Exported permission: vote on polls
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
      2 => 'editor',
    ),
    'module' => 'poll',
  );

  return $permissions;
}
