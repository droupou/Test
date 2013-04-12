//---------------------------------------------------------------------------

#ifndef EditUserH
#define EditUserH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TEditUserFrm : public TForm
{
__published:	// IDE-managed Components
        TComboBox *Name_drp;
        TEdit *FirstName_txt;
        TEdit *LastName_txt;
        TButton *ok_btn;
        TButton *Cancel_btn;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Cancel_btnClick(TObject *Sender);
        void __fastcall Name_drpChange(TObject *Sender);
        void __fastcall OnKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FirstName_txtChange(TObject *Sender);
        void __fastcall LastName_txtChange(TObject *Sender);
        void __fastcall ok_btnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool UpdateDrop();
public:		// User declarations
        __fastcall TEditUserFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditUserFrm *EditUserFrm;
//---------------------------------------------------------------------------
#endif
