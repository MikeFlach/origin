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
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
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
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
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
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
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
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function maxim_core_image_default_styles() {
  $styles = array();

  // Exported image style: carousel_icon.
  $styles['carousel_icon'] = array(
    'name' => 'carousel_icon',
    'effects' => array(
      7 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '90',
          'height' => '64',
          'keepproportions' => 1,
          'style_name' => 'carousel_icon',
        ),
        'weight' => '2',
      ),
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '90',
          'height' => '64',
          'upscale' => 0,
        ),
        'weight' => '3',
      ),
    ),
    'label' => 'carousel_icon',
  );

  // Exported image style: carousel_main.
  $styles['carousel_main'] = array(
    'name' => 'carousel_main',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '540',
          'height' => '500',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => 'carousel_main',
  );

  // Exported image style: carousel_wmark_main.
  $styles['carousel_wmark_main'] = array(
    'name' => 'carousel_wmark_main',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '540',
          'height' => '500',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
      4 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'bottom',
          'alpha' => '100',
          'path' => 'maxim_wmark_dropshadow.png',
        ),
        'weight' => '2',
      ),
    ),
    'label' => 'carousel_wmark_main',
  );

  // Exported image style: feature_banner.
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
    'label' => 'feature_banner',
  );

  // Exported image style: feature_icon.
  $styles['feature_icon'] = array(
    'name' => 'feature_icon',
    'effects' => array(
      10 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '70',
          'height' => '50',
          'keepproportions' => 1,
          'style_name' => 'feature_icon',
        ),
        'weight' => '-11',
      ),
      9 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'feature_icon',
  );

  // Exported image style: feature_large.
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
    'label' => 'feature_large',
  );

  // Exported image style: hub_banner.
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
    'label' => 'hub_banner',
  );

  // Exported image style: jumbotron.
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
    'label' => 'jumbotron',
  );

  // Exported image style: jumbotron_carousel_icon.
  $styles['jumbotron_carousel_icon'] = array(
    'name' => 'jumbotron_carousel_icon',
    'effects' => array(
      13 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '82',
          'height' => '58',
          'keepproportions' => 1,
          'style_name' => 'jumbotron_carousel_icon',
        ),
        'weight' => '-11',
      ),
      12 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'jumbotron_carousel_icon',
  );

  // Exported image style: slideshow_large.
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
    'label' => 'slideshow_large',
  );

  // Exported image style: slideshow_wmark_large.
  $styles['slideshow_wmark_large'] = array(
    'name' => 'slideshow_wmark_large',
    'effects' => array(
      1 => array(
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
      2 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'bottom',
          'alpha' => '100',
          'path' => 'maxim_wmark_dropshadow.png',
        ),
        'weight' => '2',
      ),
    ),
    'label' => 'slideshow_wmark_large',
  );

  // Exported image style: thumbnail_gallery.
  $styles['thumbnail_gallery'] = array(
    'name' => 'thumbnail_gallery',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '197',
          'height' => '197',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
    'label' => 'thumbnail_gallery',
  );

  // Exported image style: thumbnail_large.
  $styles['thumbnail_large'] = array(
    'name' => 'thumbnail_large',
    'effects' => array(
      3 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '197',
          'height' => '140',
          'keepproportions' => 1,
          'style_name' => 'thumbnail_large',
        ),
        'weight' => '-10',
      ),
      2 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'thumbnail_large',
  );

  // Exported image style: thumbnail_medium.
  $styles['thumbnail_medium'] = array(
    'name' => 'thumbnail_medium',
    'effects' => array(
      16 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '140',
          'height' => '100',
          'keepproportions' => 1,
          'style_name' => 'thumbnail_medium',
        ),
        'weight' => '-11',
      ),
      15 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'thumbnail_medium',
  );

  // Exported image style: thumbnail_small.
  $styles['thumbnail_small'] = array(
    'name' => 'thumbnail_small',
    'effects' => array(
      19 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '115',
          'height' => '82',
          'keepproportions' => 1,
          'style_name' => 'thumbnail_small',
        ),
        'weight' => '-11',
      ),
      18 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'thumbnail_small',
  );

  // Exported image style: thumbnail_wide.
  $styles['thumbnail_wide'] = array(
    'name' => 'thumbnail_wide',
    'label' => 'thumbnail_wide',
    'effects' => array(
      12 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '300',
          'height' => '120',
          'keepproportions' => 1,
          'style_name' => 'thumbnail_wide',
        ),
        'weight' => '0',
      ),
      13 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '300',
          'height' => '120',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: thumbnail_xlarge.
  $styles['thumbnail_xlarge'] = array(
    'name' => 'thumbnail_xlarge',
    'label' => 'thumbnail_xlarge',
    'effects' => array(
      12 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '435',
          'height' => '290',
          'keepproportions' => 1,
          'style_name' => 'thumbnail_xlarge',
        ),
        'weight' => '0',
      ),
      14 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '435',
          'height' => '290',
          'upscale' => 0,
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: video_thumb_large.
  $styles['video_thumb_large'] = array(
    'name' => 'video_thumb_large',
    'effects' => array(
      22 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '220',
          'height' => '157',
          'keepproportions' => 1,
          'style_name' => 'video_thumb_large',
        ),
        'weight' => '-11',
      ),
      21 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'video_thumb_large',
  );

  // Exported image style: video_thumb_small.
  $styles['video_thumb_small'] = array(
    'name' => 'video_thumb_small',
    'effects' => array(
      25 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '105',
          'height' => '75',
          'keepproportions' => 1,
          'style_name' => 'video_thumb_small',
        ),
        'weight' => '-10',
      ),
      24 => array(
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
        'weight' => '-9',
      ),
    ),
    'label' => 'video_thumb_small',
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
