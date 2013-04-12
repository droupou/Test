//---------------------------------------------------------------------------
#ifndef Unit14H#define Unit14H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "Unit6.h"
#include <Dialogs.hpp>
#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>   
#include <time.h>

//---------------------------------------------------------------------------
class TUpdForm : public TForm{__published:	// IDE-managed Components
    TImage *Image1;    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TEdit *Header_txt;
    TEdit *Title_txt;
    TEdit *EDate_date;
    TCheckBox *Approved_chk;
    TEdit *Artist_txt;
    TEdit *Title2_txt;
    TEdit *Dimensions_txt;
    TComboBox *PDate_drp;
    TButton *upd_btn;
    TButton *Close_btn;
    TComboBox *Material_drp;
    TComboBox *Entered_drp;
    TComboBox *Approved_btn;
    TLabel *Label11;
    TEdit *Date_txt;
    TButton *Next_btn;
    TButton *Prev_btn;
    TButton *Delete_btn;
    TLabel *Label12;
    TEdit *Path_txt;
    TButton *Browse_btn;
    TOpenDialog *OpenDialog1;

    void __fastcall FormCreate(TObject *Sender);    void __fastcall Next_btnClick(TObject *Sender);
    void __fastcall Prev_btnClick(TObject *Sender);
    void __fastcall Close_btnClick(TObject *Sender);
    void __fastcall upd_btnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Delete_btnclick(TObject *Sender);
    void __fastcall Browse_BtnClick(TObject *Sender);
    void __fastcall OnKeyPress(TObject *Sender, char &Key);
    void __fastcall OnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall OnGetFocus(TObject *Sender);

private:	// User declarations
    label *pres, *spres, *sHEAD;
public:		// User declarations
    label *HEAD;
    __fastcall TUpdForm(TComponent* Owner);    void __fastcall Populate();
    void __fastcall TUpdForm::AssignHEAD(label*H);
    void __fastcall TUpdForm::ResetPres();
    void __fastcall TUpdForm::GetList();

    label* TUpdForm::CopyLabel(label* l);};
//---------------------------------------------------------------------------
extern PACKAGE TUpdForm *UpdForm;
//---------------------------------------------------------------------------
#endif
