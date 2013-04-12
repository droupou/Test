/****************************************************************
 * Name:        SFSQL.cpp                                       *
 * By:          Rick Runowski                                   *
 * On:          08/22/2005                                      *
 * Description:                                                 *
 * Driver class for SQL backend.                                *
 ****************************************************************/

SFSQL::SFSQL(){
	this->conn = PQconnectdb("host=localhost dbname=storefront user=homeacct st0r3fr0nt");
	if(PQstatus(this->conn) != CONNECTION_OK){
		cerr << "Connection to database failed.  Please try again later." << endl;
		cerr << PQerrorMessage(conn) << endl  
	}
};

SFSQL::~SFSQL(){
	        PQfinish(this->conn);
};

PGresult* SFSQL::SFQuery(wxString query){
	PGresult *res;

	res = PQexec(this->conn, "BEGIN");
	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		cerr << "BEGIN Command failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return null;
	}
	PQclear(res);

	res = PQexec(this->conn, query.Prepend("DECALRE myportal CURSOR FOR "));
	if (PQresultStatus(res) != PGRES_COMMAND_OK){
		cerr << "DECLARE CURSOR failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return null;
	}
	PQclear(res);

	res = PQexec(conn, "FETCH ALL in myportal");
	if  (PQresultStatus(res) != PGRES_TUPLES_OK){
		cerr << "FETCH ALL Failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return null;
	}	

	return res;
};

void SFSQL::exit_nicely(PGconn *conn){
	PQfinish(conn);
	exit(1);
};

bool SFSQL::SFExec(wxString query){
	PGresult *res;

	res = PQexec(this->conn, "BEGIN");
	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		cerr << "BEGIN Command failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return false;
	}
	PQclear(res);

	res = PQexec(this->conn, query.Prepend("DECALRE myportal CURSOR FOR "));
	if (PQresultStatus(res) != PGRES_COMMAND_OK){
		cerr << "DECLARE CURSOR failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return false;
	}
	PQclear(res);

	res = PQexec(conn, "FETCH ALL in myportal");
	if  (PQresultStatus(res) != PGRES_TUPLES_OK){
		cerr << "FETCH ALL Failed: " << PQerrorMessage(conn) << endl;
		PQclear(res);
		return false;
	}

	return true;
											
};
