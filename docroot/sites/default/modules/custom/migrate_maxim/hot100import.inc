<?php

abstract class Hot100Migration extends Migration {
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
class Hot100SlideshowMigration extends Hot100Migration {
  
  public function __construct() {
    parent::__construct();
    $this->description = t('Import Hot 100 slideshow');

    // this absolutely has to be the correct columns in the correct order,
    // the import pays no attention to the headings in the csv file
    $columns = array(
        array('title', 'Title'),
        array('summary', 'Summary'),
        array('author', 'Author'),  
        array('channel', 'Channel'), 
    );

    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrate_maxim') . '/hot100Article.csv', $columns, array('header_rows' => 1));

    // Set up our destination - nodes of type slideshow
    $this->destination = new MigrateDestinationNode('slideshow');
    
    // Create mapping to track relationship between source rows and their resulting Drupal objects
    $this->map = new MigrateSQLMap($this->machineName,
      array(
          'title' => array('type' => 'varchar',
                          'length' => 255,
                          'not null' => TRUE,
                          'description' => 'Title',
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
    
    $body_arguments = MigrateTextFieldHandler::arguments(array('source_field'=>'summary'), array('format' => 'plain_text'), NULL);
    $this->addFieldMapping('body', 'body')
         ->arguments($body_arguments);
    $this->addFieldMapping('field_content_author','author')
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
    //$current_row = $this->maximObj->prepareContent($current_row);
    $current_row->body = '';
  }

  public function complete($entity, stdClass $source_row){
    // Retrieve slides from CSV file
    $arSlides = $this->getHot100Slides();

    /* Loop thru slides and add tables */
    $ct = 0;
    foreach ($arSlides as $slide) {
      if (strlen($slide['file']) > 0) {
        $query = db_select('file_managed', 'f')
          ->fields('f', array('fid','filename', 'uri'))
          ->condition('f.filename', $slide['file']);
        $qryResults = $query->execute();
        $num_rows = $qryResults->rowCount();
        echo 'numrows: ' . $num_rows . ':' . $slide['file'] . ': ' . $slide['title'] . "\n";
        if ($num_rows > 0) {
          foreach ($qryResults as $record){
            if (strlen($record->fid) > 0) {
              $this->insertSlide($entity, $ct++, $record->fid, $slide['title'], $slide['caption']);
            } else {
              $this->insertSlide($entity, $ct++, null, $slide['title'], $slide['caption']);
            }
          }
        } else {
          $this->insertSlide($entity, $ct++, null, $slide['title'], $slide['caption']);
        }
      } else {
        $this->insertSlide($entity, $ct++, null, $slide['title'], $slide['caption']);
      }
    }
  }

  private function getHot100Slides(){
    $csvFile = drupal_get_path('module', 'migrate_maxim') . '/2012list.csv';
    $arSlides = array();

    $file = fopen($csvFile, 'r');
    while (($line = fgetcsv($file)) !== FALSE) {
      if ($line[0] != 'Image ID') {
        array_push($arSlides, array(
          'file' => $line[0],
          'title' => utf8_encode($line[1]),
          'caption' => utf8_encode($line[2]),
        ));
      }
    }
    fclose($file);
    return $arSlides;
  }
  
  public function insertSlide($entity, $field_delta, $file_id, $title, $caption){
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
      'field_slides_description' => null,
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
