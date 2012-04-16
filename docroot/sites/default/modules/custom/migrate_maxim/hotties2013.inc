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
class HottiesProfile2013Migration extends HometownHottiesMigration {
  
  public function __construct() {
    parent::__construct();
      
    $this->description = t('Migrate hottie profiles 2013');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'sid' => t('Hottie GUID'),
    );

    // Use database view
    $query = db_select('migrate_hotties_2013', 'h')
      ->fields('h', array('sid', 'photo_1', 'photo_2', 'photo_3', 'photo_4', 'photo_5', 'photo_6', 'photo_7', 'photo_8', 'photo_9', 'photo_10', 'entry_slotting', 'fb_referrer', 'contest_week', 'hometown', 'date_of_birth', 'phone_number', 'email_address', 'first_name', 'last_name', 'address', 'state', 'city', 'zip_code', 'twittle_handle', 'facebook_id', 'resident_status', 'height', 'weight', 'measurements', 'profession', 'first_job', 'karaoke_song', 'favorite_sport_team', 'favorite_movie_actor', 'piercings_tattoos', 'mac_or_pc', 'gaming_prefs', 'talents', 'best_pick_up_line', 'craziest_thing', 'hookup_place', 'whats_in_pocket', 'most_comfortable_wearing', 'sex_pref', 'relation_status', 'read_rules', 'photo_rights', 'additional_info', 'cuervo_shot', 'referral_code', 'submitted', 'remote_addr'))
      ->orderBy('sid', 'ASC');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('hotties_profile');
    
    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'id' => array('type' => 'int',
                          'not null' => TRUE,
                          'description' => 'GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('field_media_filemobile_user_id', 'id');
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('field_profile_first_name', 'firstname');
    $this->addFieldMapping('field_profile_last_name', 'lastname');
    $this->addFieldMapping('field_profile_height', 'height');
    $this->addFieldMapping('field_profile_weight', 'weight');
    $this->addFieldMapping('field_profile_measurements', 'measurement') ->defaultValue(null);
    $this->addFieldMapping('field_profile_birthdate', 'birthdate')  ->defaultValue(null);
    $this->addFieldMapping('field_profile_phone', 'phone') ->defaultValue(null);
    $this->addFieldMapping('field_profile_email', 'email') ->defaultValue(null);
    $this->addFieldMapping('field_profile_twitter', 'twitter') ->defaultValue(null);
    $this->addFieldMapping('field_profile_address1', 'address1')  ->defaultValue(null);
    $this->addFieldMapping('field_profile_city', 'city') ->defaultValue(null);
    $this->addFieldMapping('field_profile_state', 'state')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_country', 'country')
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_geo_latitude', 'geo_latitude');
    $this->addFieldMapping('field_profile_geo_longitude', 'geo_longitude');
    $this->addFieldMapping('field_profile_hair_color', 'haircolor')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_eye_color', 'eyecolor')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_profession_misc', 'profession') ->defaultValue(null);

    // Contest Data
    $this->addFieldMapping('field_hotties_contest_week', 'week')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_hotties_contest_year', 'contest_year')
      ->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('field_hotties_contest_status', 'hottie_status')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    //$this->addFieldMapping('field_hotties_finalist_place', 'finalist_place');

