<?php

/**
 * Provide a share link as a context reaction.
 */
class simpleshare_reaction_link extends context_reaction {
  function options_form($context) {
    return array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#description' => t('Label to use for the share link.'),
      '#default_value' => $this->fetch_from_context($context) ? $this->fetch_from_context($context) : 'Share',
    );
  }

  /**
   * Output a list of active contexts.
   */
  function execute(&$links) {
    $contexts = context_active_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions['simpleshare_link'])) {
        $links['simpleshare_link'] = array(
          'title' => $this->fetch_from_context($context) ? $this->fetch_from_context($context) : 'Share',
          'href' => $_GET['q'],
          'absolute' => TRUE,
          'attributes' => array(
            'title' => drupal_get_title(),
            'class' => 'simpleshare',
          ),
        );
      }
    }
  }
}
