/***************************************************************************
 *            SFPgsql.cpp                                                  *
 *                                                                         *
 *  Sun Mar 20 20:33:33 2005                                               *
 *  Copyright  2005  Rick Runowski                                         *
 *  droupou@runowski.org                                                   *
 ***************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <wx/msgdlg.h>

// Constructor
SFPgsql::SFPgsql(){
  pghost = "dell";
  pgport = NULL;
  pgoptions = NULL;
  pgtty = NULL;
  dbName = "storefront";

  conn = PQsetdb(pghost, pgport, pgoptions, pgtty, dbName);

  if(PQstatus(conn) == CONNECTION_BAD){
    throw PGsqlBadConnection();
  }
}

void SFPgsql::exit_nicely(PGconn *conn){
  PQexec(conn, "CLOSE mycursor");
  PQexec(conn, "COMMIT");
  PQfinish(conn);
  exit(1);
}

boolean SFPgsql::sqlExecute(string query){
  res = PQexec(conn, "BEGIN");
  if (!res || PQresultStatus(res) != PGRES_COMMAND_OK){
    PQclear(res);
    throw PGsqlBeginFail();
    return false;
  }

  PQclear(res);

  res = PQexec(conn, "DECLARE mycursor CURSOR FOR " + query);
  if(!res || PQresultStatus(res) != PGRES_COMMAND_OK){
    PQclear(res);
    throw PGsqlCursorFail();
    return false;
  }
  PQclear(res);

  res = PQexec(conn, "FETCH ALL in mycursor");
  if(!res || PQresultStatus(res) != PGRES_TUPLES_OK){
    PQclear(res);
    throw PGsqlNoData();
    return false;
  }

  return true;
}

PGresult SFPgsql::sqlQuery(string query){
  if(!sqlExecute(query)){
    return NULL;
  }
  return res;
}
