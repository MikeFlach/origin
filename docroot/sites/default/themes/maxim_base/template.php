<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

  /**
  * Replace the bundled version of jQuery with jQuery 1.7.1
  * TBD - Move this code to a module.
  */
  function maxim_base_js_alter(&$javascript) {
    $javascript['misc/jquery.js']['data'] = libraries_get_path('jquery')  . '/jquery-1.7.1.min.js';
  }