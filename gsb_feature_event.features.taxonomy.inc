<?php
/**
 * @file
 * gsb_feature_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function gsb_feature_event_taxonomy_default_vocabularies() {
  return array(
    'event_test_vocab1' => array(
      'name' => 'Event Test Vocab1',
      'machine_name' => 'event_test_vocab1',
      'description' => 'Just a vocabulary we can use to test events with. ',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'event_test_vocab2' => array(
      'name' => 'Event Test Vocab2',
      'machine_name' => 'event_test_vocab2',
      'description' => 'Just a vocabulary we can use to test events with. ',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
