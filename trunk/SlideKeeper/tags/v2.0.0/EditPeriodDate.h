//---------------------------------------------------------------------------

#ifndef EditPeriodDateH
#define EditPeriodDateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TEditPDateFrm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *PDate_drp;
        TEdit *NewPDate_txt;
        TButton *ok_btn;
        TButton *Cancel_btn;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Cancel_btnClick(TObject *Sender);
        void __fastcall PDate_drpChange(TObject *Sender);
        void __fastcall OnKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ok_btnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool UpdateDrop();
public:		// User declarations
        __fastcall TEditPDateFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditPDateFrm *EditPDateFrm;
//---------------------------------------------------------------------------
#endif
