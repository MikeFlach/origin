<?php
/**
 * @file
 * maxim_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function maxim_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "apachesolr" && $api == "default_apachesolr_environment_variables") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "apachesolr" && $api == "default_apachesolr_environments") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "dart" && $api == "dart_tag_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function maxim_core_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function maxim_core_fontyourface_features_default_font() {
  return array(
    'Proxima Nova Black italic normal' => array(
      'name' => 'Proxima Nova Black italic normal',
      'enabled' => '1',
      'url' => 'http://localhost/#c59c8a2997c1eef002b1060260bc5ea4',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova Black\'',
      'css_style' => 'italic',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:81:"public://fontyourface/local_fonts/Proxima_Nova_Black-italic-normal/stylesheet.css";}',
    ),
    'Proxima Nova Black normal normal' => array(
      'name' => 'Proxima Nova Black normal normal',
      'enabled' => '1',
      'url' => 'http://localhost/#97ce0472accfba96f975486c684b487f',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova Black\'',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:81:"public://fontyourface/local_fonts/Proxima_Nova_Black-normal-normal/stylesheet.css";}',
    ),
    'Proxima Nova Semibold italic normal' => array(
      'name' => 'Proxima Nova Semibold italic normal',
      'enabled' => '1',
      'url' => 'http://localhost/#910b4c8d71ecf75289030823a3fffd99',
      'provider' => 'local_fonts',
      'css_selector' => '',
      'css_family' => '\'Proxima Nova Semibold\'',
      'css_style' => 'italic',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:84:"public://fontyourface/local_fonts/Proxima_Nova_Semibold-italic-normal/stylesheet.css";}',
    ),
    'Proxima Nova Semibold normal normal' => array(
      'name' => 'Proxima Nova Semibold normal normal',
      'enabled' => '1',
      'url' => 'http://localhost/#c5d1f013cc6dcc65ea2d0deb8ed0a818',
      'provider' => 'local_fonts',
      'css_selector' => '#zone-footer .footer-list ul li a, #zone-footer .menu-block-wrapper ul li a',
      'css_family' => '\'Proxima Nova Semibold\'',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:84:"public://fontyourface/local_fonts/Proxima_Nova_Semibold-normal-normal/stylesheet.css";}',
    ),
    'Proxima Nova Thin italic normal' => array(
      'name' => 'Proxima Nova Thin italic normal',
      'enabled' => '1',
      'url' => 'http://localhost/#2c323b7d91653a25a83e1a1d17c8c5a4',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova Thin\'',
      'css_style' => 'italic',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:80:"public://fontyourface/local_fonts/Proxima_Nova_Thin-italic-normal/stylesheet.css";}',
    ),
    'Proxima Nova Thin normal normal' => array(
      'name' => 'Proxima Nova Thin normal normal',
      'enabled' => '1',
      'url' => 'http://localhost/#920ef972b270c6ae461b8f0b38a625b0',
      'provider' => 'local_fonts',
      'css_selector' => '.navNum',
      'css_family' => '\'Proxima Nova Thin\'',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:80:"public://fontyourface/local_fonts/Proxima_Nova_Thin-normal-normal/stylesheet.css";}',
    ),
    'Proxima Nova italic bold' => array(
      'name' => 'Proxima Nova italic bold',
      'enabled' => '1',
      'url' => 'http://localhost/#d56ac0beed6b34f8d3302c79c1a6d18c',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'italic',
      'css_weight' => 'bold',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:73:"public://fontyourface/local_fonts/Proxima_Nova-italic-bold/stylesheet.css";}',
    ),
    'Proxima Nova italic bolder' => array(
      'name' => 'Proxima Nova italic bolder',
      'enabled' => '1',
      'url' => 'http://localhost/#3ea79a668705219035e389abdf518720',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'italic',
      'css_weight' => 'bolder',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:75:"public://fontyourface/local_fonts/Proxima_Nova-italic-bolder/stylesheet.css";}',
    ),
    'Proxima Nova italic lighter' => array(
      'name' => 'Proxima Nova italic lighter',
      'enabled' => '1',
      'url' => 'http://localhost/#41ba1f06b491c1dffc6c0ad3ff351b77',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'italic',
      'css_weight' => 'lighter',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:76:"public://fontyourface/local_fonts/Proxima_Nova-italic-lighter/stylesheet.css";}',
    ),
    'Proxima Nova italic normal' => array(
      'name' => 'Proxima Nova italic normal',
      'enabled' => '1',
      'url' => 'http://localhost/#be08860d0970936a67b73788b1f18a3d',
      'provider' => 'local_fonts',
      'css_selector' => '',
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'italic',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:75:"public://fontyourface/local_fonts/Proxima_Nova-italic-normal/stylesheet.css";}',
    ),
    'Proxima Nova normal bold' => array(
      'name' => 'Proxima Nova normal bold',
      'enabled' => '1',
      'url' => 'http://localhost/#d1c0ab5b7eeb39f74aa59109041b1220',
      'provider' => 'local_fonts',
      'css_selector' => 'h1, h2, h3, h4, h5, h6, b, strong, .field-name-field-channel a, h1#page-title',
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'normal',
      'css_weight' => 'bold',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:73:"public://fontyourface/local_fonts/Proxima_Nova-normal-bold/stylesheet.css";}',
    ),
    'Proxima Nova normal bolder' => array(
      'name' => 'Proxima Nova normal bolder',
      'enabled' => '1',
      'url' => 'http://localhost/#f15246e180e05b11145c5ff935385365',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'normal',
      'css_weight' => 'bolder',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:75:"public://fontyourface/local_fonts/Proxima_Nova-normal-bolder/stylesheet.css";}',
    ),
    'Proxima Nova normal lighter' => array(
      'name' => 'Proxima Nova normal lighter',
      'enabled' => '1',
      'url' => 'http://localhost/#3898f6d26d0bc47ee160bec94566499d',
      'provider' => 'local_fonts',
      'css_selector' => NULL,
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'normal',
      'css_weight' => 'lighter',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:76:"public://fontyourface/local_fonts/Proxima_Nova-normal-lighter/stylesheet.css";}',
    ),
    'Proxima Nova normal normal' => array(
      'name' => 'Proxima Nova normal normal',
      'enabled' => '1',
      'url' => 'http://localhost/#5a69625581b3513e6a0ce83023a749b4',
      'provider' => 'local_fonts',
      'css_selector' => '#region-sidebar-first section .block-inner h2.block-title, #block-system-main-menu ul',
      'css_family' => '\'Proxima Nova\'',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:1:{s:4:"path";s:75:"public://fontyourface/local_fonts/Proxima_Nova-normal-normal/stylesheet.css";}',
    ),
  );
}

/**
 * Implements hook_image_default_styles().
 */
