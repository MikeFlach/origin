<?php

function maxim_base_alpha_preprocess_page(&$vars) {
  $vars['page']['content']['content']['content_container']['#sorted'] = FALSE;

  if (!empty($vars['page']['#excluded']['feature'])) {
    $vars['page']['#excluded']['feature']['#data']['weight'] = 1;
    $vars['page']['#excluded']['feature']['#data']['wrapper_css'] = '.alpha .omega';    
    $vars['page']['content']['content']['content_container']['feature'] = $vars['page']['#excluded']['feature'];
  }

  if (!empty($vars['page']['#excluded']['content'])) {
    $vars['page']['#excluded']['content']['#data']['weight'] = 3;
    $vars['page']['#excluded']['content']['#data']['wrapper_css'] = '.alpha';    
    $vars['page']['content']['content']['content_container']['content'] = $vars['page']['#excluded']['content'];
  }

  if (!empty($vars['page']['#excluded']['sidebar_first'])) {
    $vars['page']['#excluded']['sidebar_first']['#data']['weight'] = 5;
    $vars['page']['#excluded']['sidebar_first']['#data']['wrapper_css'] = '.omega';    
    $vars['page']['content']['content']['content_container']['sidebar_first'] = $vars['page']['#excluded']['sidebar_first'];
  }
  
  dpm($vars);
}