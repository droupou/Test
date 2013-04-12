/****************************************************************************
 *            SFProduct.cpp                                                 *
 *                                                                          *
 *  Mon Feb 14 15:08:46 2005                                                *
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

 #include "SFProduct.hpp"

  SFProduct::SFProduct(String _partNumber, String _partDescription, double _cost, double _msrp){
    SFPgsql *conn = new SFPgsql();

    // TODO:  Query comparison.
    PGresult = conn.sqlQuery("SELECT * FROM ...");

    partNumber = _partNumber;
    partDescription = _partDescription;
    cost = _cost;
    msrp = _msrp;

    if(msrp < cost){
      //TODO:  Throw Error message stating that you are selling a product for
        //less than it costs to make.
    }
  }

  /*****************************************************************************
   *  Update the data currently held in the Employee to the database.          *
   *****************************************************************************/
  void SFProduct::Update(){
    ;
  }

  /*****************************************************************************
   *  Refresh will update the current object with the data in SQL.             *
   *****************************************************************************/
    Product SFProduct::Refresh(){
    ;
  }

  /*****************************************************************************
   *  Obtain the data from the Employee  object.                               *
   *****************************************************************************/
    Product SFProduct::GetCreditCard(){
    ;
  }

  bool SFProduct::changeCost(double _cost){
    cost = _cost;
    return true;
  }

  bool SFProduct::changeMsrp(double _msrp){
    if(_msrp < cost){
      //TODO:  Throw Error message stating that you are selling a product for
        //less than it costs to make.
    };
  }
