<?php

/**
 * Settings form.
 */
function simpleshare_admin_settings() {
  $form = array();
  $form['simpleshare_methods'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Share methods'),
    '#options' => simpleshare_methods(),
    '#default_value' => variable_get('simpleshare_methods', array_keys(simpleshare_methods())),
    '#description' => t('Select which share methods are available.'),
  );
  return system_settings_form($form);
}
