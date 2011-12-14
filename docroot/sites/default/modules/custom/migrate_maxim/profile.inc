<?php

abstract class MaximProfileMigration extends Migration {
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
 * Profile Node migration
 */
class profileNodeMigration extends MaximProfileMigration {
  
  public function __construct() {
    parent::__construct();
      
    $this->description = t('Migrate hottie profiles from Vignette: vgn_profiles table');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'hguid' => t('Hottie GUID'),
    );

    // Use database view
    $query = db_select('vgn_profiles', 'p')
      ->fields('p', array('hguid', 'first_name', 'last_name', 'vanity', 'height', 'weight', 'full_profile', 'measurements', 'city', 'state', 'country', 'week', 'contest_year', 'contest_status', 'finalist_place', 'start_date', 'pguid', 'title', 'image', 'body'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields,  NULL, array('map_joinable' => FALSE));
    
    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('hotties_profile');
    
    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'hguid' => array('type' => 'varchar',
                          'length' => 40,
                          'not null' => TRUE,
                          'description' => 'GUID',
          )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('field_vgn_guid', 'hguid');
    $this->addFieldMapping('field_vgn_profile_id', 'full_profile');
    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE);
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('field_profile_first_name', 'first_name');
    $this->addFieldMapping('field_profile_last_name', 'last_name');
    $this->addFieldMapping('field_profile_height', 'height');
    $this->addFieldMapping('field_profile_weight', 'weight');
    $this->addFieldMapping('field_profile_measurements', 'measurements');
    $this->addFieldMapping('field_profile_city', 'city');
    $this->addFieldMapping('field_profile_state', 'state')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_profile_country', 'country')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    // Contest Data
    $this->addFieldMapping('field_hotties_contest_week', 'week')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_hotties_contest_year', 'contest_year')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_hotties_contest_status', 'hottie_status')
      ->separator(',')
      ->arguments(array('create_term' => TRUE))
      ->defaultValue(null);
    $this->addFieldMapping('field_hotties_finalist_place', 'finalist_place');
    $this->addFieldMapping('field_channel', 'channel');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_vgn_vanity_url', 'vanity');
    $this->addFieldMapping('field_vgn_channel', 'vgnchannel');
    
    $body_arguments = MigrateTextFieldHandler::arguments(NULL, array('format' => 'full_html'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('field_vgn_image_id','image');
    $this->addFieldMapping('created', 'start_date');
    $this->addFieldMapping('changed', 'start_date');
    
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
  
  /* 
   * Prepare row before migration
   */
  public function prepareRow($current_row) {
    $current_row->channel = 'Hometown Hotties';
    // Contest Status
    switch($current_row->contest_status){
      case 0:
        $current_row->hottie_status = 'Contestant';
        break;
      case 1:
        $current_row->hottie_status = 'Semifinalist';
        break;
      case 2:
        $current_row->hottie_status = 'Finalist';
        break;
      case 3:
        $current_row->hottie_status = 'Winner';
        break;
    }
  }

  public function insertMainImage($entity, $source_row){
    // Insert main image
    $query = db_select('file_managed', 'f');
    $query->leftJoin('field_data_field_media_vgn_record_id', 'r', 'r.entity_id = f.fid');
    $qryResults = $query->fields('f', array('fid'))
      ->condition('r.field_media_vgn_record_id_value', $source_row->image)
      ->execute();
    foreach ($qryResults as $record){
      echo '; main Image: ';
      
    $arField = array(
      'entity_type' => 'node',
      'bundle' => 'hotties_profile',
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
    $query = db_select('vgn_jn_profile_slideshows', 's');
    $query->leftJoin('field_data_field_vgn_guid', 'g', 'g.field_vgn_guid_value = s.vgn_slideshow_id');
    $qryResults = $query->fields('s', array('parent_id', 'vgn_slideshow_id', 'ordering'))
      ->fields('g', array('entity_id'))
      ->condition('parent_id', $source_row->pguid)
      ->orderBy('s.ordering', 'ASC')
      ->execute();

    echo '; profile node: '. $entity->nid . ' '; 

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo '; slideshow: ' . $record->entity_id;
      $this->insertNodeRef('node', 'hotties_profile', $entity->nid, $entity->vid, 'field_profile_ref_slideshow', $record->entity_id, $ct++);
    }

    // Relate videos
    $query = db_select('vgn_jn_profile_videos', 'v');
    $query->leftJoin('field_data_field_vgn_guid', 'g', 'g.field_vgn_guid_value = v.vgn_video_id');
    $qryResults = $query->fields('v', array('parent_id', 'vgn_video_id', 'ordering'))
      ->fields('g', array('entity_id'))
      ->condition('parent_id', $source_row->pguid)
      ->orderBy('v.ordering', 'ASC')
      ->execute();

    echo 'profile node: '. $entity->nid . ' '; 

    $ct=0;
    /* Loop thru slides and add tables */
    foreach ($qryResults as $record){
      echo 'videos: ';
      var_dump($record);
      $this->insertNodeRef('node', 'hotties_profile', $entity->nid, $entity->vid, 'field_profile_ref_video', $record->entity_id, $ct++);
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
