<?php
/**
 * @file
 * gsb_feature_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gsb_feature_event_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|gsb_event|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'gsb_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '8',
    'children' => array(
      0 => 'field_city',
      1 => 'field_postal_code',
      2 => 'field_state',
      3 => 'field_street_address_1',
      4 => 'field_street_address_2',
      5 => 'field_street_address_3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location|node|gsb_event|form'] = $field_group;

  return $export;
}
