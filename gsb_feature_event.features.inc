<?php
/**
 * @file
 * gsb_feature_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gsb_feature_event_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gsb_feature_event_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function gsb_feature_event_image_default_styles() {
  $styles = array();

  // Exported image style: gsb_event_168x100.
  $styles['gsb_event_168x100'] = array(
    'name' => 'gsb_event_168x100',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '168',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function gsb_feature_event_node_info() {
  $items = array(
    'gsb_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('The GSB Public Event content type is used for events on the GSB Public web site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
