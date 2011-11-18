<?php

/**
 * @file
 * Article Migration
 */

/**
 * Maxim Migration Class
 */
abstract class MaximMediaMigration extends Migration {
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

/**
 * TIP: Files can be migrated directly by themselves, by using the MigrateDestinationFile
 * class. This will copy the files themselves from the source, and set up the
 * Drupal file tables appropriately.
 */
class MediaImageMigration extends MaximMediaMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Maxim images');
    $this->map = new MigrateSQLMap($this->machineName,
        array('mediaid' => array(
                'type' => 'varchar',
                'length' => 40,        
                'not null' => TRUE,
                'description' => 'Image ID.'
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'mediaid' => t('Image GUID'),
    );
    
    // Use database view
    /*$query = Database::getConnection('default','vgn_maxim') ->select('image_view', 'i') */ // VGN database
    $query = db_select('vgn_images', 'i')
      ->fields('i', array('recordid', 'tag_list', 'mediaid', 'title', 'description', 'cdnurl', 'sourcepath', 'sourceurl', 'copyright', 'caption', 'thumbnailpath', 'mimetype', 'height', 'width'));
      //->condition('cdnurl', 'maxim2/Maxim' , 'REGEXP');
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // TIP: Set copy_file to copy the file from its source (which could be a
    // remote server, i.e. the uri is of the form http://example.com/images/foo.jpg).
    $dest_options = array('copy_file' => FALSE, 'preserve_files' => TRUE);
    $this->destination = new MigrateDestinationFile($dest_options);

    // Just map the incoming URL to the destination's 'uri'
    $this->addFieldMapping('uri', 'sourceURL');
    $this->addFieldMapping('title','title');
    $this->addFieldMapping('filemime','mimetype');
    
    $this->addFieldMapping('uid')
      ->defaultValue(1);
    
    
    $this->addUnmigratedDestinations(array('fid', 'filename', 'status', 'timestamp'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
  	$current_row->sourceURL = str_replace('http://cdn2.maxim.com/', 'public://', $current_row->cdnurl);
  }
  
  public function complete($entity, stdClass $source_row){
  	
  	if(strlen($source_row->description) > 0){
  	 $this->insertField($entity->fid, 'field_media_description', t($source_row->description), 'full_html');
  	}
  	if(strlen($source_row->cdnurl) > 0){
  	 $this->insertField($entity->fid, 'field_media_cdn_url', $source_row->cdnurl);
  	}
  	if(strlen($source_row->sourcepath) > 0){
  	 $this->insertField($entity->fid, 'field_media_source_path', $source_row->sourcepath);
  	}
  	if(strlen($source_row->sourceurl) > 0){
  	 $this->insertField($entity->fid, 'field_media_source_url', $source_row->sourceurl);
  	}
  	if(strlen($source_row->caption) > 0){
  	 $this->insertField($entity->fid, 'field_media_caption', $source_row->caption);
  	}
  	if(strlen($source_row->thumbnailpath) > 0){
  	 $this->insertField($entity->fid, 'field_media_thumbnail_path', $source_row->thumbnailpath);
  	}
  	if(strlen($source_row->mediaid) > 0){
  	 $this->insertField($entity->fid, 'field_media_vgn_image_id', $source_row->mediaid);
  	}
  	if(strlen($source_row->recordid) > 0){
      $this->insertField($entity->fid, 'field_media_vgn_record_id', $source_row->recordid);
  	}
  	//error_log(var_dump($source_row), 3, '/var/tmp/dmigrate.log');
  }
  
  public function insertField($entity_id, $field_name, $field_value, $field_format = null){
  	$arField = array(
        'entity_type' => 'file',
        'bundle' => 'image',
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
 * Article Image migration
 */
class ArticleImageMigration extends MaximMediaMigration {
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Associate images to main images in articles');
    
    /* 
     * Run this after all images have been imported
     * */
    
    /*
    replace into maximdev.field_data_field_main_image (entity_type, bundle, deleted, entity_id, revision_id, language, delta, field_main_image_fid, field_main_image_alt, field_main_image_title, field_main_image_width, field_main_image_height )
		select 'node', 'article', 0, n.nid, n.vid, 'und', 0, f.fid, null, null, vimage.width, vimage.height  from maximdev.file_managed f
		left join maximdev.field_data_field_media_vgn_record_id r ON f.fid = r.entity_id
		left join maximdev.field_data_field_vgn_image_id i on i.field_vgn_image_id_value = r.field_media_vgn_record_id_value
		left join maximdev.vgn_images vimage on vimage.recordid = r.field_media_vgn_record_id_value
		left join maximdev.node n on n.nid = i.entity_id
		where n.nid is not null;
		replace into maximdev.field_revision_field_main_image (entity_type, bundle, deleted, entity_id, revision_id, language, delta, field_main_image_fid, field_main_image_alt, field_main_image_title, field_main_image_width, field_main_image_height )
		select 'node', 'article', 0, n.nid, n.vid, 'und', 0, f.fid, null, null, vimage.width, vimage.height  from maximdev.file_managed f
		left join maximdev.field_data_field_media_vgn_record_id r ON f.fid = r.entity_id
		left join maximdev.field_data_field_vgn_image_id i on i.field_vgn_image_id_value = r.field_media_vgn_record_id_value
		left join maximdev.vgn_images vimage on vimage.recordid = r.field_media_vgn_record_id_value
		left join maximdev.node n on n.nid = i.entity_id
		where n.nid is not null;
    */
    
    /* Table clean up */
    /*
		delete from maximdev.field_data_field_media_caption where field_media_caption_value is null;
		delete from maximdev.field_revision_field_media_caption where field_media_caption_value is null;
		
		delete from maximdev.field_data_field_media_cdn_url where field_media_cdn_url_value is null;
		delete from maximdev.field_revision_field_media_cdn_url where field_media_cdn_url_value is null;
		
		delete from maximdev.field_data_field_media_description where field_media_description_value is null;
		delete from maximdev.field_revision_field_media_description where field_media_description_value is null;
		
		delete from maximdev.field_data_field_media_source_path where field_media_source_path_value is null;
		delete from maximdev.field_revision_field_media_source_path where field_media_source_path_value is null;
		
		delete from maximdev.field_data_field_media_source_url where field_media_source_url_value is null;
		delete from maximdev.field_revision_field_media_source_url where field_media_source_url_value is null;
		
		delete from maximdev.field_data_field_media_thumbnail_path where field_media_thumbnail_path_value is null;
		delete from maximdev.field_revision_field_media_thumbnail_path where field_media_thumbnail_path_value is null;
		
		*/
   
  }
}