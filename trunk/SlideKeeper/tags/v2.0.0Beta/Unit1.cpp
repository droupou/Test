//---------------------------------------------------------------------------
#include <vcl.h>#include <iostream.h>
#pragma hdrstop
#include "Unit1.h"#include "Unit2.cpp"#include "Unit3.cpp"#include "Unit5.cpp"#include "Unit4.cpp"#include "Unit8.cpp"#include "Unit9.cpp"#include "Unit10.cpp"
#include "EditUser.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TfrmMain *frmMain;//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Exit1Click(TObject *Sender){    Close();
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::New1Click(TObject *Sender) {    Application->CreateForm(__classid(TFrmNewRec), &FrmNewRec);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::About1Click(TObject *Sender){    Application->CreateForm(__classid(TfrmAbout), &frmAbout);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnCreate(TObject *Sender){    StatusBar1->SetTextBuf("Welcome to Slide Keeper!");
    StatusBar1->Invalidate();
    this->Width = 800;
    this->Height = 600;
    this->Top = 10;
    this->Left = 10;
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::Find1Click(TObject *Sender){    Application->CreateForm(__classid(TFindFrm), &FindFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddUser1Click(TObject *Sender){    Application->CreateForm(__classid(TNewUserFrm), &NewUserFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddPeriodDate1Click(TObject *Sender){    Application->CreateForm(__classid(TAddPeriodFrm), &AddPeriodFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddMaterials1Click(TObject *Sender){    Application->CreateForm(__classid(TAddMatFrm), &AddMatFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::EditUser1Click(TObject *Sender){
    Application->CreateForm(__classid(TEditUserFrm), &EditUserFrm);
}
//---------------------------------------------------------------------------