function maxim_core_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_icon
  $styles['carousel_icon'] = array(
    'name' => 'carousel_icon',
    'effects' => array(
      9 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '90',
          'height' => '64',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: feature_banner
  $styles['feature_banner'] = array(
    'name' => 'feature_banner',
    'effects' => array(
      19 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '980',
          'height' => '600',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: feature_icon
  $styles['feature_icon'] = array(
    'name' => 'feature_icon',
    'effects' => array(
      11 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '70',
          'height' => '50',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: feature_large
  $styles['feature_large'] = array(
    'name' => 'feature_large',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '620',
          'height' => '441',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: hub_banner
  $styles['hub_banner'] = array(
    'name' => 'hub_banner',
    'effects' => array(
      15 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '940',
          'height' => '400',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: jumbotron
  $styles['jumbotron'] = array(
    'name' => 'jumbotron',
    'effects' => array(
      5 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '940',
          'height' => '500',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: jumbotron_carousel_icon
  $styles['jumbotron_carousel_icon'] = array(
    'name' => 'jumbotron_carousel_icon',
    'effects' => array(
      19 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '82',
          'height' => '58',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: slideshow_large
  $styles['slideshow_large'] = array(
    'name' => 'slideshow_large',
    'effects' => array(
      18 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '1200',
          'height' => '908',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: thumbnail_gallery
  $styles['thumbnail_gallery'] = array(
    'name' => 'thumbnail_gallery',
    'effects' => array(
      21 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '197',
          'height' => '197',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: thumbnail_large
  $styles['thumbnail_large'] = array(
    'name' => 'thumbnail_large',
    'effects' => array(
      10 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '197',
          'height' => '140',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: thumbnail_medium
  $styles['thumbnail_medium'] = array(
    'name' => 'thumbnail_medium',
    'effects' => array(
      25 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '140',
          'height' => '100',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: thumbnail_small
  $styles['thumbnail_small'] = array(
    'name' => 'thumbnail_small',
    'effects' => array(
      27 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '115',
          'height' => '82',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: video_thumb_large
  $styles['video_thumb_large'] = array(
    'name' => 'video_thumb_large',
    'effects' => array(
      29 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '220',
          'height' => '157',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: video_thumb_small
  $styles['video_thumb_small'] = array(
    'name' => 'video_thumb_small',
    'effects' => array(
      31 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '105',
          'height' => '75',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function maxim_core_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('A standard article.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('A standard blog.'),
      'has_title' => '1',
      'title_label' => t('Blog Title'),
      'help' => '',
    ),
    'hotties_profile' => array(
      'name' => t('Hometown Hotties Profile'),
      'base' => 'node_content',
      'description' => t('This is for hometown hotties profiles'),
      'has_title' => '1',
      'title_label' => t('Profile Title'),
      'help' => t('Give a title for this profile.  It could be something like First name - City, State.'),
    ),
    'joke' => array(
      'name' => t('Joke'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Joke Title'),
      'help' => '',
    ),
    'link_stub' => array(
      'name' => t('Link Stub'),
      'base' => 'node_content',
      'description' => t('Display title and links for external partners, also for internal links'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'list' => array(
      'name' => t('List'),
      'base' => 'node_content',
      'description' => t('This is for Lists (Gaming, Movies, TV, Music, Comics, etc)'),
      'has_title' => '1',
      'title_label' => t('List Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'review' => array(
      'name' => t('Review'),
      'base' => 'node_content',
      'description' => t('This is for reviews (Gaming, Movies, TV, Music, Gadgets, Rides, etc.)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slideshow' => array(
      'name' => t('Slideshow'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Video'),
      'has_title' => '1',
      'title_label' => t('Video Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
