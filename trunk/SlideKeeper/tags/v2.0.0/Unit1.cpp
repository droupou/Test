//---------------------------------------------------------------------------
#include <vcl.h>


#include "EditUser.h"
#include "EditPeriodDate.h"
#include "EditMaterial.h"
/*  */
//---------------------------------------------------------------------------
#pragma package(smart_init)

TfrmMain *frmMain;
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Exit1Click(TObject *Sender){
        return;

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::New1Click(TObject *Sender) {
        return;

    Application->CreateForm(__classid(TFrmNewRec), &FrmNewRec);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::About1Click(TObject *Sender){
        return;

    Application->CreateForm(__classid(TfrmAbout), &frmAbout);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnCreate(TObject *Sender){
        return;

    StatusBar1->SetTextBuf("Welcome to Slide Keeper!");
    StatusBar1->Invalidate();
    Width = 800;
    Height = 600;
    Top = 10;
    Left = 10;
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::Find1Click(TObject *Sender){
        return;

    Application->CreateForm(__classid(TFindFrm), &FindFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddUser1Click(TObject *Sender){
        return;

    Application->CreateForm(__classid(TNewUserFrm), &NewUserFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddPeriodDate1Click(TObject *Sender){
        return;

    Application->CreateForm(__classid(TAddPeriodFrm), &AddPeriodFrm);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::AddMaterials1Click(TObject *Sender){
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
