//---------------------------------------------------------------------------
#include <vcl.h>#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TfrmAbout *frmAbout;
const char ver[11] = "1.3.2 Beta";
//---------------------------------------------------------------------------__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::Button1Click(TObject *Sender){    if(Sender != NULL)        this->DestroyWnd();}

//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormCreate(TObject *Sender){    if(Sender == NULL)        return;        this->Product_lbl->Caption = "Product Name:  Slide Keeper";
    this->Version_lbl->Caption = strcat("Version: ", ver);
    this->Copyright_lbl->Caption = "Copyright: All rights reserved.  Copyright Rick Runowski 2003 - 2005.";
    this->Copyright_lbl->Caption = "Copyright: All rights reserved.  Copyright Rick Runowski 2003 - 2005.";
    this->Comment_lbl->Caption = "Comments:  I am not afraid of tomorrow, for I have seen yesterday and I love today.\n\t\t-- William Allen White";
    this->Comment_lbl->Height = 129;
    this->Comment_lbl->Width = 250;

    this->Width = 742;    this->Height = 283;
}

//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormClose(TObject *Sender, TCloseAction &Action){    if((Sender == NULL) && (Action == NULL))        return;    this->DestroyWnd();}

//---------------------------------------------------------------------------
