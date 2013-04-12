/****************************************************************
 * Name:	SFSQL.hpp					*
 * By:		Rick Runowski					*
 * On:		08/22/2005					*
 * Description:							*
 * Driver class for SQL backend.				*
 * **************************************************************/

#include <stdio.h>
#include <iostream.h>
#include <postgresql/libpq-fe.h>
#include <postgresql/libpq/libpq-fs.h>
#include <wx/string.h>

class SFSQL{
private:
	PGconn *conn;
public:	
	SFSQL();
	~SFSQL();

	PGresult* SFQuery(wxString query);
	bool SFExec(wxString query);
	void exit_nicely(PGconn *conn);
};

