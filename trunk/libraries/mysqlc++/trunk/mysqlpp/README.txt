mysql++ 1.7 Win32 version made by Borland C++ Builder 5.02
----------------------------------------------------------

Remarks
-------
1)This is a totally betta. Intension of this project was to make "native" library
mysql++ for Win32 platform (Borland Delphi and C++ Builder) wihout using cygwin.

2)You can re-compile this librarary using Borland Free Command line tools available at
http://www.borland.com

3)IMPORTANT: For successful compilation of this library on Borland compiler platform you
should replace STL library file iterator.h in (BCB_INSTALL_DIR)\include\Rw with new one
available in this bundle in include/Rw directory.

4)Source of mysql++ is significantly modified. This means, that it is "snapshot" of
mysql++ v.1.7. In case if new version will be released, it will not be possible automatically to recompile to Win32/Borland.

5)The library is not tested very much. It is very possible that bugs still exists.

Content of directories
----------------------
mysql++_1.7_win32_borland_v1.1
 +-include
 |  +-mysql   .... mysql  C API header files
 |  +-sqlplus .... mysql++ header  files
 |  +-Rw      .... modified iterator.h for STL library. You should copy this file to
 |                (BCB_INSTALL_DIR)\include\Rw
 +-lib
 |  +-deb .... Debug verion of libmysql.dll with import library for Borland compilers, 
 |  |          and already  compiled debug version of mysqlplus.lib
 |  +-rel .... Release verion of libmysql.dll with import library for Borland compilers   
 |             and already  compiled release version of mysqlplus.lib
 |
 +-src      
    +-sqlplus  .... source code and makefiles of the library
    |  +-debug  ... compiled debug version of mysql++ library for win32 (Borland OMF).
    |  +-release... compiled release version of mysql++ library for win32 (Borland OMF).
    |
    +-examples .... mysql++ examples

Bugs and notes
----------------
1)The mysqlplus.lib can be linked using Borland linkers to your projects, 
BUT you_should_not_use_dynamic_RTL.
2)You should always include <windows.h> in your cpp files


Best Regards !
							
November 10, 2000					Arturs Aboltins
							mailto: aaboltin@exchange.telekom.lv
							Latvia