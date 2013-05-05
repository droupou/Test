//---------------------------------------------------------------------------
#include <vcl.h>#include <iostream.h>
#pragma hdrstop
#include "Unit1.h"#include "Unit2.h"#include "Unit3.h"#include "Unit4.h"#include "Unit5.h"#include "Unit8.h"#include "Unit9.h"#include "Unit10.h"
#include "EditUser.h"
#include "EditPeriodDate.h"
#include "EditMaterial.h"
/*  */
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TfrmMain *frmMain;//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Exit1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::New1Click(TObject *Sender) {    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TFrmNewRec), &FrmNewRec);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::About1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TfrmAbout), &frmAbout);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnCreate(TObject *Sender){    if(Sender == NULL)
        return;

    StatusBar1->SetTextBuf("Welcome to Slide Keeper!");
    StatusBar1->Invalidate();
    Width = 800;
    Height = 600;
    Top = 10;
    Left = 10;
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::Find1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TFindFrm), &FindFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddUser1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TNewUserFrm), &NewUserFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddPeriodDate1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TAddPeriodFrm), &AddPeriodFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddMaterials1Click(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TAddMatFrm), &AddMatFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::EditUser1Click(TObject *Sender){
    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TEditUserFrm), &EditUserFrm);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditPeriodDate1Click(TObject *Sender){
    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TEditPDateFrm), &EditPDateFrm);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::EditMaterials1Click(TObject *Sender){
    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TEditMaterialFrm), &EditMaterialFrm);
}
//---------------------------------------------------------------------------

