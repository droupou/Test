; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=SlideKeeper
AppVerName=SlideKeeper 2.0.1
AppPublisher=Rick Runowski
AppPublisherURL=http://www.runowski.org/SlideKeeper
AppSupportURL=http://www.runowski.org/SlideKeeper
AppUpdatesURL=http://www.runowski.org/SlideKeeper
DefaultDirName={pf}\SlideKeeper
DefaultGroupName=SlideKeeper
AllowNoIcons=true
Compression=lzma
SolidCompression=true
PrivilegesRequired=admin
SetupIconFile=C:\Source Code\SlideKeeper\trunk\vrl.ico
AppCopyright=Rick Runowski 2005
ShowLanguageDialog=yes
AppID={{A58D8526-0801-4905-8621-32D2739A483B}

[Tasks]
Name: desktopicon; Description: {cm:CreateDesktopIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: unchecked
Name: quicklaunchicon; Description: {cm:CreateQuickLaunchIcon}; GroupDescription: {cm:AdditionalIcons}; Flags: unchecked

[Files]
Source: C:\Source Code\SlideKeeper\trunk\SlideKeeper.exe; DestDir: {app}; Flags: ignoreversion
Source: C:\Source Code\SlideKeeper\trunk\export.sql; DestDir: {app}; Flags: ignoreversion
Source: C:\Source Code\SlideKeeper\trunk\update.sql; DestDir: {app}; Flags: ignoreversion
Source: C:\Source Code\SlideKeeper\trunk\config.cfg; DestDir: {app}; Flags: ignoreversion

Source: C:\Source Code\SlideKeeper\trunk\readme.txt; DestDir: {app}; Flags: ignoreversion isreadme

;Source: "C:\Source Code\SlideKeeper\trunk\dist\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs
Source: C:\Source Code\SlideKeeper\trunk\thevrl.jpg; DestDir: C:\VRL\thevrl.jpg; Flags: ignoreversion recursesubdirs
Source: C:\Source Code\SlideKeeper\trunk\thevrl2.jpg; DestDir: C:\VRL\thevrl.jpg; Flags: ignoreversion recursesubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

Source: C:\Windows\system32\vcl60.bpl; DestDir: {win}\system32\
Source: C:\Windows\system32\rtl60.bpl; DestDir: {win}\system32\
Source: C:\Windows\system32\vcljpg60.bpl; DestDir: {win}\system32\
Source: C:\Windows\system32\vclshlctrls60.bpl; DestDir: {win}\system32\
Source: C:\Windows\system32\vclsmp60.bpl; DestDir: {win}\system32\
Source: C:\Windows\system32\vclx60.bpl; DestDir: {win}\system32\
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\borlndmm.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\bcbmm.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\bccide.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\borlndmm.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\brcide.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\cc3260.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\cc3260mt.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\comp32p.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\dcc60.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\delphimm.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\ilink32.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\imged32.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\ixxml60.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\lnkdfm60.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\rlink32.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\rw32core.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\stlp45.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\stlp_stldebug45.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\stlpmt45.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\stlpmt_stldebug45.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\typelibimport.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\vcltest3.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\xmlide.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\xprtfltr.dll; DestDir: {app}
Source: ..\..\..\Program Files\Borland\CBuilder6\Bin\bcbedit.dll; DestDir: {app}
Source: ..\..\..\WINDOWS\system32\libmySQL.dll; DestDir: {app}

[INI]
Filename: {app}\SlideKeeper.url; Section: InternetShortcut; Key: URL; String: http://www.runowski.org

[Icons]
Name: {group}\SlideKeeper; Filename: {app}\SlideKeeper.exe
Name: {group}\{cm:ProgramOnTheWeb,SlideKeeper}; Filename: {app}\SlideKeeper.url
Name: {group}\{cm:UninstallProgram,SlideKeeper}; Filename: {uninstallexe}
Name: {userdesktop}\SlideKeeper; Filename: {app}\SlideKeeper.exe; Tasks: desktopicon
Name: {userappdata}\Microsoft\Internet Explorer\Quick Launch\SlideKeeper; Filename: {app}\SlideKeeper.exe; Tasks: quicklaunchicon

[Run]
Filename: {app}\SlideKeeper.exe; Description: {cm:LaunchProgram,SlideKeeper}; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: {app}\SlideKeeper.url

