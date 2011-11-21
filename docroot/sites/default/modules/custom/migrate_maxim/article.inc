<?php

/**
 * @file
 * Article Migration
 */

/**
 * To define a migration process from a set of source data to a particular
 * kind of Drupal object (for example, a specific node type), you define
 * a class derived from Migration. You must define a constructor to initialize
 * your migration object. By default, your class name will be the "machine name"
 * of the migration, by which you refer to it. Note that the machine name is
 * case-sensitive.
 *
 * In any serious migration project, you will find there are some options
 * which are common to the individual migrations you're implementing. You can
 * define an abstract intermediate class derived from Migration, then derive your
 * individual migrations from that, to share settings, utility functions, etc.  
 */
abstract class MaximMigration extends Migration {
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
 * Article Node migration
 */
class ArticleNodeMigration extends MaximMigration {
	
  public function __construct() {
    parent::__construct();
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
        
    $this->description = t('Migrate articles from Vignette: AMG_Article table');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('article_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('article');
    
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
  	$current_row = $this->maximObj->prepareContent($current_row);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
    $this->maximObj->rollbackVocabulary();
  }

}



/*
 * Blog Node migration
 */
class BlogNodeMigration extends MaximMigration {
  private $cMap = array();
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate blogs from Vignette: AMG_Article table');
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('blog_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('blog');
    
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row = $this->maximObj->prepareContent($current_row);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
    $this->maximObj->rollbackVocabulary();
  }
  
}

/*
 *  Review from Article Review Node migration
 */
class ArticleReviewNodeMigration extends MaximMigration {
  private $cMap = array();
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate reviews from Vignette: AMG_Article table');
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('article_review_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row = $this->maximObj->prepareContent($current_row);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
    $this->maximObj->rollbackVocabulary();
  }
}

/*
 * Video Node migration
 */
class VideoNodeMigration extends MaximMigration {
  private $cMap = array();
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate videos from Vignette: AMG_Article table');
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('video_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('video');
    
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row = $this->maximObj->prepareContent($current_row);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
    $this->maximObj->rollbackVocabulary();
  }
  
}

/*
 * Joke Node migration
 */
class JokeNodeMigration extends MaximMigration {
  private $cMap = array();
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate jokes from Vignette: AMG_Article table');
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('joke_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'author', 'dek', 'body', 'start_date', 'tags', 'channel', 'joke_category', 'vgnchannel'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('joke');
    
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
    $this->addFieldMapping('field_vgn_vanity_url', 'vanity');
    $this->addFieldMapping('field_vgn_channel', 'vgnchannel');
    
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);
      
    $this->addFieldMapping('title', 'title');

    
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field'=>'dek'), array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'start_date');
    $this->addFieldMapping('changed', 'start_date');
    
    // Comma delimited tags
    $this->addFieldMapping('field_freeform_tags', 'tags')
      ->separator(',')
      ->arguments(array('create_term' => TRUE));
    $this->addFieldMapping('field_channel', 'channel');
    $this->addFieldMapping('field_content_author','author')
      ->separator(',')
      ->arguments(array('create_term' => TRUE));
      
    $this->addFieldMapping('field_joke_category','joke_category');
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row = $this->maximObj->prepareContent($current_row);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
    $this->maximObj->rollbackVocabulary();
  }
  
}


/*
 * Slideshow Node migration
 */
class SlideshowNodeMigration extends MaximMigration {
  
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
    //$query = Database::getConnection('default','vgn_maxim')->select('article_view', 'art')
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
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
		$query->leftJoin('field_data_field_media_description', 'd', 'd.entity_id = f.fid');
    $qryResults = $query->fields('j', array('parent_id', 'image_id', 'ordering'))
			->fields('f', array('fid'))
			->fields('d', array('field_media_description_value'))
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

    	 $this->insertSlide($entity, $source_row, $ct++, $record->fid, $record->image_id, $record->field_media_description_value);
    }

