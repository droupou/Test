<?php /* Smarty version 2.6.16, created on 2008-01-08 07:43:28
         compiled from gallery:modules/core/templates/blocks/BreadCrumb.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'counter', 'gallery:modules/core/templates/blocks/BreadCrumb.tpl', 16, false),array('modifier', 'markup', 'gallery:modules/core/templates/blocks/BreadCrumb.tpl', 17, false),array('modifier', 'default', 'gallery:modules/core/templates/blocks/BreadCrumb.tpl', 17, false),)), $this); ?>
<div class="<?php echo $this->_tpl_vars['class']; ?>
">
<?php $_from = $this->_tpl_vars['theme']['parents']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }$this->_foreach['parent'] = array('total' => count($_from), 'iteration' => 0);
if ($this->_foreach['parent']['total'] > 0):
    foreach ($_from as $this->_tpl_vars['parent']):
        $this->_foreach['parent']['iteration']++;
 if (! ($this->_foreach['parent']['iteration'] == $this->_foreach['parent']['total'])): ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['parent']['urlParams']), $this);?>
" class="BreadCrumb-<?php echo smarty_function_counter(array('name' => 'BreadCrumb'), $this);?>
">
<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['parent']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')))) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['parent']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['parent']['pathComponent'])); ?>
</a>
<?php else: ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('params' => $this->_tpl_vars['parent']['urlParams']), $this);?>
" class="BreadCrumb-<?php echo smarty_function_counter(array('name' => 'BreadCrumb'), $this);?>
">
<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['parent']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')))) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['parent']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['parent']['pathComponent'])); ?>
</a>
<?php endif;  if (isset ( $this->_tpl_vars['separator'] )): ?> <?php echo $this->_tpl_vars['separator']; ?>
 <?php endif;  endforeach; endif; unset($_from);  if (( $this->_tpl_vars['theme']['pageType'] == 'admin' || $this->_tpl_vars['theme']['pageType'] == 'module' )): ?>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.ShowItem",'arg2' => "itemId=".($this->_tpl_vars['theme']['item']['id'])), $this);?>
" class="BreadCrumb-<?php echo smarty_function_counter(array('name' => 'BreadCrumb'), $this);?>
">
<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')))) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['item']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['item']['pathComponent'])); ?>
</a>
<?php else: ?>
<span class="BreadCrumb-<?php echo smarty_function_counter(array('name' => 'BreadCrumb'), $this);?>
">
<?php echo ((is_array($_tmp=((is_array($_tmp=$this->_tpl_vars['theme']['item']['title'])) ? $this->_run_mod_handler('markup', true, $_tmp, 'strip') : smarty_modifier_markup($_tmp, 'strip')))) ? $this->_run_mod_handler('default', true, $_tmp, @$this->_tpl_vars['theme']['item']['pathComponent']) : smarty_modifier_default($_tmp, @$this->_tpl_vars['theme']['item']['pathComponent'])); ?>
</span>
<?php endif; ?>
</div>