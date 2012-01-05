<?php

/*
 * Implements hook_preprocess_node().
 */
function maxim_base_alpha_preprocess_node(&$node) {
  // Dispatch function based on node type
  $function = 'maxim_base_alpha_preprocess_node_' . $node['node']->type;
  if (function_exists($function)) {
   $function($node);
  }

  // Dispatch function based on taxonomy id
  if ( !empty($node['field_channel']['0']['tid']) ) {
    $taxonomy_function = 'maxim_base_alpha_preprocess_node__tid_' . $node['field_channel']['0']['tid'];
    if (function_exists($taxonomy_function)) {
     $taxonomy_function($node);
    }
  }
}

/*
 * Don't show main image on Found Porn articles.
 */
function maxim_base_alpha_preprocess_node__tid_49(&$node) {
  // Trick drupal into thinking main image was already rendered so it wont display.
  $node['content']['field_main_image']['#printed'] = TRUE;
}

function maxim_base_alpha_preprocess_node_article(&$node) {
  $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_blog(&$node) {
  $node['content']['body']['0']['#markup'] = cleanText($node['content']['body']['0']['#markup']);
}

function maxim_base_alpha_preprocess_node_video(&$node) {
  if (!empty($node['field_media_file']['und']['0']['field_media_5min_id']['und']['0']['value'])) {
    //print 5min player script as well as the current node 5min ID value
    $videocode = '<script type="text/javascript" src="http://pshared.5min.com/Scripts/PlayerSeed.js?sid=764&amp;amp;width=620&amp;amp;height=348&amp;amp;shuffle=0&amp;amp;sequential=1&amp;amp;autoStart=false&amp;amp;playList=' . $node['field_media_file']['und']['0']['field_media_5min_id']['und']['0']['value'] . '"></script>';
  }
  else if (!empty($node['field_media_file']['und']['0']['field_media_cdn_url']['und']['0']['value'])){
    //print the legacy flash player with a direct hardcode to the generic video stub and flv cdn file path
    $videocode = '<object width="620" height="348" id="FiveminPlayer" classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"><param name="allowfullscreen" value="true" /><param name="allowScriptAccess" value="always" /><param name="movie" value="http://embed.5min.com/399695185/&sid=764&isAutoStart=true" /><param name="flashvars" value="tpvVideoUrl=' . $node['field_media_file']['und']['0']['field_media_cdn_url']['und']['0']['value'] . '" /><param name="wmode" value="window" /><embed name="FiveminPlayer" src="http://embed.5min.com/399695185/&sid=764&isAutoStart=true&tpvVideoUrl=' . $node['field_media_file']['und']['0']['field_media_cdn_url']['und']['0']['value'] . '" type="application/x-shockwave-flash" width="620" height="348" allowfullscreen="true" allowScriptAccess="always" wmode="window" ></embed ></object>';
  }
  else {
    $videocode = t('Error: Video Not Found');
  }

  $node['content']['body']['0']['#prefix'] = $videocode;
}

function maxim_base_alpha_preprocess_node_slideshow(&$node) {
  $node['content']['body']['0']['#prefix'] = '<div class="gallery anythingSlider"><div class="wrapper"><ul></ul></div></div><div id="slideshowBody" style="margin-top:15px">.</div>';
  $node['content']['body']['0']['#markup'] = '';
}

/*
 * Strip extra break tags from content.
 */
function cleanText ($text) {
  $newText = str_replace(array('<br><br>','<br /><br />'), '<br />', $text);

  return($newText);
}

// /*
//  * This method performs general clean up to fix legacy content issues.
//  * If a node doesn't have a 'field_main_image' it will look to create one from the first image it finds in the content.
//  * It will also remove images and iframes from showing on the homepage in the teaser text.
//  */
// function create_feature_img_from_content(&$node){
//   // Only process on nodes that don't have a 'field_main_image'.
//   if (empty($node['content']['field_main_image'])) {
//     $first_image = get_first_image($node['content']['body']['0']['#markup']);
//
//     // Only process if we find an image in the body.
//     if (!empty($first_image)) {
//       $image = file_get_contents($first_image);
//
//       $base_image_path = strip_cdn_base_from_url($first_image);
//       $file_paths = parse_file_path($base_image_path);
//       $save_dir = 'public://' . $file_paths['directory'];
//
//       // Check destination directory and create it if needed.
//       if (file_prepare_directory($save_dir, FILE_CREATE_DIRECTORY)) {
//         $file = file_save_data($image, $save_dir . '/'. $file_paths['file_name'] ,FILE_EXISTS_REPLACE);
//
//         $node['node']->field_main_image['und']['0']['fid'] = $file->fid;
//
//         $body = remove_duplicate_images($node['node']->body['und']['0']['value']);
//         $node['node']->body['und']['0']['value'] = $body;
//
//         node_save($node['node']);
//       }
//     }
//   }
// }
//
// /*
//  * Finds the first image in the markup passed in and returns the image url or null of none is found.
//  */
// function get_first_image($markup) {
//   $match_image_tag = '/<img [^>]*src="([^"]+)"[^>]*>/i';
//   preg_match($match_image_tag, $markup, $match, PREG_OFFSET_CAPTURE);
//
//   if (!empty($match[1][0])) {
//     return $match[1][0];
//   }
//   else {
//     return null;
//   }
// }
//
// /*
//  * Strips the CDN path prefix from the URL.
//  */
// function strip_cdn_base_from_url($url) {
//   $match_url_prefix = '/http:\/\/cdn2.maxim.com\//';
//   $image_path = preg_replace($match_url_prefix, '', $url);
//   return $image_path;
// }
//
// /*
//  * Parses the image path and returns an associative array.
//  *   full_path => The full path to the image.
//  *   directory => The directory portion of the path.
//  *   file_name => The file portion of the path.
//  */
// function parse_file_path($image_path) {
//   preg_match('#^(.+)/([^/]+)$#', $image_path, $matches, PREG_OFFSET_CAPTURE);
//   return array(
//     'full_path' => $matches[0][0],
//     'directory' => $matches[1][0],
//     'file_name' => $matches[2][0],
//   );
// }
//
// /*
//  * TBD function to check if the main image in included in the content area and remove it on article pages.
//  */
// function remove_duplicate_images($body) {
//   $match_image_tag = '/(<img [^>]*>)/i';
//   $comment_replacement = '<!-- ${1} -->';
//   $result = preg_replace($match_image_tag, $comment_replacement, $body, 1);
//   return $result;
// }