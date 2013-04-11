<?php
// $Id$

function _bb_generate_uid() {
  $result = array();
  
  $uuid = _gen_uid();
  $enc_uid = _encrypt_uid($uuid);
  $hex_rep_enc_uid = _strToHex($enc_uid);
  
  $result['uid'] = $hex_rep_enc_uid;
  return ($result);
}

function _gen_uid() {
  return sprintf('%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
      mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ),
      mt_rand( 0, 0xffff ),
      mt_rand( 0, 0x0fff ) | 0x4000,
      mt_rand( 0, 0x3fff ) | 0x8000,
      mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff )
  );
}

function _encrypt_uid($str) {
  $ky = 'm@x1m_p@55w0rd';
  if($ky == '') {
    return $str;
  }
  $ky = str_replace(chr(32),'',$ky);
  if(strlen($ky) < 8) {
    exit('key error');
  }
  $kl = strlen($ky) < 32 ? strlen($ky) : 32;
  $k=array();
  for($i = 0;$i < $kl;$i++) {
    $k[$i] = ord($ky{$i})&0x1F;
   }
  $j=0;
  for($i = 0;$i < strlen($str);$i++) {
    $e=ord($str{$i});
    $str{$i}=$e&0xE0?chr($e^$k[$j]):chr($e);
    $j++;
    $j=$j==$kl?0:$j;
  }
  return $str;
}

function _strToHex($string){
  $hex='';

  for ($i=0; $i < strlen($string); $i++) {
    $hex .= dechex(ord($string[$i]));
  }
  return $hex;
}

