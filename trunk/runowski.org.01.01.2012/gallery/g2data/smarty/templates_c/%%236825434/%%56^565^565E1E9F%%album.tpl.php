<?php /* Smarty version 2.6.16, created on 2008-01-08 08:07:25
         compiled from gallery:themes/carbon/templates/album.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'markup', 'gallery:themes/carbon/templates/album.tpl', 63, false),array('modifier', 'entitytruncate', 'gallery:themes/carbon/templates/album.tpl', 169, false),)), $this); ?>
<table class="gcBackground1" width="100%" cellspacing="0" cellpadding="0">
<tr valign="top">
<td>
<div id="gsContent" class="gcBorder1">
<div class="gbBlockTop">
<table>
<tr>
<td class="gsActionIcon">
<div class="buttonShowSidebar"><a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "jsWarning=true"), $this);?>
"
onclick="slideIn('sidebar'); return false;"
title="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Show Sidebar'), $this);?>
"></a></div>
</td>
<?php if (( isset ( $this->_tpl_vars['links'] ) || isset ( $this->_tpl_vars['theme']['itemLinks'] ) )):  if (! isset ( $this->_tpl_vars['links'] )):  $this->assign('links', $this->_tpl_vars['theme']['itemLinks']);  endif;  $_from = $this->_tpl_vars['links']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['itemLink']):
 if ($this->_tpl_vars['itemLink']['moduleId'] == 'cart'): ?>
<td class="gsActionIcon">
<div class="buttonCart"><a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['itemLink']['params']), $this);?>
"
title="<?php echo $this->_tpl_vars['itemLink']['text']; ?>
"></a></div>
</td>
<?php elseif ($this->_tpl_vars['itemLink']['moduleId'] == 'comment'):  if ($this->_tpl_vars['itemLink']['params']['view'] == "comment.AddComment"): ?>
<td class="gsActionIcon">
<div class="buttonAddComment"><a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['itemLink']['params']), $this);?>
"
title="<?php echo $this->_tpl_vars['itemLink']['text']; ?>
"></a></div>
</td>
<?php elseif ($this->_tpl_vars['itemLink']['params']['view'] == "comment.ShowAllComments"): ?>
<td class="gsActionIcon">
<div class="buttonViewComments"><a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['itemLink']['params']), $this);?>
"
title="<?php echo $this->_tpl_vars['itemLink']['text']; ?>
"></a></div>
</td>
<?php endif;  elseif ($this->_tpl_vars['itemLink']['moduleId'] == 'slideshow'): ?>
<td class="gsActionIcon">
<div class="buttonViewSlideshow"><a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['itemLink']['params']), $this);?>
"
title="<?php echo $this->_tpl_vars['itemLink']['text']; ?>
"></a></div>
</td>
<?php endif;  endforeach; endif; unset($_from);  endif; ?>
</tr>
</table>
</div>
<?php if (! empty ( $this->_tpl_vars['theme']['navigator'] )): ?>
<div class="gbNavigator">
<?php echo $this->_reg_objects['g'][0]->theme(array('include' => "navigator.tpl"), $this);?>

</div>
<?php endif; ?>
<table width="100%" cellspacing="0" cellpadding="0">
<tr valign="top">
<td width="30%">
<div class="gsContentDetail">
<div class="gbBlock">
<?php if (! empty ( $this->_tpl_vars['theme']['item']['title'] )): ?>
<h2> <?php echo ((is_array($_tmp=$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)); ?>
 </h2>
<?php endif;  if (! empty ( $this->_tpl_vars['theme']['item']['description'] )): ?>
<p class="giDescription">
<?php echo ((is_array($_tmp=$this->_tpl_vars['theme']['item']['description'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)); ?>

</p>
<?php endif; ?>
</div>
<div class="gbBlock">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.ItemInfo",'item' => $this->_tpl_vars['theme']['item'],'showDate' => true,'showSize' => true,'showOwner' => $this->_tpl_vars['theme']['params']['showAlbumOwner'],'class' => 'giInfo'), $this);?>

</div>
<div class="gbBlock">
<?php $_from = $this->_tpl_vars['theme']['params']['albumUpperBlocks']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['block']):
 echo $this->_reg_objects['g'][0]->block(array('type' => $this->_tpl_vars['block']['0'],'params' => $this->_tpl_vars['block']['1']), $this);?>

<?php endforeach; endif; unset($_from); ?>
</div>
</div>
</td>
<td>
<?php if (! count ( $this->_tpl_vars['theme']['children'] )): ?>
<div class="giDescription gbEmptyAlbum">
<h3 class="emptyAlbum">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "This album is empty."), $this);?>

<?php if (isset ( $this->_tpl_vars['theme']['permissions']['core_addDataItem'] )): ?>
<br/>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ItemAdmin",'arg2' => "subView=core.ItemAdd",'arg3' => "itemId=".($this->_tpl_vars['theme']['item']['id'])), $this);?>
">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Add a photo!"), $this);?>

</a>
<?php endif; ?>
</h3>
</div>
<?php else:  $this->assign('childrenInColumnCount', 0); ?>
<div class="gsContentAlbum">
<table id="gsThumbMatrix" width="100%">
<tr valign="top">
<?php $_from = $this->_tpl_vars['theme']['children']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['child']):
 if (( $this->_tpl_vars['childrenInColumnCount'] == $this->_tpl_vars['theme']['params']['columns'] )): ?>
</tr>
<tr valign="top">
<?php $this->assign('childrenInColumnCount', 0);  endif;  $this->assign('childrenInColumnCount', ($this->_tpl_vars['childrenInColumnCount']+1)); ?>
<td class="<?php if ($this->_tpl_vars['child']['canContainChildren']): ?>giAlbumCell<?php else: ?>giItemCell<?php endif; ?>"
style="width: <?php echo $this->_tpl_vars['theme']['columnWidthPct']; ?>
%">
<?php if (( $this->_tpl_vars['child']['canContainChildren'] || $this->_tpl_vars['child']['entityType'] == 'GalleryLinkItem' )):  $this->assign('frameType', 'albumFrame');  ob_start();  echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ShowItem",'arg2' => "itemId=".($this->_tpl_vars['child']['id'])), $this); $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('linkUrl', ob_get_contents());ob_end_clean();  else:  $this->assign('frameType', 'itemFrame');  ob_start();  echo '';  if ($this->_tpl_vars['theme']['params']['dynamicLinks'] == 'jump'):  echo '';  echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ShowItem",'arg2' => "itemId=".($this->_tpl_vars['child']['id'])), $this); echo '';  else:  echo '';  echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['child']['id'])), $this); echo '';  endif;  echo '';  $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('linkUrl', ob_get_contents());ob_end_clean();  endif; ?>
<div>
<?php echo '';  if (isset ( $this->_tpl_vars['theme']['params'][$this->_tpl_vars['frameType']] ) && isset ( $this->_tpl_vars['child']['thumbnail'] )):  echo '';  $this->_tag_stack[] = array('container', array('type' => "imageframe.ImageFrame",'frame' => $this->_tpl_vars['theme']['params'][$this->_tpl_vars['frameType']],'width' => $this->_tpl_vars['child']['thumbnail']['width'],'height' => $this->_tpl_vars['child']['thumbnail']['height']), $this); $_block_repeat=true; $this->_reg_objects['g'][0]->container($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat); while ($_block_repeat) { ob_start(); echo '<a href="';  echo $this->_tpl_vars['linkUrl'];  echo '">';  echo $this->_reg_objects['g'][0]->image(array('id' => "%ID%",'item' => $this->_tpl_vars['child'],'image' => $this->_tpl_vars['child']['thumbnail'],'class' => "%CLASS% giThumbnail"), $this); echo '</a>';  $_obj_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo $this->_reg_objects['g'][0]->container($this->_tag_stack[count($this->_tag_stack)-1][1], $_obj_block_content, $this, $_block_repeat);} array_pop($this->_tag_stack); echo '';  elseif (isset ( $this->_tpl_vars['child']['thumbnail'] )):  echo '<a href="';  echo $this->_tpl_vars['linkUrl'];  echo '">';  echo $this->_reg_objects['g'][0]->image(array('item' => $this->_tpl_vars['child'],'image' => $this->_tpl_vars['child']['thumbnail'],'class' => 'giThumbnail'), $this); echo '</a>';  else:  echo '<a href="';  echo $this->_tpl_vars['linkUrl'];  echo '" class="giMissingThumbnail">';  echo $this->_reg_objects['g'][0]->text(array('text' => 'no thumbnail'), $this); echo '</a>';  endif;  echo ''; ?>

</div>
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.ItemLinks",'item' => $this->_tpl_vars['child'],'links' => $this->_tpl_vars['child']['itemLinks']), $this);?>

<?php if (! empty ( $this->_tpl_vars['child']['title'] )):  if ($this->_tpl_vars['child']['canContainChildren']): ?>
<table cellpadding="0" cellspacing="0">
<tr>
<td class="giTitleIcon">
<img src="<?php echo $this->_reg_objects['g'][0]->url(array('href' => "themes/carbon/images/album.gif"), $this);?>
" alt=""/>
</td>
<td>
<p class="giTitle"><?php echo ((is_array($_tmp=$this->_tpl_vars['child']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)); ?>
</p>
</td>
</tr>
</table>
<?php else: ?>
<p class="giTitle"><?php echo ((is_array($_tmp=$this->_tpl_vars['child']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)); ?>
</p>
<?php endif;  endif;  if (! empty ( $this->_tpl_vars['child']['summary'] )): ?>
<p class="giDescription">
<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['child']['summary'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)))) ? $this->_run_mod_handler('entitytruncate', true, $_tmp, 256) : smarty_modifier_entitytruncate($_tmp, 256)); ?>

</p>
<?php endif;  if (! $this->_tpl_vars['theme']['params']['itemDetails']):  echo $this->_reg_objects['g'][0]->block(array('type' => "core.ItemInfo",'item' => $this->_tpl_vars['child'],'showSummaries' => true,'class' => 'giInfo'), $this);?>

<?php else:  if (( $this->_tpl_vars['child']['canContainChildren'] && $this->_tpl_vars['theme']['params']['showAlbumOwner'] ) || ( ! $this->_tpl_vars['child']['canContainChildren'] && $this->_tpl_vars['theme']['params']['showImageOwner'] )):  $this->assign('showOwner', true);  else:  $this->assign('showOwner', false);  endif;  echo $this->_reg_objects['g'][0]->block(array('type' => "core.ItemInfo",'item' => $this->_tpl_vars['child'],'showDate' => true,'showOwner' => $this->_tpl_vars['showOwner'],'showSize' => true,'showViewCount' => true,'showSummaries' => true,'class' => 'giInfo'), $this);?>

<?php endif; ?>
</td>
<?php endforeach; endif; unset($_from);  unset($this->_sections['flush']);
$this->_sections['flush']['name'] = 'flush';
$this->_sections['flush']['start'] = (int)$this->_tpl_vars['childrenInColumnCount'];
$this->_sections['flush']['loop'] = is_array($_loop=$this->_tpl_vars['theme']['params']['columns']) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
$this->_sections['flush']['show'] = true;
$this->_sections['flush']['max'] = $this->_sections['flush']['loop'];
$this->_sections['flush']['step'] = 1;
if ($this->_sections['flush']['start'] < 0)
    $this->_sections['flush']['start'] = max($this->_sections['flush']['step'] > 0 ? 0 : -1, $this->_sections['flush']['loop'] + $this->_sections['flush']['start']);
else
    $this->_sections['flush']['start'] = min($this->_sections['flush']['start'], $this->_sections['flush']['step'] > 0 ? $this->_sections['flush']['loop'] : $this->_sections['flush']['loop']-1);
if ($this->_sections['flush']['show']) {
    $this->_sections['flush']['total'] = min(ceil(($this->_sections['flush']['step'] > 0 ? $this->_sections['flush']['loop'] - $this->_sections['flush']['start'] : $this->_sections['flush']['start']+1)/abs($this->_sections['flush']['step'])), $this->_sections['flush']['max']);
    if ($this->_sections['flush']['total'] == 0)
        $this->_sections['flush']['show'] = false;
} else
    $this->_sections['flush']['total'] = 0;
if ($this->_sections['flush']['show']):

            for ($this->_sections['flush']['index'] = $this->_sections['flush']['start'], $this->_sections['flush']['iteration'] = 1;
                 $this->_sections['flush']['iteration'] <= $this->_sections['flush']['total'];
                 $this->_sections['flush']['index'] += $this->_sections['flush']['step'], $this->_sections['flush']['iteration']++):
$this->_sections['flush']['rownum'] = $this->_sections['flush']['iteration'];
$this->_sections['flush']['index_prev'] = $this->_sections['flush']['index'] - $this->_sections['flush']['step'];
$this->_sections['flush']['index_next'] = $this->_sections['flush']['index'] + $this->_sections['flush']['step'];
$this->_sections['flush']['first']      = ($this->_sections['flush']['iteration'] == 1);
$this->_sections['flush']['last']       = ($this->_sections['flush']['iteration'] == $this->_sections['flush']['total']);
?>
<td>&nbsp;</td>
<?php endfor; endif; ?>
</tr>
</table>
</div>
<?php endif; ?>
</td>
</tr>
</table>
<?php if (! empty ( $this->_tpl_vars['theme']['navigator'] )): ?>
<div class="gbNavigator">
<?php echo $this->_reg_objects['g'][0]->theme(array('include' => "navigator.tpl"), $this);?>

</div>
<?php endif;  echo $this->_reg_objects['g'][0]->block(array('type' => "core.EmergencyEditItemLink",'class' => 'gbBlock','checkBlocks' => "sidebar,album,albumUpper"), $this);?>

<?php $_from = $this->_tpl_vars['theme']['params']['albumBlocks']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['block']):
 echo $this->_reg_objects['g'][0]->block(array('type' => $this->_tpl_vars['block']['0'],'params' => $this->_tpl_vars['block']['1']), $this);?>

<?php endforeach; endif; unset($_from); ?>
</div>
</td>
</tr>
</table>
<?php if (! empty ( $this->_tpl_vars['theme']['params']['sidebarBlocks'] )):  echo $this->_reg_objects['g'][0]->theme(array('include' => "sidebar.tpl"), $this);?>

<?php endif; ?>