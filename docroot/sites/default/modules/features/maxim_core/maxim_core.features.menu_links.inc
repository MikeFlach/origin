<?php
/**
 * @file
 * maxim_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function maxim_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management:admin/content
  $menu_links['management:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer content and comments.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/content/file
  $menu_links['management:admin/content/file'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/file',
    'router_path' => 'admin/content/file',
    'link_title' => 'Find Files',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/content/file/thumbnails
  $menu_links['management:admin/content/file/thumbnails'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/file/thumbnails',
    'router_path' => 'admin/content/file/thumbnails',
    'link_title' => 'Manage Files',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/structure
  $menu_links['management:admin/structure'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer blocks, content types, menus, etc.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-47',
    'parent_path' => 'admin',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Find Files');
  t('Manage Files');
  t('Structure');


  return $menu_links;
}
