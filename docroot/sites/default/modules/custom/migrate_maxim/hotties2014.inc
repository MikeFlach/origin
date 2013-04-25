<?php

abstract class HometownHotties2014Migration extends Migration {

  public function __construct() {
    // Always call the parent constructor first for basic setup
    parent::__construct();

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('Henry Wan', 'hwan@maxim.com', t('Implementor')),
    );
  }
}

class ProfileWeek2014 {
  private static $week = null;
  private static $arSID = array();

  public function getWeek() {
    if (is_null(self::$week)) {
      self::$week = 'week ' . variable_get('migrate_hotties_week', 1);
    }
    return self::$week;
  }

  public function getSID() {
    if (empty(self::$arSID)) {
      $sid_var = trim(variable_get('migrate_hotties_sid_list', ''));
      if (strlen($sid_var) > 0) {
        self::$arSID = explode(',', $sid_var);
      }
    }
    return self::$arSID;
  }
}

/*
 * 2014 Hotties Profiles migration
 */
class HottiesProfile2014Migration extends HometownHotties2014Migration {
  public function __construct() {
    parent::__construct();

    $this->description = t('Migrate hottie profiles 2014');

    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'sid' => t('Hottie GUID'),
    );

    // Use database view
    $query = db_select('migrate_hotties_2014', 'h')
      ->fields('h', array('sid','uid','photo_1','photo_2','photo_3','photo_4','photo_5','photo_6','photo_7','photo_8','photo_9','photo_10','entry_slotting','fb_referrer','contest_week','first_name','last_name','address','city','state','zip_code','hometown','hometown_zip','date_of_birth','phone_number','email_address','email_address_2','twitter_handle','facebook_id','instagram_handle','height','weight','measurements','relationship_status','profession','best_pickup_line','favorite_sport_team','movie_quote','favorite_videogame','song','party_trick','worst_job','danger_question','food_after','strangest_fridge','naughty_public','sexiest_clothes','tell_a_joke','piercings_tattoos','submitted'))
      ->condition('entry_slotting', 'yes');
    $arSIDs = ProfileWeek2014::getSID();
    if (!empty($arSIDs)) {
      $query->condition('h.sid', $arSIDs,'IN');
    } else {
      $query->condition('contest_week', ProfileWeek2014::getWeek());
    }
    $query->orderBy('sid', 'ASC');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('hotties_profile');

    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'sid' => array('type' => 'int',
                          'not null' => TRUE,
                          'description' => 'GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields
    $this->addFieldMapping('field_media_filemobile_user_id', 'sid');
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('status')->defaultValue(0);
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('field_profile_first_name', 'first_name');
    $this->addFieldMapping('field_profile_last_name', 'last_name');
    $this->addFieldMapping('field_profile_height', 'height');
    $this->addFieldMapping('field_profile_weight', 'weight');
    $this->addFieldMapping('field_profile_measurements', 'measurements') ->defaultValue(null);
    $this->addFieldMapping('field_profile_birthdate', 'date_of_birth')  ->defaultValue(null);
    $this->addFieldMapping('field_profile_phone', 'phone_number') ->defaultValue(null);
    $this->addFieldMapping('field_profile_email', 'email_address') ->defaultValue(null);
    $this->addFieldMapping('field_profile_twitter', 'twitter_handle') ->defaultValue(null);
    $this->addFieldMapping('field_profile_facebook', 'facebook_id') ->defaultValue(null);
    $this->addFieldMapping('field_profile_instagram', 'instagram_handle') ->defaultValue(null);
    $this->addFieldMapping('field_profile_address1', 'address')  ->defaultValue(null);
    $this->addFieldMapping('field_profile_city', 'city') ->defaultValue(null);
    $this->addFieldMapping('field_profile_state', 'state')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_zipcode', 'zip_code') ->defaultValue(null);

    $this->addFieldMapping('field_profile_country', 'country')
      ->defaultValue('USA');
    $this->addFieldMapping('field_profile_hometown', 'hometown')
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_hometown_zip', 'hometown_zip')
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_profession_misc', 'profession') ->defaultValue(null);

    // Contest Data
    $this->addFieldMapping('field_hotties_contest_week', 'contest_week')->defaultValue(null);
    $this->addFieldMapping('field_hotties_contest_year', 'contest_year')
      ->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('field_hotties_contest_status', 'hottie_status')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);

