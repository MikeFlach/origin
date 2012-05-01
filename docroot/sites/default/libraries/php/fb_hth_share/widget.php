<?php
  header("Vary: Cookie");
<<<<<<< HEAD
  require 'src/facebook.php';

  // Create our Application instance (replace this with your appId and secret).
  /*
  $facebook = new Facebook(array(
    'appId'  => '344617158898614',
    'secret' => '6dc8ac871858b34798bc2488200e503d',
  ));
  */
  $facebook = new Facebook(array(
    'appId' => '139254672864045',
    'secret' => '6354158c7a1d21cc9a0727724ff0d5a4'
  ));

  // Get User ID
  $user = $facebook->getUser();

  if ($user) {
    try {
      // Proceed knowing you have a logged in user who's authenticated.
      $user_profile = $facebook->api('/me');
    } catch (FacebookApiException $e) {
      error_log($e);
      $user = null;
    }
  }

  // Login or logout url will be needed depending on current user state.
  if ($user) {
    $logoutUrl = $facebook->getLogoutUrl();
  } else {
    $loginUrl = $facebook->getLoginUrl();
  }

=======
	require 'src/facebook.php';

	$facebook = new Facebook(array(
		'appId' => '139254672864045',
		'secret' => '6354158c7a1d21cc9a0727724ff0d5a4'
	));

	// Get User ID
	$user = $facebook->getUser();

	if ($user) {
	  try {
		// Proceed knowing you have a logged in user who's authenticated.
		$user_profile = $facebook->api('/me');
	  } catch (FacebookApiException $e) {
		error_log($e);
		$user = null;
	  }
	}

	// Login or logout url will be needed depending on current user state.
	if ($user) {
	  $logoutUrl = $facebook->getLogoutUrl();
	} else {
	  $loginUrl = $facebook->getLoginUrl();
	}
>>>>>>> cb7571ec7f2681e8a64e0b29006f78579530b8de
?>

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js" type="text/javascript"></script>
<script>
  function changeIframeDimensions() {
    $(document).ready(function() {
      $('#fb-hth', window.parent.document).height($("#fb_share").height()+41);
      $('#fb-hth', window.parent.document).width("100%");
    });
  }
  window.setInterval("changeIframeDimensions()", 1000);

</script>

<!doctype html>
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" lang="en-US" xmlns:fb="https://www.facebook.com/2008/fbml">
<<<<<<< HEAD
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# agdm_share_me: http://ogp.me/ns/fb/agdm_share_me#">
    <title>Hometown Hotties Contest</title>
    <meta property="fb:app_id"      content="139254672864045" />
    <meta property="og:type"        content="agdm_share_me:contest" />
    <meta property="og:url"         content="http://www.maxim.com/hometown-hotties-entry-form-2013" />
    <meta property="og:title"       content="You Should Enter Hometown Hotties Inspired By Jose Cuervo" />
    <meta property="og:description" content="I think you�re perfect for the Maxim Hometown Hotties contest! Take your shot and enter today." />
    <meta property="og:image"       content="http://cdn2.maxim.com/maximonline/fb/images/badge_take_your_shot.png" />
    <link rel="stylesheet" type="text/css" href="fb_style.css" />
