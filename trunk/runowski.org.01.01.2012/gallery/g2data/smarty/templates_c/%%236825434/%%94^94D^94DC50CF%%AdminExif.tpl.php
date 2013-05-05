<?php /* Smarty version 2.6.16, created on 2008-01-08 08:05:18
         compiled from gallery:modules/exif/templates/AdminExif.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'html_options', 'gallery:modules/exif/templates/AdminExif.tpl', 80, false),)), $this); ?>
<div class="gbBlock gcBackground1">
<h2> <?php echo $this->_reg_objects['g'][0]->text(array('text' => "EXIF/IPTC Settings"), $this);?>
 </h2>
</div>
<?php if (! empty ( $this->_tpl_vars['status'] )): ?>
<div class="gbBlock"><h2 class="giSuccess">
<?php if (isset ( $this->_tpl_vars['status']['added']['summary'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Added %d property to the Summary view",'many' => "Added %d properties to the Summary view",'count' => $this->_tpl_vars['status']['added']['summary'],'arg1' => $this->_tpl_vars['status']['added']['summary']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['removed']['summary'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Removed %d property from the Summary view",'many' => "Removed %d properties from the Summary view",'count' => $this->_tpl_vars['status']['removed']['summary'],'arg1' => $this->_tpl_vars['status']['removed']['summary']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['restored']['summary'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'Restored the default properties for the Summary view'), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['movedUp']['summary'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Moved %d property up in the Summary view",'many' => "Moved %d properties up in the Summary view",'count' => $this->_tpl_vars['status']['movedUp']['summary'],'arg1' => $this->_tpl_vars['status']['movedUp']['summary']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['movedDown']['summary'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Moved %d property down in the Summary view",'many' => "Moved %d properties down in the Summary view",'count' => $this->_tpl_vars['status']['movedDown']['summary'],'arg1' => $this->_tpl_vars['status']['movedDown']['summary']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['added']['detailed'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Added %d property to the Detailed view",'many' => "Added %d properties to the Detailed view",'count' => $this->_tpl_vars['status']['added']['detailed'],'arg1' => $this->_tpl_vars['status']['added']['detailed']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['removed']['detailed'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Removed %d property from the Detailed view",'many' => "Removed %d properties from the Detailed view",'count' => $this->_tpl_vars['status']['removed']['detailed'],'arg1' => $this->_tpl_vars['status']['removed']['detailed']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['restored']['detailed'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'Restored the default properties for the Detailed view'), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['movedUp']['detailed'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Moved %d property up in the Detailed view",'many' => "Moved %d properties up in the Detailed view",'count' => $this->_tpl_vars['status']['movedUp']['detailed'],'arg1' => $this->_tpl_vars['status']['movedUp']['detailed']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['movedDown']['detailed'] )):  echo $this->_reg_objects['g'][0]->text(array('one' => "Moved %d property down in the Detailed view",'many' => "Moved %d properties down in the Detailed view",'count' => $this->_tpl_vars['status']['movedDown']['detailed'],'arg1' => $this->_tpl_vars['status']['movedDown']['detailed']), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['status']['saved'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'Settings saved successfully'), $this);?>

<?php endif; ?>
</h2></div>
<?php endif; ?>
<div class="gbBlock">
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Gallery can display the EXIF data that is embedded in photos taken by most digital cameras. Gallery can also display IPTC data that was added to the photos by some IPTC enabled software."), $this);?>

</p>
</div>
<div class="gbBlock">
<h3> <?php echo $this->_reg_objects['g'][0]->text(array('text' => "Summary and Detailed EXIF/IPTC displays"), $this);?>
 </h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "There can be a great deal of EXIF/IPTC information stored in photos.  We display that data in two different views, summary and detailed.  You can choose which properties are displayed in each view."), $this);?>

</p>
<table class="gbDataTable"><tr>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Available'), $this);?>
 </th>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Summary'), $this);?>
 </th>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Detailed'), $this);?>
 </th>
</tr><tr>
<td>
<select name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[available][]"), $this);?>
" size="20" multiple="multiple">
<?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['AdminExif']['availableList']), $this);?>

</select>
</td><td>
<select name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[summary][]"), $this);?>
" size="20" multiple="multiple">
<?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['AdminExif']['summaryList']), $this);?>

</select>
</td><td>
<select name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[detailed][]"), $this);?>
" size="20" multiple="multiple">
<?php echo smarty_function_html_options(array('options' => $this->_tpl_vars['AdminExif']['detailedList']), $this);?>

</select>
</td>
</tr>
<?php if (isset ( $this->_tpl_vars['form']['error']['available']['missing'] ) || isset ( $this->_tpl_vars['form']['error']['summary']['missing'] ) || isset ( $this->_tpl_vars['form']['error']['detailed']['missing'] )): ?>
<tr>
<td colspan="3">
<div class="giError">
<?php if (isset ( $this->_tpl_vars['form']['error']['available']['missing'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'You must select at least one value in the available column'), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['form']['error']['summary']['missing'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'You must select at least one value in the summary column'), $this);?>

<?php endif;  if (isset ( $this->_tpl_vars['form']['error']['detailed']['missing'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'You must select at least one value in the detailed column'), $this);?>

<?php endif; ?>
</div>
</td>
</tr>
<?php endif; ?>
<tr>
<td>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][availableToSummary]"), $this);?>
"
value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Add to Summary'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][availableToDetailed]"), $this);?>
"
value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Add to Detailed'), $this);?>
"/>
</td><td>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][removeFromSummary]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Remove'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][moveUpSummary]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Up'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][moveDownSummary]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Down'), $this);?>
"/>
</td><td>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][removeFromDetailed]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Remove'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][moveUpDetailed]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Up'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][moveDownDetailed]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Down'), $this);?>
"/>
</td>
</tr></table>
</div>
<div class="gbBlock">
<h3> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Reset to Defaults'), $this);?>
 </h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Restore the original values for the Summary and Detailed views.  Use with caution, there is no undo!"), $this);?>

</p>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][resetSummary]"), $this);?>
"
value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Restore Summary Defaults'), $this);?>
"/>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][resetDetailed]"), $this);?>
"
value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Restore Detailed Defaults'), $this);?>
"/>
</div>
<div class="gbBlock">
<h3> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Item Upload'), $this);?>
 </h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "When photos are added to Gallery check for EXIF Image Description and apply to:"), $this);?>

</p>
<p class="giDescription">
<input type="checkbox" id="cbItemSummary"<?php if ($this->_tpl_vars['form']['item']['summary']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][summary]"), $this);?>
"/>
<label for="cbItemSummary">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Item Summary'), $this);?>

</label>
<br/>
<input type="checkbox" id="cbItemDescription"<?php if ($this->_tpl_vars['form']['item']['description']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][description]"), $this);?>
"/>
<label for="cbItemDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Item Description'), $this);?>

</label>
</p>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "When photos are added to Gallery check for IPTC Keywords and apply to:"), $this);?>

</p>
<p class="giDescription">
<input type="checkbox" id="cbItemKeywords"<?php if ($this->_tpl_vars['form']['item']['keywords']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][keywords]"), $this);?>
"/>
<label for="cbItemKeywords">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Item Keywords'), $this);?>

</label>
</p>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "When photos are added to Gallery check for IPTC Object Name and apply to:"), $this);?>

</p>
<p class="giDescription">
<input type="checkbox" id="cbItemObjectName"<?php if ($this->_tpl_vars['form']['item']['objectName']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][objectName]"), $this);?>
"/>
<label for="cbItemObjectName">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Item Title'), $this);?>

</label>
</p>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "When photos are added should we rotate them based on EXIF orientation data?"), $this);?>

</p>
<p class="giDescription">
<input type="checkbox" id="cbItemExifRotate"<?php if ($this->_tpl_vars['form']['item']['exifrotate']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][exifrotate]"), $this);?>
"/>
<label for="cbItemExifRotate">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Rotate pictures automatically'), $this);?>

</label>
</p>
<p class="giDescription">
<input type="checkbox" id="cbItemExifRotatePreserve"<?php if ($this->_tpl_vars['form']['item']['exifrotatepreserve']): ?> checked="checked"<?php endif; ?>
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[item][exifrotatepreserve]"), $this);?>
"/>
<label for="cbItemExifRotatePreserve">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Preserve Original on Rotating'), $this);?>

</label>
</p>
<input type="submit" class="inputTypeSubmit"
name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][save]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Save'), $this);?>
"/>
</div>