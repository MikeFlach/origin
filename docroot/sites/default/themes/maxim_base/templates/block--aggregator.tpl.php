<?php $tag = $block->subject ? 'section' : 'div'; ?>
<<?php print $tag; ?><?php print $attributes; ?>>
  <div class="block-inner clearfix partner-links">
    <?php print render($title_prefix); ?>
      <?php if ($block->subject): ?>
        <?php switch ($block->subject) {
          case 'TMZ':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/TMZ_25px_0.png';
            $partnerurl='http://www.tmz.com';
            break;
          case 'Videobash':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/logo_videobash_0.png';
            $partnerurl='http://www.videobash.com';
            break;
          case 'Heavy':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/logo_heavy_0.png';
            $partnerurl='http://www.heavy.com';
            break;
          case 'COED Magazine':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/coed_25px.jpg';
            $partnerurl='http://www.coedmagazine.com';
            break;
          case 'Busted Coverage':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/logo_busted_coverage_sm.png';
            $partnerurl='http://www.bustedcoverage.com';
            break;
        }; ?>
        <?php if (isset($partnerimg)): ?>
          <div class="view-header">
            <h2<?php print $title_attributes; ?>><a href="<?php print $partnerurl; ?>" target="_blnk"><img src="<?php print $partnerimg; ?>" alt="<?php print $block->subject; ?>"></a></h2>
          </div>
        <?php else: ?>
          <h2<?php print $title_attributes; ?>><?php print $block->subject; ?></h2>
        <?php endif; ?>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

    <div<?php print $content_attributes; ?>>
      <?php print $content ?>
    </div>
  </div>
</<?php print $tag; ?>>
