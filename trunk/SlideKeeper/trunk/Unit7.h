//---------------------------------------------------------------------------
#ifndef Unit7H#define Unit7H

//---------------------------------------------------------------------------#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Classes.hpp>

#include <windows>#include <winsock>
#include <mysql/mysql.h>
#include <string.h>
#include <stdio.h>

//---------------------------------------------------------------------------
class TFrame7 : public TFrame{
__published:	// IDE-managed Components    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TCheckBox *CheckBox3;
    TCheckBox *CheckBox4;
    TCheckBox *CheckBox5;
    TCheckBox *CheckBox6;
    TCheckBox *CheckBox7;
    TCheckBox *CheckBox8;
    TCheckBox *CheckBox9;
    TCheckBox *CheckBox10;
    TCheckBox *CheckBox11;
    TCheckBox *CheckBox12;
    TCheckBox *CheckBox13;
    TCheckBox *CheckBox14;
    TCheckBox *CheckBox15;
    TCheckBox *CheckBox16;
    TCheckBox *CheckBox17;
    TCheckBox *CheckBox18;
    TCheckBox *CheckBox19;
    TCheckBox *CheckBox20;
    TCheckBox *CheckBox21;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label31;
    TLabel *Label32;
    TLabel *Label41;
    TLabel *Label42;
    TLabel *Label51;
    TLabel *Label52;
    TLabel *Label61;
    TLabel *Label62;
    TLabel *Label71;
    TLabel *Label72;
    TLabel *Label81;
    TLabel *Label82;
    TLabel *Label91;
    TLabel *Label92;
    TLabel *Label101;
    TLabel *Label102;
    TLabel *Label111;
    TLabel *Label112;
    TLabel *Label121;
    TLabel *Label122;
    TLabel *Label131;
    TLabel *Label132;
    TLabel *Label141;
    TLabel *Label142;
    TLabel *Label151;
    TLabel *Label152;
    TLabel *Label161;
    TLabel *Label162;
    TLabel *Label171;
    TLabel *Label172;
    TLabel *Label181;
    TLabel *Label182;
    TLabel *Label191;
    TLabel *Label192;
    TLabel *Label201;
    TLabel *Label202;
    TLabel *Label211;
    TLabel *Label212;
    TLabel *Label213;

private:	// User declarations

public:		// User declarations
    __fastcall TFrame7(TComponent* Owner);
    void __fastcall TFrame7::AddLine(String CB, String LB);
    void __fastcall TFrame7::SetSQL(String nstr);
    void __fastcall TFrame7::ResetCnt();
    String __fastcall TFrame7::GetSQL();
    void __fastcall TFrame7::Increment();
    int __fastcall TFrame7::GetCnt();
    void __fastcall TFrame7::CreatePrintRec(int max);
    void __fastcall TFrame7::AlterPrintRec(int index);
    bool __fastcall TFrame7::GetPrintRec(int index);
};

//---------------------------------------------------------------------------
extern PACKAGE TFrame7 *Frame7;//---------------------------------------------------------------------------

#endif
