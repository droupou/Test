//---------------------------------------------------------------------------
#include <vcl.h>#pragma hdrstop

#include "Unit12.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TMsgBox *MsgBox;
//---------------------------------------------------------------------------
__fastcall TMsgBox::TMsgBox(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TMsgBox::FormCreate(TObject *Sender){    Done = false;
}

//---------------------------------------------------------------------------
void __fastcall TMsgBox::OK_btnClick(TObject *Sender){    Done = true;
}

//---------------------------------------------------------------------------
