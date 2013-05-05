//---------------------------------------------------------------------------
#ifndef Unit1H#define Unit1H

#include <Classes.hpp>#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------
#include <windows>#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
class TfrmMain : public TForm{
__published:	// IDE-managed Components    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Find1;
    TMenuItem *Exit1;
    TMenuItem *About1;
    TStatusBar *StatusBar1;
    TMenuItem *Manage1;
    TMenuItem *AddUser1;
    TMenuItem *AddPeriodDate1;
    TMenuItem *AddMaterials1;
    TMenuItem *EditUser1;

    void __fastcall Exit1Click(TObject *Sender);    void __fastcall New1Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall OnCreate(TObject *Sender);
    void __fastcall Find1Click(TObject *Sender);
    void __fastcall AddUser1Click(TObject *Sender);
    void __fastcall AddPeriodDate1Click(TObject *Sender);
    void __fastcall AddMaterials1Click(TObject *Sender);
    void __fastcall EditUser1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations    __fastcall TfrmMain(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