    $this->addFieldMapping('title', 'title');

    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'filtered_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'submitted');
    $this->addFieldMapping('published', 0);
    $this->addFieldMapping('field_channel', 'channel');

    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(), t('Do Not Migrate'));
  }

  /*
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    echo "\n" . 'user id: ' . $current_row->sid . "\n";

    $exclude_sids = explode(',', variable_get('migrate_hotties_exclude_sid', ''));
    if (in_array($current_row->sid, $exclude_sids)) {
      return FALSE;
    }

    $hometown_location = MigrationUtility2014::hometownLocation($current_row);
    $current_row->hometown = $hometown_location;

    if($current_row->height == ''){ $current_row->height = null; }
    if($current_row->weight == ''){
      $current_row->weight = null;
    } else {
      $current_row->weight = trim(str_replace('lbs.', '', $current_row->weight));
    }
    if($current_row->date_of_birth == '0000-00-00'){ $current_row->date_of_birth = null; }
    if($current_row->twitter_handle == ''){ $current_row->twitter_handle = null; }
    if($current_row->instagram_handle == ''){ $current_row->instagram_handle = null; }
    if($current_row->phone_number == ''){ $current_row->phone_number = null; }
    if($current_row->address == ''){ $current_row->address = null; }
    if($current_row->profession == ''){ $current_row->profession = null; }
    if($current_row->measurements == ''){ $current_row->measurements = null; }

    $current_row->contest_year = '2014';
    $current_row->channel = 'Hometown Hotties';
    $current_row->hottie_status = 'Contestant';
    $current_row->first_name = trim(ucwords(strtolower($current_row->first_name)));
    $current_row->city = trim(ucwords(strtolower($current_row->city)));

    $current_row->title = $current_row->first_name . ' - ' . $hometown_location;
    $current_row->body = MigrationUtility2014::buildBody($current_row);
    $current_row->state = MigrationUtility2014::getStateFromAbbr($current_row->state);

    switch($current_row->contest_week) {
      case 'week 1': $current_row->contest_week = 1; break;
      case 'week 2': $current_row->contest_week = 2; break;
      case 'week 3': $current_row->contest_week = 3; break;
      case 'week 4': $current_row->contest_week = 4; break;
      case 'week 5': $current_row->contest_week = 5; break;
    }
  }

  public function insertMainImage($entity, $source_row){
    // Insert main image
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'u.entity_id=f.fid');
    $query->fields('f', array('fid'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('u.bundle', 'image')
      ->orderBy('fid', 'ASC')
      ->range(0,1);
    $qryResults = $query->execute();

    foreach ($qryResults as $record){

    $arField = array(
      'entity_type' => 'node',
      'bundle' => 'hotties-profile',
      'entity_id' => $entity->nid,
      'revision_id' => $entity->vid,
      'delta' => 0,
      'language' => 'und',
      'field_main_image_fid' => $record->fid,
    );

    $fid = db_merge('field_data_field_main_image')
      ->key(array('entity_id' => $entity->nid))
      ->fields($arField)
      ->execute();
    $rid = db_merge('field_revision_field_main_image')
      ->key(array('entity_id' => $entity->nid))
      ->fields($arField)
      ->execute();
    }
  }

  public function insertLocation($entity, $source_row){
    $name = ucwords(strtolower($source_row->first_name));
    $zip_code = null;
    $city = null;
    $state = null;
    $latitude = null;
    $longitude = null;

    $locationFromZip = MigrationUtility2014::getLocationByZip($source_row->hometown_zip);
    if (strlen($locationFromZip['city'])) {
      $city = $locationFromZip['city'];
    }
    if (strlen($locationFromZip['state'])) {
      $state = $locationFromZip['state'];
    }
    if (strlen($locationFromZip['latitude'])) {
      $latitude = $locationFromZip['latitude'];
    }
    if (strlen($locationFromZip['longitude'])) {
      $longitude = $locationFromZip['longitude'];
    }
    /*if (strlen($source_row->city)) {
      $city = ucwords(strtolower($source_row->city));
    }
    if (strlen($source_row->state)) {
      $state = MigrationUtility2014::getStateAbbr($source_row->state);
    }*/
    if (strlen($source_row->hometown_zip)) {
      $zip_code = $source_row->hometown_zip;
    }

    if (strlen)
    $location_id = db_insert('location')
      ->fields(array(
        'name' => $name,
        'city' => $city,
        'province' => $state,
        'postal_code' => $zip_code,
        'latitude' => $latitude,
        'longitude' => $longitude,
        'country' => 'us',
      ))
      ->execute();
    db_insert('location_instance')
      ->fields(array(
        'nid' => $entity->nid,
        'vid' => $entity->vid,
        'lid' => $location_id,
      ))
      ->execute();
  }

  public function complete($entity, stdClass $source_row){
    // Insert main image
    $this->insertMainImage($entity, $source_row);
    $this->insertLocation($entity, $source_row);
  }

  public function insertNodeRef($entity_type, $bundle, $entity_id, $rev_id, $field_name, $noderef_id, $delta){
    $arField = array(
      'entity_type' => $entity_type,
      'bundle' => $bundle,
      'entity_id' => $entity_id,
      'revision_id' => $rev_id,
      'delta' => $delta,
      'language' => 'und'
    );

    $arField[$field_name . '_nid'] = $noderef_id;

    $fid = db_insert('field_data_' . $field_name)
      ->fields($arField)
      ->execute();
    $rid = db_insert('field_revision_' . $field_name)
     ->fields($arField)
     ->execute();
  }

  /*
   * Rollback function
   */
  public function preRollback() {


  }

}

