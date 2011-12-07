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
      if (!empty($node->field_media_file['und']['0']['field_media_5min_id']['und']['0']['value'])) {
        //print 5min player script as well as the current node 5min ID value
        $videocode = '<script type="text/javascript" src="http://pshared.5min.com/Scripts/PlayerSeed.js?sid=764&amp;amp;width=620&amp;amp;height=348&amp;amp;shuffle=0&amp;amp;sequential=1&amp;amp;autoStart=true&amp;amp;playList=' . $node->field_media_file['und']['0']['field_media_5min_id']['und']['0']['value'] . '"></script>';
      }
      else if (!empty($node->field_media_file['und']['0']['field_media_cdn_url']['und']['0']['value'])){
        //print the legacy flash player with a direct hardcode to the generic video stub and flv cdn file path
        $videocode = '<object width="620" height="348" id="FiveminPlayer" classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"><param name="allowfullscreen" value="true" /><param name="allowScriptAccess" value="always" /><param name="movie" value="http://embed.5min.com/399695185/&sid=764&isAutoStart=true" /><param name="flashvars" value="tpvVideoUrl=' . $node->field_media_file['und']['0']['field_media_cdn_url']['und']['0']['value'] . '" /><param name="wmode" value="window" /><embed name="FiveminPlayer" src="http://embed.5min.com/399695185/&sid=764&isAutoStart=true&tpvVideoUrl=' . $node->field_media_file['und']['0']['field_media_cdn_url']['und']['0']['value'] . '" type="application/x-shockwave-flash" width="620" height="348" allowfullscreen="true" allowScriptAccess="always" wmode="window" ></embed ></object>';
      }
      else {
        $videocode = t('Error: Video Not Found');
      }
      print $videocode;
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