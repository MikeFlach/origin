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
 * Article Tag migration
 */
class ArticleTagMigration extends MaximMigration {
	 public function __construct() {
	 	parent::__construct();
	 	
	 	$this->description = t('Migrate tags from Vignette articles to taxonomy vgn_tags');
	 	
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'guid' => array('type' => 'varchar',
                           'length' => 40,
                           'not null' => FALSE,
                           'description' => 'GUID',
                          )
        ),
        MigrateDestinationTerm::getKeySchema()
      );
      
    $query = Database::getConnection('default','vgn_maxim')
      ->select('amg_article', 'art')
      ->fields('art', array('guid','tags'))
      ->condition('tags',null,'is not');

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, array(),  NULL, array('map_joinable' => FALSE));
    $this->destination = new MigrateDestinationTerm('vgn_tags');

    $this->addFieldMapping('name', 'tags')
         ->separator(',');
       
    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('description', 'format', 'weight', 'parent_name', 'parent', 'path'), t('Do Not Migrate'));
	 }
	 
}

/*
 * Article Node migration
 */
class ArticleNodeMigration extends MaximMigration {
	private $cMap = array();
	
  public function __construct() {
    parent::__construct();
    
    $this->channelMapping();
    $this->description = t('Migrate articles from Vignette: AMG_Article table');
    
    // Define source fields (primary keys and any fields that may not be found in initial mapping query)
    $source_fields = array(
      'guid' => t('Article GUID'),
    );

    // Use database view
    $query = Database::getConnection('default','vgn_maxim')
      ->select('article_view', 'art')
      ->fields('art', array('guid', 'title', 'vanity', 'feature_title', 'feature_subtitle', 'select_type', 'author', 'image', 'dek', 'body', 'start_date', 'tags', 'channel'));

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

	  $this->addFieldMapping('title', 'title');
	  $this->addFieldMapping('field_feature_title', 'feature_title');
	  $this->addFieldMapping('field_feature_subtitle', 'feature_subtitle');
	  
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
    $source_id = $current_row->guid;

    $current_row->body = $this->formatBody($current_row->body);
    $current_row->channel = $this->getChannel($current_row->channel);
    $current_row->author = $this->formatAuthor($current_row->author);
    $current_row->tags = $this->formatTags($current_row->tags);
    
    $new_channel = $this->getChannelFromTags($current_row->tags);
    if($new_channel != ''){
    	$current_row->channel = $new_channel;
    }
    
    $current_row->column = $this->getColumn($current_row->channel);
  }
  
  /*
   * Delete taxonomy terms during rollback
   */
  public function preRollback() {
    // TODO: hardcoded vocabulary ids.  Need to get it dynamically
    $vid_vgn_column = 2; // column  
    $vid_vgn_tags = 9; // vgn tags  
    $vid_authors = 10; // content authors
    
    $terms = db_select('taxonomy_term_data', 't')->fields('t', array('tid'))->condition('vid', $vid_vgn_column)->execute();
    foreach ($terms as $term) {
      taxonomy_term_delete($term->tid);
    }
    $vocab_names = array('content_authors','freeform_tags');
    $terms = db_select('taxonomy_term_data', 't')->fields('t', array('tid'))->condition('vid', $vid_vgn_tags)->execute();
    foreach ($terms as $term) {
      taxonomy_term_delete($term->tid);
    }
    $terms = db_select('taxonomy_term_data', 't')->fields('t', array('tid'))->condition('vid', $vid_authors)->execute();
    foreach ($terms as $term) {
      taxonomy_term_delete($term->tid);
    }
  }
  
  /*
   * Get Channel based on tags
   */
  private function getChannelFromTags($tags){
  	$strChannel = '';
    if(stripos($tags, 'found porn') !== false){
    	$strChannel = 'Found Porn';
    }

    return $strChannel;
  }
  
  /*
   * Get Column for Blogs
   */
  private function getColumn($channel){
  	$strColumn = '';
  	
  	switch($channel){
  		case 'Beat This Caption':
  		case 'Dirty Briefs':
  			$strColumn = $channel;
        break;
  	}
  	
    return $strColumn;
  }
  
