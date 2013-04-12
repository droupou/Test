/********************************************************************************
 *  Created By:         Rick Runowski                                           *
 *  On:                 12/16/2004                                              *
 *  Description:                                                                *
 *  Object containting the users permission levels for the various forms.       *
 *                                                                              *
 *  Log:                                                                        *
 *  12/16/2004:         Created SFPermissions.h, and began outline of functions *
 *                        and data.                                             *
 ********************************************************************************/

struct Permissions {
    SFPermissions *next, *prev;
    int form;
};

class SFPermissions {
  protected:
    int form;
    bool granted;
    // Permissions * permissions;

  public:
    SFPermissions();
    void AddPermission();
    bool CheckPermission(int form);
};
