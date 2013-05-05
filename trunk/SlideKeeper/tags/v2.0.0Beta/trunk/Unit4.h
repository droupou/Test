//---------------------------------------------------------------------------
#ifndef Unit4H

//---------------------------------------------------------------------------
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Classes.hpp>

#include <windows>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
class TFindFrm : public TForm{

        TLabel *Label1;
        TLabel *Label2;
        TComboBox *Field_drp;
        TButton *Find_btn;
        TButton *Cancel_btn;

        void __fastcall Cancel_btnClick(TObject *Sender);
        void __fastcall Find_btnClick(TObject *Sender);
        void __fastcall Field_drpChange(TObject *Sender);
        void __fastcall SearchStr_txtChange(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
};

//---------------------------------------------------------------------------
extern PACKAGE TFindFrm *FindFrm;
//---------------------------------------------------------------------------
#endif