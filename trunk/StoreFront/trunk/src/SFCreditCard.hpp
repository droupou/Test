/******************************************************************************************
 *   Created By:        Rick Runowski                                                     *
 *   On:                12/02/2004                                                        *
 *   Description:                                                                         *
 *   This represents the Credit Card information within the storefront software.  It will *
 *     handle all operations on the customer data.                                        *
 *                                                                                        *
 *   Log:                                                                                 *
 *   12/02/2004        Created SFCreditCard.h, and began outline of functions and data.   *
 ******************************************************************************************/

class SFCreditCard{
protected:
  int ccId, custId;
  String ccNumber, ccExpirationDate;

public:
  
  SFCreditCard(int _custId);
  SFCreditCard(int _ccId, int _custId);
  SFCreditCard(int _custId, String _ccNumber, String _ccExpirationDate);

  /**************************************************************************************
   *    Update the data currently held in the credit card to the database.              *
   **************************************************************************************/
  bool Update();

  /**************************************************************************************
   *    Refresh will update the current object with the data in SQL.                    *
   **************************************************************************************/
  bool Refresh();
  
  /**************************************************************************************
   *    Manipulate data from the credit card object.                                    *
   **************************************************************************************/
  String GetNumber();
  String GetExpirationDate();
  bool SetNumer(String _ccNumber);
  bool SetExpDate(String _ccExpirationDate);
};
