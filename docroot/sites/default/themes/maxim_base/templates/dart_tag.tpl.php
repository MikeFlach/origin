<?php

/**
 * @file
 * Display the js call to display a DART ad tag.
 *
 * Variables available:
 * - $tag: The full tag object or NULL. If it's NULL, all other
 *         vars listed below will be NULL as well
 * - $json_tag: a js version of $tag.
 * - $attributes: any attributes that should be displayed on the outer-most div.
 * - $show_script_tag: boolean.
 * - $show_noscript_tag: boolean.
 * - $noscript_tag: the <noscript> tag for this DART tag, or empty string.
 * - $static_tag: use this for DART tags that appear in emails.
 *
 * @see template_preprocess_dart_tag()
 */

/**
 * Temp fix for missing class in $attributes.
 * Issue related to http://drupal.org/node/1333918
 * Not best place to do this but didn't want to change the module
 */
 $attributes = str_replace('dart-tag', "dart-tag dart-name-$tag->machinename", $attributes);

 /**
  * MAXIM: Do not load ads last because of Google pushdown bug on homepage
  */

  /* if ($is_front || strpos($_SERVER['REQUEST_URI'], '/girls') === 0 ||
    strpos($_SERVER['REQUEST_URI'], '/hometown-hotties') === 0 ||
    strpos($_SERVER['REQUEST_URI'], '/todays-girl') === 0 ||
    strpos($_SERVER['REQUEST_URI'], '/hot-100') === 0) { */
  if ($is_front) {
    $load_last = false;
  }
?>

<?php if ($tag->machinename == 'dart_maximtv_big_box') { ?>
<span id="big_box_companion" class="_fwph">
  <form id="_fw_form_big_box_companion" style="display:none">
      <input type="hidden" name="_fw_input_big_box_companion" id="_fw_input_big_box_companion" value="slid=big_box_companion&tpcl=DISPLAY&ptgt=p&w=300&h=250">
  </form>
  <span id="_fw_container_big_box_companion" class="_fwac">
<?php } ?>
<div <?php print $attributes; ?>>
  <?php if ($tag->slug): ?>
    <span class="slug"><?php print $tag->slug; ?></span>
  <?php endif; ?>

  <?php if ($show_script_tag): ?>
    <?php if ($load_last): ?>
      <script type="text/javascript">Drupal.DART.settings.loadLastTags['<?php print $tag->machinename; ?>'] = '<?php print $json_tag; ?>';</script>
    <?php else: ?>
      <script type="text/javascript">Drupal.DART.tag('<?php print $json_tag; ?>');</script>
      <?php print $noscript_tag; ?>
    <?php endif; ?>
  <?php else: ?>
    <?php print $static_tag; ?>
  <?php endif; ?>
</div>
<?php if ($tag->machinename == 'dart_maximtv_big_box') { ?>
  </span></span>
<?php } ?>
