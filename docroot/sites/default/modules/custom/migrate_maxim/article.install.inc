<?php

/**
 * @file
 * Set up for the Maxim Migrate
 */

function migrate_maxim_schema(){
	$schema['migrate_maxim_article_node'] = migrate_maxim_article_schema_node();
}

function migrate_maxim_article_schema_node(){
 return array(
    'description' => 'Old Maxim Articles.',
    'fields' => array(
      'guid'  => array(
        'type' => 'varchar',
				'length' => 40,
        'not null' => TRUE,
        'description' => 'GUID',
      ),
      'title'  => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => TRUE,
      ),
      'vanity' => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => FALSE,
        'description' => 'Vanity URL.  Not Used.',
      ),
      'featured' => array(
        'type' => 'boolean',
        'not null' => FALSE,
        'description' => 'Is Featured Article?',
      ),
      'feature_title' => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => FALSE,
        'description' => 'Featured Title.',
      ),
      'feature_subtitle' => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => FALSE,
        'description' => 'Featured SubTitle.',
      ),
      'author' => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => FALSE,
        'description' => 'Author',
      ),
      'image' => array(
        'type' => 'varchar',
        'length' => 40,
        'not null' => FALSE,
        'description' => 'Image ID',
      ),
      'dek' => array(
        'type' => 'longtext',
        'not null' => FALSE,
        'description' => 'DEK',
      ),
      'body' => array(
        'type' => 'longtext',
        'not null' => FALSE,
        'description' => 'Article Body',
      ),
      'start_date' => array(
        'type' => 'date',
        'not null' => FALSE,
        'description' => 'Start Date',
      ),
      'end_date' => array(
        'type' => 'date',
        'not null' => FALSE,
        'description' => 'End Date',
      ),
      'tags' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'description' => 'Tags',
      ),
      'marketing' => array(
        'type' => 'varchar',
        'length' => 155,
        'not null' => FALSE,
        'description' => 'Marketing',
      ),
      'skin' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'description' => 'Skin',
      )
    ),
    'primary key' => array('guid'),
  );

}

