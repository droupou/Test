/*******************************************************************************
 *  Created By:        Rick Runowski                                           *
 *  On:                12/02/2004                                              *
 *  Description:                                                               *
 *  Object containing information on the product.                              *
 *                                                                             *
 *  Log:                                                                       *
 *  12/02/2004:        Created SFProduct.h, and began outline of functions and *
 *                       data.                                                 *
 *******************************************************************************/

struct Product {
  String partNumber, partDescription;
  double cost, msrp;
};

class SFProduct {
protected:
  String partNumber, partDescription;
  double cost, msrp;

public:
  SFProduct(String _partNumber, String _partDescription, double _cost, double _msrp);
  void Update();
  Product Refresh();
  bool changeCost(double _cost);
  bool changeMsrp(double _msrp);
};
