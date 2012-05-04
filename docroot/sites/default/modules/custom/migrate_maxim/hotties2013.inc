<?php

abstract class HometownHotties2013Migration extends Migration {

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

/*
 * 2013 Hotties Profiles migration
 */
class HottiesProfile2013Migration extends HometownHotties2013Migration {
  public function __construct() {
    parent::__construct();
      
    $this->description = t('Migrate hottie profiles 2013');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'sid' => t('Hottie GUID'),
    );

    // Use database view
    $query = db_select('migrate_hotties_2013', 'h')
      ->fields('h', array('sid', 'photo_1', 'photo_2', 'photo_3', 'photo_4', 'photo_5', 'photo_6', 'photo_7', 'photo_8', 'photo_9', 'photo_10', 'entry_slotting', 'fb_referrer', 'contest_week', 'hometown', 'date_of_birth', 'phone_number', 'email_address', 'first_name', 'last_name', 'address', 'state', 'city', 'zip_code', 'twitter_handle', 'facebook_id', 'resident_status', 'height', 'weight', 'measurements', 'profession', 'first_job', 'karaoke_song', 'favorite_sport_team', 'favorite_movie_actor', 'piercings_tattoos', 'mac_or_pc', 'gaming_prefs', 'talents', 'best_pick_up_line', 'craziest_thing', 'hookup_place', 'whats_in_pocket', 'most_comfortable_wearing', 'sex_pref', 'relationship_status', 'read_rules', 'photo_rights', 'additional_info', 'cuervo_shot', 'referral_code', 'submitted', 'remote_addr'))
      ->condition('entry_slotting', 'yes')
      ->isNotNull('contest_week')
      ->orderBy('sid', 'ASC');

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
    $this->addFieldMapping('field_profile_geo_latitude', 'geo_latitude')->defaultValue(null);
    $this->addFieldMapping('field_profile_geo_longitude', 'geo_longitude')->defaultValue(null);

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
    if($current_row->height == ''){ $current_row->height = null; }
    if($current_row->weight == ''){ 
      $current_row->weight = null; 
    } else {
      $current_row->weight = trim(str_replace('lbs.', '', $current_row->weight));
    }
    if($current_row->date_of_birth == '0000-00-00'){ $current_row->date_of_birth = null; }
    if($current_row->twitter_handle == ''){ $current_row->twitter_handle = null; }
    if($current_row->phone_number == ''){ $current_row->phone_number = null; }
    if($current_row->address == ''){ $current_row->address = null; }
    if($current_row->profession == ''){ $current_row->profession = null; }
    if($current_row->measurements == ''){ $current_row->measurements = null; }

    $current_row->contest_year = '2013';
    $current_row->channel = 'Hometown Hotties';
    $current_row->hottie_status = 'Contestant';
    $current_row->first_name = trim(ucwords(strtolower($current_row->first_name)));
    $current_row->city = trim(ucwords(strtolower($current_row->city)));

    $current_row->title = $current_row->first_name . ' - ' . $current_row->city . ', ' . $current_row->state;
    $current_row->body = MigrationUtility::buildBody($current_row);
    $current_row->state = MigrationUtility::getStateFromAbbr($current_row->state);

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
    if (strlen($source_row->city)) {
      $city = ucwords(strtolower($source_row->city));
    }
    if (strlen($source_row->state)) {
      $state = MigrationUtility::getStateAbbr($source_row->state);
    }
    if (strlen($source_row->zip_code)) {
      $zip_code = $source_row->zip_code;
    }
    
