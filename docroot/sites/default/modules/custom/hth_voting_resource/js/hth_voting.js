// $Id$

(function ($) {
  var hth_voting_api = {
    'apiPath': '/js-api/hth_vote'
  };

  // REST functions.
  hth_voting_api.create = function (vote, callback) {
    $.ajax({
      type: "POST",
      url: this.apiPath,
      data: JSON.stringify(vote),
      dataType: 'json',
      contentType: 'application/json',
      success: callback
    });
  };

  hth_voting_api.retreive = function (nid, callback) {
    $.ajax({
      type: "GET",
      url: this.apiPath + '/' + nid,
      dataType: 'json',
      success: callback
    });
  };

  $(document).ready(function () {
    var nid, uid, cast_vote, vote_count_display;

    nid = 12345;
    uid = 'fbtest';

    $('<div id="votetaking"><form>' +
      '<div class="vote-wrapper">' +
      '<input class="save" type="submit" value="Vote" />' +
      '<div class="vote_count"></div>' +
      '</div></form></div>').appendTo('body');

    // Stop the form from submitting
    $('#votetaking form').submit(function () {
      return false;
    });

    $('#notetaking input.save').click(function () {
      var data;
      data = {
        nid: nid,
        uid: uid
      };

      hth_voting_api.create(data, cast_vote);

      vote = null;
    });

    cast_vote = function (res) {
      hth_voting_api.retreive(res.nid, function (res) { vote_count_display(res); });
    };

    vote_count_display = function (voteData) {
      $('#votetaking .vote_count').html(voteData);
    }
  });
}(jQuery));