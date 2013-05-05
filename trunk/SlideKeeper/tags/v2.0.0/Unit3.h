//---------------------------------------------------------------------------
#ifndef Unit3H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TfrmAbout : public TForm{
__published:	// IDE-managed Components
    TImage *Image1;
    TLabel *Product_lbl;
    TLabel *Version_lbl;
    TLabel *Copyright_lbl;
    TLabel *Comment_lbl;

    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
    __fastcall TfrmAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAbout *frmAbout;
//---------------------------------------------------------------------------
#endif