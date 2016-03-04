<?php // -*-php-*-

require_once 'simplepie.inc';

class FooFeed extends SimplePie {
  var $url;
  var $fid;
  var $checked;
  var $refresh;
  var $link;
  var $description;
  var $modified;
  var $updated;
  var $etag;

  var $items = array();

  var $image_title;
  var $image_link;
  var $image_url;

  // Error
  var $_ok;
  var $_error;
  function ok(&$err) {
    $err = $this->error();
    return $this->_ok;
  }

  function FooFeed(&$feed, &$string) {
    SimplePie::SimplePie();
    // todo: configurable.
    ////    SimplePie::strip_ads(true);
    SimplePie::strip_htmltags(false);
    //    SimplePie::feed_url($feed->url);
    SimplePie::set_raw_data($string);

    $this->_ok = SimplePie::init();
    if (!$this->_ok) {
      return;
    }

    $this->fid = $feed->fid;
    $this->url = $feed->url;
    $this->checked = time();
    $this->updated = $this->checked;
    $this->link = SimplePie::get_link();
    $this->description = SimplePie::get_description();
    $this->refresh = $feed->refresh;
    $this->modified = $feed->modified;
    $this->etag = $feed->etag;

    $this->image_title = SimplePie::get_image_title();
    $this->image_link = SimplePie::get_image_link();
    $this->image_url = SimplePie::get_image_url();

    foreach (SimplePie::get_items() as $_item) {
      $item = array();
      $item['title'] = $_item->get_title();
      $item['description'] = $_item->get_description();
      $item['time'] = $_item->get_date('U');
      $item['guid'] = $_item->get_id();
      $item['link'] = $_item->get_permalink();

      if (!$item['guid']) {
	$item['guid'] = $item['title'];
      }
      if (!$item['time']) {
	$item['time'] = time();
      }

      $this->items[] = $item;
    }
    //    print_r($this);
  }
}
?>
