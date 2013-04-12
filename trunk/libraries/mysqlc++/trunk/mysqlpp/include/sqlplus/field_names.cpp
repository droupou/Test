#include <windows.h>

#include "field_names3.hh"
#include "result2.hh"

void FieldNames::init(const ResUse *res)
{
  int num = res->num_fields();
  reserve(num);
  Fields fs = res->fields();
  for (int i = 0; i < num; i++)
  {
      Field f = fs[i];
      string p(f.name);
      str_to_lwr(p);
      push_back(p);
  }
}
//=================================================================
