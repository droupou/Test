<?php /* Smarty version 2.6.16, created on 2008-01-11 07:49:41
         compiled from gallery:themes/carbon/templates/navigatorMicroThumbs.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'default', 'gallery:themes/carbon/templates/navigatorMicroThumbs.tpl', 7, false),)), $this); ?>
<?php echo $this->_reg_objects['g'][0]->callback(array('type' => "core.LoadPeers",'item' => ((is_array($_tmp=@$this->_tpl_vars['item'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['item']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['item'])),'windowSize' => ((is_array($_tmp=@$this->_tpl_vars['windowSize'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['params']['maxMicroThumbs']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['params']['maxMicroThumbs'])),'addEnds' => false,'loadThumbnails' => true), $this);?>

<?php $this->assign('data', $this->_tpl_vars['block']['core']['LoadPeers']);  if (! empty ( $this->_tpl_vars['data']['peers'] )): ?>
<div>
<?php $this->assign('lastIndex', 0);  $this->assign('columnIndex', 0); ?>
<table cellpadding="0" cellspacing="2">
<tr>
<?php $_from = $this->_tpl_vars['data']['peers']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['peer']):
 $this->assign('title', ((is_array($_tmp=@$this->_tpl_vars['peer']['title'])) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['peer']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['peer']['pathComponent'])));  if (( $this->_tpl_vars['columnIndex'] == 4 )): ?>
</tr>
<tr>
<?php $this->assign('columnIndex', 0);  endif;  if (( ! $this->_tpl_vars['peer']['canContainChildren'] && $this->_tpl_vars['peer']['entityType'] != 'GalleryLinkItem' )):  if (( $this->_tpl_vars['peer']['peerIndex'] == $this->_tpl_vars['data']['thisPeerIndex'] )): ?>
<td id="microThumbCurrent" align="center" width="44" height="40">
<?php if (isset ( $this->_tpl_vars['peer']['thumbnail'] )):  echo $this->_reg_objects['g'][0]->image(array('item' => $this->_tpl_vars['peer'],'image' => $this->_tpl_vars['peer']['thumbnail'],'maxSize' => 40,'title' => ($this->_tpl_vars['title'])), $this);?>

<?php else:  echo $this->_reg_objects['g'][0]->text(array('text' => 'no thumbnail'), $this);?>

<?php endif; ?>
</td>
<?php else: ?>
<td align="center" width="44" height="40">
<?php echo '<a href="';  echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['theme']['pageUrl'],'arg1' => "itemId=".($this->_tpl_vars['peer']['id'])), $this); echo '">';  if (isset ( $this->_tpl_vars['peer']['thumbnail'] )):  echo '';  echo $this->_reg_objects['g'][0]->image(array('item' => $this->_tpl_vars['peer'],'image' => $this->_tpl_vars['peer']['thumbnail'],'maxSize' => 40,'title' => ($this->_tpl_vars['title'])), $this); echo '';  else:  echo '';  echo $this->_reg_objects['g'][0]->text(array('text' => 'no thumbnail'), $this); echo '';  endif;  echo '</a>'; ?>

</td>
<?php endif;  $this->assign('lastIndex', $this->_tpl_vars['peer']['peerIndex']);  $this->assign('columnIndex', $this->_tpl_vars['columnIndex']+1);  endif;  endforeach; endif; unset($_from); ?>
</tr>
</table>
</div>
<?php endif; ?>