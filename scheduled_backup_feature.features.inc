<?php
/**
 * @file
 * scheduled_backup_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scheduled_backup_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
}
