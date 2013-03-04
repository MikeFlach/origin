<?php
/**
 * @file
 * Today's Girl Widget view template
 *
 */
$widget_rid = rand(10,10000);
$widget_ga = widget_build_ga();
$widget_html = <<<WIDGETHTMLBLOCK
<link rel="stylesheet" href="http://cdn2.maxim.com/maxim/sites/default/libraries/widget/widget.css" media="all" />
<div id="mxm_widget_hottie_{$widget_rid}" class="mxm-widget-hottie">
  <div class="mxm-widget-head">{$header}</div>
  <div class="mxm-widget-body">{$rows}</div>
  <div class="mxm-widget-foot">{$footer}<div style="clear:both;font-size:1px;height:0;">&nbsp;</div></div>
</div>
WIDGETHTMLBLOCK;
$widget_jsblock = <<<WIDGETJSBLOCK
  var mxm_widget_hottie_{$widget_rid}=document.getElementById("mxm_widget_hottie_{$widget_rid}");
  if(mxm_widget_hottie_{$widget_rid}.offsetWidth < 210){mxm_widget_hottie_{$widget_rid}.className+=" mxm-widget-hottie-sm";}
  document.write('<img src="{$widget_ga}' + '&utme=8(embedDomain*embedURL*hottie)9(' + document.domain + '*' + encodeURIComponent(document.URL) + '*' + document.getElementById("mxm_widget_hottie_nid").getAttribute("nid") + ')" />');
WIDGETJSBLOCK;

header('Content-type: application/javascript');
header('Cache-Control: public, max-age=3600');
header('Etag: ' . hash('md5', $variables['view']->result[0]->nid));
header('Expires: '.gmdate('D, d M Y H:i:s \G\M\T', time() + 3600));
header_remove('Last-Modified');

// remove whitespace
$widget_html = trim(preg_replace('/\n|\r/', '', $widget_html));
$widget_js_str = json_encode($widget_html);
echo 'document.write(' . $widget_js_str . ');';
echo trim(preg_replace('/\n|\r|/', '', $widget_jsblock));;
exit();

function widget_build_ga() {
  $var_utmac = 'UA-4245914-1'; //enter the new urchin code
  $var_utmhn = 'widget.maxim.com'; //enter your domain
  $var_utmn = rand(1000000000,9999999999);//random request number
  $var_cookie = rand(10000000,99999999);//random cookie number
  $var_random = rand(1000000000,2147483647); //number under 2147483647
  $var_today = time(); //today
  //$var_referer = $_SERVER['HTTP_REFERER']; //referer url

  $var_uservar = '-'; //enter your own user defined variable
  $var_utmp = urlencode($_SERVER['REQUEST_URI']);

  $urchinUrl = 'http://www.google-analytics.com/__utm.gif?utmwv=1&utmn='.$var_utmn.'&utmsr=-&utmsc=-&utmul=-&utmje=0&utmfl=-&utmdt=-&utmhn='.$var_utmhn.'&utmp='.$var_utmp.'&utmac='.$var_utmac.'&utmcc=__utma%3D'.$var_cookie.'.'.$var_random.'.'.$var_today.'.'.$var_today.'.'.$var_today.'.2%3B%2B__utmb%3D'.$var_cookie.'%3B%2B__utmc%3D'.$var_cookie.'%3B%2B__utmz%3D'.$var_cookie.'.'.$var_today.'.2.2.utmccn%3D(direct)%7Cutmcsr%3D(direct)%7Cutmcmd%3D(none)%3B%2B__utmv%3D'.$var_cookie.'.'.$var_uservar.'%3B';
  return $urchinUrl;
}

