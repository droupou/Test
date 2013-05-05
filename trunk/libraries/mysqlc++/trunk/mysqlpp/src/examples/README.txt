mysql++ examples (Win32/Borland) version
-----------------------------------------

NOTES:
-------
1)Examples are linked to libmysql.lib and mysqlplus.lib located in ../../lib/deb directory
2)Makefiles are tested using command-line tools of Borland C++ Builder 5.02 Enterprise.

PROBLEMS:
----------
1)Only examples cgi_image.cpp fieldinf1.cpp resetdb.cpp simple1.cpp updel_x_.cpp compiled successfully.
2)Examples using custom macros (custom*.cpp)(includes custom-macros.hh) doesn't compile at all. This is because Borland compiler doesn't support such a long macro expansions.
3)When compiling code with mysql++ you should be very careful with linker options.

HOW TO RUN
-----------
1) You should have mysql server installed on your localhost with user root and no password.
2) Run resetdb.exe example in order to create test database.
3) Run other examples

Good Luck !

Arturs Aboltins,				2000-11-10
Latvia
mailto:aaboltin@exchange.telekom.lv
t.:+371-7321566
