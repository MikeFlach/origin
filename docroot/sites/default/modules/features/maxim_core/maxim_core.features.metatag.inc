<?php
/**
 * @file
 * maxim_core.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function maxim_core_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => 'Maxim.com - the Ultimate Guys Guide - check out hot girls, sexy photos and videos of celebrities, Hometown Hotties, and our Hot 100. Maxim is your source of funny lists, jokes, sexy women, and movies online.',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => 'girls, hot girls, sexy girls, sexy photos, sexy videos, hometown hotties, celebrities, gaming, hot 100, entertainment, maxim, cars, sports, babes, jokes, funny, maxim.com',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
        'value' => ' "Maxim Digital", "MAXIM", "MAXIM ONLINE", "Maximonline.com", "Maxim.com" and the "M" Logo" are registered trademarks owned by Alpha Media Group Inc. "Maxim.com" and "MAXIM TO GO" are trademark owned by Alpha Media Group Inc.',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => 'http://www.maxim.com[current-page:url:relative]',
      ),
      'shortlink' => array(
        'value' => '',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'fb:admins' => array(
        'value' => '',
      ),
      'fb:app_id' => array(
        'value' => '',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:image' => array(
        'value' => 'http://cdn2.maxim.com/maxim/sites/default/files/devil_logo_red.gif',
      ),
      'og:url' => array(
        'value' => 'http://www.maxim.com[current-page:url:relative]',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:street-address' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:postal-code' => array(
        'value' => '',
      ),
      'og:country-name' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:video' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:site' => array(
        'value' => '@MaximMag ',
      ),
      'twitter:site:id' => array(
        'value' => '',
      ),
      'twitter:creator' => array(
        'value' => '@MaximMag ',
      ),
      'twitter:creator:id' => array(
        'value' => '',
      ),
      'twitter:url' => array(
        'value' => 'http://www.maxim.com[current-page:url:relative]',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title]',
      ),
      'twitter:description' => array(
        'value' => 'Maxim: It’s what guys want.',
      ),
      'twitter:image' => array(
        'value' => 'http://cdn2.maxim.com/maxim/sites/default/files/devil_logo_red.gif',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
      ),
      'twitter:player' => array(
        'value' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'config' => array(
      'title' => array(
        'value' => 'Maxim | The Ultimate Guys Guide - Maxim is your source of hot girls, funny lists, jokes, sexy women, and movies online.',
      ),
      'description' => array(
        'value' => 'See the sexiest photos & videos of the world\'s hottest women, plus the funniest stories about sports, gear, entertainment & sex. Maxim: It\'s what guys want.',
      ),
      'canonical' => array(
        'value' => 'http://www.maxim.com',
      ),
      'og:site_name' => array(
        'value' => '[site:name] ',
      ),
      'og:title' => array(
        'value' => 'Maxim | A Guide for Men to Beautiful Women, Sports, Movies & Jokes',
      ),
      'og:description' => array(
        'value' => 'The sexiest photos & videos of the world’s hottest women, plus the funniest stories about sports, gear, entertainment & sex. Maxim: It’s what guys want. ',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => 'http://www.maxim.com',
      ),
      'twitter:title' => array(
        'value' => 'Maxim | The Ultimate Guys Guide - Maxim is your source of hot girls, funny lists, jokes, sexy women, and movies online.',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] [current-page:page-number] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'keywords' => array(
        'value' => '[node:field_tags], [node:field_channel], [node:field_ppt], girls, hot girls, sexy girls, sexy photos, sexy videos, hometown hotties, celebrities, gaming, hot 100, entertainment, maxim, cars, sports, babes, jokes, funny, maxim.com',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:image' => array(
        'value' => '[node:field_main_image]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:summary]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_main_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:celebrity_profile.
  $config['node:celebrity_profile'] = array(
    'instance' => 'node:celebrity_profile',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | Hot Pics & Sexy Photos | Girls of Maxim',
      ),
      'twitter:card' => array(
        'value' => 'photo',
      ),
    ),
  );

  // Exported Metatag config instance: node:generic_profile.
  $config['node:generic_profile'] = array(
    'instance' => 'node:generic_profile',
    'config' => array(
      'twitter:card' => array(
        'value' => 'photo',
      ),
    ),
  );

  // Exported Metatag config instance: node:hotties_profile.
  $config['node:hotties_profile'] = array(
    'instance' => 'node:hotties_profile',
    'config' => array(
      'title' => array(
        'value' => '[node:title] [node:field_hotties_contest_year] | Women from Maxim | Hometown Hotties',
      ),
      'description' => array(
        'value' => '[node:title] - Maxim Hometown Hotties Contestant Week:[node:field-hotties-contest-week] - Year:[node:field_hotties_contest_year]',
      ),
      'og:description' => array(
        'value' => '[node:title] - Maxim Hometown Hotties Contestant Week:[node:field-hotties-contest-week] - Year:[node:field_hotties_contest_year]',
      ),
      'twitter:card' => array(
        'value' => 'photo',
      ),
    ),
  );

  // Exported Metatag config instance: node:slideshow.
  $config['node:slideshow'] = array(
    'instance' => 'node:slideshow',
    'config' => array(
      'twitter:card' => array(
        'value' => 'photo',
      ),
    ),
  );

  // Exported Metatag config instance: node:video.
  $config['node:video'] = array(
    'instance' => 'node:video',
    'config' => array(
      'title' => array(
        'value' => '[node:title] - MaximTV (video) | [site:name]',
      ),
      'og:type' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => 'application/x-shockwave-flash',
      ),
      'twitter:description' => array(
        'value' => '[node:body]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'config' => array(
      'title' => array(
        'value' => '[term:name] [current-page:page-number] | [site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'og:title' => array(
        'value' => '',
      ),
      'twitter:title' => array(
        'value' => '[term:name] | Maxim',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
      'og:type' => array(
        'value' => 'profile',
      ),
      'og:title' => array(
        'value' => '[user:name]',
      ),
    ),
  );

  // Exported Metatag config instance: view.
  $config['view'] = array(
    'instance' => 'view',
    'config' => array(
      'title' => array(
        'value' => '[view:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[view:title] [view:description]',
      ),
      'canonical' => array(
        'value' => '[view:url]?page=[current-page:query:page]',
      ),
    ),
  );

  return $config;
}
