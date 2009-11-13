<?php

/**
 * Implementation of hook_views_handlers()
 */
function simpleshare_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'simpleshare') . '/views',
    ),
    'handlers' => array(
      'simpleshare_handler_field_link' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter()
 */
function simpleshare_views_data_alter(&$data) {
  $data['views']['simpleshare_link'] = array(
    'title' => t('Simple Share link'),
    'help' => t('Link for sharing a particular item.'),
    'field' => array(
      'handler' => 'simpleshare_handler_field_link',
    ),
  );
}
