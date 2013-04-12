/****************************************************************
 * Name:	HASQL.hpp					*
 * By:		Rick Runowski					*
 * On:		08/22/2005					*
 * Description:							*
 * Driver class for SQL backend.				*
 * **************************************************************/

#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <postgresql/libpq/libpq-fs.h>
#include <wx/string.h>

class HASQL{
private:
	PGconn *conn;
public:	
	HASQL();
	~HASQL();

	bool CreateBank(char *name, bool positive);
	void exit();
};

HASQL::HASQL(){
	this->conn = PQconnectdb("host=localhost dbname=homeaccount user=homeacct h0m3fr0nt");

	if(PQstatus(this->conn) != CONNECTION_OK){
		cerr << "Connection to database failed.  Please try again later." << endl;
		cerr << PQerrorMessage(conn) << endl;
		this->exit();
	}
/*  */
};

HASQL::~HASQL(){
	PQfinish(this->conn);
};

bool HASQL::CreateBank(char *name, bool positive ){
	PGresult *res;
	wxString query;

	query = "INSERT INTO tb_bank (sz_name, bn_pos) VALUES('" + wxString(name) + "',";

	if(positive)
		query += wxString("true)");
	else
		query += wxString("false)");

	res = PQexec(this->conn, query);
	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		this->exit();
	}
	// Check res here.
	
	PQclear(res);
};

void exit(){
	PQfinish(this->conn);
	exit(1);
}
