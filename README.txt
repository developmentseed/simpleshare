
Simple Share
------------

Simple sharing of URLs using various methods. Supports Twitter, Facebook and
email.

Install instructions
--------------------

- Install drupal module.
- Use Views module to add a share link to your listing ("Simple Share link"
  field)
- Alternatively use hook_link_alter to add a simple share link to nodes.

Simple Share link format
------------------------

$links['simpleshare'] = array(
  'title' => t('Share'),
  'href' => '',
  'attributes' => array(
    'class' => 'simpleshare',
  ),
);