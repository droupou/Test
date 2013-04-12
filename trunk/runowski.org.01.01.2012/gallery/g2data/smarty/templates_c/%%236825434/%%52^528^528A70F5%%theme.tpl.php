<?php /* Smarty version 2.6.16, created on 2008-01-08 07:49:45
         compiled from gallery:themes/ajaxian/templates/theme.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'markup', 'gallery:themes/ajaxian/templates/theme.tpl', 14, false),array('modifier', 'default', 'gallery:themes/ajaxian/templates/theme.tpl', 14, false),)), $this); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html lang="<?php echo $this->_reg_objects['g'][0]->language(array(), $this);?>
">
<head>
<?php echo $this->_reg_objects['g'][0]->head(array(), $this);?>

<?php if (empty ( $this->_tpl_vars['head']['title'] )): ?>
<title><?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')))) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['item']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['item']['pathComponent'])); ?>
</title>
<?php endif; ?>
<link rel="stylesheet" type="text/css" href="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "theme.css"), $this);?>
" />
<?php if ($this->_tpl_vars['theme']['pageType'] == 'album' || $this->_tpl_vars['theme']['pageType'] == 'photo'): ?>
<script type="text/javascript">
// <![CDATA[
var DEBUG_AJAXIAN = false;  /* Show debug output down the side */
var LOADING_IMAGE = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Loading Image...",'forJavascript' => true), $this);?>
';
var PHOTO_DATA = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Photo Data','forJavascript' => true), $this);?>
';
var FILE_SIZE = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Full image size: %s kilobytes.",'arg1' => "%SIZE%",'forJavascript' => true), $this);?>
';
var SUMMARY = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Summary: ",'forJavascript' => true), $this);?>
';
var DESCRIPTION = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Description: ",'forJavascript' => true), $this);?>
';
var VIEW_IMAGE = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'View fullsize image','forJavascript' => true), $this);?>
';
// ]]>
</script>
<script type="text/javascript" src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "javascript/common-functions.js"), $this);?>
"></script>
<script type="text/javascript" src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "javascript/thumbnail-functions.js"), $this);?>
"></script>
<script type="text/javascript" src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "javascript/slideshow-functions.js"), $this);?>
"></script>
<?php endif; ?>
</head>
<body class="gallery">
<div id="msgarea"></div>
<div <?php echo $this->_reg_objects['g'][0]->mainDivAttributes(array(), $this);?>
>
<div id="white-rap">
<?php if ($this->_tpl_vars['theme']['useFullScreen']):  $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "gallery:".($this->_tpl_vars['theme']['moduleTemplate']), 'smarty_include_vars' => array('l10Domain' => $this->_tpl_vars['theme']['moduleL10Domain'])));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
  elseif ($this->_tpl_vars['theme']['pageType'] == 'progressbar'): ?>
<div id="header">
<h1><img src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => "images/galleryLogo_sm.gif"), $this);?>
" width="107" height="48" alt=""
id="main-logo" /></h1>
</div>
<div id="main"><div id="frame">
<?php echo $this->_reg_objects['g'][0]->theme(array('include' => "progressbar.tpl"), $this);?>

</div></div>
<?php else: ?>
<div id="header">
<h1><a href="<?php echo $this->_reg_objects['g'][0]->url(array(), $this);?>
"><img src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => "images/galleryLogo_sm.gif"), $this);?>
"
width="107" height="48" alt="Gallery" id="main-logo" /></a></h1>
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "search.SearchBlock",'showAdvancedLink' => false), $this);?>

<div class="gbBreadCrumb">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.BreadCrumb"), $this);?>

</div>
</div>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "gallery:modules/core/templates/JavaScriptWarning.tpl", 'smarty_include_vars' => array('l10Domain' => 'modules_core')));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
<div id="main">
<div id="frame">
<?php if ($this->_tpl_vars['theme']['pageType'] == 'album'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "album.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'photo'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "photo.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'admin'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "admin.tpl"), $this);?>

<?php elseif ($this->_tpl_vars['theme']['pageType'] == 'module'):  echo $this->_reg_objects['g'][0]->theme(array('include' => "module.tpl"), $this);?>

<?php endif; ?>
</div>
</div>
<div id="footer">
<p><?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => 'validation'), $this);?>

<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => 'gallery2'), $this);?>

<?php echo $this->_reg_objects['g'][0]->logoButton(array('type' => "gallery2-version"), $this);?>
</p>
<p id="footerSystemLinks">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.SystemLinks",'order' => "core.SiteAdmin core.YourAccount core.Login core.Logout",'othersAt' => 4), $this);?>

</p>
</div>
<?php endif; ?>
</div>
</div>
<?php echo $this->_reg_objects['g'][0]->trailer(array(), $this);?>

<?php echo $this->_reg_objects['g'][0]->debug(array(), $this);?>

</body>
</html>