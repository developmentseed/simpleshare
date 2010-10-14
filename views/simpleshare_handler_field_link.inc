<?php
// $Id$

/**
 * @file
 * Class definition of simpleshare_handler_field_link.
 */

/**
 * Allows users to link to a given item through a service.
 */
class simpleshare_handler_field_link extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    $options['url'] = array('default' => '', 'translatable' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['url'] = array(
      '#title' => t('URL to share'),
      '#type' => 'textfield',
      '#default_value' => $this->options['url'],
    );
    $form['text'] = array(
      '#title' => t('Text'),
      '#type' => 'textfield',
      '#default_value' => $this->options['text'],
    );
    $form['help'] = array(
      '#type' => 'item',
      '#value' => $parent_form['alter']['help']['#prefix'],
    );

  }

  function render($values) {
    return check_plain($this->options['text']);
  }

  /**
   * Render a field using advanced settings.
   *
   * This renders a field normally, then decides if render-as-link and
   * text-replacement rendering is necessary.
   */
  function advanced_render($values) {
    drupal_add_js(drupal_get_path('module', 'simpleshare') . '/simpleshare.js');
    drupal_add_css(drupal_get_path('module', 'simpleshare') . '/simpleshare.css');

    $this->last_render = $value = $this->render($values);
    $this->original_value = $value;

    $tokens = $this->get_render_tokens($this->options['alter']);

    $url = filter_xss_admin($this->options['url']);
    $url = strtr($url, $tokens);
    $url = strip_tags($url);

    $text = filter_xss_admin($this->options['text']);
    $text = strip_tags(strtr($text, $tokens));
    $options = array(
      'absolute' => TRUE,
      'attributes' => array(
        'title' => $text,
      ),
    );
    $output = '<span class="simpleshare">' . l($value, $url, $options) . '</span>';
    return $output;
  }
}
