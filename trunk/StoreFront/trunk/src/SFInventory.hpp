/**********************************************************************************
 *  Created By:         Rick Runowski                                             *
 *  On:                 12/16/2004                                                *
 *  Description:                                                                  *
 *  Object containing information on the inventory levels.                        *
 *                                                                                *
 *  Log:                                                                          *
 *  12/16/2004:         Created SFInventory.h, and began outline of functions and *
 *                        data.                                                   *
 **********************************************************************************/

class SFInventory {
  protected:
    SFProduct * product;
    String location;
    int qty;
  public:
     SFInventory();
     SFInventory(SFProduct prod, String loc, int quantity);

    bool addProduct(int quantity);
    bool subProduct(int quantity);
    bool equals(SFInventory * that);
};
