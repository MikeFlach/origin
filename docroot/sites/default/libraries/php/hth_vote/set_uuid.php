<script>
  nid = parent.Drupal.settings.Maxim.nid;
  uid = getCookie('maxim_uuid');

  result = httpGet('/js-api/vote/'+nid+'~'+uid+'.json');
  alert(result == '"no_vote_entered"');

  if (result == '"no_vote_entered"') {
    parent.document.getElementById('hth_vote').style.display = 'block';
  }
  else if (result == '"voting_year_finished"') {
    parent.document.getElementById('hth_vote').style.display = 'none';
  }
  else if (result == '"voting_week_finished"') {
    parent.document.getElementById('hth_vote').style.display = 'none';
    parent.document.getElementById('hth_no_vote_msg').innerHTML = 'My week is over.  Wish me luck!';
    parent.document.getElementById('hth_no_vote_msg').style.display = 'block';
  }
  else if (result == '"limit_reached"') {
    parent.document.getElementById('hth_vote').style.display = 'none';
    parent.document.getElementById('hth_no_vote_msg').innerHTML = 'You already votede for me today.  Thank you!';
    parent.document.getElementById('hth_no_vote_msg').style.display = 'block';
  }
  function getCookie(c_name){
    var i,x,y,ARRcookies=document.cookie.split(";");

    for (i=0;i<ARRcookies.length;i++) {
      x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
      y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
      x=x.replace(/^\s+|\s+$/g,"");

      if (x==c_name) {
        return unescape(y);
      }
    }
  }

  function httpGet(url) {
    var xmlHttp = null;

    xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET", url, false);
    xmlHttp.send(null);

    return xmlHttp.responseText;
  }
</script>

<?php
/*
 * create, encrypt & store (via cookie) a uuid that will be used to track user hometown hottie votes.
 */

//process_uuid_cookie();

function process_uuid_cookie() {
  $uuid = $_COOKIE['maxim_uuid'];

  if (!isset($uuid)) {
    $enc_uuid = generate_uuid();
    $hex_rep_enc_uuid = strToHex($enc_uuid);
    $expires = cookie_day_val(365);
    setcookie('maxim_uuid', $hex_rep_enc_uuid, $expires, '/');
  }

  return;
}

function cookie_day_val($days) {
  return ((time() + (86400 * $days)));
}

function gen_uuid() {
  return sprintf('%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
      mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ),
      mt_rand( 0, 0xffff ),
      mt_rand( 0, 0x0fff ) | 0x4000,
      mt_rand( 0, 0x3fff ) | 0x8000,
      mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff )
  );
}

function encrypt_uuid($str) {
  $ky = 'm@x1m_p@55w0rd';
  if($ky=='')return $str;
  $ky=str_replace(chr(32),'',$ky);
  if(strlen($ky)<8)exit('key error');
  $kl=strlen($ky)<32?strlen($ky):32;
  $k=array();for($i=0;$i<$kl;$i++){
  $k[$i]=ord($ky{$i})&0x1F;}
  $j=0;for($i=0;$i<strlen($str);$i++){
  $e=ord($str{$i});
  $str{$i}=$e&0xE0?chr($e^$k[$j]):chr($e);
  $j++;$j=$j==$kl?0:$j;}
  return $str;
}

function generate_uuid() {
  $uuid = gen_uuid();
  $enc_uuid = encrypt_uuid($uuid);

  return ($enc_uuid);
}

function strToHex($string){
 $hex='';

 for ($i=0; $i < strlen($string); $i++) {
   $hex .= dechex(ord($string[$i]));
 }
 return $hex;
}