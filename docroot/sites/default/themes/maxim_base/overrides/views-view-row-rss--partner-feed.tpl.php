<?php
/**
 * @file views-view-row-rss.tpl.php
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print $title; ?></title>
    <link><?php print url($link, array('query' => array('utm_source' => $view->current_display, 'utm_medium' => 'rss', 'utm_campaign' => 'syndication'))); ?></link>
    <description><?php print $description; ?></description>
    <?php print $item_elements; ?>
  </item>
