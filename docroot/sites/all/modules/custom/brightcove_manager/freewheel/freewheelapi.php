<?php

require_once('config.php');

require_once(dirname(__FILE__) . '/../feed/videofeedapi.php');

/**
 * Freewheel API
 */
class FreewheelAPI {

private $xml_file = '';

function __construct() {
  $this->xml_file = DRUPAL_ROOT . '/sites/default/files/ads/' . date('YmdHis') . '_maxim.xml';
}

public function process_bvi_xml($fromdate = 'yesterday') {
  $num_videos = $this->build_bvi_xml($fromdate);
  if ($num_videos > 0) {
    $this->send_bvi_xml();
  }
  return $num_videos;
}

private function send_bvi_xml() {
  //$post_url = 'http://bvi.fwmrm.net/submit.cgi?id=' . FREEWHEEL_USER . '&filename=' . $this->xml_file . '&hash=' . FREEWHEEL_TOKEN;
  $post_url = 'https://api.freewheel.tv/services/upload/bvi.xml';
  //$post_url = 'http://localhost.maxim.com/feeds/freewheel/ingest.php';

  $ch = curl_init();
  curl_setopt($ch, CURLOPT_VERBOSE, true);
  curl_setopt($ch, CURLOPT_URL, $post_url);
  curl_setopt($ch, CURLOPT_HTTPHEADER,
    array('X-FreeWheelToken: ' . FREEWHEEL_TOKEN)
  );
  curl_setopt($ch, CURLOPT_HEADER, false);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_POST, true);
  curl_setopt($ch, CURLOPT_POSTFIELDS, array(
    'upload_file[]' => "@$this->xml_file",
  ));
  $result = curl_exec($ch);
  curl_close($ch);
  unlink($this->xml_file);
  echo $result;
}

