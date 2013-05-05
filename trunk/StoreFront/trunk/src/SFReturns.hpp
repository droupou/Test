/********************************************************************************
 *  Created By:     Rick Runowski                                               *
 *  On:             12/16/2004                                                  *
 *  Description:                                                                *
 *  Object containing information on the returns.                               *
 *                                                                              *
 *  Log:                                                                        *
 *  12/16/2004:     Created SFReturns.h, and began outline of functions and     *
 *                    data.                                                     *
 ********************************************************************************/
#include <string.h>
#include "SFPgsql.h"

struct prodList {
    prodList *next, *prev;
    SFProduct *product;
    String serialNumber, orderNumber;
    String testResults, employee;
};

class SFReturns {
  protected:
    String returnNum;
    date dateReceived, dateShipped;
    String shipper, shipMethod;
    String comments;
    prodList *head, *curr;

  public:
    SFReturns(date _dateReceived, date _dateShipped, String _shipper,
      String _shipMethod, String comments);
    SFReturns(string _returnNum);
    bool AddProduct(SFProduct _product, String  _serialNumber,
      String _orderNumber, String _testResults, String _employee);
    bool DeleteProduct(SFProduct _product, String _serialNumber);
    bool Update();
};
