//---------------------------------------------------------------------------
#include <vcl.h>#pragma hdrstop
#include "Unit11.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)#pragma link "Unit13"
#pragma resource "*.dfm"

TPrintview_frm *Printview_frm;
//---------------------------------------------------------------------------
__fastcall TPrintview_frm::TPrintview_frm(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TPrintview_frm::OnClose(TObject *Sender,      TCloseAction &Action){
    this->DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TPrintview_frm::FormCreate(TObject *Sender){    ;}

//---------------------------------------------------------------------------
