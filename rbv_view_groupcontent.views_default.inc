<?php
/**
 * @file
 * rbv_view_groupcontent.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rbv_view_groupcontent_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rbv_view_groupcontent';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'rbv_view_groupcontent';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Collaborazioni';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'vmode_group_content';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content in this group.';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_com_logo']['id'] = 'field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['table'] = 'field_data_field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['field'] = 'field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['label'] = '';
  $handler->display->display_options['fields']['field_com_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Slogan */
  $handler->display->display_options['fields']['field_com_tagline']['id'] = 'field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['table'] = 'field_data_field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['field'] = 'field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_com_tagline']['element_label_colon'] = FALSE;
  /* Field: Content: Settori di impatto */
  $handler->display->display_options['fields']['field_com_categories']['id'] = 'field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['table'] = 'field_data_field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['field'] = 'field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['label'] = '';
  $handler->display->display_options['fields']['field_com_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_com_categories']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );

  /* Display: Pane: Progetti */
  $handler = $view->new_display('panel_pane', 'Pane: Progetti', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Progetti';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_com_logo']['id'] = 'field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['table'] = 'field_data_field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['field'] = 'field_com_logo';
  $handler->display->display_options['fields']['field_com_logo']['label'] = '';
  $handler->display->display_options['fields']['field_com_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_com_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Slogan */
  $handler->display->display_options['fields']['field_com_tagline']['id'] = 'field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['table'] = 'field_data_field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['field'] = 'field_com_tagline';
  $handler->display->display_options['fields']['field_com_tagline']['label'] = '';
  $handler->display->display_options['fields']['field_com_tagline']['element_label_colon'] = FALSE;
  /* Field: Content: Settori di impatto */
  $handler->display->display_options['fields']['field_com_categories']['id'] = 'field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['table'] = 'field_data_field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['field'] = 'field_com_categories';
  $handler->display->display_options['fields']['field_com_categories']['label'] = '';
  $handler->display->display_options['fields']['field_com_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_com_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_com_categories']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );

  /* Display: Pane: Relazioni */
  $handler = $view->new_display('panel_pane', 'Pane: Relazioni', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Relazioni';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'relation' => 'relation',
  );
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );

  /* Display: Pane: Collaborazioni */
  $handler = $view->new_display('panel_pane', 'Pane: Collaborazioni', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Collaborazioni';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'collaboration' => 'collaboration',
  );
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );
  $export['rbv_view_groupcontent'] = $view;

  return $export;
}
