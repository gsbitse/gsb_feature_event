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
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
 * Implements hook_flag_default_flags().
 */
function gsb_feature_event_flag_default_flags() {
  $flags = array();
  // Exported flag: "Promote to Front Page Flag".
  $flags['promote_to_front_page_flag'] = array(
    'content_type' => 'node',
    'title' => 'Promote to Front Page Flag',
    'global' => '0',
    'types' => array(
      0 => 'gsb_event',
    ),
    'flag_short' => 'Promote to Front Page Flag',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'UnPromote from Front Page Flag',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'gsb_feature_event',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

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

/**
 * Implements hook_default_search_api_index().
 */
function gsb_feature_event_default_search_api_index() {
  $items = array();
  $items['event_index'] = entity_import('search_api_index', '{
    "name" : "Event Index",
    "machine_name" : "event_index",
    "description" : "Index for all Events",
    "server" : "solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "field_club_description" : { "type" : "text" },
        "field_event_test_vocab_1" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_test_vocab_2" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_audience" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "search_api_url" : { "type" : "uri" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "gsb_event" : "gsb_event" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title-search",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_club_description" : true, "search_api_aggregation_1" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_club_description" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_club_description" : true, "search_api_aggregation_1" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_club_description" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
