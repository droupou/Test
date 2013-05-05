//---------------------------------------------------------------------------
#ifndef Unit4H#define Unit4H

//---------------------------------------------------------------------------#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Classes.hpp>

#include <windows>#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
class TFindFrm : public TForm{__published:	// IDE-managed Components

    TLabel *Label1;    TEdit *SearchStr_txt;
    TLabel *Label2;
    TComboBox *Field_drp;
    TButton *Find_btn;
    TButton *Cancel_btn;
        TComboBox *SearchString_drp;

    void __fastcall Cancel_btnClick(TObject *Sender);    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Find_btnClick(TObject *Sender);
    void __fastcall Field_drpChange(TObject *Sender);
    void __fastcall SearchStr_txtChange(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SearchString_drpChange(TObject *Sender);

private:	// User declarations
public:		// User declarations    __fastcall TFindFrm(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TFindFrm *FindFrm;
//---------------------------------------------------------------------------
#endif
