<?php /* Smarty version 2.6.16, created on 2008-01-08 07:47:54
         compiled from gallery:modules/core/templates/AdminRepository.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('function', 'cycle', 'gallery:modules/core/templates/AdminRepository.tpl', 249, false),)), $this); ?>
<div class="gbBlock gcBackground1">
<h2> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Repository'), $this);?>
 </h2>
</div>
<?php if (! empty ( $this->_tpl_vars['status']['error'] )): ?>
<div class="gbBlock">
<h2 class="giError">
<?php if (! empty ( $this->_tpl_vars['status']['error']['download'] )):  $_from = $this->_tpl_vars['status']['error']['download']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['error']):
 echo $this->_tpl_vars['error']; ?>
<br/>
<?php endforeach; endif; unset($_from);  echo $this->_reg_objects['g'][0]->text(array('text' => "Please make sure that your internet connection is set up properly or try again later."), $this);?>
<br/>
<?php endif;  if (! empty ( $this->_tpl_vars['status']['error']['scanPlugin'] )):  $_from = $this->_tpl_vars['status']['error']['scanPlugin']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pluginId']):
 echo $this->_reg_objects['g'][0]->text(array('text' => "Failed to scan status from plugin: %s.",'arg1' => $this->_tpl_vars['pluginId']), $this);?>
<br/>
<?php endforeach; endif; unset($_from);  endif;  if (! empty ( $this->_tpl_vars['status']['error']['repositoryInitErrorCount'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => "Your local copy of the repository was broken and has been fixed.  Please download the plugin list again."), $this);?>

<?php endif; ?>
</h2>
<?php if (! empty ( $this->_tpl_vars['status']['error']['failedToDownload'] )):  $_from = $this->_tpl_vars['status']['error']['failedToDownload']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }$this->_foreach['plugin'] = array('total' => count($_from), 'iteration' => 0);
if ($this->_foreach['plugin']['total'] > 0):
    foreach ($_from as $this->_tpl_vars['pluginName'] => $this->_tpl_vars['failedFiles']):
        $this->_foreach['plugin']['iteration']++;
?>
<h2 class="giError"> <?php echo $this->_reg_objects['g'][0]->text(array('text' => "Failed to download the %s plugin because the following files/directories could not be modified:",'arg1' => $this->_tpl_vars['pluginName']), $this);?>
</h2>
<ul>
<?php $_from = $this->_tpl_vars['failedFiles']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['file']):
?>
<li class="giError"> <?php echo $this->_tpl_vars['file']; ?>
 (unable to download) </li>
<?php endforeach; endif; unset($_from); ?>
</ul>
<?php if (! ($this->_foreach['plugin']['iteration'] == $this->_foreach['plugin']['total'])): ?><br/><?php endif;  endforeach; endif; unset($_from);  endif;  if (! empty ( $this->_tpl_vars['status']['error']['failedToInstall'] )):  $_from = $this->_tpl_vars['status']['error']['failedToInstall']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }$this->_foreach['plugin'] = array('total' => count($_from), 'iteration' => 0);
if ($this->_foreach['plugin']['total'] > 0):
    foreach ($_from as $this->_tpl_vars['pluginName'] => $this->_tpl_vars['failedFiles']):
        $this->_foreach['plugin']['iteration']++;
?>
<h2 class="giError"> <?php echo $this->_reg_objects['g'][0]->text(array('text' => "Failed to download the %s plugin because the following files/directories could not be modified:",'arg1' => $this->_tpl_vars['pluginName']), $this);?>
 </h2>
<ul>
<?php $_from = $this->_tpl_vars['failedFiles']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['file']):
?>
<li class="giError"> <?php echo $this->_tpl_vars['file']; ?>
 </li>
<?php endforeach; endif; unset($_from); ?>
</ul>
<?php if (! ($this->_foreach['plugin']['iteration'] == $this->_foreach['plugin']['total'])): ?><br/><?php endif;  endforeach; endif; unset($_from);  endif;  if (! empty ( $this->_tpl_vars['status']['error']['cantUpgradeInUse'] )): ?>
<h2 class="giError"> Some plugins could not be automatically upgraded because they are in use.  Please return to the <a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.SiteAdmin",'arg2' => "subView=core.AdminPlugins"), $this);?>
"><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Plugins'), $this);?>
</a> page and click the <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'upgrade'), $this);?>
 link for each of the following plugins: </h2>
<ul>
<?php $_from = $this->_tpl_vars['status']['error']['cantUpgradeInUse']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pluginName']):
?>
<li class="giError"> <?php echo $this->_tpl_vars['pluginName']; ?>
 </li>
<?php endforeach; endif; unset($_from); ?>
</ul>
<?php endif; ?>
</div>
<?php endif;  if (! empty ( $this->_tpl_vars['status'] )): ?>
<div class="gbBlock"><h2 class="giSuccess">
<?php if (isset ( $this->_tpl_vars['status']['indexUpdated'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => "The repository index has been successfully updated."), $this);?>

<?php elseif (isset ( $this->_tpl_vars['status']['noUpgradeAvailable'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => "All plugins are already up-to-date."), $this);?>

<?php elseif (! empty ( $this->_tpl_vars['status']['updated'] )):  $_from = $this->_tpl_vars['status']['updated']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['item']):
?>
<p>
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "%s plugin updated.",'arg1' => $this->_tpl_vars['item']), $this);?>

</p>
<?php endforeach; endif; unset($_from);  endif;  if (! empty ( $this->_tpl_vars['status']['languagePacksDeleted'] )): ?>
<p>
<?php echo $this->_reg_objects['g'][0]->text(array('one' => "%d language pack deleted.",'many' => "%d language packs deleted.",'count' => $this->_tpl_vars['status']['languagePacksDeleted'],'arg1' => $this->_tpl_vars['status']['languagePacksDeleted']), $this);?>

</p>
<?php endif; ?>
</h2></div>
<?php endif; ?>
<div class="gbTabBar">
<span class="o"><span>
<a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.SiteAdmin",'arg2' => "subView=core.AdminPlugins"), $this);?>
">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Plugins'), $this);?>

</a>
</span></span>
<span class="giSelected o"><span>
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Get More Plugins'), $this);?>

</span></span>
</div>
<div class="gbBlock">
<p class="giDescription">
<?php ob_start(); ?><b><?php echo $this->_reg_objects['g'][0]->text(array('text' => "No personal information about you or your Gallery installation is sent to the Gallery server at any time."), $this);?>
</b><?php $this->_smarty_vars['capture']['noPersonalInfoTransmitted'] = ob_get_contents(); ob_end_clean();  echo $this->_reg_objects['g'][0]->text(array('text' => "Download and install new plugins quickly and easily.  If you decide you don't like a plugin, you can delete it from your Gallery.  There are multiple different plugin repositories, you can choose which ones you want to use (it's ok to use all of them at once).  Once you've chosen, you must periodically download the latest plugin list to find out about available updates. %s On slower connections the process might take a minute or two.",'arg1' => $this->_smarty_vars['capture']['noPersonalInfoTransmitted']), $this);?>

</p>
<div id="AdminRepository_Configure" style="height: 0px; opacity: 0; overflow: hidden;">
<input id="repositories_released" type="checkbox" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][released]"), $this);?>
" <?php if (! empty ( $this->_tpl_vars['form']['repositories']['released'] )): ?>checked="checked"<?php endif; ?>  value="released">
<label for="repositories_released">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Officially Released Gallery Project plugins (%srecommended%s)",'arg1' => "<b>",'arg2' => "</b>"), $this);?>

<?php if (! empty ( $this->_tpl_vars['AdminRepository']['indexMetaData']['released']['timestamp'] )):  ob_start();  echo $this->_reg_objects['g'][0]->date(array('style' => 'datetime','timestamp' => $this->_tpl_vars['AdminRepository']['indexMetaData']['released']['timestamp']), $this); $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('updateDate', ob_get_contents());ob_end_clean(); ?>
<i><?php echo $this->_reg_objects['g'][0]->text(array('text' => "last updated on %s",'arg1' => $this->_tpl_vars['updateDate']), $this);?>
</i>
<?php endif; ?>
</label>
</input>
<br/>
<input id="repositories_experimental" type="checkbox" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][experimental]"), $this);?>
" <?php if (! empty ( $this->_tpl_vars['form']['repositories']['experimental'] )): ?>checked="checked"<?php endif; ?>  value="experimental">
<label for="repositories_experimental">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Experimental Gallery Project plugins (%scool new features, might be buggy%s)",'arg1' => "<b>",'arg2' => "</b>"), $this);?>

<?php if (! empty ( $this->_tpl_vars['AdminRepository']['indexMetaData']['experimental']['timestamp'] )):  ob_start();  echo $this->_reg_objects['g'][0]->date(array('style' => 'datetime','timestamp' => $this->_tpl_vars['AdminRepository']['indexMetaData']['experimental']['timestamp']), $this); $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('updateDate', ob_get_contents());ob_end_clean(); ?>
<i><?php echo $this->_reg_objects['g'][0]->text(array('text' => "last updated on %s",'arg1' => $this->_tpl_vars['updateDate']), $this);?>
</i>
<?php endif; ?>
</label>
</input>
<br/>
<input id="repositories_community" type="checkbox" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][community]"), $this);?>
" <?php if (! empty ( $this->_tpl_vars['form']['repositories']['community'] )): ?>checked="checked"<?php endif; ?>  value="community">
<label for="repositories_community">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Community plugins (%suse at your own risk!%s)",'arg1' => "<b>",'arg2' => "</b>"), $this);?>

<?php if (! empty ( $this->_tpl_vars['AdminRepository']['indexMetaData']['community']['timestamp'] )):  ob_start();  echo $this->_reg_objects['g'][0]->date(array('style' => 'datetime','timestamp' => $this->_tpl_vars['AdminRepository']['indexMetaData']['community']['timestamp']), $this); $this->_smarty_vars['capture']['default'] = ob_get_contents();  $this->assign('updateDate', ob_get_contents());ob_end_clean(); ?>
<i><?php echo $this->_reg_objects['g'][0]->text(array('text' => "last updated on %s",'arg1' => $this->_tpl_vars['updateDate']), $this);?>
</i>
<?php endif; ?>
</label>
</input>
<br/>
<p>
<input id="AdminRepository_saveRepositoryList" type="button" class="inputTypeSubmit" onclick="if (validateRepositoryList()) { saveRepositoryList();  closeRepositoryList() }" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Save'), $this);?>
"/>
<input id="AdminRepository_closeRepositoryList" type="reset" class="inputTypeSubmit" onclick="closeRepositoryList()" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Cancel'), $this);?>
"/>
</p>
</div>
<script type="text/javascript">
// <![CDATA[
var postUrl = '<?php echo $this->_reg_objects['g'][0]->url(array(), $this);?>
';
var commandArg = '<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => 'command'), $this);?>
';
var viewArg = '<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => 'view'), $this);?>
';
var authTokenArg = '<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => 'authToken'), $this);?>
=<?php echo $this->_tpl_vars['AdminRepository']['authToken']; ?>
';
var repositoryArgs = [
'<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][released]"), $this);?>
',
'<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][experimental]"), $this);?>
',
'<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[repositories][community]"), $this);?>
' ];
var repositoryMessageTitle = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Repository Error','forJavascript' => true), $this);?>
';
var repositoryMessageBody = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => "You must select at least one repository.",'forJavascript' => true), $this);?>
';
var repositoryMessageOkButton = '<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Ok','forJavascript' => true), $this);?>
';
var formElements = document.getElementById("siteAdminForm").elements;
// ]]>
</script>
</div>
<?php if (! $this->_tpl_vars['AdminRepository']['writeable']['modules'] || ! $this->_tpl_vars['AdminRepository']['writeable']['themes']): ?>
<div class="gbBlock">
<h3><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Configure your Gallery'), $this);?>
</h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Before you can proceed, you have to change some permissions so that Gallery can install plugins for you.  It's easy.  Just execute the following in a shell or via your ftp client:"), $this);?>

</p>
<p class="gcBackground1" style="border-width: 1px; border-style: dotted; padding: 4px">
<b>
cd gallery2<br/>
<?php if (! $this->_tpl_vars['AdminRepository']['writeable']['modules']): ?>chmod 777 modules<br/><?php endif;  if (! $this->_tpl_vars['AdminRepository']['writeable']['themes']): ?>chmod 777 themes<br/><?php endif; ?>
</b>
</p>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "If you have trouble changing permissions, ask your system administrator for assistance.  When you've fixed the permissions, click the Continue button to proceed."), $this);?>

</p>
</div>
<div class="gbBlock gcBackground1">
<input class="inputTypeSubmit" type="button" onclick="document.location='<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.SiteAdmin",'arg2' => "subView=core.AdminRepository"), $this);?>
'" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Continue'), $this);?>
" />
</div>
<?php else: ?>
<div class="gbBlock gcBackground1">
<input type="submit" class="inputTypeSubmit" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][update]"), $this);?>
" value="<?php if (isset ( $this->_tpl_vars['AdminRepository']['indexMetaData'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => 'Update Plugin List'), $this); else:  echo $this->_reg_objects['g'][0]->text(array('text' => 'Download Plugin List'), $this); endif; ?>"/>
<input id="AdminRepository_showRepositoryList" type="button" class="inputTypeSubmit" onclick="showRepositoryList()" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Show Repository List'), $this);?>
"/>
</div>
<?php if (isset ( $this->_tpl_vars['AdminRepository']['indexMetaData'] )):  if ($this->_tpl_vars['AdminRepository']['isCoreUpgradeAvailable']): ?>
<div class="gbBlock">
<h3><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Upgrade Gallery'), $this);?>
</h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "A new version of Gallery is available, but it cannot be upgraded through this interface. Upgrading it might make some of your current plugins stop working, but others that rely on the features of the new version may become available. Here are the recommended steps for upgrading:"), $this);?>

</p>
<p>
<ol>
<li><?php echo $this->_reg_objects['g'][0]->text(array('text' => "%sDownload%s the new Gallery package",'arg1' => "<a href=\"http://codex.gallery2.org/Downloads\">",'arg2' => "</a>"), $this);?>
</li>
<li><?php echo $this->_reg_objects['g'][0]->text(array('text' => "Read the %supgrade instructions%s and perform the upgrade",'arg1' => "<a href=\"http://codex.gallery2.org/Gallery2:Upgrading\">",'arg2' => "</a>"), $this);?>
</li>
</ol>
</p>
</div>
<?php endif;  endif; ?>
<div class="gbBlock">
<?php if (isset ( $this->_tpl_vars['AdminRepository']['browseData'] )): ?>
<p class="giDescription">
<?php if ($this->_tpl_vars['AdminRepository']['isCoreUpgradeAvailable']):  if (isset ( $this->_tpl_vars['AdminRepository']['showIncompatible'] )):  echo $this->_reg_objects['g'][0]->text(array('text' => "Incompatible plugins are marked with an exclamation icon."), $this);?>

<?php else:  ob_start(); ?><a href="<?php echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.SiteAdmin",'arg2' => "subView=core.AdminRepository",'arg3' => "coreApi=".($this->_tpl_vars['AdminRepository']['latestCoreApiVersion']),'arg4' => "themeApi=".($this->_tpl_vars['AdminRepository']['latestThemeApiVersion']),'arg5' => "moduleApi=".($this->_tpl_vars['AdminRepository']['latestModuleApiVersion']),'arg6' => "showIncompatible=true"), $this);?>
"><?php $this->_smarty_vars['capture']['listLink'] = ob_get_contents(); ob_end_clean();  echo $this->_reg_objects['g'][0]->text(array('text' => "A new core module version is available. There may be plugins that are incompatible with the installed core module, which are not shown here. You can view a %scomplete list%s of plugins, including incompatible ones, which are marked with a red icon.",'arg1' => $this->_smarty_vars['capture']['listLink'],'arg2' => "</a>"), $this);?>

<?php endif;  endif; ?>
</p>
<?php ob_start(); ?>
<div class="AdminPlugins_legend">
<span class="icon-plugin-upgrade" style="margin-right: 10px; vertical-align: top">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'upgrade available'), $this);?>

</span>
<span class="icon-plugin-locked" style="margin-right: 10px; vertical-align: top">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'locked'), $this);?>

</span>
<span class="icon-plugin-incompatible" style="margin-right: 10px; vertical-align: top">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'incompatible'), $this);?>

</span>
</div>
<?php $this->_smarty_vars['capture']['legend'] = ob_get_contents(); ob_end_clean();  echo $this->_smarty_vars['capture']['legend']; ?>

<table class="gbDataTable">
<?php $this->assign('group', "");  $_from = $this->_tpl_vars['AdminRepository']['browseData']; if (!is_array($_from) && !is_object($_from)) { settype($_from, 'array'); }if (count($_from)):
    foreach ($_from as $this->_tpl_vars['pluginId'] => $this->_tpl_vars['plugin']):
 if ($this->_tpl_vars['group'] != $this->_tpl_vars['plugin']['groupLabel']):  if (! empty ( $this->_tpl_vars['group'] )): ?>
<tr><td> &nbsp; </td></tr>
<?php endif; ?>
<tr>
<th colspan="6"><h2><?php echo $this->_tpl_vars['plugin']['groupLabel']; ?>
</h2></th>
</tr><tr>
<th> &nbsp; </th>
<?php if ($this->_tpl_vars['plugin']['type'] == 'themes'): ?>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Theme Name'), $this);?>
 </th>
<?php else: ?>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Module Name'), $this);?>
 </th>
<?php endif; ?>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Installed'), $this);?>
 </th>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Latest'), $this);?>
 </th>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Description'), $this);?>
 </th>
<th> <?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Actions'), $this);?>
 </th>
</tr>
<?php endif;  $this->assign('group', $this->_tpl_vars['plugin']['groupLabel']); ?>
<tr class="<?php echo smarty_function_cycle(array('values' => "gbEven,gbOdd"), $this);?>
">
<td>
<div style="height: 16px" class="icon-plugin-<?php if ($this->_tpl_vars['plugin']['locked']): ?>locked" title="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Locked Plugin'), $this);?>
"
<?php elseif (! $this->_tpl_vars['plugin']['isCompatible']): ?>incompatible" title="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Incompatible Plugin'), $this);?>
"
<?php elseif ($this->_tpl_vars['plugin']['isUpgradeable']): ?>upgrade title="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Upgrade Available'), $this);?>
"
<?php else: ?>download"<?php endif; ?>/>
</td>
<td>
<?php echo $this->_tpl_vars['plugin']['name']; ?>

</td>
<td align="center">
<?php echo $this->_tpl_vars['plugin']['localVersion']; ?>

</td>
<td align="center">
<?php echo $this->_tpl_vars['plugin']['repositoryVersion']; ?>

</td>
<td>
<?php echo $this->_tpl_vars['plugin']['description']; ?>

<?php if (! $this->_tpl_vars['plugin']['isCompatible']): ?>
<br/>
<span class="giError">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Incompatible plugin!"), $this);?>

<?php if ($this->_tpl_vars['plugin']['api']['required']['core'] != $this->_tpl_vars['plugin']['api']['provided']['core']): ?>
<br/>
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Core API Required: %s (available: %s)",'arg1' => $this->_tpl_vars['plugin']['api']['required']['core'],'arg2' => $this->_tpl_vars['plugin']['api']['provided']['core']), $this);?>

<?php endif;  if ($this->_tpl_vars['plugin']['api']['required']['plugin'] != $this->_tpl_vars['plugin']['api']['provided']['plugin']): ?>
<br/>
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Plugin API Required: %s (available: %s)",'arg1' => $this->_tpl_vars['plugin']['api']['required']['plugin'],'arg2' => $this->_tpl_vars['plugin']['api']['provided']['plugin']), $this);?>

<?php endif; ?>
</span>
<?php endif; ?>
</td>
<td>
<?php if ($this->_tpl_vars['plugin']['locked'] || ! $this->_tpl_vars['plugin']['isCompatible']): ?>
&nbsp;
<?php else:  echo '<a href="';  echo $this->_reg_objects['g'][0]->url(array('arg1' => "view=core.SiteAdmin",'arg2' => "subView=core.AdminRepositoryDownload",'arg3' => "pluginType=".($this->_tpl_vars['plugin']['type']),'arg4' => "pluginId=".($this->_tpl_vars['pluginId'])), $this); echo '">';  if ($this->_tpl_vars['plugin']['isUpgradeable']):  echo '';  echo $this->_reg_objects['g'][0]->text(array('text' => 'upgrade'), $this); echo '';  elseif (! $this->_tpl_vars['plugin']['localVersion']):  echo '';  echo $this->_reg_objects['g'][0]->text(array('text' => 'download'), $this); echo '';  else:  echo '';  echo $this->_reg_objects['g'][0]->text(array('text' => 'modify'), $this); echo '';  endif;  echo '</a>'; ?>

<?php endif; ?>
</td>
</tr>
<?php endforeach; endif; unset($_from); ?>
</table>
<?php echo $this->_smarty_vars['capture']['legend']; ?>

<?php endif; ?>
</div>
<?php if ($this->_tpl_vars['AdminRepository']['upgradesAvailable']): ?>
<div class="gbBlock">
<h3><?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Upgrade All Plugins'), $this);?>
</h3>
<p class="giDescription">
<?php echo $this->_reg_objects['g'][0]->text(array('text' => "Gallery can automatically upgrade your themes and modules to the latest available versions. No new plugins will be downloaded."), $this);?>

</p>
</div>
<div class="gbBlock gcBackground1">
<input type="submit" class="inputTypeSubmit" name="<?php echo $this->_reg_objects['g'][0]->formVar(array('var' => "form[action][upgradeAll]"), $this);?>
" value="<?php echo $this->_reg_objects['g'][0]->text(array('text' => 'Upgrade All'), $this);?>
"/>
</div>
<?php endif;  endif; ?> 