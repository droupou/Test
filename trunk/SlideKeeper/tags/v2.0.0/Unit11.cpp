//---------------------------------------------------------------------------
#include <vcl.h>
#include "Unit11.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TPrintview_frm *Printview_frm;
//---------------------------------------------------------------------------
__fastcall TPrintview_frm::TPrintview_frm(TComponent* Owner)
    ;
}
//---------------------------------------------------------------------------
void __fastcall TPrintview_frm::OnClose(TObject *Sender,
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TPrintview_frm::FormCreate(TObject *Sender){
}

//---------------------------------------------------------------------------