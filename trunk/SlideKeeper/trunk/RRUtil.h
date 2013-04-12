/****************************************************************************
 *    Utilities for Rick Runowski.                                          *
 ****************************************************************************/

#include <string>

#ifndef RRUTIL
#define RRUTIL
//---------------------------------------------------------------------------

bool IsDate(String oDate){
  bool ret;
  ret =
  (
    (
      (oDate[3] == '/') ||
      (oDate[3] == '.')
    ) &&
    (
      (atoi(oDate.SubString(1, 2).c_str()) <= 12)
    ) &&
    (
       (oDate[6] == '/') || (oDate[6] == '.')
    ) &&
    (
      (atoi(oDate.SubString(4,2).c_str()) <= 31)
    ) &&
    (
       (atoi(oDate.SubString(4,2).c_str()) != 0)
    )
  );
  return ret;
}

#endif