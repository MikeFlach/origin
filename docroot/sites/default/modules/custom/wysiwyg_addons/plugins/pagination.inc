<?php

/**
 * Define Wysiwyg plugins.
 */
function wysiwyg_addons_pagination_plugin($editor, $version) {
  $plugins['pagination'] = array(
    'title'      => t('Pagination'),
    'icon file'  => 'pagination.gif',
    'icon title' => t('Insert a page break'),
    'filename'   => 'pagination.js',
    'settings'   => array('paginationPagebreak' => '[pagebreak]'),
  );
  return $plugins;
}
