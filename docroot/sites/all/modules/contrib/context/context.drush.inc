<?php
/**
 * @file
 * Drush integration of Context.
 *
 * * drush cache-clear context - Clears the Context specific caches.
 */

//Maxim Patch This whole file is a patch to add drush cache clear to drush menu
/**
 * Adds a cache clear option for context.
 */
function context_drush_cache_clear(&$types) {
  $types['context'] = 'context_invalidate_cache';
}
