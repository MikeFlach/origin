<item>
 <title><?php print $title; ?></title>
 <link><?php print $link; ?></link>
 <guid><?php print $link; ?></guid>
 <description><![CDATA[<?php print $node->body[und][0][safe_summary]; ?>]]></description>
 <?php
 $item_elements = ereg_replace('<dc:creator>.*</dc:creator>', '', $item_elements);  // removes author
 $item_elements = ereg_replace('<dc:creator />', '', $item_elements);  // removes author
 $item_elements = ereg_replace('<guid.*</guid>', '', $item_elements);  // removes guid
 ?>
 <dc:creator><?php print $author_name ?></dc:creator>
 <content:encoded>
 <![CDATA[
 <?php print $node->body[und][0][safe_value]; ?>
 ]]>
 </content:encoded>
 <?php print $item_elements;?>
</item>