  /*
   * Format Body
   */ 
  private function formatBody($body){
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
  private function formatTags($tags){
  	$tags = str_replace(' and ',', ', $tags);
  	$tags = str_replace(', ', ',', $tags);
  	$tags = strtolower($tags);
  	// Remove multiple commas
  	$tags = str_replace(',,', ',', $tags);
  	// Remove last comma, if any
  	$tags = rtrim($tags, ","); 

  	return trim($tags);
  }
  
  /*
   * Format author
   */
  private function formatAuthor($author){
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
  
  /*
   * Get new channel
   */
  private function getChannel($channel){
    if(array_key_exists($channel,$this->cMap)){
  	  return $this->cMap[$channel];	
  	} else {
  		return $channel;
  	}
  }
  
  private function channelMapping(){
  	
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
	  $this->cMap['Home/GIRLS/Sex'] = 'Sex';
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
	  
	  $this->cMap['Home/Home/STUFF/Articles/Articles Subchannel 1'] = 'Gadget/Tech';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Dumb Stuff'] = 'Travel';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Eat Out and Drink Up'] = 'Travel';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Get There'] = 'Travel';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Look Awesome'] = 'Grooming';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/Stuff'] = 'Lifestyle';
	  $this->cMap['Home/Home/STUFF/Guy\`s Guide to Spring Break/True Stories of Spring Break'] = 'Travel';
	  
	  $this->cMap['Home/MOVIES'] = 'Movies';
	  $this->cMap['Home/MOVIES/Articles'] = 'Movies';
	  $this->cMap['Home/MOVIES/Slideshows'] = 'Movies';
	  $this->cMap['Home/MOVIES/Videos'] = 'Entertainment Videos';
	  
	  $this->cMap['Home/MUSIC'] = 'Music';
	  $this->cMap['Home/MUSIC/Articles'] = 'Music';
	  $this->cMap['Home/MUSIC/Slideshows'] = 'Music';
	  $this->cMap['Home/MUSIC/Videos'] = 'Entertainment Videos';
	  
	  $this->cMap['Home/SPORTS'] = 'Sports';
	  $this->cMap['Home/SPORTS/Articles'] = 'Sports';
	  $this->cMap['Home/SPORTS/Dirty Briefs'] = 'Dirty Briefs';
	  $this->cMap['Home/SPORTS/Maximum Warrior'] = 'Maximum Warrior';
	  $this->cMap['Home/SPORTS/Slidewshows'] = 'Sports';
	  $this->cMap['Home/SPORTS/Videos'] = 'Sports Videos';

	  $this->cMap['Home/STUFF'] = 'Gadgets & Rides';
	  $this->cMap['Home/STUFF/2011 Tech Buying Guide'] = 'Gift Guides';
	  $this->cMap['Home/STUFF/A Drink With Maxim'] = 'Beer, Wine, Spirits & Cocktails';
	  $this->cMap['Home/STUFF/Adam Richamn\'s Grub Guide'] = 'Food & Recipes';
	  $this->cMap['Home/STUFF/Articles'] = 'Food & Recipes';
	  $this->cMap['Home/STUFF/Dads and Grads Gift Guide'] = 'Gift Guides';
	  $this->cMap['Home/STUFF/Eat to the Beat'] = 'Food & Recipes';
	  $this->cMap['Home/STUFF/Great American Bar Search'] = 'Bars & Restaurants';
	  $this->cMap['Home/STUFF/Guy\'s Guide to Spring Break'] = 'Fashion';
	  $this->cMap['Home/STUFF/Guy\'s Guide to Summer'] = 'Fashion';
	  $this->cMap['Home/STUFF/Slideshows'] = 'Rides';
	  $this->cMap['Home/STUFF/The Real Guy\'s Guide'] = 'Fashion';
	  $this->cMap['Home/STUFF/Videos'] = 'Gadgets & Rides Videos';
	  
    $this->cMap['Home/TV'] = 'TV';
    $this->cMap['Home/TV/Articles'] = 'TV';
    $this->cMap['Home/TV/Slideshows'] = 'TV';
	  $this->cMap['Home/TV/Videos'] = 'Entertainment Videos';
	  
	  $this->cMap['Home/VIDEO'] = 'Maxim TV';
	  $this->cMap['Home/VIDEO/Gaming'] = 'Gaming Videos';
	  $this->cMap['Home/VIDEO/Girls'] = 'Girls Videos';
	  $this->cMap['Home/VIDEO/Hometown Hotties'] = 'Girls Videos';
	  $this->cMap['Home/VIDEO/Humor'] = 'Humor Videos';
	  $this->cMap['Home/VIDEO/Movies'] = 'Entertainment Videos';
	  $this->cMap['Home/VIDEO/Music Videos'] = 'Entertainment Videos';
	  $this->cMap['Home/VIDEO/Sports'] = 'Sports Videos';
	  $this->cMap['Home/VIDEO/Television'] = 'Entertainment Videos'; 

  }
  
}

