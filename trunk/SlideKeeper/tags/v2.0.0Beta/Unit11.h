//---------------------------------------------------------------------------#ifndef Unit11H
#define Unit11H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit13.h"

//---------------------------------------------------------------------------
class TPrintview_frm : public TForm{__published:	// IDE-managed Components

    TFrame13 *Frame131;
    void __fastcall OnClose(TObject *Sender, TCloseAction &Action);    void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
    __fastcall TPrintview_frm(TComponent* Owner);};
//---------------------------------------------------------------------------
extern PACKAGE TPrintview_frm *Printview_frm;
//---------------------------------------------------------------------------
#endif
