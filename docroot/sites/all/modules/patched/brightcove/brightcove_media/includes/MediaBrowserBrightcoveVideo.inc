<?php

/**
 * @file
 * Definition of MediaBrowserUpload.
 */

/**
 * Media browser plugin for showing the upload form.
 *
 * @deprecated
 */
class MediaBrowserBrightcoveVideo extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPluginInterface::access().
   */
  public function access($account = NULL) {
    return media_access('edit', $account);
  }

  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    //$upload_form = drupal_get_form('brightcove_media_upload_form');
    //$upload_form = drupal_render($upload_form);
    $upload_form = '';
    $filter_form = drupal_get_form('brightcove_media_browser_filter_form');
    $filter_form = drupal_render($filter_form);
    $bcpath = drupal_get_path('module', 'brightcove_media');

    return array(
      '#title' => t('Brightcove videos'),
      '#settings' => array(
//        'viewMode' => 'thumbnails',
        'getMediaUrl' => url('brightcove/media/list'),
        'multiselect' => isset($params['multiselect']) && $params['multiselect'] != 'false',
//        'types' => isset($params['types']) ? $params['types'] : array(),
      ),
      '#attached' => array(
        'library' => array(

        ),
        'js' => array(
          $bcpath . '/js/brightcove_media.js',
          $bcpath . '/js/brightcove_media.video.js',
        ),
        'css' => array(
          $bcpath . '/brightcove_media.css',
        ),
      ),
      // If the #form and #markup parameters are not empty the media module will not
      // render fake submit and cancel buttons.
      '#form' => array(FALSE),
      '#markup' => '<div id="container"><div id="scrollbox">' . $upload_form . $filter_form . '</div></div>',
    );
  }
}
