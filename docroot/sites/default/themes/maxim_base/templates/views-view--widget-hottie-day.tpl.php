<?php
/**
 * @file
 * Today's Girl Widget view template
 *
 */
$rid = rand(10,10000);
$html = <<<HTMLBLOCK
<link rel="stylesheet" href="http://cdn2.maxim.com/maxim/sites/default/libraries/widget/widget.css" media="all" />
<div id="mxm_widget_hottie_{$rid}" class="mxm-widget-hottie">
  <div class="mxm-widget-head">{$header}</div>
  <div class="mxm-widget-body">{$rows}</div>
  <div class="mxm-widget-foot">{$footer}<div style="clear:both;font-size:1px;">&nbsp;</div></div>
</div>
HTMLBLOCK;
$jsblock = <<<JSBLOCK
  var mxm_widget_hottie_{$rid}=document.getElementById("mxm_widget_hottie_{$rid}");
  if(mxm_widget_hottie_{$rid}.offsetWidth < 210){mxm_widget_{$rid}.className+=" mxm-widget-hottie-sm";}
JSBLOCK;

// remove whitespace
$html = trim(preg_replace('/\n|\r/', '', $html));
$js_str = json_encode($html);
echo 'document.write(' . $js_str . ');';
echo trim(preg_replace('/\n|\r|/', '', $jsblock));;
exit();
