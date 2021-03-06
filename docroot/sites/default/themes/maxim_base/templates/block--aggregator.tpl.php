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
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/coed_25px.png';
            $partnerurl='http://www.coedmagazine.com';
            break;
          case 'Busted Coverage':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/logo_busted_coverage_sm.png';
            $partnerurl='http://www.bustedcoverage.com';
            break;
          case 'Lacesout':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/lacesoutlogo.png';
            $partnerurl='http://msn.foxsports.com/lacesout';
            break;
          case 'Red Bull':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/redbull_25px.png';
            $partnerurl='http://www.redbull.com';
            break;
          case 'AskMen':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/logo_25h_askmen.gif';
            $partnerurl='http://www.askmen.com';
            break;
          case 'Swim Daily':
            $partnerimg='http://cdn2.maxim.com/maxim/sites/default/files/SIlogo_BK.png';
            $partnerurl='http://swimdaily.si.com/';
            break;
        }; ?>
        <?php if (isset($partnerimg)): ?>
          <div class="view-header">
            <h2<?php print $title_attributes; ?>><img src="<?php print $partnerimg; ?>" alt="<?php print $block->subject; ?>"></h2>
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
