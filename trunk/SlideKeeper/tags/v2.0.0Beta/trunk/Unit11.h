//---------------------------------------------------------------------------
#define Unit11H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Unit13.h"

//---------------------------------------------------------------------------
class TPrintview_frm : public TForm{

    TFrame13 *Frame131;
    void __fastcall OnClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
    __fastcall TPrintview_frm(TComponent* Owner);
//---------------------------------------------------------------------------
extern PACKAGE TPrintview_frm *Printview_frm;
//---------------------------------------------------------------------------
#endif