</head>
    <body>

      <div id="fb_share">
        <img src="http://cdn2.maxim.com/maximonline/fb/images/takeyourshot.jpg" id="shot">
        <div class="copy">
          <h1>Know a Hottie? Tell them to sign up.</h1>
          For every completed entry from your badge referral, the better your chances to win a trip to Vegas with the Hotties.

          <?php if ($user) { ?>
          <a href="<?php echo $logoutUrl; ?>">Logout</a>
          <form id="form_confirmation">
            <input id="confirmation" type="checkbox" name="confirmation" /> Yes, I've read and agree to the <a href="#" target="_blank">Official Rules</a> and <a href="http://www.maxim.com/corporate/terms-conditions" target="_blank">Terms &amp; Conditions</a>.
          </form>
          <?php } else { ?>
            <fb:login-button data-perms="email"></fb:login-button>
            <em>You are not connected right now.</em>
          <?php } ?>
        </div>
        <?php if ($user) { ?>
        <ul>
          <li><a id="getMyFriends" href="#"/><img src="http://cdn2.maxim.com/maximonline/fb/images/invite.png"></a></li>
        </ul>
        <div id="fb_dialog_display">
          <div id="friends_wall">
            <!-- POST TO MY FRIEND'S WALL PLACEHOLDER -->
          </div>
        </div>
        <?php } ?>
      </div>
      <div id="fb-root"></div>
      <script>
        window.fbAsyncInit = function() {
          FB.init({
            appId: '<?php echo $facebook->getAppID() ?>',
            cookie: true,
            xfbml: true,
            oauth: true
          });
          FB.Event.subscribe('auth.login', function(response) {
            window.location.reload(true);
          });
          FB.Event.subscribe('auth.logout', function(response) {
            window.location.reload(true);
          });
          changeIframeDimensions();
        };
        (function() {
          var e = document.createElement('script'); e.async = true;
          e.src = document.location.protocol +
            '//connect.facebook.net/en_US/all.js';
          document.getElementById('fb-root').appendChild(e);
        }());
        changeIframeDimensions();
      </script>

    <script>
            $(function(){

                    var shareUrl = 'http://www.maxim.com/hometown-hotties-entry-form-2013';
                    var shareTitle = 'You Should Enter Hometown Hotties Inspired By Jose Cuervo';
                    var shareDescription = 'I think you�re perfect for the Maxim Hometown Hotties contest! Take your shot and enter today.';
                    var shareImage = 'http://cdn2.maxim.com/maximonline/fb/images/badge_take_your_shot.png';
                    var conf_id = '';


                    $('#confirmation').click(function(){
                            var confirmed = $('#confirmation:checkbox').attr('checked');

                            if (typeof confirmed === 'undefined') {
                                    conf_id = '';
                            }
                            else
                            {
                                    FB.getLoginStatus(function(response) {
                                            if (!response.authResponse) {
                                                    // console.log('not connected');
                                            } else {
                                                    conf_id = response.authResponse.userID;
                                            }
                                    });
                            }
    changeIframeDimensions();
                    });

                    $('#shareWithFriends').click(function(){
                            var body = 'Using Share Me Test';
                            FB.ui({ method: 'apprequests',
                            message: body});
    changeIframeDimensions();
                    });

                    $('#getMyFriends').click(function(){
                            $(this).addClass('selected');
                            $('#postToMyWall').removeClass('selected');

                            var profilePicsDiv = document.getElementById('friends_wall');

                            FB.api('/me/friends', {fields: 'id, name, picture'}, function(response){
                                    var markup = '';
                                    var numFriends = response.data.length;

                                    if (numFriends > 0) {
                                            for (var i=0; i<numFriends; i++) {
                                                    markup += (
                                                            '<div class="fb_profile"><a href="" id="' + response.data[i].id + '"><img src="' + response.data[i].picture + '" alt="' + response.data[i].name + '" title="' + response.data[i].name + '"/><label>' + response.data[i].name + '</label></a></div>'
                                                    );
                                            }
                                    } else {
                                            alert('you seem to not have any friends to show');
                                    }
                                    profilePicsDiv.innerHTML = markup;
                            });

                            $('#fb_dialog_display div').hide();
                            $('#fb_dialog_display #friends_wall').show();
                            $('#fb_share #fb_dialog_display').addClass('buffer');
    changeIframeDimensions();
                    });

                    $('body').delegate('.fb_profile a', 'click', function(e){

                            var uid = $(this).attr('id');

                            FB.ui(
                              {
                                method: 'feed',
                                to: uid,
                                message: 'sharing...',
                                name: shareTitle,
                                caption: 'http://www.hometownhotties.com',
                                      description: (
                                      shareDescription
                                ),
                                link: shareUrl + '?ref_id=' + conf_id,
                                picture: shareImage,
                                actions: [
                                            { name: shareTitle, link: shareUrl }
                                ],
                              user_message_prompt: 'Share your thoughts about ' + shareTitle
                              },
                              function(response) {
                                    if (response && response.post_id) {
                                      //alert('Post was published.');
                                      //console.log(shareUrl + '?id=' + conf_id);
                                    } else {
                                      //alert('Post was not published.');
                                      //console.log(shareUrl + '?id=' + conf_id);
                                    }
                              }
                            );

                            e.preventDefault();
                            return false;
                    });
  changeIframeDimensions();
            });
    </script>