private function build_bvi_xml($fromdate = 'yesterday') {
  $videos = $this->get_videos($fromdate);
  $item_count = count($videos['items']);

  $feedAPI = new VideoFeedAPI();

  $xml = new XMLWriter();
  //$xml->openURI('php://output');
  $xml->openURI($this->xml_file);
  $xml->setIndent(true);
  $xml->setIndentString('  ');
  $xml->startDocument('1.0', 'UTF-8');
  $xml->startElement('FWCoreContainer');
    $xml->startAttribute('bvi_xsd_version');
      $xml->text('1');
    $xml->endAttribute();
    $xml->startAttribute('contact_email');
      $xml->text(FREEWHEEL_EMAIL);
    $xml->endAttribute();
    $xml->startElement('FWCallBackURL');
      $xml->startAttribute('url');
        $xml->text(MAXIM_SERVER_CALLBACK . '/' . drupal_get_path('module', 'brightcove_manager') . '/freewheel/ingest.php?id=' . FREEWHEEL_ID);
      $xml->endAttribute();
    $xml->endElement(); // FWCallBackURL

    // Loop through videos

    foreach ($videos['items'] as $item) {
      //print_r($item); die();
      // Get categories for video item
      $tags = explode(',', $item->tags);
      $categories = $feedAPI->get_category_for_video($tags);

      $xml->startElement('FWVideoDocument');
        $xml->startAttribute('video_id');
          $xml->text($item->brightcove_id);
        $xml->endAttribute();
        $xml->startElement('fwContentOwner');
          $xml->startElement('SelfContentOwner');
          $xml->endElement(); // SelfContentOwner
        $xml->endElement(); // fwContentOwner
        $xml->startElement('fwOperation');
          $xml->text('Upsert');
        $xml->endElement(); // fwOperation
        $xml->startElement('fwReplaceGroup');
          $xml->text('true');
        $xml->endElement(); // fwReplaceGroup

        // Titles
        $xml->startElement('fwTitles');
          // Episode title
          $xml->startElement('titleItem');
            $xml->startElement('title');
              $xml->text($item->name);
            $xml->endElement(); // title
            $xml->startElement('titleType');
              $xml->text('Episode Title1');
            $xml->endElement(); // titleType
          $xml->endElement(); // titleItem

          $series_ct = 0;
          foreach ($categories as $cat) {
            $cat_type = '';
            switch ($cat['type']) {
              case 'series':
                if($series_ct == 0) {
                  $cat_type = 'Series';
                }
                $series_ct++;
              break;
              //case 'channel': $cat_type = 'Group'; break;
            }
            if (strlen($cat_type) > 0) {
              $xml->startElement('titleItem');
                $xml->startElement('title');
                  $xml->text($cat['name']);
                $xml->endElement(); // title
                $xml->startElement('titleType');
                  $xml->text($cat_type);
                $xml->endElement(); // titleType
              $xml->endElement(); // titleItem
            }
          }
        $xml->endElement(); // fwTitles

        // Descriptions
        $xml->startElement('fwDescriptions');
          $xml->startElement('descriptionItem');
            $xml->startElement('description');
              $xml->text($item->short_description);
            $xml->endElement(); // description
            $xml->startElement('descriptionType');
              $xml->text('Episode');
            $xml->endElement(); // descriptionType
          $xml->endElement(); // descriptionItem
        $xml->endElement(); // fwDescriptions

        // Languages
        $xml->startElement('fwLangs');
          $xml->startElement('langItem');
            $xml->text('en');
          $xml->endElement(); // langItem
        $xml->endElement(); // fwLangs

        // Genres
        foreach ($categories as $cat) {
          $genre = '';
          switch ($cat['type']) {
            case 'channel': $genre = $cat['name']; break;
          }
          if (strlen($genre) > 0) {
            $xml->startElement('fwGenres');
              $xml->startElement('genreItem');
                $xml->text($genre);
              $xml->endElement(); // genreItem
            $xml->endElement(); // fwGenres
            break;
          }
        }

        // Available Date Range
        $xml->startElement('fwDateAvailable');
          if ($item->start_date > 0) {
            $xml->startElement('dateAvailableStart');
              $xml->text(date('Y-m-d\TH:i:s\Z' ,$item->start_date));
            $xml->endElement(); // dateAvailableStart
          }
          if ($item->end_date > 0) {
            $xml->startElement('dateAvailableEnd');
              $xml->text(date('Y-m-d\TH:i:s\Z' ,$item->end_date));
            $xml->endElement(); // dateAvailableEnd
          }
        $xml->endElement(); // fwDateAvailable

        // Rating
        $xml->startElement('fwRating');
          $xml->text('Unrated');
        $xml->endElement(); // fwRating

        // Date Issued (Use start date)
        if ($item->start_date > 0) {
          $xml->startElement('fwDateIssued');
            $xml->text(date('Y-m-d\TH:i:s\Z' ,$item->start_date));
          $xml->endElement(); // fwDateIssued
        }

        // Duration in seconds
        $xml->startElement('fwDuration');
          $xml->text(intval($item->video_length/1000));
        $xml->endElement(); // fwDuration


      $xml->endElement(); // FWVideoDocument
      $xml->flush();
    }
    // End loop through videos

  $xml->endElement(); // FWCoreContainer
  $xml->endDocument();
  $xml->flush();

  return $item_count;
}

private function get_videos($fromdate = 'yesterday') {
  $output = array('statusmsg'=>'', 'total_count'=>0, 'items'=> array());
  switch ($fromdate) {
    case 'all':
      $searchResults = db_select('brightcove_manager_metadata', 'b')
        ->fields('b')
        ->condition('active', 1)
        ->condition('deleted', 0)
        ->orderBy('start_date', 'ASC')
        ->execute();
    break;
    default:
      if (strlen($fromdate) > 0) {
        $int_fromdate = strtotime($fromdate);
      }
      $searchResults = db_select('brightcove_manager_metadata', 'b')
        ->fields('b')
        ->condition('active', 1)
        ->condition('deleted', 0)
        ->condition('last_modified_date', $int_fromdate, '>')
        ->orderBy('start_date', 'ASC')
        ->execute();
    break;
  }

  if ($searchResults->rowCount() > 0) {
    $output['statusmsg'] = 'SUCCESS';
    $output['total_count'] = $searchResults->rowCount();
    $output['items'] = array();
    foreach ($searchResults as $record) {
      array_push($output['items'], $record);
    }
  }
  return $output;
}

}
