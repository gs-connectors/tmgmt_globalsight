<?php

function tmgmt_globalsight_admin_form() {
  $form = array();

  $form['sync'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Sync translations'),
  );
  $form['sync']['download'] = array(
    '#type' => 'submit',
    '#value' => t('Download'),
    '#description' => t('Try to download translations manually.')
  );

  $form['tmgmt_globalsight_download_on_cron'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('tmgmt_globalsight_download_on_cron', 1),
    '#title' => t('Download on cron'),
    '#description' => t('Enabling this allows download of new translations during cron jobs.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function tmgmt_globalsight_admin_form_submit(&$form, &$form_state) {
  //dsm($form_state);
  switch ($form_state['values']['op']) {

    // Handles settings submission.
    case $form_state['values']['submit']:
      variable_set('tmgmt_globalsight_download_on_cron', $form_state['values']['tmgmt_globalsight_download_on_cron']);
      break;

    // Handles download button.
    case $form_state['values']['download']:
      tmgmt_globalsight_get_all();
      break;
  }


}
