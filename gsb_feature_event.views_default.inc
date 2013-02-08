<?php
/**
 * @file
 * gsb_feature_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gsb_feature_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'gsb_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GSB Event';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Event Image */
  $handler->display->display_options['fields']['field_event_image']['id'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['table'] = 'field_data_field_event_image';
  $handler->display->display_options['fields']['field_event_image']['field'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_image']['settings'] = array(
    'image_style' => 'gsb_image_small',
    'image_link' => '',
  );
  /* Field: Content: Event Date */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gsb_event' => 'gsb_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 2;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Node Id';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Event Test Vocab 1 (field_event_test_vocab_1) */
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['id'] = 'field_event_test_vocab_1_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['table'] = 'field_data_field_event_test_vocab_1';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['field'] = 'field_event_test_vocab_1_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['value'] = '';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['expose']['operator_id'] = 'field_event_test_vocab_1_tid_op';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['expose']['label'] = 'Event Test Vocab 1 (field_event_test_vocab_1)';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['expose']['operator'] = 'field_event_test_vocab_1_tid_op';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['expose']['identifier'] = 'field_event_test_vocab_1_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_test_vocab_1_tid']['vocabulary'] = 'event_test_vocab1';
  /* Filter criterion: Content: Event Test Vocab 2 (field_event_test_vocab_2) */
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['id'] = 'field_event_test_vocab_2_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['table'] = 'field_data_field_event_test_vocab_2';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['field'] = 'field_event_test_vocab_2_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['value'] = '';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['expose']['operator_id'] = 'field_event_test_vocab_2_tid_op';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['expose']['label'] = 'Event Test Vocab 2 (field_event_test_vocab_2)';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['expose']['operator'] = 'field_event_test_vocab_2_tid_op';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['expose']['identifier'] = 'field_event_test_vocab_2_tid';
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_test_vocab_2_tid']['vocabulary'] = 'event_test_vocab2';

  /* Display: Sidebar */
  $handler = $view->new_display('panel_pane', 'Sidebar', 'sidebar');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'GSB Content Panes';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Front Page */
  $handler = $view->new_display('block', 'Front Page', 'frontpage');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['gsb_event'] = $view;

  return $export;
}
