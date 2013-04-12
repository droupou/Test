<?php /* Smarty version 2.6.16, created on 2008-01-08 07:49:51
         compiled from gallery:themes/ajaxian/templates/album.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'markup', 'gallery:themes/ajaxian/templates/album.tpl', 7, false),array('modifier', 'default', 'gallery:themes/ajaxian/templates/album.tpl', 7, false),array('modifier', 'entitytruncate', 'gallery:themes/ajaxian/templates/album.tpl', 109, false),)), $this); ?>
<h2 id="item-title"><?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp) : smarty_modifier_markup($_tmp)))) ? $this->_run_mod_handler('default', true, $_tmp, ' ') : smarty_modifier_default($_tmp, ' ')); ?>
</h2>
<?php if (! empty ( $this->_tpl_vars['theme']['navigator'] )): ?>
<div class="gbBlock gcBackground2 gbNavigator">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.Navigator",'navigator' => $this->_tpl_vars['theme']['navigator'],'reverseOrder' => true), $this);?>

</div>
<?php endif;  if (! count ( $this->_tpl_vars['theme']['children'] )): ?>
<div class="gbBlock giDescription gbEmptyAlbum">
<p class="emptyAlbum">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "This album is empty."), $this);?>

<?php if (isset ( $this->_tpl_vars['theme']['permissions']['core_addDataItem'] )): ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ItemAdmin",'arg2' => "subView=core.ItemAdd",'arg3' => "itemId=".($this->_tpl_vars['theme']['item']['id'])), $this);?>
"><?php echo $this->_reg_objects['g'][0]->text(array('text' => "Add a photo!"), $this);?>
</a>
<?php endif; ?>
</p>
</div>
<?php else: ?>
<div id="main-image-container">
<div id="slideshow-controls">
<ul id="control-buttons">
<li><button id="controls-left">
<img src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "images/controls-left.png"), $this);?>
" alt="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Left'), $this);?>
" />
</button></li>
<li><button id="controls-play">
<img src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "images/controls-play.png"), $this);?>
" alt="<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Play/Pause"), $this);?>
" />
</button></li>
<li><button id="controls-right">
<img src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "images/controls-right.png"), $this);?>
" alt="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Right'), $this);?>
" />
</button></li>
</ul>
</div>
<?php if ($this->_tpl_vars['theme']['imageCount'] > 0): ?>
<div id="sliding-frame">
<div id="loading">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Loading Album..."), $this);?>

</div>
<p><img src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "images/blank.png"), $this);?>
"
alt="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Main image placeholder'), $this);?>
" id="main-image" /></p>
</div>
<?php endif;  $this->assign('childrenInColumnCount', 0);  $this->assign('subalbumCount', 0); ?>
<div id="thumbs-container">
<table id="gsThumbMatrix">
<tr valign="top">
<?php $_from = $this->_tpl_vars['theme']['children']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['child']):
 if (! $this->_tpl_vars['child']['canContainChildren'] && $this->_tpl_vars['child']['entityType'] != 'GalleryLinkItem'):  if (( $this->_tpl_vars['childrenInColumnCount'] == $this->_tpl_vars['theme']['params']['columns'] )): ?>
</tr><tr valign="top">
<?php $this->assign('childrenInColumnCount', 0);  endif;  $this->assign('childrenInColumnCount', ($this->_tpl_vars['childrenInColumnCount']+1)); ?>
<td class="giItemCell">
<?php if (isset ( $this->_tpl_vars['theme']['params']['itemFrame'] ) && isset ( $this->_tpl_vars['child']['thumbnail'] )):  $this->_tag_stack[] = array('container', array('type' => "imageframe.ImageFrame",'frame' => $this->_tpl_vars['theme']['params']['itemFrame']), $this); $_block_repeat=true; $this->_reg_objects['g'][0]->container($this->_tag_stack[count($this->_tag_stack)-1][1], null, $this, $_block_repeat); while ($_block_repeat) { ob_start();?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['child']['id'])), $this);?>
"><?php echo $this->_reg_objects['g'][0]->image(array('id' => "%ID%",'item' => $this->_tpl_vars['child'],'image' => $this->_tpl_vars['child']['thumbnail'],'class' => "%CLASS% giThumbnail size:=".($this->_tpl_vars['child']['size'])."= summary:=".($this->_tpl_vars['child']['summary'])."= description:=".($this->_tpl_vars['child']['description'])."="), $this);?>
</a>
<?php $_obj_block_content = ob_get_contents(); ob_end_clean(); $_block_repeat=false;echo $this->_reg_objects['g'][0]->container($this->_tag_stack[count($this->_tag_stack)-1][1], $_obj_block_content, $this, $_block_repeat);} array_pop($this->_tag_stack);?>

<?php elseif (isset ( $this->_tpl_vars['child']['thumbnail'] )): ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['child']['id'])), $this);?>
"><?php echo $this->_reg_objects['g'][0]->image(array('item' => $this->_tpl_vars['child'],'image' => $this->_tpl_vars['child']['thumbnail'],'class' => "r giThumbnail size:=".($this->_tpl_vars['child']['size'])."= summary:=".($this->_tpl_vars['child']['summary'])."= description:=".($this->_tpl_vars['child']['description'])."="), $this);?>
</a>
<?php else: ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['child']['id'])), $this);?>
"
class="giMissingThumbnail">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'no thumbnail'), $this);?>

</a>
<?php endif; ?>
</td>
<?php else:  $this->assign('subalbumCount', ($this->_tpl_vars['subalbumCount']+1));  endif;  endforeach; endif; unset($_from);  unset($this->_sections['flush']);
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
</div>
<?php $this->assign('childrenInColumnCount', 0);  if ($this->_tpl_vars['subalbumCount'] > 0): ?>
<div id="subalbums-container">
<h3><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Subalbums'), $this);?>
</h3>
<table id="gsSubAlbumMatrix">
<tr valign="top">
<?php $_from = $this->_tpl_vars['theme']['children']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['child']):
 if ($this->_tpl_vars['child']['canContainChildren'] || $this->_tpl_vars['child']['entityType'] == 'GalleryLinkItem'):  if (( $this->_tpl_vars['childrenInColumnCount'] == 2 )): ?>
</tr><tr>
<?php $this->assign('childrenInColumnCount', 0);  endif;  $this->assign('childrenInColumnCount', ($this->_tpl_vars['childrenInColumnCount']+1)); ?>
<td class="giAlbumCell gcBackground1">
<?php if (isset ( $this->_tpl_vars['child']['thumbnail'] )): ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ShowItem",'arg2' => "itemId=".($this->_tpl_vars['child']['id'])), $this);?>
">
<?php echo $this->_reg_objects['g'][0]->image(array('item' => $this->_tpl_vars['child'],'image' => $this->_tpl_vars['child']['thumbnail'],'class' => 'giThumbnail'), $this);?>

<?php echo ((is_array($_tmp=$this->_tpl_vars['child']['title'])) ? $this->_run_mod_handler('entitytruncate', true, $_tmp, 25) : smarty_modifier_entitytruncate($_tmp, 25)); ?>
</a>
<?php else: ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ShowItem",'arg2' => "itemId=".($this->_tpl_vars['child']['id'])), $this);?>
"
class="giMissingThumbnail">
<img src="<?php echo $this->_reg_objects['g'][0]->theme(array('url' => "images/missing.png"), $this);?>
" width="40" height="40"
alt="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'no thumbnail'), $this);?>
" />
<?php echo ((is_array($_tmp=$this->_tpl_vars['child']['title'])) ? $this->_run_mod_handler('entitytruncate', true, $_tmp, 25) : smarty_modifier_entitytruncate($_tmp, 25)); ?>
</a>
<?php endif;  echo $this->_reg_objects['g'][0]->block(array('type' => "core.ItemInfo",'item' => $this->_tpl_vars['child'],'showDate' => false,'showOwner' => $this->_tpl_vars['theme']['params']['showAlbumOwner'],'showSize' => true,'showViewCount' => true,'showSummaries' => true,'class' => 'giInfo'), $this);?>

</td>
<?php endif;  endforeach; endif; unset($_from);  unset($this->_sections['flush']);
$this->_sections['flush']['name'] = 'flush';
$this->_sections['flush']['start'] = (int)$this->_tpl_vars['childrenInColumnCount'];
$this->_sections['flush']['loop'] = is_array($_loop=2) ? count($_loop) : max(0, (int)$_loop); unset($_loop);
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
<?php endif;  endif;  if (! empty ( $this->_tpl_vars['theme']['navigator'] )): ?>
<div class="gbBlock gcBackground2 gbNavigator">
<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.Navigator",'navigator' => $this->_tpl_vars['theme']['navigator']), $this);?>

</div>
<?php endif; ?>
<script type="text/javascript">
// <![CDATA[
var slideshowImageWidths = new Array(<?php if ($this->_tpl_vars['theme']['imageCount'] == 1): ?>1);
slideshowImageWidths[0] = <?php echo $this->_tpl_vars['theme']['imageWidths']; ?>
;
<?php else:  echo $this->_tpl_vars['theme']['imageWidths']; ?>
);<?php endif; ?>
var slideshowImages = new Array();
<?php $_from = $this->_tpl_vars['theme']['children']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['i'] => $this->_tpl_vars['it']):
 if (! $this->_tpl_vars['it']['canContainChildren'] && $this->_tpl_vars['it']['entityType'] != 'GalleryLinkItem'): ?>
slideshowImages.push('<?php if (isset ( $this->_tpl_vars['it']['image'] )):  echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.DownloadItem",'arg2' => "itemId=".($this->_tpl_vars['it']['image']['id']),'arg3' => "serialNumber=".($this->_tpl_vars['it']['image']['serialNumber']),'htmlEntities' => false), $this); else:  echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['it']['id']),'htmlEntities' => false), $this); endif; ?>');
<?php endif;  endforeach; endif; unset($_from); ?>
// ]]>
</script>
<?php $_from = $this->_tpl_vars['theme']['params']['albumBlocks']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['block']):
 echo $this->_reg_objects['g'][0]->block(array('type' => $this->_tpl_vars['block']['0'],'params' => $this->_tpl_vars['block']['1']), $this);?>

<?php endforeach; endif; unset($_from);  echo $this->_reg_objects['g'][0]->block(array('type' => "core.GuestPreview",'class' => 'gbBlock'), $this);?>

<?php echo $this->_reg_objects['g'][0]->block(array('type' => "core.EmergencyEditItemLink",'class' => 'gbBlock','checkBlocks' => 'album'), $this);?>
