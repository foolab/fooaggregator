<?php

function fooaggregator_views_handlers() {
  $data['info'] = array('path' => drupal_get_path('module', 'fooaggregator'));
  $data['handlers']['views_handler_argument_fooaggregator_fid']['parent'] = 'views_handler_argument_numeric';

  return $data;
}

function fooaggregator_views_data() {
  $data = array();

  $data['fooaggregator_feed']['table']['group'] = t('Rss Feed');
  $data['fooaggregator_feed']['table']['base'] = array(
        'field' => 'fid', 'title' => t('Rss Feed')
	);

  $data['fooaggregator_feed']['fid'] = array(
        'title' => t('Feed ID'),
	'field' => array('handler' => 'views_handler_field_numeric',),
	'sort' => array('handler' => 'views_handler_sort'),
	'argument' => array('handler' => 'views_handler_argument_fooaggregator_fid',
			    ),
/*
			    'parent' => 'views_handler_argument_numeric',
			    'numeric' => TRUE,
			    'name field' => 'title',
			    'validate type' => 'fid',
			    ),
	*/
	'filter' => array('handler' => 'views_handler_filter_numeric'),
	);
  $data['fooaggregator_feed']['title'] = array(
        'title' => t('Feed Name'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['url'] = array(
        'title' => t('RSS Feed URL'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['link'] = array(
        'title' => t('Link'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['checked'] = array(
        'title' => t('Last Checked'),
	'field' => array('handler' => 'views_handler_field_numeric',),
	);
  $data['fooaggregator_feed']['updated'] = array(
        'title' => t('Last Updated'),
	'field' => array('handler' => 'views_handler_field_numeric',),
	);
  $data['fooaggregator_feed']['modified'] = array(
        'title' => t('Last Modified'),
	'field' => array('handler' => 'views_handler_field_numeric',),
	);
  $data['fooaggregator_feed']['description'] = array(
        'title' => t('Description'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['image_url'] = array(
        'title' => t('Image Link'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['image_title'] = array(
        'title' => t('Image Title'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['image_link'] = array(
        'title' => t('Image Link'),
	'field' => array('handler' => 'views_handler_field',),
	);
  $data['fooaggregator_feed']['visible'] = array(
        'title' => t('Visible Or Not'),
	'field' => array('handler' => 'views_handler_field_numeric',),
	'filter' => array('handler' => 'views_handler_filter_boolean_operator',
			  'type' => 'yes-no',
			  'label' => t('Visible'),),
	);

  $data['fooaggregator']['table']['group'] = t('Rss Feed Item');
  $data['fooaggregator']['table']['join']['node'] = array(
        'left_field' => 'nid',
	'field' => 'nid',
	);

  /*
  $data['fooaggregator']['table']['join']['fooaggregator_feed'] = array(
									'left_field' => 'fid',
									'field' => 'fid',
									'type' => 'INNER',
									);
  */
  $data['fooaggregator']['link'] = array(
        'title' => t('Link'),
	'help' => t('Link to the item'),
	'field' => array(
			 'handler' => 'views_handler_field',
			 'click sortable' => FALSE,
			 ),
	);

   $data['fooaggregator']['fid'] = array(
      'title' => t('Feed ID'),
      'relationship' => array(
			      'handler' => 'views_handler_relationship',
			      'base' => 'fooaggregator_feed',
			      'base field' => 'fid',
			      'label' => t('Rss Feed'),
			      ),
      );

  return $data;
}

?>