    //error_log(var_dump($source_row), 3, '/var/tmp/dmigrate.log');
  }
  
  public function insertSlide($entity, $source_row, $field_delta, $file_id, $record_id, $caption){
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
		$qry = db_query("delete from field_data_field_slide_caption where bundle='field_slide_wrapper'");
		$qry = db_query("delete from field_revision_field_slide_caption where bundle='field_slide_wrapper'");
  }

}

/*
 * Maxim Process
 */
class Maxim_Process{
	
  public function __construct() {
    $this->channelObj = new Maxim_Channels();
    $this->authorObj = new Maxim_Authors();
    $this->formatObj = new Maxim_Format();
   
    $this->channelObj->channelMapping();
  }

	public function prepareContent($current_row){
    $source_id = $current_row->guid;

    $current_row->body = $this->formatObj->formatBody($current_row->body);
    $current_row->channel = $this->channelObj->getChannel($current_row->channel);
    $current_row->author = $this->authorObj->format($current_row->author);
    $current_row->tags = $this->formatObj->formatTags($current_row->tags);
    
    $new_channel = $this->channelObj->getChannelFromTags($current_row->tags);
    if($new_channel != ''){
      $current_row->channel = $new_channel;
    }
    
    $current_row->column = $this->channelObj->getColumn($current_row->channel);
    
    return $current_row;
	}
	
	
	public function rollbackVocabulary(){
	  // Delete taxonomy terms from these vocabularies
    $vocab_names = array('content_authors','freeform_tags','columns');

    $terms = db_query("SELECT tid FROM taxonomy_term_data t LEFT JOIN taxonomy_vocabulary v
       ON v.vid = t.vid WHERE v.machine_name IN (:vocabs)", array(':vocabs'=>$vocab_names));
    foreach ($terms as $term) {
      taxonomy_term_delete($term->tid);
    }
	}
	
}

/* 
 * Maxim Format Class
 */
class Maxim_Format {
  /*
   * Format Body
   */ 
  public function formatBody($body){
    // Modify body CDN URL - Search and replace /file_source with cdn URL 
    $searchExp = '/file_source';
    $cdnURL = 'http://cdn2.maxim.com/maxim/files/maxim2';
    $body = str_replace($searchExp, $cdnURL, $body);
    
    // Remove Related Links
    $body = preg_replace('/(<p>|<br>|<b>|<i>|\n)*Related Links.*/is','',$body);
    
    return $body;
   }
  
  /* 
   * Format tags
   */
  public function formatTags($tags){
    $tags = str_replace(' and ',', ', $tags);
    $tags = str_replace(', ', ',', $tags);
    $tags = strtolower($tags);
    // Remove multiple commas
    $tags = str_replace(',,', ',', $tags);
    // Remove last comma, if any
    $tags = rtrim($tags, ","); 

    return trim($tags);
  }

}

/*
 * Authors Class
 */
class Maxim_Authors {
  public function format($author){
    $author = str_replace(' and ',',', $author);
    $author = str_replace(', ',',', $author);
    $strAuthor = $author;
    switch ($author){
      case 'Maxim':
      case 'Maxim Staff,Liquor.com':
      case 'Maxim Staff from Liquor.com':
      case 'Maxim Staff,HeavyMMA.com':
      case 'Maxim Staff1':
      case 'Maxim staff':
      case 'maxim staff':
      case 'Maxim.com Staff':
      case 'Maxim.com staff':
      case 'maxim.com staff':
      case 'n/a':
      case 'G.':
        $strAuthor = 'Maxim Staff';
        break;
      case 'Bllender Blog':
        $strAuthor = 'Blender Blog';
        break;
      case 'Cory':
        $strAuthor = 'Cory Jones';
        break;
      case 'Dan bova':
        $strAuthor = 'Dan Bova';
        break;
      case 'Eric Spitznage':
        $strAuthor = 'Eric Spitznagel';
        break;
      case 'Gerasimos':
        $strAuthor = 'Gerasimos Manolatos';
        break;
      case 'Jessica Kind':
        $strAuthor = 'Jessica King';
        break;
      case 'Joanna':
        $strAuthor = 'Joanna Krupa';
        break;
      case 'John Devore':
        $strAuthor = 'John DeVore';
        break;
      case 'John Devore,Krista Soriano':
        $strAuthor = 'John DeVore,Krista Soriano';
        break;
      case 'Jordan':
        $strAuthor = 'Jordan Burchette';
        break;
      case 'Larry':
        $strAuthor = 'Larry Dobrow';
        break;
      case 'Nick Leftely':
        $strAuthor = 'Nick Leftley';
        break;
      case 'Paul':
        $strAuthor = 'Paul Ulane';
        break;
      case 'Stan':
      case 'Stan H':
        $strAuthor = 'Stan Horaczek';
        break;
      case 'T.J. Dietsch':
        $strAuthor = 'TJ Dietsch'; 
        break;
      case 'fatpickle':
        $strAuthor = 'Fatpickle';
        break; 
    }
    return trim($strAuthor);
  }

}



/*
 * Channels Class
 */
class Maxim_Channels {
	private $cMap = array();
	
