/****************************************************************************
 ****************************************************************************/

//---------------------------------------------------------------------------
String SQLParse(String old){
    String newstr;

    newstr = "";

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
