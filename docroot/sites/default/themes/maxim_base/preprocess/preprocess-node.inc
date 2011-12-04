<?php

function maxim_base_alpha_preprocess_node(&$node) {
  $markup = $node['content']['body']['0']['#markup'];
  $match_image_tag = '/<img [^>]*src="([^"]+)"[^>]*>/i';
  $match_url_prefix = '/http:\/\/cdn2.maxim.com\//';

  // make the first image the thumbnail.
  if (drupal_is_front_page()) {
    if (empty($node['content']['field_main_image'])) {
      preg_match($match_image_tag, $markup, $matches, PREG_OFFSET_CAPTURE);

      if (!empty($matches[1][0])) {
        $image_path = preg_replace($match_url_prefix, '', $matches[1][0]);

        $node['content']['field_main_image']['0'] = array(
          '#theme' => 'image_formatter',
          '#image_style' => 'thumbnail_large',
          '#item' => array(
            'width' => '197',
            'height' => '140',
            'uri' => $image_path,
            'type' => 'image',
            'alt' => null,
            'title' => null,
          ),
        );
      }
    }

    // strip images & iframes from the markup.
    if ($node['type'] == 'article' || 'blog') {
      $match_bad_tags = '/<(img|iframe)[^>]*>/i';
      $node['content']['body']['0']['#markup'] = preg_replace($match_bad_tags, '', $markup, -1);
    }
  }
}