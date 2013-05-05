//---------------------------------------------------------------------------
#ifndef Unit10H#define Unit10H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TAddMatFrm : public TForm{__published:	// IDE-managed Components

    TLabel *Label1;    TEdit *Material_txt;
    TButton *OK_btn;
    TButton *Cancel_btn;

    void __fastcall Cancel_btnClick(TObject *Sender);    void __fastcall FormCreate(TObject *Sender);
    void __fastcall OK_btnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
    __fastcall TAddMatFrm(TComponent* Owner);};
//---------------------------------------------------------------------------
extern PACKAGE TAddMatFrm *AddMatFrm;
//---------------------------------------------------------------------------
#endif
