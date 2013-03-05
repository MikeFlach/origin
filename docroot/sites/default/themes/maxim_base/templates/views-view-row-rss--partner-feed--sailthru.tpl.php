<?php
/**
 * @file views-view-row-rss--partner-feed--sailthru.tpl.php
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print $title; ?></title>
    <link><?php $url= url($link, array('query' => array('utm_source' => $view->current_display, 'utm_medium' => 'rss', 'utm_campaign' => 'syndication'))); print htmlspecialchars($url); ?></link>
    <description><?php $description = html_entity_decode($description); $description = strip_tags($description); print $description; ?></description>
    <?php print $item_elements; ?>
  </item>
