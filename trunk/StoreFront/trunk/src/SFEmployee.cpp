/**********************************************************************************
 *                                SFEmployee.cpp                                  *
 *                        Copyright 2005 Rick Runowski                            *
 *                                                                                *
 *    Created By:           Rick Runowski                                         *
 *    On:                   12/02/2004                                            *
 *    Description:                                                                *
 *        Object containing information on the employees.                         *
 *                                                                                *
 *    Log:                                                                        *
 *    12/02/2004:           Created SFEmployee.h, and began outline of functions  *
 *                              and data.                                         *
 *    01/17/2005:           Created SFEmployee.cpp.                               *
 *                                                                                *
 *    Email:                droupou@runowski.org                                  *
 **********************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

SFEmployee::SFEmployee(String _title, String _firstName, String _lastName,
		       String _positionDescription,
		       String _departmentDescription)
{
    title = _title;
    firstName = _firstName;
    lastName = _lastName;
    positionDescription = _positionDescription;
    departmentDescription = _departmentDescription;

    //TODO:  If this employee already exists, pull data on them and verify it is correct.
    //    If it doesn't exist insert it into the db and update the id number.
};

Employee SFEmployee::Refresh();
// title, f_name, l_name, positionDescription, departmentDescription
String *SFEmployee::getEmployeeData();
// title, f_name, l_name, positionDescription, departmentDescription
bool SFEmployee::changeEmployeeData(String _data[5]);
