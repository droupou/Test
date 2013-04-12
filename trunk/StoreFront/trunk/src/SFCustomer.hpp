/***************************************************************************************
 *  Created By:     Rick Runowski                                                      *
 *  On:             12/02/2004                                                         *
 *  Description:                                                                       *
 *  This represents the customer within the storefront software.  It will handle all   *
 *    operations on the customer data.                                                 *
 *                                                                                     *
 *  Log:                                                                               *
 *  12/02/2004:     Created SFCustomer.h, and began outline of functions and data.     *
 *  12/16/2004:     Added a list for the part numbers.                                 *
 ***************************************************************************************/

struct SFPhoneNum {
    SFPhoneNum *next, *prev;
    String phoneNumber;
}; 

struct SFEmail {
    SFEmail *next, *prev;
    String email;
}; 

struct CreditCard {
    CreditCard *next, *prev;
    SFCreditCard creditCard;
}; 

struct Customer {
    String title, firstName, lastName, companyName, address1, address2;
    char gender;
    bool contact;
    String zip, city, state, extention;

    SFEmail *email;
    SFPhoneNum *phoneNumber;
    CreditCard *creditCard;
}; 

class SFCustomer {

private: 
    int id;
    String title, firstName, lastName, companyName, address1, address2;
    char gender;
    bool contact;
    String zip, city, state, extention;

    SFEmail *email;
    SFPhoneNum *phoneNumber;
    CreditCard *creditCard;

public: 
    SFCustomer();
    ~SFCustomer();

  /***************************************************************************************************************
   *  Alter Customer will verify the data within the database has not yet been changed and update the            *
   *  information.  If it has already been changed by another user, display a dialog box with both sets of       *
   *  information in it and allow the user to choose which data should be updated.  If the data has been         *
   *  changed, but matches exactly, then no dialog will be displayed.                                            *
   ***************************************************************************************************************/
    void AlterCustomer(String title, String firstname, String lastname,
		       String companyname, String address1,
		       String address2, char gender, bool contact,
		       String zip, String city, String state,
		       String phoneNumber, String extention, String email);
    void AlterCustomer(Customer cust);

    void AddPhoneNumber(String phoneNum);
    void AddEmail(String email);
    void AddCreditCard(String creditCard);

  /*************************************************************************************************************
   *  Refreshes the customer with the data in the SQL Database.                                                *
   *************************************************************************************************************/
    void Refresh();

  /*************************************************************************************************************
   *  GetCustomer will return a Customer struct object with the data from this customer.                       *
   *************************************************************************************************************/
    Customer GetCustomer();
};
