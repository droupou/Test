//---------------------------------------------------------------------------
#include <vcl.h>

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TfrmAbout *frmAbout;
const char ver[11] = "1.3.2 Beta";
//---------------------------------------------------------------------------
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::Button1Click(TObject *Sender){

//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormCreate(TObject *Sender){
    this->Version_lbl->Caption = strcat("Version: ", ver);
    this->Copyright_lbl->Caption = "Copyright: All rights reserved.  Copyright Rick Runowski 2003 - 2005.";
    this->Copyright_lbl->Caption = "Copyright: All rights reserved.  Copyright Rick Runowski 2003 - 2005.";
    this->Comment_lbl->Caption = "Comments:  I am not afraid of tomorrow, for I have seen yesterday and I love today.\n\t\t-- William Allen White";
    this->Comment_lbl->Height = 129;
    this->Comment_lbl->Width = 250;

    this->Width = 742;
}

//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormClose(TObject *Sender, TCloseAction &Action){

//---------------------------------------------------------------------------