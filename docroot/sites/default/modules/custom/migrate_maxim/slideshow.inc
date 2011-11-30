<?php

abstract class MaximSlideshowMigration extends Migration {
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
 * Slideshow Node migration
 */
class SlideshowNodeMigration extends MaximSlideshowMigration {
  
  public function __construct() {
    parent::__construct();
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
        
    $this->description = t('Migrate slideshows from Vignette: AMG_Slideshow table');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Slideshow GUID'),
    );

    // Use database view
    $query = db_select('vgn_slideshows', 's')
      ->fields('s', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'today_girl', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('slideshow');
    
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
    $this->addFieldMapping('field_todays_girl', 'today_girl');
    
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field'=>'dek'), array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('field_vgn_image_id','image');
    $this->addFieldMapping('created', 'start_date');
    $this->addFieldMapping('changed', 'start_date');
    
    // Comma delimited tags
    $this->addFieldMapping('field_freeform_tags', 'tags')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
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
  }
  
  public function complete($entity, stdClass $source_row){
    // Retrieve slides
    $query = db_select('vgn_jn_slideshow_images', 'j');
    $query->leftJoin('field_data_field_media_vgn_record_id', 'r', 'r.field_media_vgn_record_id_value = j.image_id');
    $query->leftJoin('file_managed', 'f', 'f.fid = r.entity_id');
    $query->leftJoin('field_data_field_media_caption', 'c', 'c.entity_id = f.fid');
    $query->leftJoin('field_data_field_media_description', 'd', 'd.entity_id = f.fid');
    $qryResults = $query->fields('j', array('parent_id', 'image_id', 'ordering'))
      ->fields('f', array('fid'))
      ->fields('d', array('field_media_description_value'))
      ->fields('c', array('field_media_caption_value'))
      ->condition('parent_id', $source_row->guid)
      ->orderBy('parent_id', 'ASC')
      ->orderBy('ordering')
      ->execute();

    echo 'entity: '. $entity->nid . ' - guid -' . $source_row->guid;

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'slides';
      var_dump($record);

      $this->insertSlide($entity, $source_row, $ct++, $record->fid, $record->image_id, $record->field_media_caption_value, $record->field_media_description_value);
    }

    //error_log(var_dump($source_row), 3, '/var/tmp/dmigrate.log');
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

		$qry = db_query("delete FROM field_collection_item where field_name='field_slides_wrapper'");
    $qry = db_query("delete FROM field_collection_item where field_name='field_slides_wrapper'");
		$qry = db_query("delete FROM field_data_field_slides_wrapper where bundle='slideshow'");
		$qry = db_query("delete FROM field_revision_field_slides_wrapper where bundle='slideshow'");
		$qry = db_query("delete from field_data_field_slides where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slides where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_data_field_slide_title where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slide_title where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_data_field_slide_caption where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slide_caption where bundle='field_slide_wrapper'");
  }

}
