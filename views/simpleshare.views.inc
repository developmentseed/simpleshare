<?php
// $Id$

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data_alter().
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
