<?php

/**
 * Comscore Beacon call
 */

function comscore_beacon($site, $pageTitle, $pageURL) {
  $base_url = 'http://b.scorecardresearch.com/p?';
  $site_domain = 'http://' . $site . '.maxim.com';
  $params = array(
      'c1' => '2', //Tag Type
      'c2' => '6036003', // Client ID
      'c4' => '', // Full page URL
      'c7' => '', // Full page URL
      'c8' => '', // Page Title
      'c9' => '', // Referrer URL
    );

    $params['c8'] = $pageTitle;
    $params['c4'] = $params['c7']
                  = $site_domain . $pageURL;

    $qry = http_build_query($params);

    // Create a stream
    $opts = array(
      'http'=>array(
        'method'=>"GET",
      )
    );

    $context = stream_context_create($opts);
    $file = file_get_contents($base_url . $qry, false, $context);
}
