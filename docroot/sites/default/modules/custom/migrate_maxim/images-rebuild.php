<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

function buildImages($params){
  $strHTML = '';
  $fileLocation = $_SERVER['DOCUMENT_ROOT'] . '/sites/default/files/private-files/';
  $styleURL = '/sites/default/files/styles/';
  $style = 'thumbnail_gallery';
  $domain = 'http://edit.maxim.com';

  if (isset($params['style'])) {
    $style = $params['style'];
  }
  $styleURL .= $style . '/public/';

  if (isset($params['file'])) {
    $fileLocation .= $params['file'];
    if (file_exists($fileLocation)) {
      $file = fopen($fileLocation,'r');
      while(!feof($file)) { 
        $img = fgets($file);
        if (strlen($img)) {
          $imgLocation = str_replace('public://', '/', $img);
          $imgStyle = $styleURL . $imgLocation;
          $strHTML .= '<div class="img-block"><a href="' . $domain . '/sites/default/files/' . $imgLocation . '" title="' . $imgLocation . '" target="_blank"><img src="' . $domain . $imgStyle . '" /></a></div>';
        }
      }
      fclose($file);
    } else {
      $strHTML .= 'Input file does not exist';
    }
  } else {
    $strHTML .= 'Input file not defined';
  }
  return $strHTML;
}
?>

<html>
  <head>
    <title>Images</title>
    <style>
      .img-block { float:left; border:1px solid #CCC; margin:1px; pading:2px; }
      .img-text { display:block; font-size:12px; }
    </style>
  </head>
  <body>
    <?php echo buildImages($_GET); ?>
  </body>
</html>
