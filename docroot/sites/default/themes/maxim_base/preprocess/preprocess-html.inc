<?php
/**
 * Override or insert variables into the html template.
 */

// modify title and meta tags
function maxim_base_alpha_preprocess_html(&$vars) {
  $title_suffix = ' | Maxim';

  switch(url($_GET['q'])) {
    case '/actionsports':
      $vars['head_title'] = 'Latest Extreme Sports Videos & News | Maxim Action Sports';
      _maxim_meta_description('Need some motivation for dusting off the bike or breaking out the board? Maxim Action Sports has you covered. Let\'s go make a memory.');
    break;
    case '/columns/check-please':
      $vars['head_title'] = 'Check, Please: Latest NHL News & Hockey Action from Maxim Sports';
      _maxim_meta_description('Visit Maxim\'s NHL news column for the latest hockey updates and action from around the league. Check, please!');
    break;
    case '/girls':
      $vars['head_title'] = 'Sexy Women, Hot Chicks & Beautiful Babes' . $title_suffix;
      _maxim_meta_description('Sexy women. Hot chicks. Beautiful babes. No matter how you put it, Maxim has you covered. Browse the sexiest photo galleries this side of the Milky Way.');
    break;
    case '/girls/girls-of-maxim':
      $vars['head_title'] = 'Sexy Photos of Cover Girls | Girls of Maxim Sexy Pictures';
      _maxim_meta_description('If sexy photos are what you seek, look no further than the Girls of Maxim. Browse sexy pictures of Maxim cover girls, celebrities, & hometown hotties.');
    break;
    case '/girls/hometown-hotties':
      $vars['head_title'] = 'Hot Girls Next Door Photos | Meet the Maxim Hometown Hotties';
      _maxim_meta_description('Maxim Hometown Hotties are the hot girls next door that you never knew existed. Click to look for familiar faces in this year\'s photos.');
    break;
    case '/girls/hot100':
      $vars['head_title'] = '100 Most Beautiful Women in the World | Maxim Hot 100';
      _maxim_meta_description('Each year the masses select the 100 most beautiful women in the world. See who tops Maxim\'s list this year.');
    break;
    case '/girls/todays-girl':
      $vars['head_title'] = 'Hot Celebrity Photo Galleries | Today\'s Girl by Maxim';
      _maxim_meta_description('Not enough hot celebrities in your life? Today\'s Girl from Maxim posts a new photo gallery each day. The day just got a little brighter!');
    break;
    case '/maximtv':
      $vars['head_title'] = 'Sexy Videos, Hot Videos | Maxim TV';
      _maxim_meta_description('In the mood for hot videos with sexy models, gorgeous celebrities, and hometown hotties? Check out Maxim TV for an endless supply of sexy footage.');
    break;
    case '/maximtv/entertainment':
      $vars['head_title'] = 'Sexy Celebrity Videos | Entertainment News & Interviews | Maxim TV';
      _maxim_meta_description('Watch Maxim entertainment news and sexy celebrity videos from the hottest women in Hollywood. Celeb gossip has never looked so good.');
    break;
    case '/maximtv/funny':
      $vars['head_title'] = 'Funny Videos & Comedy Clips | Maxim TV Originals & Viral Videos';
      _maxim_meta_description('Every day should include more funny videos. Click to view a collection of the best comedy clips and viral videos on the web.');
    break;
    case '/maximtv/girls':
      $vars['head_title'] = 'Maxim Model Videos & Photo Shoot Interviews | Maxim TV';
      _maxim_meta_description('Watch behind the scenes model videos from the hottest Maxim photo shoots and plus intimate interviews so you two can get to know each other.');
    break;
    case '/maximtv/sports':
      $vars['head_title'] = 'Extreme Sports Videos & Funny Sports Moments | Maxim TV';
      _maxim_meta_description('Discover extreme sports videos and some funny moments in sports with our girls from Maxim. Hold on tight.');
    break;
    case '/maximtv/upkeep':
      $vars['head_title'] = 'Fashion Advice & Workout Videos for Men | Upkeep with Maxim TV';
      _maxim_meta_description('Maxim\'s fashion and workout experts have advice that is specifically designed for men--no yoga videos here. Wait, yes, Maxim has those, too.');
    break;
    case '/maximtv/vices':
      $vars['head_title'] = 'Cocktail & Drink Recipes for Men & Other Party Vices | Maxim TV';
      _maxim_meta_description('What\'s it like to be at a real party? The Maxim girls show you with the best cocktail recipes and access to the hottest Maxim parties and vices.');
    break;
    case '/sports/girls-of-sports':
      $vars['head_title'] = 'Hottest Female Athletes Photos | Girls of Sports from Maxim';
      _maxim_meta_description('Maxim loves the game. But we also love the women who play it. That\'s why we cover the hottest female athletes in the world. Come celebrate sports with us.');
    break;
    case '/sports/the-big-leagues':
      $vars['head_title'] = 'Big League Sports News from the NFL, MLB, NBA & NHL' . $title_suffix;
      _maxim_meta_description('Maxim provides the latest news from the NFL, MLB, NBA & NHL. Check for updates about what you missed, why it\'s important and how it affects your team.');
    break;
    case '/upkeep':
      $vars['head_title'] = 'Latest Trends & Fashion Tips for Men | Upkeep Ideas for Guys by Maxim';
      _maxim_meta_description('Maxim knows women and (more importantly for you) knows what they want. Here are the latest trends for men and tips about style, grooming and fitness.');
    break;
    default:
      if ($vars['is_front']) {
        $vars['head_title'] = 'Maxim | The Ultimate Guys Guide';
        _maxim_meta_description('See the sexiest photos & videos of the world\'s hottest women, plus the funniest stories about sports, gear, entertainment & sex. Maxim is what guys want.');
      } elseif ((strstr($_GET['q'], 'slideshow')) || (strstr($_GET['q'], 'gallery'))) {
        $nid = end(explode("/", $_GET['q']));
        if (is_numeric($nid)) {
          $vars['head_title'] = node_load($nid)->title . $title_suffix;
        }
        elseif (strstr($_GET['q'], 'slideshow')) {
          $vars['head_title'] = 'Slideshow' . $title_suffix;
        }
        else {
          $vars['head_title'] = 'Gallery' . $title_suffix;
        }
      } elseif (strstr($_GET['q'], 'oscarsmadness')) {
       $vars['head_title'] = 'Oscars Madness' . $title_suffix;
      }
    break;
  }
}

function _maxim_meta_description($desc) {
  $meta_description = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'description',
      'content' =>  $desc,
    )
  );
  drupal_add_html_head($meta_description, 'meta_description');
}
