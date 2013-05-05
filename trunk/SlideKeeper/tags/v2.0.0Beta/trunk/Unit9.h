//---------------------------------------------------------------------------
#ifndef Unit9H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TAddPeriodFrm : public TForm{

    TLabel *Label1;
    TEdit *Date_txt;
    TButton *OK_btn;
    TButton *Cancel_btn;

    void __fastcall Cancel_btnClick(TObject *Sender);
    void __fastcall OK_btnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
    __fastcall TAddPeriodFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddPeriodFrm *AddPeriodFrm;
//---------------------------------------------------------------------------
#endif