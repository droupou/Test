BCB = C:\Program Files\Borland\CBuilder6\Bin
MYSQL= C:\Source Code\libraries\mysqlc++\trunk\mysqlpp
RESFILES = 
RESDEPEN = $(RESFILES)
LIBFILES = $(MYSQL)\lib\deb\libmysql.lib $(MYSQL)\lib\deb\mysqlplus.lib
IDLFILES = 
IDLGENFILES = 
LIBRARIES = 
SPARELIBS = 
DEFFILE = 
# ---------------------------------------------------------------------------
PATHCPP = .;
PATHASM = .;
PATHPAS = .;
PATHRC = .;
DEBUGLIBPATH = $(BCB)\lib\debug
RELEASELIBPATH = $(BCB)\lib\release
USERDEFINES = _DEBUG
SYSDEFINES = NO_STRICT;_NO_VCL
INCLUDEPATH = $(BCB)\include;$(MYSQL)\include\mysql;$(MYSQL)\include\sqlplus
LIBPATH = $(BCB)\lib\obj;$(BCB)\lib
WARNINGS= -w-par
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Vx -Ve -X- -rd -a8 -5 -b- -k -y -v -vi- -tWC -tWM -c
PFLAGS = -$YD -$W -$O- -v -JPHNE -M
RFLAGS = 
AFLAGS = /mx /w2 /zd
LFLAGS = -D"" -ap -Tpe -x -Gn -v
# ---------------------------------------------------------------------------
ALLOBJ = c0x32.obj
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) $(LIBRARIES) import32.lib cw32mt.lib
# ---------------------------------------------------------------------------
# MAKE SECTION
# ---------------------------------------------------------------------------
# This section of the project file is not used by the BCB IDE.  It is for
# the benefit of building from the command-line using the MAKE utility.
# ---------------------------------------------------------------------------

.autodepend
# ---------------------------------------------------------------------------
!if "$(USERDEFINES)" != ""
AUSERDEFINES = -d$(USERDEFINES:;= -d)
!else
AUSERDEFINES =
!endif

!if !$d(BCC32)
BCC32 = bcc32
!endif

!if !$d(CPP32)
CPP32 = cpp32
!endif

!if !$d(DCC32)
DCC32 = dcc32
!endif

!if !$d(TASM32)
TASM32 = tasm32
!endif

!if !$d(LINKER)
LINKER = ilink32
!endif

!if !$d(BRCC32)
BRCC32 = brcc32
!endif


# ---------------------------------------------------------------------------
!if $d(PATHCPP)
.PATH.CPP = $(PATHCPP)
.PATH.C   = $(PATHCPP)
!endif

!if $d(PATHPAS)
.PATH.PAS = $(PATHPAS)
!endif

!if $d(PATHASM)
.PATH.ASM = $(PATHASM)
!endif

!if $d(PATHRC)
.PATH.RC  = $(PATHRC)
!endif
#----------------------------------------------------------------------------
ALL: simple1.exe resetdb.exe cgi_image.exe simple1.exe fieldinf1.exe updel_x_.exe
# ---------------------------------------------------------------------------
resetdb.exe: $(IDLGENFILES) resetdb.obj $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) \
    $(ALLOBJ) resetdb.obj, {$<},, \
    $(ALLLIB), $(DEFFILE), $(ALLRES)
	
# ---------------------------------------------------------------------------
cgi_image.exe: $(IDLGENFILES) cgi_image.obj $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) \
    $(ALLOBJ) cgi_image.obj, {$<},, \
    $(ALLLIB), $(DEFFILE), $(ALLRES)
	
# ---------------------------------------------------------------------------
simple1.exe: $(IDLGENFILES) simple1.obj $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) \
    $(ALLOBJ) simple1.obj, {$<},, \
    $(ALLLIB), $(DEFFILE), $(ALLRES)
	
# ---------------------------------------------------------------------------
fieldinf1.exe: $(IDLGENFILES) fieldinf1.obj $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) \
    $(ALLOBJ) fieldinf1.obj, {$<},, \
    $(ALLLIB), $(DEFFILE), $(ALLRES)
	
# ---------------------------------------------------------------------------
updel_x_.exe: $(IDLGENFILES) updel_x_.obj $(RESDEPEN) $(DEFFILE)
    $(BCB)\BIN\$(LINKER) $(LFLAGS) -L$(LIBPATH) \
    $(ALLOBJ) updel_x_.obj, {$<},, \
    $(ALLLIB), $(DEFFILE), $(ALLRES)
	
# ---------------------------------------------------------------------------
.pas.hpp:
    $(BCB)\BIN\$(DCC32) $(PFLAGS) -U$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -O$(INCLUDEPATH) --BCB {$< }
		
.pas.obj:
    $(BCB)\BIN\$(DCC32) $(PFLAGS) -U$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -O$(INCLUDEPATH) --BCB {$< }

.cpp.obj:
    $(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

.c.obj:
    $(BCB)\BIN\$(BCC32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n$(@D) {$< }

.c.i:
    $(BCB)\BIN\$(CPP32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n. {$< }

.cpp.i:
    $(BCB)\BIN\$(CPP32) $(CFLAG1) $(WARNINGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -n. {$< }

.asm.obj:
    $(BCB)\BIN\$(TASM32) $(AFLAGS) -i$(INCLUDEPATH:;= -i) $(AUSERDEFINES) -d$(SYSDEFINES:;= -d) $<, $@

.rc.res:
    $(BCB)\BIN\$(BRCC32) $(RFLAGS) -I$(INCLUDEPATH) -D$(USERDEFINES);$(SYSDEFINES) -fo$@ $<
# ---------------------------------------------------------------------------




