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
    case '/funny':
      $vars['head_title'] = 'Latest Funny Articles & Hilarious Videos | Maxim';
    break;
     case '/funny/beat-this-caption':
      $vars['head_title'] = 'Funny Photo Caption Contest | Beat This Caption by Maxim';
    break;
    case '/funny/comedians':
      $vars['head_title'] = 'Top Comedians & Funny Celebrities | Maxim Comedy';
    break;
    case '/funny/found-porn':
      $vars['head_title'] = 'Best Funny Porn Photos| Maxim\'s Found Porn';
    break;
    case '/funny/jokes':
      $vars['head_title'] = 'Funny Jokes & Hilarious Stories | Maxim';
    break;
    case '/gadgets-rides':
      $vars['head_title'] = 'Latest Technology Articles & Reviews | Maxim New Tech Guides';
    break;
    case '/gadgets-rides/gadgets':
      $vars['head_title'] = 'Cool New Gadgets for Men | Maxim High Tech Gadgets & Gizmos';
    break;
    case '/gadgets-rides/gift-guides':
      $vars['head_title'] = 'Cool Gifts for Guys (& Gals) | Maxim Gift Ideas & Guides';
    break;
    case '/gadgets-rides/rides':
      $vars['head_title'] = 'News & Reviews of the Hottest Cars & Motorcycles | Maxim Rides';
    break;
    case '/girls':
      $vars['head_title'] = 'Sexy Women, Hot Girls & Beautiful Babes' . $title_suffix;
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
    case '/tough/true-crime':
      $vars['head_title'] = ' True Crime News & Stories | Outrageous & Funny Reports from Maxim';
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
    case '/upkeep/sex-relationships':
      $vars['head_title'] = 'Sex Tips & Relationship Advice for Men | Maxim';
    break;
    case '/vices':
      $vars['head_title'] = 'Food, Drinks, Women & Other Guilty Pleasures for Men | Maxim Vices';
    break;
    case '/vices/booze':
      $vars['head_title'] = 'Cocktail Recipes + Beer, Whiskey & Alcohol Reviews | Maxim Booze';
    break;
    case '/vices/food':
      $vars['head_title'] = 'Recipes, Reviews and Weird Food News | Maxim';
    break;
    case '/vices/travel':
      $vars['head_title'] = 'Travel Advice & Vacation Ideas for Guys | Maxim Travel';
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
