//---------------------------------------------------------------------------
#ifndef Unit13H#define Unit13H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TFrame13 : public TFrame{
__published:	// IDE-managed Components
    TLabel *Label1;    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    void __fastcall FrameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFrame13(TComponent* Owner);};
//---------------------------------------------------------------------------
extern PACKAGE TFrame13 *Frame13;
//---------------------------------------------------------------------------
#endif
