<?php
/**
 * @file
 * maxim_site_structure.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function maxim_site_structure_taxonomy_default_vocabularies() {
  return array(
    'channels' => array(
      'name' => 'Channels',
      'machine_name' => 'channels',
      'description' => 'maxim channels ',
      'hierarchy' => '1',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
