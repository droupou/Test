<?php /* Smarty version 2.6.16, created on 2008-01-08 07:50:00
         compiled from gallery:themes/carbon/templates/theme.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'markup', 'gallery:themes/carbon/templates/theme.tpl', 14, false),array('modifier', 'default', 'gallery:themes/carbon/templates/theme.tpl', 21, false),)), $this); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html lang="<?php echo $this->_reg_objects['g'][0]->language(array(), $this);?>
">
<head>
<?php echo $this->_reg_objects['g'][0]->head(array(), $this);?>

<?php if ($this->_tpl_vars['theme']['pageType'] == 'album' || $this->_tpl_vars['theme']['pageType'] == 'photo'): ?>
<meta name="keywords" content="<?php echo $this->_tpl_vars['theme']['item']['keywords']; ?>
" />
<meta name="description" content="<?php echo ((is_array($_tmp=$this->_tpl_vars['theme']['item']['description'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')); ?>
" />
<?php endif;  if ($this->_tpl_vars['theme']['pageType'] != 'admin'): ?>
<script type="text/javascript" src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => 'themes/carbon/theme.js'), $this);?>
"></script>
<?php endif;  if (empty ( $this->_tpl_vars['head']['title'] )): ?>
<title><?php echo ((is_array($_tmp=((is_array($_tmp=@$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['item']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['item']['pathComponent'])))) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')); ?>
</title>
<?php endif; ?>
<link rel="stylesheet" type="text/css" href="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "theme.css"), $this);?>
"/>
</head>
<body class="gallery">
<?php if (! empty ( $this->_tpl_vars['jsWarning'] )):  $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "gallery:modules/core/templates/JavaScriptWarning.tpl", 'smarty_include_vars' => array('l10Domain' => 'modules_core')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
  endif; ?>
<div <?php echo $this->_reg_objects['g'][0]->mainDivAttributes(array(), $this);?>
>
<?php if ($this->_tpl_vars['theme']['useFullScreen']):  $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "gallery:".($this->_tpl_vars['theme']['moduleTemplate']), 'smarty_include_vars' => array('l10Domain' => $this->_tpl_vars['theme']['moduleL10Domain'])));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
  elseif ($this->_tpl_vars['theme']['pageType'] == 'progressbar'): ?>
<div id="gsHeader">
<?php if (! empty ( $this->_tpl_vars['theme']['params']['logoImageLocation'] )): ?>
<img src="<?php echo $this->_tpl_vars['theme']['params']['logoImageLocation']; ?>
" alt=""/>
<?php else: ?>
<img src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => "images/galleryLogo_sm.gif"), $this);?>
" width="107" height="48" alt=""/>
<?php endif; ?>
</div>
<?php echo $this->_reg_objects['g'][0]->theme(array('include' => "progressbar.tpl"), $this);?>

<?php else: ?>
<div id="gsHeader">
<table width="100%" cellspacing="0" cellpadding="0">
<tr>
<td align="left" valign="top" width="50%">
<a href="<?php echo $this->_reg_objects['g'][0]->url(array(), $this);?>
">
<?php if (! empty ( $this->_tpl_vars['theme']['params']['logoImageLocation'] )): ?>
<img src="<?php echo $this->_tpl_vars['theme']['params']['logoImageLocation']; ?>
" alt=""/>
<?php else: ?>
<img src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => "images/galleryLogo_sm.gif"), $this);?>
" width="107" height="48" alt=""/>
<?php endif; ?>
</a>
</td>
<td align="right" valign="top">
<?php echo $this->_reg_objects['g'][0]->theme(array('include' => "ads.tpl"), $this);?>

</td>
</tr>
</table>
</div>
<div id="gsNavBar" class="gcBorder1">
<div class="gbSystemLinks">
<?php if (! empty ( $this->_tpl_vars['theme']['params']['extraLink'] ) && ! empty ( $this->_tpl_vars['theme']['params']['extraLinkUrl'] )): ?>
<span class="block-core-SystemLink">
<a href="<?php echo $this->_tpl_vars['theme']['params']['extraLinkUrl']; ?>
"><?php echo $this->_tpl_vars['theme']['params']['extraLink']; ?>
</a>
</span>
&laquo;
<?php endif;  echo $this->_reg_objects['g'][0]->block(array('type' => "core.SystemLinks",'order' => "core.SiteAdmin core.YourAccount core.Login core.Logout",'separator' => "&laquo;",'othersAt' => 4), $this);?>

<?php if ($this->_tpl_vars['theme']['pageType'] != 'admin'): ?>
<span class="block-core-SystemLink">
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "jsWarning=true"), $this);?>
" 
onclick="toggleSidebar('sidebar'); return false;"><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Sidebar'), $this);?>
</a>
</span>
<?php endif; ?>
</div>
<div class="gbBreadCrumb">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.BreadCrumb",'separator' => "&raquo;"), $this);?>

</div>
</div>
<?php if ($this->_tpl_vars['theme']['pageType'] == 'album'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "album.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'photo'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "photo.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'admin'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "admin.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'module'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "module.tpl"), $this);?>

<?php endif; ?>
<div id="gsFooter" class="gcBorder1">
<table width="100%" cellspacing="0" cellpadding="0">
<tr>
<td align="left" width="50%">
<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => 'validation'), $this);?>

<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => 'gallery2'), $this);?>

<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => "gallery2-version"), $this);?>

<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => 'donate'), $this);?>

</td>
<td align="right">
<?php echo '';  if (! empty ( $this->_tpl_vars['theme']['params']['copyright'] )):  echo '';  echo $this->_tpl_vars['theme']['params']['copyright'];  echo '';  endif;  echo ''; ?>

<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.GuestPreview"), $this);?>

</td>
</tr>
</table>
</div>
<?php endif; ?>  </div>
<?php echo $this->_reg_objects['g'][0]->trailer(array(), $this);?>

<?php echo $this->_reg_objects['g'][0]->debug(array(), $this);?>

</body>
</html>