  /*
   * Get Column based on Channel
   */
  public function getColumn($channel){
    $strColumn = '';
    
    switch($channel){
      case 'Beat This Caption':
        $strColumn = $channel;
        break;
      case 'Dirty Briefs':
        $strColumn = 'The Dump Blog';
        break;
    }
    
    return $strColumn;
  }
	
  /*
   * Get Channel based on tags
   */
  public function getChannelFromTags($tags){
    $strChannel = '';
    if(stripos($tags, 'found porn') !== false){
      $strChannel = 'Found Porn';
    } 

    return $strChannel;
  }
	
  /*
   * Get channel from mapping
   */
	public function getChannel($channel){
		if(array_key_exists($channel,$this->cMap)){
			return $this->cMap[$channel];  
    } else {
      return $channel;
		}
	}
	
  public function channelMapping(){
    
    $this->cMap['Home/GAMING'] = 'Gaming';
    $this->cMap['Home/GAMING/Articles'] = 'Gaming';
    $this->cMap['Home/GAMING/BFG'] = 'Gaming';
    $this->cMap['Home/GAMING/Features'] = 'Gaming';
    $this->cMap['Home/GAMING/Maxim Games'] = 'Gaming';
    $this->cMap['Home/GAMING/Reviews'] = 'Gaming';
    $this->cMap['Home/GAMING/Slideshows'] = 'Gaming';
    $this->cMap['Home/GAMING/Videos'] = 'Gaming';
    
    $this->cMap['Home/GIRLS'] = 'Girls';
    $this->cMap['Home/GIRLS/Articles'] = 'Girls';
    $this->cMap['Home/GIRLS/Beach Watch'] = 'Girls of Maxim';
    $this->cMap['Home/GIRLS/Girls of Maxim'] = 'Girls of Maxim';
    $this->cMap['Home/GIRLS/Hometown Hotties'] = 'Hometown Hotties';
    $this->cMap['Home/GIRLS/Hot 100'] = 'Hot 100';
    $this->cMap['Home/GIRLS/Meet Other Singles'] = 'Girls';
    $this->cMap['Home/GIRLS/Sex'] = 'Sex & Relationships';
    $this->cMap['Home/GIRLS/Slideshows'] = 'Girls';
    $this->cMap['Home/GIRLS/Today\'s Girl'] = 'Today\'s Girl';
    $this->cMap['Home/GIRLS/Videos'] = 'Girls';
    $this->cMap['Home/Home/GIRLS/Today\'s Girl/Today\'s Girl Subchannel 1'] = 'Girls';
    
    $this->cMap['Home/HUMOR'] = 'Funny';
    $this->cMap['Home/HUMOR/Animated GIFs'] = 'Stupid Clips';
    $this->cMap['Home/HUMOR/Articles'] = 'Funny';
    $this->cMap['Home/HUMOR/Beat This Caption'] = 'Beat This Caption';
    $this->cMap['Home/HUMOR/Features'] = 'Funny';
    $this->cMap['Home/HUMOR/Jokes'] = 'Jokes';
    $this->cMap['Home/HUMOR/Slideshows'] = 'Funny';
    $this->cMap['Home/HUMOR/Videos'] = 'Funny';
    $this->cMap['Home/Home/HUMOR/Beat This Caption/magazine'] = 'Beat This Caption';
    $this->cMap['Home/Home/HUMOR/Beat This Caption/online'] = 'Beat This Caption';
    
    $this->cMap['Home/Home/STUFF/Articles/Articles Subchannel 1'] = 'Gadgets';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Dumb Stuff'] = 'Travel';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Eat Out and Drink Up'] = 'Travel';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Get There'] = 'Travel';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Look Awesome'] = 'Grooming';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Stuff'] = 'Gadgets';
    $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/True Stories of Spring Break'] = 'Travel';
    
