/****************************************************************************************
 *  Author:  Mick Walker                                                                *
 *  Revised by: Rick Runowski                                                           *
 *  Date of revision:  05/19/2004                                                       *
 *                                                                                      *
 *  This DLL is a derivative work that heavily copies from the program source found at  *
 *   http://www.planet-source-code.com/vb/scripts/ShowCode.asp?txtCodeId=7894&lngWId=3  *
 *   The DLL should be used to encode and decode file into and out of the UUEncode      *
 *   format.                                                                            *
 ***************************************************************************************/

#pragma once

class UUEncode{
private:
    static const int MAX_PATH_SIZE;
    static const int SEARCH_STRING_SIZE;

    char code_array[4];
    char byte_array[3];
    char coded_line[62];

    void uuencode_array();
    void put_coded_array(int line_length);
    void write_coded_line(int line_length);
    int DEC(int c);

public:

    void EncodeFile(char *fileName);
    void DecodeFile(char *fileName);
}
