<?php
/**
 * @file
 * scheduled_backup_feature.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function scheduled_backup_feature_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'daily_scheduled_backups';
  $item->name = 'Daily Scheduled Backups Directory';
  $item->subtype = 'file';
  $item->location = 'private://backup_migrate/scheduled/daily';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['daily_scheduled_backups'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'monthly';
  $item->name = 'Monthly Scheduled Backups Directory';
  $item->subtype = 'file';
  $item->location = 'private://backup_migrate/scheduled/monthly';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['monthly'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'weekly_scheduled_backups_directory';
  $item->name = 'Weekly Scheduled Backups Directory';
  $item->subtype = 'file';
  $item->location = 'private://backup_migrate/scheduled/weekly';
  $item->settings = array(
    'chmod' => '',
    'chgrp' => '',
  );
  $export['weekly_scheduled_backups_directory'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_profiles().
 */
function scheduled_backup_feature_exportables_backup_migrate_profiles() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'general_backup';
  $item->name = 'General Backup';
  $item->filename = '[site:name]';
  $item->append_timestamp = TRUE;
  $item->timestamp_format = 'Y-m-d\\TH-i-s';
  $item->filters = array(
    'compression' => 'gzip',
    'notify_success_enable' => 0,
    'notify_success_email' => 'dev@genero.fi',
    'notify_failure_enable' => 1,
    'notify_failure_email' => 'dev@genero.fi',
    'utils_site_offline' => 0,
    'utils_site_offline_message' => 'The site is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'utils_description' => '',
    'use_cli' => 1,
    'ignore_errors' => 0,
    'sources' => array(
      'db' => array(
        'exclude_tables' => array(
        ),
        'nodata_tables' => array(
          'cache' => 'cache',
          'cache_admin_menu' => 'cache_admin_menu',
          'cache_block' => 'cache_block',
          'cache_bootstrap' => 'cache_bootstrap',
          'cache_field' => 'cache_field',
          'cache_filter' => 'cache_filter',
          'cache_form' => 'cache_form',
          'cache_guiders' => 'cache_guiders',
          'cache_image' => 'cache_image',
          'cache_libraries' => 'cache_libraries',
          'cache_media_xml' => 'cache_media_xml',
          'cache_menu' => 'cache_menu',
          'cache_metatag' => 'cache_metatag',
          'cache_page' => 'cache_page',
          'cache_path' => 'cache_path',
          'cache_rules' => 'cache_rules',
          'cache_token' => 'cache_token',
          'cache_update' => 'cache_update',
          'cache_views' => 'cache_views',
          'cache_views_data' => 'cache_views_data',
          'history' => 'history',
          'sessions' => 'sessions',
          'watchdog' => 'watchdog',
        ),
        'utils_lock_tables' => 1,
      ),
      'files' => array(
        'exclude_filepaths' => 'backup_migrate
styles
css
js
ctools
less',
      ),
      'archive' => array(
        'exclude_filepaths' => 'public://backup_migrate
public://styles
public://css
public://js
public://ctools
public://less
private://backup_migrate
sites/default/settings.local.php
/tmp
public://',
      ),
    ),
  );
  $export['general_backup'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function scheduled_backup_feature_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'daily_schedule';
  $item->name = 'Daily Schedule';
  $item->source_id = 'db';
  $item->destination_id = 'daily_scheduled_backups';
  $item->copy_destination_id = '';
  $item->profile_id = 'general_backup';
  $item->keep = 7;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'elysia';
  $item->cron_schedule = '0 4 * * *';
  $export['daily_schedule'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'monthly_scheduled';
  $item->name = 'Monthly Scheduled';
  $item->source_id = 'db';
  $item->destination_id = 'monthly';
  $item->copy_destination_id = '';
  $item->profile_id = 'general_backup';
  $item->keep = 12;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'elysia';
  $item->cron_schedule = '20 4 8 * *';
  $export['monthly_scheduled'] = $item;

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'weekly_schedule';
  $item->name = 'Weekly Schedule';
  $item->source_id = 'db';
  $item->destination_id = 'monthly';
  $item->copy_destination_id = '';
  $item->profile_id = 'general_backup';
  $item->keep = 4;
  $item->period = 604800;
  $item->enabled = TRUE;
  $item->cron = 'elysia';
  $item->cron_schedule = '10 4 * * 0';
  $export['weekly_schedule'] = $item;

  return $export;
}