    $this->cMap['Home/MOVIES'] = 'Movies';
    $this->cMap['Home/MOVIES/Articles'] = 'Movies';
    $this->cMap['Home/MOVIES/Slideshows'] = 'Movies';
    $this->cMap['Home/MOVIES/Videos'] = 'Movies';
    
    $this->cMap['Home/MUSIC'] = 'Music';
    $this->cMap['Home/MUSIC/Articles'] = 'Music';
    $this->cMap['Home/MUSIC/Slideshows'] = 'Music';
    $this->cMap['Home/MUSIC/Videos'] = 'Entertainment Videos';
    
    $this->cMap['Home/SPORTS'] = 'Sports';
    $this->cMap['Home/SPORTS/Articles'] = 'Sports';
    $this->cMap['Home/SPORTS/Dirty Briefs'] = 'The Dump Blog';
    $this->cMap['Home/SPORTS/Maximum Warrior'] = 'Maximum Warrior';
    $this->cMap['Home/SPORTS/Slidewshows'] = 'Sports';
    $this->cMap['Home/SPORTS/Videos'] = 'Sports';

    $this->cMap['Home/STUFF'] = 'Gadgets & Rides';
    $this->cMap['Home/STUFF/2011 Tech Buying Guide'] = 'Gift Guides';
    $this->cMap['Home/STUFF/A Drink With Maxim'] = 'Booze';
    $this->cMap['Home/STUFF/Adam Richamn\'s Grub Guide'] = 'Food';
    $this->cMap['Home/STUFF/Articles'] = 'Gadgets';
    $this->cMap['Home/STUFF/Dads and Grads Gift Guide'] = 'Gift Guides';
    $this->cMap['Home/STUFF/Eat to the Beat'] = 'Food';
    $this->cMap['Home/STUFF/Great American Bar Search'] = 'Booze';
    $this->cMap['Home/STUFF/Guy\'s Guide to Spring Break'] = 'Travel';
    $this->cMap['Home/STUFF/Guy\'s Guide to Summer'] = 'Travel';
    $this->cMap['Home/STUFF/Slideshows'] = 'Rides';
    $this->cMap['Home/STUFF/The Real Guy\'s Guide'] = 'Clothes';
    $this->cMap['Home/STUFF/Videos'] = 'Gadgets & Rides';
    
    $this->cMap['Home/TV'] = 'TV';
    $this->cMap['Home/TV/Articles'] = 'TV';
    $this->cMap['Home/TV/Slideshows'] = 'TV';
    $this->cMap['Home/TV/Videos'] = 'TV';
    
    $this->cMap['Home/VIDEO'] = 'Maxim TV';
    $this->cMap['Home/VIDEO/Gaming'] = 'Gaming';
    $this->cMap['Home/VIDEO/Girls'] = 'Girls';
    $this->cMap['Home/VIDEO/Hometown Hotties'] = 'Hometown Hotties';
    $this->cMap['Home/VIDEO/Humor'] = 'Stupid Clips';
    $this->cMap['Home/VIDEO/Movies'] = 'Movies';
    $this->cMap['Home/VIDEO/Music Videos'] = 'Music';
    $this->cMap['Home/VIDEO/Sports'] = 'The Big Leagues';
    $this->cMap['Home/VIDEO/Television'] = 'TV'; 

  }
}


