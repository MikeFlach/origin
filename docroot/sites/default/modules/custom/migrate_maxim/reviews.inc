<?php

abstract class MaximReviewsMigration extends Migration {
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
 * Reviews Node migration
 */
class ReviewsNodeMigration extends MaximReviewsMigration {
  
  public function __construct() {
    parent::__construct();
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
        
    $this->description = t('Migrate Reviews from Vignette: AMG_review table');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Review GUID'),
    );

    // Use database view
    //$query = Database::getConnection('default','vgn_maxim')->select('article_view', 'art')
    $query = db_select('vgn_reviews', 'r')
      ->fields('r', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('review');
    
    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'guid' => array('type' => 'varchar',
                          'length' => 40,
                          'not null' => TRUE,
                          'description' => 'GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('field_vgn_guid', 'guid');
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_feature_title', 'feature_title');
    $this->addFieldMapping('field_feature_subtitle', 'feature_subtitle');
    $this->addFieldMapping('field_vgn_vanity_url', 'vanity');
    $this->addFieldMapping('field_vgn_channel', 'vgnchannel');
    $this->addFieldMapping('field_reviews_star_rating', 'tags');
    $this->addFieldMapping('field_reviews_type', 'review_type');
    
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field'=>'dek'), array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('field_vgn_image_id','image');
    $this->addFieldMapping('created', 'start_date');
    $this->addFieldMapping('changed', 'start_date');

    $this->addFieldMapping('field_channel', 'channel');
    $this->addFieldMapping('field_content_author','author')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
      
    $this->addFieldMapping('field_column','column')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row = $this->maximObj->prepareContent($current_row);
    switch($current_row->select_type){
      case 1:
        $current_row->review_type = 'Game';
        break;
      case 2:
        $current_row->review_type = 'DVD';
        break;
      case 3:
        $current_row->review_type = 'Movie';
        break;
      case 4:
        $current_row->review_type = 'TV Shows';
        break;
      case 5:
        $current_row->review_type = 'Music';
        break;
      case 6:
        $current_row->review_type = 'Gear';
        break;
      case 7:
        $current_row->review_type = 'Other';
        break;
    }

  }
  
  public function complete($entity, stdClass $source_row){
		// Retrieve Additional fields
  	$qryResults = db_select('vgn_jn_review_fields', 'f')
			->fields('f', array('attribute', 'attr_value'))
    	->condition('parent_id', $source_row->guid)
    	->orderBy('ordering')
			->execute();
    
		echo 'entity: '. $entity->nid . ' - guid -' . $source_row->guid;

		/* Loop thru fields and add to tables */
		foreach ($qryResults as $record){
			echo 'fields';
			var_dump($record);
      switch ($record->attribute){
        case 'Release Date':
          $this->insertField('date', $entity->nid, $entity->vid, 'field_reviews_release_date', $record->attr_value);
          break;
        case 'Airs':
          $this->insertField('text', $entity->nid, $entity->vid, 'field_reviews_air_date', $record->attr_value);
        break;
        case 'Artist':
          $this->insertField('text', $entity->nid, $entity->vid, 'field_reviews_artist', $record->attr_value);
        break;
        case 'Official Site':
          $this->insertField('link', $entity->nid, $entity->vid, 'field_reviews_website', $record->attr_value);
        break;
        case 'Price':
          $this->insertField('text', $entity->nid, $entity->vid, 'field_reviews_price', $record->attr_value);
        break;
        case 'MPAA Rating':
           $this->insertField('term', $entity->nid, $entity->vid, 'field_reviews_mpaa_rating', $record->attr_value, 'reviews_mpaa_ratings');
        break;
        case 'Network':
           $this->insertField('term', $entity->nid, $entity->vid, 'field_reviews_tv_network', $record->attr_value, 'reviews_tv_networks');
        break;
        case 'Platform':
           $this->insertField('term', $entity->nid, $entity->vid, 'field_reviews_game_platform', $record->attr_value, 'reviews_game_platforms');
        break;
        case 'Source':
           $this->insertField('term', $entity->nid, $entity->vid, 'field_reviews_source', $record->attr_value, 'reviews_sources');
        break;
      }
    }

    //error_log(var_dump($source_row), 3, '/var/tmp/dmigrate.log');
  }

  public function insertField($type, $entity_id, $rev_id, $field_table_name, $field_value, $vocabulary_name = null){
    $runQuery = 1;
  	$arField = array(
        'entity_type' => 'node',
        'bundle' => 'review',
        'revision_id' => $rev_id,
        'delta' => 0,
  	    'language' => 'und'
    );
     
    switch($type){
      case 'text':
      case 'date':
        $arField[$field_table_name . '_value'] = $field_value;
      break;
      case 'term':
        $arTerms = preg_split('/,/', $field_value);
        $ct=0;
        foreach($arTerms as $term){
          $this->processTerms($field_table_name, $term, $vocabulary_name, $arField, $entity_id, $ct++);
        }
        $runQuery = 0;
      break;
      case 'link':
        $arField[$field_table_name . '_url'] = $field_value;
      break;
    }
    
    if($runQuery == 1){
    	$fid = db_merge('field_data_' . $field_table_name)
    	 ->key(array('entity_id' => $entity_id))
    	 ->fields($arField)
    	 ->execute();
      $rid = db_merge('field_revision_' . $field_table_name)
       ->key(array('entity_id' => $entity_id))
       ->fields($arField)
       ->execute();
    }
  }
  
  public function processTerms($field_table_name, $term, $vocabulary_name, $arField, $entity_id, $delta){
    $term = trim($term);
    switch ($term){
      case 'pc':
        $term = 'PC';
      break;
    }
    // Get termID from DB
	  $query = db_select('taxonomy_term_data', 't');
    $query->leftJoin('taxonomy_vocabulary', 'v', 'v.vid = t.vid');
    $qryResults = $query->fields('t', array('tid'))
      ->condition('v.machine_name', $vocabulary_name)
    	->condition('t.name', $term)
      ->execute();
    
    if($qryResults->rowCount() > 0){
      while ($record = mysql_fetch_row($qryResults)){
        $arField[$field_table_name . '_tid'] = $record->tid;
      }
    } else {
      // Get vocabulary id
      $qryVoc = db_select('taxonomy_vocabulary', 'v')
        ->fields('v', array('vid'))
        ->condition('v.machine_name', $vocabulary_name)
        ->execute();
      foreach ($qryVoc as $record){
        $vid = $record->vid;
      }
      echo 'vid: "' . $vid . '"' . "\n";
      if(strlen($vid)){
        // Insert term
        $qryInsert = "INSERT INTO {taxonomy_term_data} (vid, name, format) VALUES (:vid, :name, :format)";
        $args = array(':vid' => $vid, ':name' => $term, ':format' => 'plain_text');
        $tid = db_query($qryInsert, $args, array('return' => Database::RETURN_INSERT_ID));
        $insertData = db_insert('taxonomy_term_hierarchy')
         ->fields(array('tid' => $tid))
         ->execute();
        $arField[$field_table_name . '_tid'] = $tid;
      }
    }
    $arField['delta'] = $delta;
    $arField['entity_id'] = $entity_id;
  	$fid = db_insert('field_data_' . $field_table_name)
  	 ->fields($arField)
  	 ->execute();
    $rid = db_insert('field_revision_' . $field_table_name)
     ->fields($arField)
     ->execute();
  }

  /*
   * Rollback function
   */
  public function preRollback() {
  }

}
