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

class MediaHottieMigration extends MaximMediaMigration {
  public $conversion = 1015;
  public $conversion_ext = 'jpg';

  public function __construct(){
    parent::__construct();
    $this->description = t('Hometown Hotties images');
    $this->map = new MigrateSQLMap($this->machineName,
        array('id' => array(
                'type' => 'int',     
                'not null' => TRUE,
                'description' => 'FileMobile ID',
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'id' => t('Image GUID'),
    );

   // Use database view
    $query = db_select('fm_files', 'f')
      ->fields('f', array('id', 'uid', 'title', 'channel', 'filetype', 'message', 'upload', 'publicUrl', 'thumbUrl', 'contenttype', 'filename', 'extension', 'moderationstatus', 'channel_shortname', 'channel_name', 'conversions'))
      ->condition('conversions', $this->conversion , 'REGEXP');
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // TIP: Set copy_file to copy the file from its source (which could be a
    // remote server, i.e. the uri is of the form http://example.com/images/foo.jpg).
    $dest_options = array('copy_file' => FALSE, 'preserve_files' => TRUE);
    $this->destination = new MigrateDestinationFile($dest_options);

    // Just map the incoming URL to the destination's 'uri'
    $this->addFieldMapping('uri', 'sourceURL');
    $this->addFieldMapping('title','title');
    $this->addFieldMapping('filemime','contenttype');
    $this->addFieldMapping('filename','filename');
    $this->addFieldMapping('timestamp','timestamp');
    $this->addFieldMapping('status')
                    ->defaultValue(1);

    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addUnmigratedDestinations(array('fid'));
  }

  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row->sourceURL = 'public://maxim/files/maxim2/Maxim/Hotties/2011/' . $current_row->uid . '/' . $current_row->id . '_' . $this->conversion . '.' . $this->conversion_ext;
    $current_row->cdnurl = 'http://cdn2.maxim.com/maxim/files/maxim2/Maxim/Hotties/2011/' . $current_row->uid . '/' . $current_row->id . '_' . $this->conversion . '.' . $this->conversion_ext;
  	$current_row->filename = '2011 Hometown Hottie - ' . $current_row->title;
    $current_row->timestamp = Migration::timestamp($current_row->upload);
    echo $current_row->sourceURL . "\n ";
  }

  public function complete($entity, stdClass $source_row){
    	
    if(strlen($source_row->message) > 0){
      $this->insertField($entity->fid, 'image', 'field_media_description', t($source_row->message), 'plain_text');
    }
    if(strlen($source_row->cdnurl) > 0){
      $this->insertField($entity->fid, 'image', 'field_media_cdn_url', $source_row->cdnurl);
    }
    $this->insertField($entity->fid, 'image', 'field_media_source_url', 'http://rstorage.filemobile.com/storage/' . $source_row->id);
    if(strlen($source_row->id) > 0){
      $this->insertField($entity->fid, 'image', 'field_media_filemobile_id', $source_row->id);
    }
    if(strlen($source_row->uid) > 0){
      $this->insertField($entity->fid, 'image', 'field_media_filemobile_user_id', $source_row->uid);
    }
  }

  function ListFind($list, $value, $delimiter=","){
    $arr = explode($delimiter, $list);

    for($i=0; $i<count($arr); ++$i){
      if(strcmp($arr[$i], $value) == 0) {
        return true;
      }
    }
    return false;
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
    $query = db_select('vgn_images', 'i')
      ->fields('i', array('recordid', 'tag_list', 'mediaid', 'title', 'description', 'cdnurl', 'sourcepath', 'sourceurl', 'copyright', 'caption', 'thumbnailpath', 'mimetype', 'mediatype', 'filesize', 'height', 'width', 'modifiedon'));
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
    $this->addFieldMapping('filesize','filesize');
    $this->addFieldMapping('filename','filename');
    $this->addFieldMapping('status')
                    ->defaultValue(1);

    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addUnmigratedDestinations(array('fid', 'timestamp'));
  }

  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    echo 'mediaid: ' . $current_row->mediaid . '; title: ' . $current_row->title . "\n";
    if(strlen($current_row->cdnurl) > 0){
      $current_row->sourceURL = str_replace('http://cdn2.maxim.com/', 'public://', $current_row->cdnurl);
			$current_row->filename = basename($current_row->cdnurl);
    } else if (strlen($current_row->sourcepath) > 0) {
      $current_row->sourceURL = 'public://maxim/files/maxim2' . $current_row->sourcepath;
			$current_row->filename = basename($current_row->sourcepath);
    }
		// Multiply file size x 1000
		if(is_numeric($current_row->filesize)){
			$current_row->filesize = $current_row->filesize * 1000;	
		}
  }