    $this->addFieldMapping('title', 'title');
    
    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'created');

    $this->addFieldMapping('field_filemobile_user_id', 'id');
    $this->addFieldMapping('field_channel', 'channel');

    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    echo "\n" . 'user id: ' . $current_row->id . "\n";
    $current_row->eyecolor = trim(strtolower($current_row->eyecolor));
    $current_row->haircolor = trim(strtolower($current_row->haircolor));
    if($current_row->eyecolor == 'd' || $current_row->eyecolor == '') { $current_row->eyecolor=null; }
    if($current_row->haircolor == 'd' || $current_row->haircolor == '') { $current_row->haircolor=null; }
    if($current_row->height == ''){ $current_row->height=null; }
    if($current_row->weight == ''){ $current_row->weight=null; }
    if($current_row->birthdate == '0000-00-00'){ $current_row->birthdate=null; }
    if($current_row->twitter == ''){ $current_row->twitter=null; }
    if($current_row->phone == ''){ $current_row->phone=null; }
    if($current_row->address1 == ''){ $current_row->address1=null; }
    if($current_row->profession == ''){ $current_row->profession=null; }
    if($current_row->measurement == ''){ $current_row->measurement=null; }

    $current_row->contest_year = '2011';
    $current_row->channel = 'Hometown Hotties';
    $current_row->week = $this->getContestWeek($current_row);
    $current_row->hottie_status = $this->getContestStatus($current_row);

    $current_row->title = $current_row->firstname . ' - ' . $current_row->city . ', ' . MigrationUtility::getStateAbbr($current_row->state);
    $current_row->body = MigrationUtility::buildBody($current_row);
  }

  private function getContestWeek($current_row){
    $wks=array();
    $query = db_select('fm_jn_group_user', 'g');
    $qryResults = $query->fields('g', array('userID','groupID', 'offset', 'description'))
      ->condition('g.userID', $current_row->id)
      ->execute();
    
    foreach ($qryResults as $record){
      $wks[]=str_replace('Week #', '', $record->description);
    }
    return implode(",", $wks);
  }

  private function getContestStatus($current_row){
    $status=array('Contestant');
    $query = db_select('fm_jn_group_user', 'g');
    $qryResults = $query->fields('g', array('userID','groupID', 'offset', 'description'))
      ->condition('g.userID', $current_row->id)
      ->execute();
    
    foreach ($qryResults as $record){
      switch($record->description){
        case 'Semifinalists':
          $status[] = 'Semifinalist';
          break;
        case 'Finalists':
          $status[] = 'Finalist';
          break;
      }
      // hard-code winner
      if($record->userid == '2350023'){
        $status[] = 'Winner';
      }
    }
    return implode(",", $status);
  }

  public function insertMainImage($entity, $source_row){
    // Insert main image
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_filemobile_id', 'fm', 'fm.entity_id = f.fid');
    $qryResults = $query->fields('f', array('fid'))
      ->condition('fm.field_media_filemobile_id_value', $source_row->avatar)
      ->execute();
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

    // Relate slideshows
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_media_filemobile_user_id', 'u', 'n.nid = u.entity_id');
    $qryResults = $query->fields('n', array('nid', 'vid', 'type'))
      ->fields('u', array('entity_id', 'field_media_filemobile_user_id_value'))
      ->condition('u.field_media_filemobile_user_id_value', $source_row->id)
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


/*
 * Slideshow Node migration
 */
class HottieSlideshowMigration extends HometownHottiesMigration {
  
  public function __construct() {
    parent::__construct();
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
        
    $this->description = t('Migrate hotties slideshow from filemobile');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'id' => t('Hotties GUID'),
    );

    // Use database view
    $query = db_select('fm_users', 'u')
      ->fields('u', array('id', 'avatar', 'firstname', 'lastname', 'city', 'state', 'weight', 'height', 'measurement', 'profession', 'relationshipStatus', 'favSportsTeam', 'favActor', 'karaokeSong', 'firstJob', 'piercingTattoos', 'superPower', 'pickupLine', 'craziestThing', 'somethingFree', 'unusualHookup', 'comfortableOutfit', 'amazingRomp', 'created'))
      ->orderBy('id', 'ASC');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('slideshow');
    
    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'id' => array('type' => 'int',
                          'not null' => TRUE,
                          'description' => 'Hotties GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    
    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('changed', 'created');

    $this->addFieldMapping('field_media_filemobile_user_id', 'id');
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
    $current_row->title = $current_row->firstname . ' - ' . $current_row->city . ', ' . MigrationUtility::getStateAbbr($current_row->state);
    $current_row->channel = 'Hometown Hotties';
    $current_row->body = MigrationUtility::buildBody($current_row);
  }

  public function insertMainImage($entity, $source_row){
    // Insert main image
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_filemobile_id', 'fm', 'fm.entity_id = f.fid');
    $qryResults = $query->fields('f', array('fid'))
      ->condition('fm.field_media_filemobile_id_value', $source_row->avatar)
      ->execute();
    foreach ($qryResults as $record){
      echo '; main Image: ';
      
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
    $query->leftJoin('field_data_field_media_filemobile_id', 'fm', 'fm.entity_id = f.fid');
    $query->leftJoin('fm_files', 'files', 'files.id = fm.field_media_filemobile_id_value');
    $qryResults = $query->fields('f', array('fid'))
      ->fields('files', array('id', 'filetype', 'message', 'moderationstatus'))
      ->condition('files.uid', $source_row->id)
      ->orderBy('files.filetype','ASC')
      ->orderBy('files.upload','ASC')
      ->execute();

    echo 'entity: '. $entity->nid . ' - user -' . $source_row->id;

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'slides';
      var_dump($record);
      if(($record->filetype == 1 && $record->moderationstatus == 1) ||  $record->filetype == 2){
        $this->insertSlide($entity, $source_row, $ct++, $record->fid, $record->id, $record->message, '');
      }
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
					'field_slide_caption_format' => 'full_html',
		   );
		      
		  $insertData = db_insert('field_data_field_slide_caption')
		   ->fields($arField)
		   ->execute();
		  $insertRev = db_insert('field_revision_field_slide_caption')
		   ->fields($arField)
		   ->execute();
		}
     
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {

		/*$qry = db_query("delete FROM field_collection_item where field_name='field_slides_wrapper'");
    $qry = db_query("delete FROM field_collection_item where field_name='field_slides_wrapper'");
		$qry = db_query("delete FROM field_data_field_slides_wrapper where bundle='slideshow'");
		$qry = db_query("delete FROM field_revision_field_slides_wrapper where bundle='slideshow'");
		$qry = db_query("delete from field_data_field_slides where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slides where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_data_field_slide_title where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slide_title where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_data_field_slide_caption where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slide_caption where bundle='field_slide_wrapper'");*/
  }

}

/*
 * Migration utility functions
 */
class MigrationUtility {

  public function buildBody($current_row){
    $strBody = '<h2>My Profile</h2>';
    if(strlen($current_row->height) > 0){
      $strBody .= '<p><strong>Height:</strong> ' . $current_row->height . '</p>';
    }
    if(strlen($current_row->weight) > 0){
      $strBody .= '<p><strong>Weight:</strong> ' . $current_row->weight . ' lbs.</p>';
    }
    if(strlen($current_row->measurement) > 0){
      $strBody .= '<p><strong>Measurements:</strong> ' . $current_row->measurement . '</p>';
    }
    if(strlen($current_row->profession) > 0){
      $strBody .= '<p><strong>Profession:</strong> ' . $current_row->profession . '</p>';
    }
    if(strlen($current_row->relationshipstatus) > 0){
      $strBody .= '<p><strong>Relationship Status:</strong> ' . $current_row->relationshipstatus . '</p>';
    }
    if(strlen($current_row->favsportsteam) > 0){
      $strBody .= '<p><strong>Favorite Sport/Team:</strong> ' . $current_row->favsportsteam . '</p>';
    }
    if(strlen($current_row->favactor) > 0){
      $strBody .= '<p><strong>Favorite Movie/Actor:</strong> ' . $current_row->favactor . '</p>';
    }
    if(strlen($current_row->karaokesong) > 0){
      $strBody .= '<p><strong>Go-to karaoke song:</strong> ' . $current_row->karaokesong . '</p>';
    }
    if(strlen($current_row->firstjob) > 0){
      $strBody .= '<p><strong>My first job:</strong> ' . $current_row->firstjob . '</p>';
    }
    if(strlen($current_row->piercingtattoos) > 0){
      $strBody .= '<p><strong>Piercings/Tattoos (How many? Where?)</strong> ' . $current_row->piercingtattoos . '</p>';
    }
    if(strlen($current_row->superpower) > 0){
      $strBody .= '<p><strong>What fun fact, talent, or mutant superpower of yours should guys know about?</strong> ' . $current_row->superpower . '</p>';
    }
    if(strlen($current_row->pickupline) > 0){
      $strBody .= "<p><strong>What's the most memorable pick up line you've ever heard? " . $current_row->pickupline . '</p>';
    }
    if(strlen($current_row->craziestthing) > 0){
      $strBody .= "<p><strong>What's the craziest thing you've ever done?</strong> " . $current_row->craziestthing . '</p>';
    }
    if(strlen($current_row->unusualhookup) > 0){
      $strBody .= "<p><strong>What's the most unusual place you've ever hooked up? How'd it go?</strong> " . $current_row->unusualhookup . '</p>';
    }
    if(strlen($current_row->somethingfree) > 0){
      $strBody .= "<p><strong>Have you ever lied to get something for free? What was it?</strong> " . $current_row->somethingfree . '</p>';
    }
    if(strlen($current_row->comfortableoutfit) > 0){
      $strBody .= "<p><strong>What do you feel most comfortable wearing?</strong> " . $current_row->comfortableoutfit . '</p>';
    }
    if(strlen($current_row->amazingromp) > 0){
      $strBody .= "<p><strong>Would you rather have boring sex all the time or an amazing romp once a year?</strong> " . $current_row->amazingromp . '</p>';
    }

    return $strBody;
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
