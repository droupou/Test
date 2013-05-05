//---------------------------------------------------------------------------

#ifndef EditMaterialH
#define EditMaterialH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TEditMaterialFrm : public TForm
{
__published:	// IDE-managed Components
        TButton *ok_btn;
        TButton *Cancel_btn;
        TComboBox *Material_drp;
        TEdit *NewMaterial_txt;
        void __fastcall Cancel_btnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Material_drpChange(TObject *Sender);
        void __fastcall OnKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ok_btnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    bool UpdateDrop();
public:		// User declarations
        __fastcall TEditMaterialFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditMaterialFrm *EditMaterialFrm;
//---------------------------------------------------------------------------
#endif
