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
    $query = db_select('vgn_article', 'art')
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
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
   // $query = Database::getConnection('default','vgn_maxim')->select('blog_view', 'art')
    $query = db_select('vgn_blog', 'art')
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
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
    //$query = Database::getConnection('default','vgn_maxim')->select('article_review_view', 'art')
    $query = db_select('vgn_article_review', 'art')
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
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
class VideoContentNodeMigration extends MaximMigration {
  private $cMap = array();
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate videos from Vignette: vgn_media_video table');
    
    // Instantiate Maxim Core
    $this->maximObj = new Maxim_Process();
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'mediaid' => t('Media ID'),
    );

    // Use database view
    //$query = Database::getConnection('default','vgn_maxim')->select('video_view', 'art')
    $query = db_select('vgn_media_video', 'v')
      ->fields('v', array('recordid', 'tags', 'mediaid', 'guid', 'title', 'description', 'body', 'cdnurl', 'sourcepath', 'sourceurl', 'copyright', 'caption', 'thumbnailpath', 'modifiedon', 'channel', 'vgnchannel' ));

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
                          'description' => 'mediaid',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('field_vgn_guid', 'mediaid');
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_vgn_channel', 'vgnchannel');
    $this->addFieldMapping('field_media_thumbnail_path','thumbnailpath');
    $this->addFieldMapping('field_media_vgn_record_id','recordid');
    $this->addFieldMapping('field_media_cdn_url', 'video_url');
    $this->addFieldMapping('field_media_5min_id', 'fivemin_id');
    
    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'description')
         ->arguments($body_arguments);
    $this->addFieldMapping('created', 'modifiedon');
    $this->addFieldMapping('changed', 'modifiedon');
    
    // Comma delimited tags
    $this->addFieldMapping('field_freeform_tags', 'tags')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_channel', 'channel');
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row->video_url = '';
    if(strlen($current_row->thumbnailpath) > 0){
      $current_row->thumbnailpath = 'http://cdn2.maxim.com/maxim/files/maxim2' . $current_row->thumbnailpath;
    }
    $current_row = $this->maximObj->prepareContent($current_row);
    $current_row->tags = str_replace(' ', ',' , $current_row->tags);
  }
  
  /*
   * Rollback function
   */
  public function preRollback() {
  }
  
 public function complete($entity, stdClass $source_row){
    // Retrieve video fid
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_vgn_record_id', 'r', 'f.fid = r.entity_id');
    $qryResults = $query->fields('f', array('fid'))
      ->fields('r', array('field_media_vgn_record_id_value'))
      ->condition('field_media_vgn_record_id_value', $source_row->recordid)
      ->execute();

    foreach ($qryResults as $record){
      echo 'entityid: ' . $entity->nid .', video: ';
      var_dump($record);
      
      $arField = array(
          'entity_type' => 'node',
          'bundle' => 'video',
          'entity_id' => $entity->nid,
          'revision_id' => $entity->vid,
          'delta' => 0,
          'language' => 'und',
          'field_media_file_fid' => $record->fid,
          'field_media_file_display' => 1,
       );
      $insertData = db_merge('field_data_field_media_file')
        ->key(array('entity_id' => $entity->nid))
        ->fields($arField)
        ->execute();
      $insertRev = db_merge('field_revision_field_media_file')
        ->key(array('entity_id' => $entity->nid))
        ->fields($arField)
        ->execute();
    }
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
    //$query = Database::getConnection('default','vgn_maxim')->select('joke_view', 'art')
    $query = db_select('vgn_joke', 'art')
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
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
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



