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
    // Remove unnecessary paragraph.
    /*var pattern = new RegExp('<p>' + pagebreak + '</p>', 'ig');
    content = content.replace(pattern, placeholder);
    // Move breaks starting at the beginning of paragraphs to before them.
    pattern = new RegExp('<p>' + pagebreak + '(<[^p])', 'ig');
    content = content.replace(pattern, placeholder + '<p>$1');
    // Move breaks starting at the end of to after the paragraphs.
    pattern = new RegExp('([^p]>)' + pagebreak + '<\/p>', 'ig');
    content = content.replace(pattern, '$1</p>' + placeholder);*/
    // Other breaks.
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

    // Fix paragraphs opening just before breaks.
    /*var pattern = new RegExp('(?:' + pagebreak + ')*(<p[^>]*?>\s*)' + pagebreak, 'ig');
    newContent = newContent.replace(pattern, paginationPagebreak + '$1');
    //    console.log('3\n'+newContent);
    // Remove duplicate breaks and any preceding whitespaces.
    pattern = new RegExp('(?:\s*' + pagebreak + '){2,}' + pagebreak, 'ig');
    newContent = newContent.replace(pattern, paginationPagebreak);
    //    console.log('4\n'+newContent);
    // Fix paragraphs ending after breaks.
    pattern = new RegExp(pagebreak + '(\s*<\/p>)(?:' + pagebreak + ')*', 'ig');
    newContent = newContent.replace(pattern, '$1' + paginationPagebreak);
    //    console.log('5\n'+newContent);
    // Remove duplicate breaks with trailing whitespaces.
    pattern = new RegExp('(?:' + pagebreak + '\s*){2,}', 'ig');
    newContent = newContent.replace(pattern, paginationPagebreak);*/
    //    console.log('done\n'+newContent);
    return newContent;
  },

  /**
   * Helper function to return a HTML placeholder.
   */
  _getPlaceholder: function (settings) {
    return '<span class="wysiwyg-pagebreak-span"><img src="' + settings.path + '/images/spacer.gif" alt="pagebreak" title="pagebreak" class="wysiwyg-pagebreak drupal-content" /></span>';
  }
};

})(jQuery);
