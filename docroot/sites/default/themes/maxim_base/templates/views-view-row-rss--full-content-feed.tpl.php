<?php

/**
 * @file
 * Full content view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <guid><?php print $link; ?></guid>
    <description><?php print $node->body['und'][0]['safe_value']; ?></description>
    <?php
    $item_elements = preg_replace('#<dc:creator>.*</dc:creator>#', '', $item_elements);  // removes author
    $item_elements = preg_replace('#<dc:creator />#', '', $item_elements);  // removes author
    $item_elements = preg_replace('#<guid.*</guid>#', '', $item_elements);  // removes guid
    ?>
    <dc:creator><?php print $author_name ?></dc:creator>
    <?php print $item_elements; ?>
  </item>