<?php /* Smarty version 2.6.16, created on 2008-01-15 11:36:05
         compiled from gallery:themes/carbon/templates/module.tpl */ ?>
<table class="gcBackground1" width="100%" cellspacing="0" cellpadding="0">
<tr valign="top">
<td>
<?php $_smarty_tpl_vars = $this->_tpl_vars;
$this->_smarty_include(array('smarty_include_tpl_file' => "gallery:".($this->_tpl_vars['theme']['moduleTemplate']), 'smarty_include_vars' => array('l10Domain' => $this->_tpl_vars['theme']['moduleL10Domain'])));
$this->_tpl_vars = $_smarty_tpl_vars;
unset($_smarty_tpl_vars);
 ?>
</td>
</tr>
</table>
<?php if (! empty ( $this->_tpl_vars['theme']['params']['sidebarBlocks'] )):  echo $this->_reg_objects['g'][0]->theme(array('include' => "sidebar.tpl"), $this);?>

<?php endif; ?>