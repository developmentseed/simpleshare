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
  $form['simpleshare_non_local_url'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow non-local URLs'),
    '#default_value' => variable_get('simpleshare_non_local_url', FALSE),
    '#description' => t('Check to allow sharing of URLs that do not point back to this web site.'),
  );
  return system_settings_form($form);
}
