/********************************************************************
 *  Created By:         Rick Runowski                               *
 *  On:                 03/20/2005                                  *
 *  Description:                                                    *
 *  Library to connect to postgresql server.                        *
 *                                                                  *
 *  Log:                                                            *
 *  03/20/2005:         Created SFPgsql.hpp, and began outline of   *
 *                        functions and data.                       *
 ********************************************************************/

#include <libpq-fe.h>

using namespace std;

class PGsqlBadConnection{
public:
  PGsqlBadConnection(){};
  ~PGsqlBadConnection(){};
  const char *ShowReason() const { return "Bad Connection";}
};

class PGsqlBeginFail{
public:
  PGsqlBeginFail(){};
  ~PGsqlBeginFail(){};
  const char *ShowReason() const { return "Begin Failed";}
};

class PGsqlCursorFail{
  PGsqlCursorFail(){};
  ~PGsqlCursorFail(){};
  const char *ShowReason() const { return "Cursor Failed";}
};

class PGsqlNoData{
  PGsqlNoData(){};
  ~PGsqlNoData(){};
  const char *ShowReason() const { return "No data in Cursor";}
};

class SFPgsql{
protected:
  char       *pghost, *pgport, *pgoptions, *pgtty, *dbName;
  int        nFields, i, j;
  PGconn     *conn;
  PGresult   *res;

public:
  SFPgsql();
  PGresult sqlQuery(string query);
  void exit_nicely(PGconn *conn);
  boolean  sqlExecute(string query);
};
