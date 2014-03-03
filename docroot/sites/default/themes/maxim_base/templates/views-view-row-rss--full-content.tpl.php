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
    <description><?php print $description; ?></description>
    <content:encoded>
    <![CDATA[
    <?php print $node->body[und][0][safe_value]; ?>
    ]]>
    </content:encoded>
    <?php print $item_elements; ?>
  </item>