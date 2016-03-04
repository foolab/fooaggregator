<?php

class views_handler_argument_fooaggregator_fid extends views_handler_argument_numeric {
  /**
   * Override the behavior of title(). Get the feed name.
   */
  function title_query() {
    if (!$this->argument) {
      return array();
    }

    $names = array();
    $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));
    $result = db_query("SELECT f.title FROM {fooaggregator_feed} f WHERE f.fid IN ($placeholders)"
		       , $this->value);
    while ($o = db_fetch_object($result)) {
      $names[] = check_plain($o->title);
    }
    return $names;
  }
}

?>
