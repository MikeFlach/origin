(function ($) {

Drupal.wysiwyg.plugins['pagination'] = {

  /**
   * Return whether the passed node belongs to this plugin.
   */
  isNode: function(node) {
    return ($(node).is('img.wysiwyg-pagebreak'));
  },

  /**
   * Execute the button.
   */
  invoke: function(data, settings, instanceId) {
    if (data.format == 'html') {
      var content = this._getPlaceholder(settings);
    }
    else {
      var content = settings.paginationPagebreak;
    }
    if (typeof content != 'undefined') {
      Drupal.wysiwyg.instances[instanceId].insert(content);
    }
  },

  /**
   * Replace all [pagebreak] tags with images.
   */
  attach: function(content, settings, instanceId) {
    // @see http://drupal.org/node/510552#comment-3879096
    // @todo Update this technique if that thread produces a better way to do
    // image replacement.

    var paginationPagebreak = settings.paginationPagebreak;
    var placeholder = this._getPlaceholder(settings);

    // Some WYSIWYGs (CKEditor) will strip the slash from single tags:
    // <foo /> becomes <foo>
    // Escape square brackets for use in regexp
    var pagebreak = paginationPagebreak.replace(/\[/g, '\\[').replace(/\]/g, '\\]').replace(/\/>/, '/?>').replace(/ /g, ' ?');
    pattern = new RegExp(pagebreak, 'ig');
    content = content.replace(pattern, placeholder);

    return content;
  },

  /**
   * Replace images with [pagebreak] in content upon detaching editor.
   */
  detach: function(content, settings, instanceId) {
    // @see http://drupal.org/node/510552#comment-3879096
    // @todo Update this technique if that thread produces a better way to do
    // image replacement.

    var $content = $('<div>' + content + '</div>');
    var paginationPagebreak = settings.paginationPagebreak;
     var pagebreak = paginationPagebreak.replace(/\[/g, '\\[').replace(/\]/g, '\\]').replace(/\/>/, '/?>').replace(/ /g, ' ?');
    $.each($('span.wysiwyg-pagebreak-span', $content), function () {
      $('<span class="wysiwyg-pagebreak-span">' + paginationPagebreak + "</span>").insertBefore(this);
      $(this).remove();
    });
    var newContent = $content.html();
    return $content.html();
  },

  /**
   * Helper function to return a HTML placeholder.
   */
  _getPlaceholder: function (settings) {
    return '<span class="wysiwyg-pagebreak-span"><img src="' + settings.path + '/images/spacer.gif" alt="pagebreak" title="pagebreak" class="wysiwyg-pagebreak drupal-content" /></span>';
  }
};

})(jQuery);
