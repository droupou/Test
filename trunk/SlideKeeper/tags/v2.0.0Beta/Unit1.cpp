//---------------------------------------------------------------------------
#include <vcl.h>

#include "Unit1.h"
#include "EditUser.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TfrmMain *frmMain;
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Exit1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::New1Click(TObject *Sender) {
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::About1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnCreate(TObject *Sender){
    StatusBar1->Invalidate();
    this->Width = 800;
    this->Height = 600;
    this->Top = 10;
    this->Left = 10;
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::Find1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddUser1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddPeriodDate1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddMaterials1Click(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::EditUser1Click(TObject *Sender){
    Application->CreateForm(__classid(TEditUserFrm), &EditUserFrm);
}
//---------------------------------------------------------------------------
