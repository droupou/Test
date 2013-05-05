/******************************************************************************************
 *    Created By:       Rick Runowski                                                     *
 *    On:               12/02/2004                                                        *
 *    Description:                                                                        *
 *    This represents the Credit Card information within the storefront software.  It     *
 *      will handle all operations on the customer data.                                  *
 *                                                                                        *
 *    Log:                                                                                *
 *    12/28/2005        Created SFCreditCard.cpp, and began creating functions.           *
 *    											  *
 *    ToDo:										  *
 *    1.	May have problem pulling credit cards using only customer ID.  What 	  *
 *    		happens if the customer has more than one id?				  *
 *    											  *
 *    2.	Do we need a field to determine what type of credit card it is?		  *
 ******************************************************************************************/

SFCreditCard::SFCreditCard(int _custID){
	SFSQL SQL* = new SFSQL();
	PGresult *res;

	res = SQL.query("SELECT tk_creditcardID, tk_custid, cs_creditcardnum, cs_expdate FROM tb_creditcard WHERE tk_custid = " + _custID);

	ccId = PQgetvalue(res, 0, 0);
	custId = PQgetvalue(res, 0, 1);
	ccNumber = PQgetvalue(res, 0, 2);
	ccExpirationDate = PQgetvalue(res, 0, 3);

	delete(SQL);
}

SFCreditCard::SFCreditCard(int _ccId, int _custID){
	SFSQL SQL* = new SFSQL();
	PGresult *res;

	res = SQL.query("SELECT tk_creditcardID, tk_custid, cs_creditcardnum, cs_expdate FROM tb_creditcard WHERE tk_custid = " + _custID 
			+ " AND tk_creditcardID = " + _ccId);

	ccId = PQgetvalue(res, 0, 0);
	custID = PQgetvalue(res, 0, 1);
	ccNumber = PQgetvalue(res, 0, 2);
	ccExpirationDate = PQgetvalue(res, 0, 3);

	delete(SQL);
}

SFCreditCard::SFCreditCard(int _custId, String _ccNumber, String _ccExpirationDate){
	SFSQL SQL* = new SFSQL();
	PGresult *res;

	res = SQL.query("SELECT tk_creditcardID, tk_custid, cs_creditcardnum, cs_expdate FROM tb_creditcard WHERE tk_custid = " + _custID
			+ "AND cs_creditcardnum = '" + _ccNumber + "' AND cs_expdate = '" + ccExpirationDate + "'");

	ccId = PQgetvalue(res, 0, 0);
	custID = PQgetValue(res, 0, 1);
	ccNumber = PQgetvalue(res, 0, 2);
	ccExpirationDate = PQgetvalue(res, 0, 3);

	delete(SQL);
}

void SFCreditCard::Update(){
	SFSQL SQL* = new SFSQL();
	PGresult *res;

	res = SQL.query("UPDATE tb_creditcard (cs_creditcardnum, cs_expdate) VALUES('" + ccNumber +"', '" + ccExpirationDate 
			+ "') WHERE tk_creditcardID = " + ccId);
}

void SFCreditCard::Refresh(){
	SFSQL SQL* = new SFSQL();
	PGresult *res;

	res = SQL.query("SELECT tk_creditcardID, tk_custid, cs_creditcardnum, cs_expdate FROM tb_creditcard WHERE tk_custid = " + custID
			+ " AND tk_creditcardID = " + ccId);

	ccNumber = PQgetvalue(res, 0, 2);
	ccExpirationDate = PQgetvalue(res, 0, 3);

	delete(SQL);
}

String SFCreditCard::GetNumber(){
    return ccNumber;
}

String SFCreditCard::getExpirationDate(){
    return ccExpirationDate;
}

bool SFCreditCard::SetNumer(String _ccNumber){
	int c, chk, luhn;
	
	//  Basic Luhn Check.
	if ((_ccNumber[0] == 5) && (_ccNumber[1] > 0) && (_ccNumber[1] < 6) && (_ccNumber.length == 16)){
		// Master Card Check
	} else if((_ccNumber[0] == 4) && ((_ccNumber.length == 13) || (_ccNumber.length == 16))){
		// Visa Card Check
	} else if((_ccNumber[0] == 3) && ((_ccNumber[1] == 4)||(_ccNumber[1] == 7)) && (_ccNumber.length == 15)){
		// American Express Card Check
	} else if((_ccNumber[0] == 3) && (((_ccNumber[1] == 0) && ((_ccNumber[2] == 0) || (_ccNumber[2] == 5)))||(_ccNumber[1] == 6)||(_ccNumber[1] == 8))){
		//Diners Club Card Check
	} else if((_ccNumber[0] == 6) && (_ccNumber[1] == 0) && (_ccNumber[2] == 1) && (_ccNumber[3] == 1)){
		// Discover Card Check
	}

	c = _ccNumber.length;
	chk = _ccNumber[c--];
	luhn = 0;
	
	// Find Luhn Number
	for(;c >= 0; c--){
		luhn += (((_ccNumber[c]*2)%10) + ((_ccNumber[c--]*2)/10));
		luhn += _ccNumber[c];
	}

	if ((luhn%10) == 0){
		ccNumber = _ccNumber;
		return true;
	} 

	return false;
}

bool SFCreditCard::SetExpDate(String _ccExpirationDate){
	
}
    
