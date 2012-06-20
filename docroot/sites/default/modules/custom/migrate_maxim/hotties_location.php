<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

// Include Drupal bootstrap
chdir($_SERVER['DOCUMENT_ROOT']);
define('DRUPAL_ROOT', getcwd());
require_once $_SERVER['DOCUMENT_ROOT'] . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

hottieLocations();

function hottieLocations(){
  $query = "select n.nid, n.vid, n.title, fn.field_profile_first_name_value as first_name, c.field_profile_city_value as city, 
            s.field_profile_state_tid, z.field_profile_zipcode_value, t.name as state from node n
            left join field_data_field_profile_city c on n.nid=c.entity_id
            left join field_data_field_profile_state s on n.nid=s.entity_id
            left join field_data_field_profile_first_name fn on n.nid=fn.entity_id
            left join field_data_field_profile_zipcode z on n.nid=z.entity_id
            left join taxonomy_term_data t on t.tid=s.field_profile_state_tid
            left join location_instance li on li.nid=n.nid
            left join location l on l.lid=li.lid
            where n.type='hotties_profile'
            and l.lid is null";

  $result = db_query($query);

  foreach ($result as $data) {
    try{
    $longitude = '';
    $latitude = '';
    $state = getStateAbbr($data->state);
    $country = '';
    $city = $data->city;
    $first_name = $data->first_name;

    $qryLoc = "select * from zipcodes where city = :city and state= :state limit 1";
    $qryParams = array(':city' => $city, ':state' => $state);
    $location_result = db_query($qryLoc, $qryParams);

    foreach ($location_result as $locData) {
      $longitude = $locData->longitude;
      $latitude = $locData->latitude;
      $state = $locData->state;
      $country = $locData->country;
      $zip_code = $locData->zip;
    }

    if(strlen($longitude) == 0) {
      $longitude = 0;
    }
    if(strlen($latitude) == 0) {
      $latitude = 0;
    }
    if($zip_code == NULL) {
      $zip_code = '';
    }
    if($state == NULL) {
      $state = '';
    }
    if($country == NULL) {
      $country = '';
    }
    if($city == NULL) {
      $city = '';
    }
    if($first_name == NULL) {
      $first_name = '';
    }

    $location_id = db_insert('location')
      ->fields(array(
        'name' => $first_name,
        'city' => $city,
        'province' => $state,
        'postal_code' => $zip_code,
        'longitude' => $longitude,
        'latitude' => $latitude,
        'country' => $country,
      ))
      ->execute();

    db_insert('location_instance')
      ->fields(array(
        'nid' => $data->nid,
        'vid' => $data->vid,
        'lid' => $location_id,
      ))
      ->execute();

    echo $data->nid . ', ' . $location_id . ': ' . $city . ', ' . $state . ' ' . $zip_code . "<br />\n"; flush();
    } catch (Exception $e) {
      var_dump($e);die();
    }
  }

  mysql_close($con);
}

  function getStateAbbr($state){
    switch($state){
      case 'Alabama': $state_abbr = 'AL'; break;  
      case 'Alaska': $state_abbr = 'AK'; break;
      case 'Arizona': $state_abbr = 'AZ'; break;
      case 'Arkansas': $state_abbr = 'AR'; break;
      case 'California': $state_abbr = 'CA'; break;
      case 'Colorado': $state_abbr = 'CO'; break;
      case 'Connecticut': $state_abbr = 'CT'; break;
      case 'Delaware': $state_abbr = 'DE'; break;
      case 'District of Columbia': $state_abbr = 'DC'; break;
      case 'Florida': $state_abbr = 'FL'; break;
      case 'Georgia': $state_abbr = 'GA'; break;
      case 'Hawaii': $state_abbr = 'HI'; break;
      case 'Idaho': $state_abbr = 'ID'; break;
      case 'Illinois': $state_abbr = 'IL'; break;
      case 'Indiana': $state_abbr = 'IN'; break;
      case 'Iowa': $state_abbr = 'IA'; break;
      case 'Kansas': $state_abbr = 'KS'; break;
      case 'Kentucky': $state_abbr = 'KY'; break;
      case 'Louisiana': $state_abbr = 'LA'; break;
      case 'Maine': $state_abbr = 'ME'; break;
      case 'Maryland': $state_abbr = 'MD'; break;
      case 'Massachusetts': $state_abbr = 'MA'; break;
      case 'Michigan': $state_abbr = 'MI'; break;
      case 'Minnesota': $state_abbr = 'MN'; break;
      case 'Mississippi': $state_abbr = 'MS'; break;
      case 'Missouri': $state_abbr = 'MO'; break;
      case 'Montana': $state_abbr = 'MT'; break;
      case 'Nebraska': $state_abbr = 'NE'; break;
      case 'Nevada': $state_abbr = 'NV'; break;
      case 'New Hampshire': $state_abbr = 'NH'; break;
      case 'New Jersey': $state_abbr = 'NJ'; break;
      case 'New Mexico': $state_abbr = 'NM'; break;
      case 'New York': $state_abbr = 'NY'; break;
      case 'North Carolina': $state_abbr = 'NC'; break;
      case 'North Dakota': $state_abbr = 'ND'; break;
      case 'Ohio': $state_abbr = 'OH'; break;
      case 'Oklahoma': $state_abbr = 'OK'; break;
      case 'Oregon': $state_abbr = 'OR'; break;
      case 'Pennsylvania': $state_abbr = 'PA'; break;
      case 'Rhode Island': $state_abbr = 'RI'; break;
      case 'South Carolina': $state_abbr = 'SC'; break;
      case 'South Dakota': $state_abbr = 'SD'; break;
      case 'Tennessee': $state_abbr = 'TN'; break;
      case 'Texas': $state_abbr = 'TX'; break;
      case 'Utah': $state_abbr = 'UT'; break;
      case 'Vermont': $state_abbr = 'VT'; break;
      case 'Virginia': $state_abbr = 'VA'; break;
      case 'Washington': $state_abbr = 'WA'; break;
      case 'West Virginia': $state_abbr = 'WV'; break;
      case 'Wisconsin': $state_abbr = 'WI'; break;
      case 'Wyoming': $state_abbr = 'WY'; break;
      default: $state_abbr = $state; break;
    }
    return $state_abbr;
  }
