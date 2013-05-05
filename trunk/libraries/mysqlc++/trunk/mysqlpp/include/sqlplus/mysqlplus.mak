<?xml version='1.0' encoding='utf-8' ?>
<!-- C++Builder XML Project -->
<PROJECT>
  <MACROS>
    <VERSION value="BCB.05.03"/>
    <PROJECT value="..\..\lib\deb\mysqlplus.lib"/>
    <OBJFILES value="coldata.obj connection.obj datetime.obj field_names.obj field_types.obj 
      manip.obj query.obj result.obj set.obj sql_query.obj string_util.obj 
      type_info.obj vallist.obj"/>
    <RESFILES value=""/>
    <IDLFILES value=""/>
    <IDLGENFILES value=""/>
    <DEFFILE value=""/>
    <RESDEPEN value="$(RESFILES)"/>
    <LIBFILES value="..\..\lib\deb\libmysql.lib"/>
    <LIBRARIES value=""/>
    <SPARELIBS value=""/>
    <PACKAGES value=""/>
    <PATHCPP value=".;"/>
    <PATHPAS value=".;"/>
    <PATHRC value=".;"/>
    <PATHASM value=".;"/>
    <DEBUGLIBPATH value=""/>
    <RELEASELIBPATH value=""/>
    <LINKER value="TLib"/>
    <USERDEFINES value="_DEBUG"/>
    <SYSDEFINES value="NO_STRICT"/>
    <MAINSOURCE value="mysqlplus.bpf"/>
    <INCLUDEPATH value="$(BCB)\include;..\..\include\mysql"/>
    <LIBPATH value="$(BCB)\lib\obj;$(BCB)\lib"/>
    <WARNINGS value="-w-par"/>
    <WARNOPTSTR value=""/>
    <LISTFILE value=""/>
  </MACROS>
  <OPTIONS>
    <IDLCFLAGS value="-I$(BCB)\include -I..\..\include\mysql -src_suffix cpp -D_DEBUG -no_tie -boa"/>
    <CFLAG1 value="-Od -Vx -Ve -X- -a8 -6 -b- -k -y -v -vi- -c -tW -tWM"/>
    <PFLAGS value="-$Y+ -$W -$O- -v -JPHNE -M"/>
    <RFLAGS value=""/>
    <AFLAGS value="/mx /w2 /zi"/>
    <LFLAGS value="-l&quot;D:\cpp\win\lib\deb\&quot; /P256"/>
  </OPTIONS>
  <LINKER>
    <ALLOBJ value="$(OBJFILES)"/>
    <ALLRES value=""/>
    <ALLLIB value=""/>
  </LINKER>
  <IDEOPTIONS>
[Version Info]
IncludeVerInfo=0
AutoIncBuild=0
MajorVer=1
MinorVer=0
Release=0
Build=0
Debug=0
PreRelease=0
Special=0
Private=0
DLL=0
Locale=1062
CodePage=1257

[Version Info Keys]
CompanyName=
FileDescription=
FileVersion=1.0.0.0
InternalName=
LegalCopyright=
LegalTrademarks=
OriginalFilename=
ProductName=
ProductVersion=1.0.0.0
Comments=

[HistoryLists\hlIncludePath]
Count=2
Item0=$(BCB)\include;..\..\include\mysql
Item1=$(BCB)\include\STL;$(BCB)\include;..\..\include\mysql

[HistoryLists\hlLibraryPath]
Count=1
Item0=$(BCB)\lib\obj;$(BCB)\lib

[HistoryLists\hlDebugSourcePath]
Count=1
Item0=$(BCB)\source\vcl

[HistoryLists\hlConditionals]
Count=1
Item0=_DEBUG

[HistoryLists\hlFinalOutputDir]
Count=1
Item0=..\..\lib\deb\

[HistoryLists\hIBPIOutputDir]
Count=2
Item0=D:\cpp\win\lib\deb\
Item1=..\..\lib\deb\

[HistoryLists\hlTlibPageSize]
Count=1
Item0=0x0100

[Debugging]
DebugSourceDirs=$(BCB)\source\vcl

[Parameters]
RunParams=
HostApplication=
RemoteHost=
RemotePath=
RemoteDebug=0

[Compiler]
ShowInfoMsgs=0
LinkDebugVcl=0
LinkCGLIB=0

[CORBA]
AddServerUnit=0
AddClientUnit=0
PrecompiledHeaders=0

[Language]
ActiveLang=
ProjectLang=
RootDir=
  </IDEOPTIONS>
</PROJECT>