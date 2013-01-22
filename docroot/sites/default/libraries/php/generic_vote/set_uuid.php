<script>
  var uid = getCookie('maxim_uuid');
  var nid = parent.Drupal.settings.Maxim.nid;
  var votingCampaign = parent.Drupal.settings.Maxim.general_profile_data.vote_campaign_name;
  var limitReachedTxt = parent.Drupal.settings.Maxim.general_profile_data.voting_limit_text;
  var isActive = parent.Drupal.settings.Maxim.general_profile_data.vote_campaign_active;
  var closedTxt = parent.Drupal.settings.Maxim.general_profile_data.voting_closed_text;

  processVote = function(responseText) {
    debug = false;
    if (debug) { 
      alert(responseText);
      alert('/vote/generic-vote/'+nid+'~'+uid+'~'+encodeURIComponent(votingCampaign)+'.json');
      alert(votingCampaign); alert(limitReachedTxt); alert(isActive); alert(closedTxt);
    }
    
    if (!isActive) {
      parent.document.getElementById('generic_vote').style.display = 'none';
      parent.document.getElementById('generic_no_vote_msg').innerHTML = closedTxt;
      parent.document.getElementById('generic_no_vote_msg').style.display = 'block';
    }
    else {
      if (responseText.indexOf('no-vote-entered') != -1) {
        parent.document.getElementById('generic_vote').style.display = 'block';
        parent.document.getElementById('generic_no_vote_msg').style.display = 'none';
      }
      else if (responseText.indexOf('limit-reached') != -1) {
        parent.document.getElementById('generic_vote').style.display = 'none';
        parent.document.getElementById('generic_no_vote_msg').innerHTML = limitReachedTxt;
        parent.document.getElementById('generic_no_vote_msg').style.display = 'block';
      }
    }
  }
  
  doAjaxRequest('/js-api/generic-vote/'+nid+'~'+uid+'~'+encodeURIComponent(votingCampaign)+'.json', processVote);
  
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

  function doAjaxRequest(url, callback) {
    var ajaxRequest = null;
  
    try {
      // Opera 8.0+, Firefox, Safari
      ajaxRequest = new XMLHttpRequest();
    } 
    catch (e) {
      // Internet Explorer Browsers
      try {
        ajaxRequest = new ActiveXObject("Msxml2.XMLHTTP");
      } 
      catch (e) {
        try {
          ajaxRequest = new ActiveXObject("Microsoft.XMLHTTP");
        } 
        catch (e) {
          // Something went wrong
          return false;
        }
      }
    }

    ajaxRequest.open("GET", url, false);
    ajaxRequest.onreadystatechange = function() {
      if(ajaxRequest.readyState == 4) {
        callback(ajaxRequest.responseText);
      }
    }
    ajaxRequest.send(null);
  }
  
  function getQueryParams(qs) {
    qs = qs.split("+").join(" ");

    var params = {}, tokens,
        re = /[?&]?([^=]+)=([^&]*)/g;

    while (tokens = re.exec(qs)) {
        params[decodeURIComponent(tokens[1])]
            = decodeURIComponent(tokens[2]);
    }

    return params;
  }

  
  function replaceAll(txt, replace, with_this) {
    return txt.replace(new RegExp(replace, 'g'),with_this);
  }


</script>

<?php
  header("Vary: Cookie");
  /*
   * create, encrypt & store (via cookie) a uuid that will be used to track votes.
   */

  process_uuid_cookie();

  function process_uuid_cookie() {
    if (!isset($_COOKIE["maxim_uuid"])) {
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