  public function complete($entity, stdClass $source_row){
  	
  if(strlen($source_row->description) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_description', t($source_row->description), 'full_html');
  }
  if(strlen($source_row->cdnurl) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_cdn_url', $source_row->cdnurl);
  }
  if(strlen($source_row->sourcepath) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_source_path', $source_row->sourcepath);
  }
  if(strlen($source_row->sourceurl) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_source_url', $source_row->sourceurl);
  }
  if(strlen($source_row->caption) > 0 ){
    $this->insertField($entity->fid, 'image', 'field_media_caption', $source_row->caption);
  }
  if(strlen($source_row->thumbnailpath) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_thumbnail_path', 'http://cdn2.maxim.com/maxim/files/maxim2' . $source_row->thumbnailpath);
  }
  if(strlen($source_row->mediaid) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_vgn_image_id', $source_row->mediaid);
  }
  if(strlen($source_row->recordid) > 0){
    $this->insertField($entity->fid, 'image', 'field_media_vgn_record_id', $source_row->recordid);
  }
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
 * Hotties video files
 */
class VideoHottiesMigration extends MaximMediaMigration {
  public $conversion_ext = 'mp4';

  public function __construct(){
    parent::__construct();
    $this->description = t('Hometown Hotties video');
    $this->map = new MigrateSQLMap($this->machineName,
        array('id' => array(
                'type' => 'int',     
                'not null' => TRUE,
                'description' => 'FileMobile ID',
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'id' => t('Video GUID'),
    );

   // Use database view
    $query = db_select('fm_files', 'f')
      ->fields('f', array('id', 'uid', 'title', 'channel', 'filetype', 'message', 'upload', 'publicUrl', 'thumbUrl', 'contenttype', 'filename', 'extension', 'moderationstatus', 'channel_shortname', 'channel_name', 'conversions'))
      ->condition('extension', 'mov');
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // TIP: Set copy_file to copy the file from its source (which could be a
    // remote server, i.e. the uri is of the form http://example.com/images/foo.jpg).
    $dest_options = array('copy_file' => FALSE, 'preserve_files' => TRUE);
    $this->destination = new MigrateDestinationFile($dest_options);

    // Just map the incoming URL to the destination's 'uri'
    $this->addFieldMapping('uri', 'sourceURL');
    $this->addFieldMapping('title','title');
    $this->addFieldMapping('filemime','contenttype');
    $this->addFieldMapping('filename','filetitle');
    $this->addFieldMapping('timestamp','timestamp');
    $this->addFieldMapping('status')
                    ->defaultValue(1);

    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addUnmigratedDestinations(array('fid'));
  }

  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row->sourceURL = 'public://maxim/files/maxim2/Maxim/Hotties/2011/' . $current_row->uid . '/' . $current_row->id . '.' . $this->conversion_ext;
    $current_row->cdnurl = 'http://cdn2.maxim.com/maxim/files/maxim2/Maxim/Hotties/2011/' . $current_row->uid . '/' . $current_row->id  . '.' . $this->conversion_ext;
  	$current_row->filetitle = '2011 Hometown Hottie Video - ' . $current_row->title;
    $current_row->timestamp = Migration::timestamp($current_row->upload);
  }

  public function complete($entity, stdClass $source_row){
    if(strlen($source_row->title) > 0){
     $this->insertField($entity->fid, 'video', 'field_media_title', t($source_row->filetitle), 'plain_text');
    }
    if(strlen($source_row->message) > 0){
      $this->insertField($entity->fid, 'video', 'field_media_description', t($source_row->message), 'plain_text');
    }
    if(strlen($source_row->cdnurl) > 0){
      $this->insertField($entity->fid, 'video', 'field_media_cdn_url', $source_row->cdnurl);
    }
    $this->insertField($entity->fid, 'video', 'field_media_source_url', 'http://rstorage.filemobile.com/storage/' . $source_row->id);
    if(strlen($source_row->id) > 0){
      $this->insertField($entity->fid, 'video', 'field_media_filemobile_id', $source_row->id);
    }
    if(strlen($source_row->uid) > 0){
      $this->insertField($entity->fid, 'video', 'field_media_filemobile_user_id', $source_row->uid);
    }
    $this->insertField($entity->fid, 'video', 'field_media_thumbnail_path', 'http://cdn2.maxim.com/maxim/files/maxim2/Maxim/Hotties/2011/' . $source_row->uid . '/' . $source_row->id  . '.jpg');
  }

  function ListFind($list, $value, $delimiter=","){
    $arr = explode($delimiter, $list);

    for($i=0; $i<count($arr); ++$i){
      if(strcmp($arr[$i], $value) == 0) {
        return true;
      }
    }
    return false;
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
  
/**
 * Media import files (videos)
 */
class MediaFilesMigration extends MaximMediaMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Maxim video');
    $this->map = new MigrateSQLMap($this->machineName,
        array('mediaid' => array(
                'type' => 'varchar',
                'length' => 40,        
                'not null' => TRUE,
                'description' => 'Video ID.'
                )
             ),
        MigrateDestinationFile::getKeySchema()
    );
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'mediaid' => t('Video GUID'),
			'recordid' => t('Record ID'),
    );
    
    // Use database view
    $query = db_select('vgn_media_video', 'i')
      ->fields('i', array('recordid', 'tags', 'mediaid', 'title', 'description', 'cdnurl', 'sourcepath', 'sourceurl', 'copyright', 'caption', 'thumbnailpath', 'mimetype', 'mediatype', 'filesize', 'height', 'width', 'modifiedon' ));
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));

    // TIP: Set copy_file to copy the file from its source (which could be a
    // remote server, i.e. the uri is of the form http://example.com/images/foo.jpg).
    $dest_options = array('copy_file' => FALSE, 'preserve_files' => TRUE, 'copy_blob' => FALSE, 'copy_destination' => null, 'language' => 'und');
    $this->destination = new MigrateDestinationExternalFile($dest_options);

    // Just map the incoming URL to the destination's 'uri'
    $this->addFieldMapping('uri', 'sourceURL');
    $this->addFieldMapping('title','title');
    $this->addFieldMapping('filemime','mimetype');
    $this->addFieldMapping('filesize','filesize');

    $this->addFieldMapping('timestamp', 'modifiedon');
    $this->addFieldMapping('filename','filename');
    $this->addFieldMapping('status')
				->defaultValue(1);
    
    $this->addFieldMapping('uid')
      ->defaultValue(1);
    
    $this->addUnmigratedDestinations(array('fid'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
   if($current_row->mediatype == 'image'){
      if(strlen($current_row->cdnurl) > 0){
        $current_row->sourceURL = str_replace('http://cdn2.maxim.com/', 'public://', $current_row->cdnurl);
        $current_row->filename = basename($current_row->cdnurl);
      } else if (strlen($current_row->sourcepath) > 0) {
        $current_row->sourceURL = 'public://maxim/files/maxim2' . $current_row->sourcepath;
        $current_row->filename = basename($current_row->sourcepath);
      }
    } else {
      $current_row->fivemin_id = '';
      if(strlen($current_row->cdnurl) > 0){
        $current_row->sourceURL = $current_row->cdnurl;
        $current_row->filename = basename($current_row->cdnurl);
      } else if (strlen($current_row->sourcepath) > 0) {
        $current_row->sourceURL = 'http://cdn2.maxim.com/maxim/files/maxim2' . $current_row->sourcepath;
       	$current_row->filename = basename($current_row->sourcepath);
      }
      if(is_numeric($current_row->caption)){
        $current_row->fivemin_id = $current_row->caption;
      }
    echo 'media: ' . $current_row->mediaid ."\n" ;
    // Multiply file size x 1000
    }
    if(is_numeric($current_row->filesize)){
        $current_row->filesize = $current_row->filesize * 1000;	
    }
  }

  public function complete($entity, stdClass $source_row){
    if(strlen($source_row->title) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_title', t($source_row->title), 'plain_text');
    }
    if(strlen($source_row->description) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_description', t($source_row->description), 'full_html');
    }
    if(strlen($source_row->cdnurl) > 0){
      $this->insertField($entity->fid, $source_row->mediatype, 'field_media_cdn_url', $source_row->cdnurl);
    }
    if(strlen($source_row->sourcepath) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_source_path', $source_row->sourcepath);
    }
    if(strlen($source_row->sourceurl) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_source_url', $source_row->sourceurl);
    }
    if(strlen($source_row->caption) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_caption', $source_row->caption);
    }
    if($source_row->mediatype == 'video' && is_numeric($source_row->caption)){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_5min_id', $source_row->caption);
    }
    if(strlen($source_row->thumbnailpath) > 0){
      $this->insertField($entity->fid, $source_row->mediatype, 'field_media_thumbnail_path', 'http://cdn2.maxim.com/maxim/files/maxim2' . $source_row->thumbnailpath);
    }
    if(strlen($source_row->mediaid) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_vgn_image_id', $source_row->mediaid);
    }
    if(strlen($source_row->recordid) > 0){
     $this->insertField($entity->fid, $source_row->mediatype, 'field_media_vgn_record_id', $source_row->recordid);
    }
    //error_log(var_dump($source_row), 3, '/var/tmp/dmigrate.log');
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

  }
}
