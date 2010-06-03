Drupal.behaviors.simpleshare = function() {
  $('a.simpleshare:not(.processed)').each(function() {
    $(this).addClass('processed').click(function() {
      // Cleanup any existing popups.
      $('div.simpleshare-popup').remove();

      // Make an AJAX call for this link.
      var title = $(this).attr('title') ? $(this).attr('title') : $(document).attr('title');
      var url = $(this).attr('href');
      var ajax_url = Drupal.settings.basePath + 'simpleshare';
      $.get(ajax_url, {'title': title, 'url': url}, function(data) {
        $(document.body).append(data);
        $('div.simpleshare-popup').show()
        .children('span.close').click(function() {
          $('div.simpleshare-popup').remove();
        });
      });
      return false;
    });
  });
};
