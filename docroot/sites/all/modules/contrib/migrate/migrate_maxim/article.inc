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
		new MigrateTeamMember('Mike LeDu', 'mledu@maxim.com', t('Implementor')),
		new MigrateTeamMember('Henry Wan', 'hwan@maxim.com', t('Implementor')),
    	new MigrateTeamMember('Bill Breen', 'bbreen@maxim.com', t('Implementor'))
    );

  }
}

/**
 * There are four essential components to set up in your constructor:
 *  $this->source - An instance of a class derived from MigrateSource, this
 *    will feed data to the migration.
 *  $this->destination - An instance of a class derived from MigrateDestination,
 *    this will receive data that originated from the source and has been mapped
 *    by the Migration class, and create Drupal objects.
 *  $this->map - An instance of a class derived from MigrateMap, this will keep
 *    track of which source items have been imported and what destination objects
 *    they map to.
 *  Mappings - Use $this->addFieldMapping to tell the Migration class what source
 *    fields correspond to what destination fields, and additional information
 *    associated with the mappings.
 */
class ArticleNodeMigration extends MaximMigration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate articles from Vignette: AMG_Article table');

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

    $query = Database::getConnection('default','vgn_maxim')
			->select('amg_article', 'art')
			->fields('art', array('guid', 'title', 'vanity', 'featured', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'end_date', 'tags', 'marketing', 'skin', 'related'))
             // This sort assures that parents are saved before children.
             ->orderBy('guid', 'ASC');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, array(),  NULL, array('map_joinable' => FALSE));

    // Set up our destination - nodes of type article_maxim
    $this->destination = new MigrateDestinationNode('article');

    // Mapped fields

    $this->addFieldMapping('is_new')
         ->defaultValue(TRUE);
    $this->addFieldMapping('path', 'vanity')
         ->description(t('Mapping vanity from source to vanity'));

    // Comma delimited tags
    $this->addFieldMapping('field_tags', 'tags')
         ->separator(',');
		 
	$this->addFieldMapping('title', 'title');
	$this->addFieldMapping('body', 'body')
		->arguments(array('format' => 'full_html'));
	$this->addFieldMapping('field_dek', 'dek')
		->arguments(array('format' => 'full_html'));;
	$this->addFieldMapping('field_feature_list_title','feature_title');
	$this->addFieldMapping('field_feature_list_subtitle','feature_subtitle');
	$this->addFieldMapping('field_author','author');
	$this->addFieldMapping('field_vgn_guid', 'guid');
	$this->addFieldMapping('field_vgn_image_id','image');
	$this->addFieldMapping('created', 'start_date');
	$this->addFieldMapping('changed', 'start_date');
	
    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('featured', 'select_type', 'vanity', 'image', 'end_date', 'marketing', 'skin', 'related'), t('Do Not Migrate'));
  }
}


