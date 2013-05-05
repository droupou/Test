#include <windows.h>

#include <string>
using namespace std ;

#include "coldata4.hh"
#include "const_string3.hh"

template class mysql_ColData<string>;
template class mysql_ColData<const_string>;
