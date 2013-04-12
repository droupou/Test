/**********************************************************************************
 *    Created By:          Rick Runowski                                          *
 *    On:                  12/02/2004                                             *
 *    Description:                                                                *
 *    Object containing information on the employees.                             *
 *                                                                                *
 *    Log:                                                                        *
 *    12/02/2004:          Created SFEmployee.h, and began outline of functions   *
 *                             and data.                                          *
 **********************************************************************************/

class SFEmployee{

protected:
  String title, firstName, lastName, positionDescription, departmentDescription, ssn;
  int empId, superId;

public:
  SFEmployee();
  SFEmployee(String _title, String _firstName, String _lastName, String _positionDescription, String _departmentDescription, String ssn);

  /********************************************************************************
   *    Refresh will update the current object with the data in SQL.              *
   ********************************************************************************/
  bool Refresh();
  
  /********************************************************************************
   *    Manipulate EmployeeName data.                                             *
   ********************************************************************************/
  // The returned string array will be in the order of :
  // title, f_name, l_name, positionDescription, departmentDescription, ssn
  String* GetEmployeeData(); 

  // The data array will need to be in the order of:
  // title, f_name, l_name, positionDescription, departmentDescription, ssn
  bool ChangeEmployeeData(String _data[6]);  
};