class MediaHottie2014Migration extends HometownHotties2014Migration {

  public function __construct(){
    parent::__construct();
    $this->description = t('Hometown Hotties images');
    $this->map = new MigrateSQLMap($this->machineName,
        array('fid' => array(
                'type' => 'int',
                'not null' => TRUE,
                'description' => 'Hometown Hottie File ID',
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );

    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'fid' => t('Image GUID'),
    );

    // Database query
    $query = db_select('migrate_hotties_files_2014', 'f');
    $query->fields('f', array('sid', 'fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp', 'type', 'rank'));
    $query->leftJoin('migrate_hotties_2014', 'h', 'f.sid = h.sid');
    $query->fields('h', array('first_name', 'city', 'state', 'hometown', 'hometown_zip'))
      ->condition('entry_slotting', 'yes');
    $arSIDs = ProfileWeek2014::getSID();
    if (!empty($arSIDs)) {
      $query->condition('h.sid', $arSIDs,'IN');
    } else {
      $query->condition('contest_week', ProfileWeek2014::getWeek());
    }
    $query->orderBy('f.sid', 'ASC')
      ->orderBy('rank', 'ASC');
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // TIP: Set copy_file to copy the file from its source (which could be a
    // remote server, i.e. the uri is of the form http://example.com/images/foo.jpg).
    $dest_options = array('copy_file' => FALSE, 'preserve_files' => TRUE);
    $this->destination = new MigrateDestinationFile($dest_options);

    // Just map the incoming URL to the destination's 'uri'

    $this->addFieldMapping('uri', 'targetURI');
    $this->addFieldMapping('filemime','filemime');
    $this->addFieldMapping('filename','filename');
    $this->addFieldMapping('timestamp','timestamp');
    $this->addFieldMapping('status', 'status')->defaultValue(1);

    $this->addFieldMapping('uid')->defaultValue(1);

    $this->addUnmigratedDestinations(array());
  }

  /*
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $exclude_sids = explode(',', variable_get('migrate_hotties_exclude_sid', ''));
    if (in_array($current_row->sid, $exclude_sids)) {
      return FALSE;
    }

    $this->copyHottieFile($current_row);

    // After the 3rd image, do not insert into database
    if ($current_row->rank > 3) {
      return FALSE;
    }
    $hometown_location = MigrationUtility2014::hometownLocation($current_row);

    $current_row->timestamp = Migration::timestamp($current_row->timestamp);
    $current_row->first_name = ucwords(strtolower($current_row->first_name));
    $current_row->description = $current_row->first_name . ' - ' . $hometown_location . ', ' . ' - 2014 Hometown Hottie Contestant';
    echo 'old fid:' . $current_row->fid . "\n";
  }

  private function copyHottieFile($current_row){
    $hometown_location = MigrationUtility2014::hometownLocation($current_row);
    $hometown_location = str_replace(',', '', $hometown_location);
    $hometown_location = str_replace(' ', '_', trim($hometown_location));

    $source = $current_row->uri;
    $infoSource = pathinfo($source);
    $dest_filename =  $current_row->sid . '_' . str_replace(' ', '_', trim($current_row->first_name)) . '_' .
       $hometown_location . '_' . $current_row->rank . '.' . $infoSource['extension'];
    $destination = 'public://hotties/2014/' . strtolower($dest_filename);
    echo "\n" . $source . "\n" .  $destination . "\n";
    file_unmanaged_copy($source, $destination, $replace = FILE_EXISTS_REPLACE);
    $current_row->targetURI = $destination;
    $current_row->filename = strtolower($dest_filename);
  }

  public function complete($entity, stdClass $source_row){
   echo 'new fid: ' . $entity->fid . "\n";
    $this->insertField($entity->fid, 'image', 'field_image_type', 'Photograph');
    $this->insertField($entity->fid, 'image', 'field_image_promotional', 0);
    $this->insertField($entity->fid, 'image', 'field_image_origin', 'Original');
    $this->insertField($entity->fid, 'image', 'field_media_filemobile_id', $source_row->fid);
    $this->insertField($entity->fid, 'image', 'field_media_filemobile_user_id', $source_row->sid);
    $this->insertField($entity->fid, 'image', 'field_media_description', t($source_row->description), 'plain_text');
    $this->insertField($entity->fid, 'image', 'field_media_source_url', $source_row->uri);
 }

  public function insertField($entity_id, $bundle, $field_name, $field_value, $field_format = null){
    $arField = array(
        'entity_type' => 'file',
        'bundle' => $bundle,
        'revision_id' => $entity_id,
        'delta' => 0,
        'language' => 'und'
     );

     $arField[$field_name . '_value'] = $field_value;
     if(strlen($field_format)){
      $arField[$field_name . '_format'] = $field_format;
     }

    $fid = db_merge('field_data_' . $field_name)
     ->key(array('entity_id' => $entity_id))
     ->fields($arField)
     ->execute();
    $rid = db_merge('field_revision_' . $field_name)
     ->key(array('entity_id' => $entity_id))
     ->fields($arField)
     ->execute();
  }
}


/*
 * Slideshow Node migration
 */
class HottieSlideshow2014Migration extends HometownHotties2014Migration {

  public function __construct() {
    parent::__construct();

    // Instantiate Maxim Process
    $this->maximObj = new Maxim_Process();

    $this->description = t('Create hotties slideshow');

    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'fid' => t('Hotties GUID'),
    );

    // Database query
    $query = db_select('migrate_hotties_files_2014', 'f');
    $query->fields('f', array('sid', 'fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp', 'type', 'rank'));
    $query->leftJoin('migrate_hotties_2014', 'h', 'f.sid = h.sid');
    $query->fields('h', array('sid','entry_slotting','first_name','state', 'city', 'hometown','hometown_zip','best_pickup_line','favorite_sport_team','movie_quote','favorite_videogame','song','party_trick','worst_job','danger_question','food_after','strangest_fridge','naughty_public','sexiest_clothes','tell_a_joke','piercings_tattoos','submitted'))
      ->condition('entry_slotting', 'yes');
      $arSIDs = ProfileWeek2014::getSID();
      if (!empty($arSIDs)) {
        $query->condition('h.sid', $arSIDs,'IN');
      } else {
        $query->condition('contest_week', ProfileWeek2014::getWeek());
      }
      $query->orderBy('f.sid', 'ASC')
      ->orderBy('rank', 'ASC');
    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('slideshow');

    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'sid' => array('type' => 'int',
                          'not null' => TRUE,
                          'description' => 'Hotties GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('status')->defaultValue(0);
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('title', 'title');

    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'filtered_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'submitted');

    $this->addFieldMapping('field_media_filemobile_user_id', 'sid');
    $this->addFieldMapping('field_channel', 'channel');

    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(), t('Do Not Migrate'));
  }

  /*
   * Prepare row before migration
   */
  public function prepareRow($current_row) {

    $exclude_sids = explode(',', variable_get('migrate_hotties_exclude_sid', ''));
    if (in_array($current_row->sid, $exclude_sids)) {
      return FALSE;
    }

    //$current_row = $this->maximObj->prepareContent($current_row);
    $hometown_location = MigrationUtility2014::hometownLocation($current_row);
    $current_row->first_name = ucwords(strtolower($current_row->first_name));
    $current_row->title = $current_row->first_name . ' - ' . $hometown_location;
    $current_row->channel = 'Hometown Hotties';
    $current_row->body = MigrationUtility2014::buildBody($current_row);
  }


  public function insertMainImage($entity, $source_row){
    // Insert main image
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'u.entity_id=f.fid');
    $query->fields('f', array('fid'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('u.bundle', 'image')
      ->orderBy('fid', 'ASC')
      ->range(0,1);
    $qryResults = $query->execute();

    foreach ($qryResults as $record){

    $arField = array(
      'entity_type' => 'node',
      'bundle' => 'slideshow',
      'entity_id' => $entity->nid,
      'revision_id' => $entity->vid,
      'delta' => 0,
      'language' => 'und',
      'field_main_image_fid' => $record->fid,
    );

    $fid = db_merge('field_data_field_main_image')
      ->key(array('entity_id' => $entity->nid))
      ->fields($arField)
      ->execute();
    $rid = db_merge('field_revision_field_main_image')
      ->key(array('entity_id' => $entity->nid))
      ->fields($arField)
      ->execute();
    }
  }

  public function complete($entity, stdClass $source_row){
    // Insert main image
    $this->insertMainImage($entity, $source_row);

    // Retrieve slides
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'u.entity_id=f.fid');
    $query->leftJoin('migrate_hotties_2014', 'h', 'u.field_media_filemobile_user_id_value = h.sid');
    $query->fields('f', array('fid'))
      ->fields('h', array('first_name', 'city', 'state'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('u.bundle', 'image')
      ->orderBy('fid', 'ASC');
    $qryResults = $query->execute();

    echo 'entity: '. $entity->nid . ' - user -' . $source_row->sid . "\n";

    $ct=0;
    /* Loop thru slides and add tables.  Create only 3 slides. */
    foreach ($qryResults as $record){
      echo 'slides';
      if ($ct < 3) {
        var_dump($record);
        $this->insertSlide($entity, $source_row, $ct++, $record->fid, $record->sid, '', '');
      } else {
        break;
      }
    }

    /* Do not include in xml sitemap */
    $numUpdated = db_update('xmlsitemap')
      ->fields(array(
        'status' => 0,
        'status_override' => 1,
      ))
      ->condition('loc','node/'.$entity->nid)
      ->execute();
    echo 'xmlsitemap updated (' . $numUpdated  .')' . "\n";

    // Relate slideshows to Profile
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'n.nid = u.entity_id');
    $qryResults = $query->fields('n', array('nid', 'vid', 'type'))
      ->fields('u', array('entity_id', 'field_media_filemobile_user_id_value'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('type', 'hotties_profile')
      ->execute();

    echo 'slideshow node: '. $entity->nid . "\n";

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'node: ' . $record->nid  . "\n";
      $this->insertNodeRef('node', 'hotties_profile', $record->nid, $record->vid, 'field_profile_ref_slideshow', $entity->nid, $ct++);
    }
  }

  public function insertNodeRef($entity_type, $bundle, $entity_id, $rev_id, $field_name, $noderef_id, $delta){
    $arField = array(
      'entity_type' => $entity_type,
      'bundle' => $bundle,
      'entity_id' => $entity_id,
      'revision_id' => $rev_id,
      'delta' => $delta,
      'language' => 'und'
    );

    $arField[$field_name . '_nid'] = $noderef_id;

    $fid = db_insert('field_data_' . $field_name)
      ->fields($arField)
      ->execute();
    $rid = db_insert('field_revision_' . $field_name)
     ->fields($arField)
     ->execute();
  }

  public function insertSlide($entity, $source_row, $field_delta, $file_id, $record_id, $title, $caption){
    // Insert into field_collection_item
      $qryInsert = "INSERT INTO {field_collection_item} (field_name) VALUES (:fieldname)";
      $args = array(':fieldname' => 'field_slides_wrapper');
      $item_id = db_query($qryInsert, $args, array('return' => Database::RETURN_INSERT_ID));

    // Insert into field_slides_wrapper
    $arField = array(
        'entity_type' => 'node',
        'bundle' => 'slideshow',
        'entity_id' => $entity->nid,
        'revision_id' => $entity->vid,
        'delta' => $field_delta,
        'language' => 'und',
        'field_slides_wrapper_value' => $item_id,
     );

    $insertData = db_insert('field_data_field_slides_wrapper' . $field_name)
     ->fields($arField)
     ->execute();
    $insertRev = db_insert('field_revision_field_slides_wrapper' . $field_name)
     ->fields($arField)
     ->execute();

    // Insert field_slides
    $arField = array(
      'entity_type' => 'field_collection_item',
      'bundle' => 'field_slide_wrapper',
      'entity_id' => $item_id,
      'revision_id' => $item_id,
      'language' => 'und',
      'delta' => 0,
      'field_slides_display' => 1,
      'field_slides_fid' => $file_id,
      'field_slides_description' => $record_id,
    );

    $insertData = db_insert('field_data_field_slides')
     ->fields($arField)
     ->execute();
    $insertRev = db_insert('field_revision_field_slides')
     ->fields($arField)
     ->execute();

    // Insert field_slide_title
    // Check to see if the image has a title
    if(strlen($title) > 0){
       $arField = array(
          'entity_type' => 'field_collection_item',
          'bundle' => 'field_slide_wrapper',
          'entity_id' => $item_id,
          'revision_id' => $item_id,
          'language' => 'und',
          'delta' => 0,
          'field_slide_title_value' => $title,
          'field_slide_title_format' => 'filtered_html',
       );

      $insertData = db_insert('field_data_field_slide_title')
       ->fields($arField)
       ->execute();
      $insertRev = db_insert('field_revision_field_slide_title')
       ->fields($arField)
       ->execute();
    }

    // Insert field_slide_caption
    // Check to see if the image has a description
    if(strlen($caption) > 0){
       $arField = array(
          'entity_type' => 'field_collection_item',
          'bundle' => 'field_slide_wrapper',
          'entity_id' => $item_id,
          'revision_id' => $item_id,
          'language' => 'und',
          'delta' => 0,
          'field_slide_caption_value' => $caption,
          'field_slide_caption_format' => 'filtered_html',
       );

      $insertData = db_insert('field_data_field_slide_caption')
       ->fields($arField)
       ->execute();
      $insertRev = db_insert('field_revision_field_slide_caption')
       ->fields($arField)
       ->execute();
    }

  }

}

/*
 * Migration utility functions
 */
class MigrationUtility2014 {

  public function hometownLocation($current_row) {
    $hometown = '';

    $arHometown = MigrationUtility2014::getLocationByZip($current_row->hometown_zip);
    $hometownFromZip = $arHometown['hometown'];

    if (strlen($hometownFromZip) > 0) {
      $hometown = $hometownFromZip;
    } else {
      if (strlen($current_row->hometown) > 0) {
        $hometown = $current_row->hometown;
      } else {
        $hometown = $current_row->city . ', ' . $current_row->state;
      }
    }

    return $hometown;
  }


  public function getLocationByZip($zip) {
    $location = array();
    $location['city'] = '';
    $location['state'] = '';
    $location['hometown'] = '';
    $location['latitude'] = '';
    $location['longitude'] = '';
    $qryResults = db_select('zipcodes', 'z')
      ->fields('z', array('zip','city','state','longitude','latitude'))
      ->condition('zip', $zip)
      ->execute();

    if ($qryResults->rowCount() > 0) {
      foreach ($qryResults as $record) {
        $location['city'] = $record->city;
        $location['state'] = $record->state;
        $location['hometown'] = $record->city . ', ' . $record->state;
        $location['latitude'] = $record->latitude;
        $location['longitude'] = $record->longitude;
        break;
      }
    }
    return $location;
  }

  public function buildBody($current_row){
    $strBody = '<h2>' . trim(ucwords(strtolower($current_row->first_name))) . "'s Q &amp; A</h2>";

    if(strlen($current_row->favorite_sport_team) > 0){
      $strBody .= '<p><strong>Who\'s your favorite sports team, and why?</strong><br />' . $current_row->favorite_sport_team . '</p>';
    }
    if(strlen($current_row->movie_quote) > 0){
      $strBody .= '<p><strong>What\'s your favorite movie quote?</strong><br />' . $current_row->movie_quote . '</p>';
    }
    if(strlen($current_row->favorite_videogame) > 0){
      $strBody .= '<p><strong>What\'s your favorite video game, and could you kick our butts at it?</strong><br />' . $current_row->favorite_videogame . '</p>';
    }
    if(strlen($current_row->piercings_tattoos) > 0){
      $strBody .= '<p><strong>Piercings/Tattoos (How many? Where?)</strong><br />' . $current_row->piercings_tattoos . '</p>';
    }
    if(strlen($current_row->song) > 0){
      $strBody .= '<p><strong>What\'s the most embarrassing song on your iPod?</strong><br />' . $current_row->song . '</p>';
    }
    if(strlen($current_row->party_trick) > 0){
      $strBody .= '<p><strong>What\'s your best party trick?</strong><br />' . $current_row->party_trick . '</p>';
    }
    if(strlen($current_row->best_pickup_line) > 0){
      $strBody .= '<p><strong>What\'s the most memorable pick-up line you\'ve ever heard?</strong><br />' . $current_row->best_pickup_line . '</p>';
    }
    if(strlen($current_row->worst_job) > 0){
      $strBody .= "<p><strong>What's the worst job you've ever had?</strong><br />" . $current_row->worst_job . '</p>';
    }
    if(strlen($current_row->danger_question) > 0){
      $strBody .= "<p><strong>What's the most dangerous thing you've ever done?</strong><br />" . $current_row->danger_question . '</p>';
    }
    if(strlen($current_row->food_after) > 0){
      $strBody .= '<p><strong>It\'s 4AM after a crazy night out – what are we eating?</strong><br />' . $current_row->food_after . '</p>';
    }
    if(strlen($current_row->strangest_fridge) > 0){
      $strBody .= "<p><strong>What's the strangest thing in your fridge right now?</strong><br />" . $current_row->strangest_fridge . '</p>';
    }
    if(strlen($current_row->naughty_public) > 0){
      $strBody .= "<p><strong>What's the naughtiest thing you've ever done in public?</strong><br />" . $current_row->naughty_public . '</p>';
    }
    if(strlen($current_row->sexiest_clothes) > 0){
      $strBody .= "<p><strong>What do you feel sexiest wearing?</strong><br />" . $current_row->sexiest_clothes . '</p>';
    }
    if(strlen($current_row->tell_a_joke) > 0){
      $strBody .= "<p><strong>Tell us a joke.</strong><br />" . $current_row->tell_a_joke . '</p>';
    }

    return $strBody;
  }

  public function getStatefromAbbr($state_abbr){
    switch($state_abbr){
      case 'AL': $state = 'Alabama'; break;
      case 'AK': $state = 'Alaska'; break;
      case 'AZ': $state = 'Arizona'; break;
      case 'AR': $state = 'Arkansas'; break;
      case 'CA': $state = 'California'; break;
      case 'CO': $state = 'Colorado'; break;
      case 'CT': $state = 'Connecticut'; break;
      case 'DE': $state = 'Delaware'; break;
      case 'DC': $state = 'District of Columbia'; break;
      case 'FL': $state = 'Florida'; break;
      case 'GA': $state = 'Georgia'; break;
      case 'HI': $state = 'Hawaii'; break;
      case 'ID': $state = 'Idaho'; break;
      case 'IL': $state = 'Illinois'; break;
      case 'IN': $state = 'Indiana'; break;
      case 'IA': $state = 'Iowa'; break;
      case 'KS': $state = 'Kansas'; break;
      case 'KY': $state = 'Kentucky'; break;
      case 'LA': $state = 'Louisiana'; break;
      case 'ME': $state = 'Maine'; break;
      case 'MD': $state = 'Maryland'; break;
      case 'MA': $state = 'Massachusetts'; break;
      case 'MI': $state = 'Michigan'; break;
      case 'MN': $state = 'Minnesota'; break;
      case 'MS': $state = 'Mississippi'; break;
      case 'MO': $state = 'Missouri'; break;
      case 'MT': $state = 'Montana'; break;
      case 'NE': $state = 'Nebraska'; break;
      case 'NV': $state = 'Nevada'; break;
      case 'NH': $state = 'New Hampshire'; break;
      case 'NJ': $state = 'New Jersey'; break;
      case 'NM': $state = 'New Mexico'; break;
      case 'NY': $state = 'New York'; break;
      case 'NC': $state = 'North Carolina'; break;
      case 'ND': $state = 'North Dakota'; break;
      case 'OH': $state = 'Ohio'; break;
      case 'OK': $state = 'Oklahoma'; break;
      case 'OR': $state = 'Oregon'; break;
      case 'PA': $state = 'Pennsylvania'; break;
      case 'RI': $state = 'Rhode Island'; break;
      case 'SC': $state = 'South Carolina'; break;
      case 'SD': $state = 'South Dakota'; break;
      case 'TN': $state = 'Tennessee'; break;
      case 'TX': $state = 'Texas'; break;
      case 'UT': $state = 'Utah'; break;
      case 'VT': $state = 'Vermont'; break;
      case 'VA': $state = 'Virginia'; break;
      case 'WA': $state = 'Washington'; break;
      case 'WV': $state = 'West Virginia'; break;
      case 'WI': $state = 'Wisconsin'; break;
      case 'WY': $state = 'Wyoming'; break;
    }
    return $state;
  }

  public function getStateAbbr($state){
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
    }
    return $state_abbr;
  }

}
