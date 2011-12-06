<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>

  <?php if (!$page && $title): ?>
  <header>
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php print render($title_suffix); ?>
  </header>
  <?php endif; ?>

  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print 5min player script as well as the current node 5min ID value
      print '<script type="text/javascript" src="http://pshared.5min.com/Scripts/PlayerSeed.js?sid=764&amp;amp;width=620&amp;amp;height=348&amp;amp;shuffle=0&amp;amp;sequential=1&amp;amp;autoStart=true&amp;amp;playList=' . $node->field_media_file['und']['0']['field_media_5min_id']['und']['0']['value'] . '"></script>';
      print render($content);
    ?>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>