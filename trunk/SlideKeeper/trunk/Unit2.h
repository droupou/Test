//---------------------------------------------------------------------------#ifndef Unit2H
#define Unit2H
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>
#include <time.h>
#include "label.h"
#include <stdio.h>#include <Forms.hpp>

//---------------------------------------------------------------------------
class TFrmNewRec : public TForm{__published:	// IDE-managed Components

    TImage *Image1;    TLabel *Label1;
    TEdit *Header_txt;
    TLabel *Label2;
    TEdit *Title_txt;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *EDate_date;
    TLabel *Label6;
    TLabel *Label7;
    TCheckBox *Approved_chk;
    TLabel *Label8;
    TEdit *Artist_txt;
    TLabel *Label9;
    TEdit *Title2_txt;
    TLabel *Label10;
    TEdit *Dimensions_txt;
    TComboBox *PDate_drp;
    TButton *OK_btn;
    TButton *Clear_btn;
    TButton *Cancel_btn;
    TComboBox *Material_drp;
    TComboBox *Entered_drp;
    TComboBox *Approved_btn;
    TLabel *Label11;
    TEdit *Date_txt;
    TLabel *Label12;
    TEdit *Path_txt;
    TButton *Browse_btn;
    TOpenDialog *OpenDialog1;

    void __fastcall Cancel_btnClick(TObject *Sender);
    void __fastcall Clear_btnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall OK_btnClick(TObject *Sender);
    void __fastcall OnGetFocus(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Browse_btnClick(TObject *Sender);
    void __fastcall Material_drpChange(TObject *Sender);
    void __fastcall OnKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall OnOnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations    label *l;
public:		// User declarations
    __fastcall TFrmNewRec(TComponent* Owner);};

//---------------------------------------------------------------------------
extern PACKAGE TFrmNewRec *FrmNewRec;
//---------------------------------------------------------------------------
#endif
