<?php
/**
 * @file
 * maxim_site_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function maxim_site_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:taxonomy/term/1
  $menu_links['main-menu:taxonomy/term/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/1',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Girls',
    'options' => array(
      'attributes' => array(
        'title' => 'Girls Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:taxonomy/term/11
  $menu_links['main-menu:taxonomy/term/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/11',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Hometown Hotties',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'taxonomy/term/1',
  );
  // Exported menu link: main-menu:taxonomy/term/2
  $menu_links['main-menu:taxonomy/term/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/2',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Sports',
    'options' => array(
      'attributes' => array(
        'title' => 'Sports Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:taxonomy/term/3
  $menu_links['main-menu:taxonomy/term/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Gaming',
    'options' => array(
      'attributes' => array(
        'title' => 'Gaming Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: main-menu:taxonomy/term/5
  $menu_links['main-menu:taxonomy/term/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/5',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Gadgets & Rides',
    'options' => array(
      'attributes' => array(
        'title' => 'Gadgets Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:taxonomy/term/6
  $menu_links['main-menu:taxonomy/term/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/6',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Food & Drink',
    'options' => array(
      'attributes' => array(
        'title' => 'Food & Drink Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: main-menu:taxonomy/term/7
  $menu_links['main-menu:taxonomy/term/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/7',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Guy Stuff',
    'options' => array(
      'attributes' => array(
        'title' => 'Guy Stuff Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: main-menu:taxonomy/term/8
  $menu_links['main-menu:taxonomy/term/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Humor',
    'options' => array(
      'attributes' => array(
        'title' => 'Humor Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/9
  $menu_links['main-menu:taxonomy/term/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/9',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Military',
    'options' => array(
      'attributes' => array(
        'title' => 'Military Channel',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Food & Drink');
  t('Gadgets & Rides');
  t('Gaming');
  t('Girls');
  t('Guy Stuff');
  t('Hometown Hotties');
  t('Humor');
  t('Military');
  t('Sports');


  return $menu_links;
}
