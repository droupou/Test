<?php /* Smarty version 2.6.16, created on 2008-01-10 14:07:06
         compiled from gallery:modules/core/templates/DefaultButton.tpl */ ?>
<?php $this->assign('buttonId', "defaultSubmitBtn".($this->_tpl_vars['callCount'])); ?>
<input type="submit" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => $this->_tpl_vars['name']), $this);?>
" value="" id="<?php echo $this->_tpl_vars['buttonId']; ?>
"
style="background-color: transparent; border-style: none; position: absolute; right: 0"/>
<script type="text/javascript">
// <![CDATA[
var a = navigator.userAgent.toLowerCase(), b = document.getElementById('<?php echo $this->_tpl_vars['buttonId']; ?>
');
if (a.indexOf('msie') < 0 || a.indexOf('opera') >= 0) b.style.display = 'none';
// ]]>
</script>
<input type="text" name="stupidIE" value="" style="display: none"/>