<?php

class views_handler_argument_fooaggregator_fid extends views_handler_argument_numeric {
    /**
     * Override the behavior of title(). Get the feed name.
     */
    function title_query() {
        $names = array();

        $result = db_select('fooaggregator_feed', 'f')
            ->fields('f', array('title'))
            ->condition('f.fid', $this->value, 'IN')
            ->execute();
        foreach ($result as $o) {
            $names[] = check_plain($o->title);
        }

        return $names;
    }
}

?>
