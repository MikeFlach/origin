<?php
/*
 * create, encrypt & store (via cookie) a uuid that will be used to track user hometown hottie votes.
 */

process_uuid_cookie();

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

function encrypt_uuid($uuid) {
  $password = 'm@x1m_p@55w0rd';
  $salt = openssl_random_pseudo_bytes(8);

  $salted = '';
  $dx = '';

  while (strlen($salted) < 48) {
    $dx = md5($dx.$password.$salt, true);
    $salted .= $dx;
  }

  $key = substr($salted, 0, 32);
  $iv  = substr($salted, 32,16);

  $encrypted_data = openssl_encrypt($uuid, 'aes-256-cbc', $key, true, $iv);
  return base64_encode('Salted__' . $salt . $encrypted_data);
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