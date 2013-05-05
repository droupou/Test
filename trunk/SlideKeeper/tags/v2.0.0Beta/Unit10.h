//---------------------------------------------------------------------------
#ifndef Unit10H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TAddMatFrm : public TForm{

    TLabel *Label1;
    TButton *OK_btn;
    TButton *Cancel_btn;

    void __fastcall Cancel_btnClick(TObject *Sender);
    void __fastcall OK_btnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
    __fastcall TAddMatFrm(TComponent* Owner);
//---------------------------------------------------------------------------
extern PACKAGE TAddMatFrm *AddMatFrm;
//---------------------------------------------------------------------------
#endif