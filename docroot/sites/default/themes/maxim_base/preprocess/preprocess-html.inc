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
    break;
    case '/columns/check-please':
      $vars['head_title'] = 'Check, Please: Latest NHL News & Hockey Action from Maxim Sports';
    break;
    case '/entertainment':
      $vars['head_title'] = 'Top Entertainment News & Celebrity Interviews | Maxim';
    break;
    case '/entertainment/comics':
      $vars['head_title'] = 'Maxim Comic Book Previews & Reviews | Cosplay Photos & Videos';
    break;
    case '/entertainment/gaming':
      $vars['head_title'] = 'Latest Gaming News & Video Game Reviews & Previews | Maxim';
    break;
    case '/entertainment/movies':
      $vars['head_title'] = 'New Movie News, Reviews & Actor Interviews | Maxim Movies';
    break;
    case '/entertainment/music':
      $vars['head_title'] = 'Best New Music Videos, Concert Clips & Band Interviews | Maxim';
    break;
    case '/entertainment/tv':
      $vars['head_title'] = 'Best TV Show News & Reviews | Maxim TV Shows';
    break;
    case '/girls':
      $vars['head_title'] = 'Sexy Women, Hot Chicks & Beautiful Babes' . $title_suffix;
    break;
    case '/girls/girls-of-maxim':
      $vars['head_title'] = 'Sexy Photos of Cover Girls | Girls of Maxim Sexy Pictures';
    break;
    case '/girls/hometown-hotties':
      $vars['head_title'] = 'Hot Girls Next Door Photos | Meet the Maxim Hometown Hotties';
    break;
    case '/girls/hot100':
      $vars['head_title'] = '100 Most Beautiful Women in the World | Maxim Hot 100';
    break;
    case '/girls/todays-girl':
      $vars['head_title'] = 'Hot Celebrity Photo Galleries | Today\'s Girl by Maxim';
    break;
    case '/maximtv':
      $vars['head_title'] = 'Sexy Videos, Hot Videos | Maxim TV';
    break;
    case '/maximtv/entertainment':
      $vars['head_title'] = 'Sexy Celebrity Videos | Entertainment News & Interviews | Maxim TV';
    break;
    case '/maximtv/funny':
      $vars['head_title'] = 'Funny Videos & Comedy Clips | Maxim TV Originals & Viral Videos';
    break;
    case '/maximtv/girls':
      $vars['head_title'] = 'Maxim Model Videos & Photo Shoot Interviews | Maxim TV';
    break;
    case '/maximtv/sports':
      $vars['head_title'] = 'Extreme Sports Videos & Funny Sports Moments | Maxim TV';
    break;
    case '/maximtv/upkeep':
      $vars['head_title'] = 'Fashion Advice & Workout Videos for Men | Upkeep with Maxim TV';
    break;
    case '/maximtv/vices':
      $vars['head_title'] = 'Cocktail & Drink Recipes for Men & Other Party Vices | Maxim TV';
    break;
    case '/sports/girls-of-sports':
      $vars['head_title'] = 'Hottest Female Athletes Photos | Girls of Sports from Maxim';
    break;
    case '/sports/the-big-leagues':
      $vars['head_title'] = 'Big League Sports News from the NFL, MLB, NBA & NHL' . $title_suffix;
    break;
    case '/upkeep':
      $vars['head_title'] = 'Latest Trends & Fashion Tips for Men | Upkeep Ideas for Guys by Maxim';
    break;
    case '/upkeep/clothes':
      $vars['head_title'] = 'Men\'s Clothes Style Guide | Maxim Men\'s Fashion Blog';
    break;
    case '/upkeep/fitness':
      $vars['head_title'] = 'Fitness Articles & Health Tips for Men | Maxim Fitness Advice';
    break;
    case '/upkeep/grooming':
      $vars['head_title'] = 'Grooming Tips for Men & Essential Male Grooming Advice | Maxim';
    break;
    case '/upkeep/how-to':
      $vars['head_title'] = 'How To Be A Better Man | Maxim Tips & Advice for Men';
    break;
    case '/upkeep/money':
      $vars['head_title'] = 'Maxim Money Management Tips | Budgeting & Saving Money for Men';
    break;
    default:
      if ($vars['is_front']) {
        $vars['head_title'] = 'Maxim | The Ultimate Guys Guide';
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
