<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content
 *   keyed by field ID.
 * - $header: an array of headers(labels) for fields.
 * - $themed_rows: a array of rows with themed fields.
 * @ingroup views_templates
 */
?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9" xmlns:video="http://www.google.com/schemas/sitemap-video/1.1">
<?php foreach ($themed_rows as $count => $row): ?>
<url>
   <loc><?php echo $row['path']; ?></loc>
   <video:video>
      <video:thumbnail_loc><?php echo $row['field_main_image']; ?></video:thumbnail_loc>
      <video:title><?php echo htmlspecialchars($row['title']); ?></video:title>
      <video:player_loc><?php echo $row['field_brightcove_video']; ?></video:player_loc>
   </video:video>
</url>
<?php endforeach;