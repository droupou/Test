//---------------------------------------------------------------------------
#ifndef Unit8H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TNewUserFrm : public TForm{
__published:	// IDE-managed Components
        TLabel *Label2;
        TEdit *First_txt;
        TEdit *Last_txt;
        TButton *OK_btn;
        TButton *Cancel_btn;

        void __fastcall Cancel_btnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Onclose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TNewUserFrm(TComponent* Owner);

//---------------------------------------------------------------------------
extern PACKAGE TNewUserFrm *NewUserFrm;
//---------------------------------------------------------------------------
#endif