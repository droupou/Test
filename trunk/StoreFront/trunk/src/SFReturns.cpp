/****************************************************************************
 *            SFReturns.cpp                                                 *
 *                                                                          *
 *  Mon Feb 14 14:50:37 2005                                                *
 *  Copyright  2005  Rick Runowski                                          *
 *  droupou@runowski.org                                                    *
 ****************************************************************************/

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

SFReturns::SFReturns(date _dateReceived, date _dateShipped, String _shipper,
  String _shipMethod, String _comments){
    String rnum, emsg = NULL;
    bool err = false;

    conn = new SFPgsql();

    returnNum = "RRUN-";

    try{
      PGresult lres = conn->sqlExecute("SELECT EXTRACT(EPOCH FROM CURRENT_TIMESTAMP);");
      if(PQresultStatus(lres) != PGRES_TUPLES_OK){
         wxMessageBox("PGRES_TUPLES_OK returned false.", "Error Message", wxOK|wxICON_HAND, this, -1, -1);
         PQclear(lres);
      }
      else{
        returnNum += itoa(int(PQgetvalue(lres, 1,1)));
        PQclear(lres);
      }

      head = curr = NULL;
      dateReceived = _dateReceived;
      dateShipped = _dateShipped;
      shipper = _shipper;
      shipMethod = _shipMethod;
      comments = _comments;
    }
    catch(PGsqlBadConnection E){
      emsg = "Cannot create connection to Postgres server.";
      err = true;
    }
    catch(PGsqlBeginFail E){
      emsg = "Cannot Begin a transaction.";
      err = true;
    }
    catch(PGsqlCursorFail E){
      emsg = "Cannot create a Cursor.";
      err = true;
    }
    catch(PGsqlNoData E){
      emsg = "Cursor didn't return any data.";
      err = true;
    }

    if(err){
      wxMessageBox(emsg, "Error Message", wxOK|wxICON_HAND, this, -1, -1);
    }
  }

  bool SFReturns::AddProduct(SFProduct _product, String  _serialNumber,
    String _orderNumber, String _testResults, String _employee){
    if(head == NULL){
      head = curr = new prodList;
    }
    else{
      curr->next = new prodList;
      curr->next->prev = curr;
      curr = curr->next;
    }

    curr->product = _product;
    curr->serialNumber = _serialNumber;
    curr->orderNumber = _orderNumber;
    curr->testResults = _testResults;
    curr->employee = _employee;
  }

  SFReturns::SFReturns(string _returnNum){
    conn = new SFPgsql();
    PGresult res;

    res = conn->sqlQuery(
        "SELECT * FROM tb_returns INNER JOIN tb_returndetails ON "
        + "tb_returns.tk_returnid = tb_returndetails.tk_returnid;");

    if(PQresultStatus(lres) != PGRES_TUPLES_OK){
      wxMessageBox("PGRES_TUPLES_OK returned false.",
        "Error Message", wxOK|wxICON_HAND, this, -1, -1);
        PQclear(lres);
    }
    else{
      returnNum += itoa(int(PQgetvalue(lres, 1,1)));
      PQclear(lres);
    }
  }

  bool SFReturns::DeleteProduct(SFProduct _product, _serialNumber){
    prodList *tcurr;

    tcurr = head;
    while((tcurr->serialNumber != _serialNumber) && (tcurr->next != NULL)){
      tcurr = tcurr->next;
    }

    if(tcurr->serialNumber == _serialNumber){
      tcurr->prev->next = tcurr->next;
      tcurr->next->prev = tcurr->prev;
      delete(tcurr);
    }
    else{
      wxMessageBox("Attempted to delete product that didn't exist.",
      "Error Message", wxOK|wxICON_HAND, this, -1, -1);
    }
  }

  bool SFReturns::Update(){
    SFPgsql *conn = new SFPgsql();
    PGresult *res;
    string sql, retId, emsg = NULL;
    bool ret = true;

    sql = "SELECT tk_returnid FROM tb_returns WHERE sz_returnnumber = '"
      + returnNum + "';";
    try{
      res = conn->sqlQuery(sql);

      retId = PQgetvalue(res, 0, 0);
    }
    catch(PGsqlBadConnection E){
      emsg = "Cannot create connection to Postgres server.";
      err = true;
    }
    catch(PGsqlBeginFail E){
      emsg = "Cannot Begin a transaction.";
      err = true;
    }
    catch(PGsqlCursorFail E){
      emsg = "Cannot create a Cursor.";
      err = true;
    }
    catch(PGsqlNoData E){
      emsg = "Cursor didn't return any data.";
      err = true;
    }

    if(err){
      wxMessageBox(emsg, "Error Message", wxOK|wxICON_HAND, this, -1, -1);
    }

    return ret;
  }