=======
	<head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# agdm_share_me: http://ogp.me/ns/fb/agdm_share_me#">
		<title>Hometown Hotties Contest</title>
		<meta property="fb:app_id"      content="139254672864045" />
		<meta property="og:type"        content="agdm_share_me:contest" />
		<meta property="og:url"         content="http://www.maxim.com/hometown-hotties-entry-form-2013" />
		<meta property="og:title"       content="You Should Enter Hometown Hotties Inspired By Jose Cuervo" />
		<meta property="og:description" content="I think you�re perfect for the Maxim Hometown Hotties contest! Take your shot and enter today." />
		<meta property="og:image"       content="http://cdn2.maxim.com/maximonline/fb/images/badge_take_your_shot.png" />
		<link rel="stylesheet" type="text/css" href="fb_style.css" />
	</head>
	<body>

	<div id="fb_share" onclick="changeIframeDimensions();">
		<img src="http://cdn2.maxim.com/maximonline/fb/images/takeyourshot.jpg" id="shot">
		<div class="copy">
			<h1>Know a Hottie? Tell them to sign up.</h1>
			For every completed entry from your badge referral, the better your chances to win a trip to Vegas with the Hotties.

			<?php if ($user) { ?>
			<a href="<?php echo $logoutUrl; ?>">Logout</a>
			<form id="form_confirmation">
				<input id="confirmation" type="checkbox" name="confirmation" /> Yes, I've read and agree to the <a href="#" target="_blank">Official Rules</a> and <a href="http://www.maxim.com/corporate/terms-conditions" target="_blank">Terms &amp; Conditions</a>.
			</form>
			<?php } else { ?>
				<fb:login-button data-perms="email"></fb:login-button>
				<em>You are not connected right now.</em>
			<?php } ?>
		</div>
		<?php if ($user) { ?>
		<ul>
			<li><a id="getMyFriends" href="#"/><img src="http://cdn2.maxim.com/maximonline/fb/images/invite.png"></a></li>
		</ul>
		<div id="fb_dialog_display">
			<div id="friends_wall">
				<!-- POST TO MY FRIEND'S WALL PLACEHOLDER -->
			</div>
		</div>
		<?php } ?>
	</div>
	<div id="fb-root"></div>
    <script>
      window.fbAsyncInit = function() {
        FB.init({
          appId: '<?php echo $facebook->getAppID() ?>',
          cookie: true,
          xfbml: true,
          oauth: true
        });
        FB.Event.subscribe('auth.login', function(response) {
          window.location.reload();
        });
        FB.Event.subscribe('auth.logout', function(response) {
          window.location.reload();
        });
      };
      (function() {
        var e = document.createElement('script'); e.async = true;
        e.src = document.location.protocol +
          '//connect.facebook.net/en_US/all.js';
        document.getElementById('fb-root').appendChild(e);
      }());
    </script>

	<script>
		$(function(){

			var shareUrl = 'http://www.maxim.com/hometown-hotties-entry-form-2013';
			var shareTitle = 'You Should Enter Hometown Hotties Inspired By Jose Cuervo';
			var shareDescription = 'I think you�re perfect for the Maxim Hometown Hotties contest! Take your shot and enter today.';
			var shareImage = 'http://cdn2.maxim.com/maximonline/fb/images/badge_take_your_shot.png';
			var conf_id = '';


			$('#confirmation').click(function(){
				var confirmed = $('#confirmation:checkbox').attr('checked');

				if (typeof confirmed === 'undefined') {
					conf_id = '';
				}
				else
				{
					FB.getLoginStatus(function(response) {
						if (!response.authResponse) {
							// console.log('not connected');
						} else {
							conf_id = response.authResponse.userID;
						}
					});
				}
			});

			$('#shareWithFriends').click(function(){
				var body = 'Using Share Me Test';
				FB.ui({ method: 'apprequests',
				message: body});
			});

			$('#getMyFriends').click(function(){
				$(this).addClass('selected');
				$('#postToMyWall').removeClass('selected');

				var profilePicsDiv = document.getElementById('friends_wall');

				FB.api('/me/friends', {fields: 'id, name, picture'}, function(response){
					var markup = '';
					var numFriends = response.data.length;

					if (numFriends > 0) {
						for (var i=0; i<numFriends; i++) {
							markup += (
								'<div class="fb_profile"><a href="" id="' + response.data[i].id + '"><img src="' + response.data[i].picture + '" alt="' + response.data[i].name + '" title="' + response.data[i].name + '"/><label>' + response.data[i].name + '</label></a></div>'
							);
						}
					} else {
						alert('you seem to not have any friends to show');
					}
					profilePicsDiv.innerHTML = markup;
				});

				$('#fb_dialog_display div').hide();
				$('#fb_dialog_display #friends_wall').show();
				$('#fb_share #fb_dialog_display').addClass('buffer');
			});

			$('body').delegate('.fb_profile a', 'click', function(e){

				var uid = $(this).attr('id');

				FB.ui(
				  {
				   method: 'feed',
				   to: uid,
				   message: 'sharing...',
				   name: shareTitle,
				   caption: 'http://www.hometownhotties.com',
					  description: (
					  shareDescription
				   ),
				   link: shareUrl + '?ref_id=' + conf_id,
				   picture: shareImage,
				   actions: [
						{ name: shareTitle, link: shareUrl }
				   ],
				  user_message_prompt: 'Share your thoughts about ' + shareTitle
				  },
				  function(response) {
					if (response && response.post_id) {
					  //alert('Post was published.');
					  //console.log(shareUrl + '?id=' + conf_id);
					} else {
					  //alert('Post was not published.');
					  //console.log(shareUrl + '?id=' + conf_id);
					}
				  }
				);

				e.preventDefault();
				return false;
			});
		});
	</script>
>>>>>>> cb7571ec7f2681e8a64e0b29006f78579530b8de
  </body>
</html>
