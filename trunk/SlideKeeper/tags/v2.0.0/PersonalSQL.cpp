/**************************************************************************** *    An SQL header that allows me to parse SQL.                            *
 ****************************************************************************/

//---------------------------------------------------------------------------
String SQLParse(String old){
    String newstr;    int count;

    newstr = "";    count = 1;

    while(count <= old.Length()){
        if((old.SubString(count,1) == "'") || (old.SubString(count,1) == '\\')){
            newstr += "\\";
            newstr += old.SubString(count,1);
        }
        else{
            newstr += old.SubString(count,1);
        }
        count++;
    }
    return newstr;
}