    $location_id = db_insert('location')
      ->fields(array(
        'name' => $name,
        'city' => $city,
        'province' => $state,
        'postal_code' => $zip_code,
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

    // Relate slideshows
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'n.nid = u.entity_id');
    $qryResults = $query->fields('n', array('nid', 'vid', 'type'))
      ->fields('u', array('entity_id', 'field_media_filemobile_user_id_value'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('type', 'slideshow')
      ->execute();

    echo 'profile node: '. $entity->nid . "\n"; 

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'slideshow: ' . $record->entity_id  . "\n";
      $this->insertNodeRef('node', 'hotties_profile', $entity->nid, $entity->vid, 'field_profile_ref_slideshow', $record->entity_id, $ct++);
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
  
  /*
   * Rollback function
   */
  public function preRollback() {


  }

}

class MediaHottie2013Migration extends HometownHotties2013Migration {

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
    $query = db_select('migrate_hotties_files_2013', 'f');
    $query->fields('f', array('sid', 'fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp', 'type', 'rank'));
    $query->leftJoin('migrate_hotties_2013', 'h', 'f.sid = h.sid');
    $query->fields('h', array('first_name', 'city', 'state'))
      ->condition('entry_slotting', 'yes')
      ->isNotNull('contest_week')
      ->orderBy('f.sid', 'ASC')
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
    $this->copyHottieFile($current_row);
    $current_row->timestamp = Migration::timestamp($current_row->timestamp);
    $current_row->first_name = ucwords(strtolower($current_row->first_name));
    $current_row->description = 'Hometown Hottie Contestant 2013: ' . $current_row->first_name . ' - ' . ucwords(strtolower($current_row->city)) . ', ' . $current_row->state;
    echo 'old fid:' . $current_row->fid . "\n";
  }

  private function copyHottieFile($current_row){
    $source = $current_row->uri;
    $infoSource = pathinfo($source);
    $dest_filename =  $current_row->sid . '_' . str_replace(' ', '_', trim($current_row->first_name)) . '_' .
       str_replace(' ', '_', trim($current_row->city)) . '_' . $current_row->state . '_' . $current_row->rank . '.' . $infoSource['extension'];
    $destination = 'public://hotties/2013/' . strtolower($dest_filename);
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
class HottieSlideshow2013Migration extends HometownHotties2013Migration {
  
  public function __construct() {
    parent::__construct();
    
    // Instantiate Maxim Process
    $this->maximObj = new Maxim_Process();
        
    $this->description = t('Migrate hotties slideshow from filemobile');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'fid' => t('Hotties GUID'),
    );

    // Database query
    $query = db_select('migrate_hotties_files_2013', 'f');
    $query->fields('f', array('sid', 'fid', 'filename', 'uri', 'filemime', 'filesize', 'status', 'timestamp', 'type', 'rank'));
    $query->leftJoin('migrate_hotties_2013', 'h', 'f.sid = h.sid');
    $query->fields('h', array('sid', 'entry_slotting','hometown', 'date_of_birth', 'first_name', 'state', 'city', 'resident_status', 'height', 'weight', 'measurements', 'profession', 'first_job', 'karaoke_song', 'favorite_sport_team', 'favorite_movie_actor', 'piercings_tattoos', 'mac_or_pc', 'gaming_prefs', 'talents', 'best_pick_up_line', 'craziest_thing', 'hookup_place', 'whats_in_pocket', 'most_comfortable_wearing', 'sex_pref', 'relationship_status', 'cuervo_shot', 'submitted'))
      ->condition('entry_slotting', 'yes')
      ->isNotNull('contest_week')
      ->orderBy('f.sid', 'ASC')
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
    //$current_row = $this->maximObj->prepareContent($current_row);
    $current_row->first_name = ucwords(strtolower($current_row->first_name));
    $current_row->city = ucwords(strtolower($current_row->city));
    $current_row->title = $current_row->first_name . ' - ' . $current_row->city . ', ' . $current_row->state;
    $current_row->channel = 'Hometown Hotties';
    $current_row->body = MigrationUtility::buildBody($current_row);
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
    $query->leftJoin('migrate_hotties_2013', 'h', 'u.field_media_filemobile_user_id_value = h.sid');
    $query->fields('f', array('fid'))
      ->fields('h', array('first_name', 'city', 'state'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->sid)
      ->condition('u.bundle', 'image')
      ->orderBy('fid', 'ASC');
    $qryResults = $query->execute();

    echo 'entity: '. $entity->nid . ' - user -' . $source_row->sid;

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'slides';
      var_dump($record);
      $this->insertSlide($entity, $source_row, $ct++, $record->fid, $record->sid, '', '');
    }
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
class MigrationUtility {

  public function buildBody($current_row){
    $strBody = '<h2>' . trim(ucwords(strtolower($current_row->first_name))) . "'s Q &amp; A</h2>";

    if(strlen($current_row->favorite_sport_team) > 0){
      $strBody .= '<p><strong>Favorite Sport/Team</strong><br />' . $current_row->favorite_sport_team . '</p>';
    }
    if(strlen($current_row->favorite_movie_actor) > 0){
      $strBody .= '<p><strong>Favorite Movie/Actor</strong><br />' . $current_row->favorite_movie_actor . '</p>';
    }
    if(strlen($current_row->karaoke_song) > 0){
      $strBody .= '<p><strong>Go-to karaoke song</strong><br />' . $current_row->karaoke_song . '</p>';
    }
    if(strlen($current_row->first_job) > 0){
      $strBody .= '<p><strong>My first job</strong><br />' . $current_row->first_job . '</p>';
    }
    if(strlen($current_row->piercings_tattoos) > 0){
      $strBody .= '<p><strong>Piercings/Tattoos (How many? Where?)</strong><br />' . $current_row->piercings_tattoos . '</p>';
    }
    if(strlen($current_row->mac_or_pc) > 0){
      $strBody .= '<p><strong>Mac or PC?</strong><br />' . $current_row->mac_or_pc . '</p>';
    }
    if(strlen($current_row->gaming_prefs) > 0){
      $strBody .= "<p><strong>Nintendo, Xbox 360, PS3, or don't game?</strong><br />" . $current_row->gaming_prefs . '</p>';
    }
    if(strlen($current_row->talents) > 0){
      $strBody .= '<p><strong>What fun fact, talent or superpower of yours should guys know about?</strong><br />' . $current_row->talents . '</p>';
    }
    if(strlen($current_row->best_pick_up_line) > 0){
      $strBody .= "<p><strong>What's the most memorable pick up line you've ever heard?</strong><br />" . $current_row->best_pick_up_line . '</p>';
    }
    if(strlen($current_row->craziest_thing) > 0){
      $strBody .= "<p><strong>What's the craziest thing you've ever done?</strong><br />" . $current_row->craziest_thing . '</p>';
    }
    if(strlen($current_row->hookup_place) > 0){
      $strBody .= "<p><strong>What's the most unusual place you've ever hooked up? How'd it go?</strong><br />" . $current_row->hookup_place . '</p>';
    }
    if(strlen($current_row->whats_in_pocket) > 0){
      $strBody .= "<p><strong>What's in your purse or pocket right now?</strong><br />" . $current_row->whats_in_pocket . '</p>';
    }
    if(strlen($current_row->most_comfortable_wearing) > 0){
      $strBody .= "<p><strong>What do you feel most comfortable wearing?</strong><br />" . $current_row->most_comfortable_wearing . '</p>';
    }
    if(strlen($current_row->sex_pref) > 0){
      $strBody .= "<p><strong>Would you rather have boring sex all the time or an amazing romp once a year?</strong><br />" . $current_row->sex_pref . '</p>';
    }
    if(strlen($current_row->cuervo_shot) > 0){
      $strBody .= "<p><strong>If you could do a shot of Jose Cuervo with anyone -- dead or alive -- who would it be?</strong><br />" . $current_row->cuervo_shot . '</p>';
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
