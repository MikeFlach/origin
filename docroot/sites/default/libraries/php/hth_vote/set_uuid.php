<script>
  var nid = parent.Drupal.settings.Maxim.nid;
  var uid = getCookie('maxim_uuid');
  var isActive = false;
  var debug = false;
  
  processVote = function(responseText) {
    if (debug) { 
      alert(responseText);
      alert('/js-api/vote/'+nid+'~'+uid+'.json');
    }
    
    if (isActive) {
      if (responseText.indexOf('no_vote_entered') != -1) {
        parent.document.getElementById('hth_vote').style.display = 'block';
      }
      else if (responseText.indexOf('voting_year_finished') != -1) {
        parent.document.getElementById('hth_vote').style.display = 'none';
      }
      else if (responseText.indexOf('voting_week_finished') != -1) {
        parent.document.getElementById('hth_vote').style.display = 'none';
        //parent.document.getElementById('hth_no_vote_msg').innerHTML = 'My week is over. <a href="/hometown-hotties/2013">Check out and vote for this week’s girls!</a>';
        parent.document.getElementById('hth_no_vote_msg').innerHTML = 'Voting is closed. Check back in a few weeks to see who made it to the finals!';
        parent.document.getElementById('hth_no_vote_msg').style.display = 'block';
      }
      else if (responseText.indexOf('limit_reached') != -1) {
        parent.document.getElementById('hth_vote').style.display = 'none';
        parent.document.getElementById('hth_no_vote_msg').innerHTML = 'Thanks for voting for me today! Feel free to cast your ballot for other girls.';
        parent.document.getElementById('hth_no_vote_msg').style.display = 'block';
      }
    }
    else {
      parent.document.getElementById('hth_vote').style.display = 'none';
      parent.document.getElementById('hth_no_vote_msg').innerHTML = 'Check out our Finalists, and come back soon to vote for a winner!';
      parent.document.getElementById('hth_no_vote_msg').style.display = 'block';
    }
  }
  doAjaxRequest('/js-api/vote/'+nid+'~'+uid+'.json', processVote);
  
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
  
</script>

<?php
 /* create, encrypt & store (via cookie) a uuid that will be used to track user hometown hottie votes.*/
  header("Vary: Cookie");
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
