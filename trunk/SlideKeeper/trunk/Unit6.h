//---------------------------------------------------------------------------
#ifndef Unit6H#define Unit6H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "label.h"
#include "Unit7.h"
#include "Unit14.h"
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TOutputFrm : public TForm{
__published:	// IDE-managed Components
    TButton *Print_btn;    TButton *Cancel_btn;
    TButton *Details_btn;
    TButton *Next_btn;
    TButton *Previous_btn;
    TFrame7 *Frame71;
    TPrintDialog *PrintDialog1;

    void __fastcall Cancel_btnClick(TObject *Sender);    void __fastcall FormCreate(TObject *Sender);
    void __fastcall OnResize(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormClose();
    void __fastcall Next_btnClick(TObject *Sender);
    void __fastcall Print_btnClick(TObject *Sender);
    void __fastcall Previous_btnClick(TObject *Sender);
    void __fastcall Frame71CheckBox1Click(TObject *Sender);
    void __fastcall Frame71CheckBox2Click(TObject *Sender);
    void __fastcall Frame71CheckBox3Click(TObject *Sender);
    void __fastcall Frame71CheckBox4Click(TObject *Sender);
    void __fastcall Frame71CheckBox5Click(TObject *Sender);
    void __fastcall Frame71CheckBox6Click(TObject *Sender);
    void __fastcall Frame71CheckBox7Click(TObject *Sender);
    void __fastcall Frame71CheckBox8Click(TObject *Sender);
    void __fastcall Frame71CheckBox9Click(TObject *Sender);
    void __fastcall Frame71CheckBox10Click(TObject *Sender);
    void __fastcall Frame71CheckBox11Click(TObject *Sender);
    void __fastcall Frame71CheckBox12Click(TObject *Sender);
    void __fastcall Frame71CheckBox13Click(TObject *Sender);
    void __fastcall Frame71CheckBox14Click(TObject *Sender);
    void __fastcall Frame71CheckBox15Click(TObject *Sender);
    void __fastcall Frame71CheckBox16Click(TObject *Sender);
    void __fastcall Frame71CheckBox17Click(TObject *Sender);
    void __fastcall Frame71CheckBox18Click(TObject *Sender);
    void __fastcall Frame71CheckBox19Click(TObject *Sender);
    void __fastcall Details_btnClick(TObject *Sender);
    void __fastcall OnMouseUp(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y);
        void __fastcall OnClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
    label *HEAD, *tHEAD, *clabel;    int number;    bool update;public:		// User declarations
    __fastcall TOutputFrm(TComponent* Owner);
    void __fastcall TOutputFrm::AddLabel(String header, String title,
        String title2, String Material, String PDate, String EDate,
        String Enter, bool Is_Approved, String Approve, String Artist,
        String Dimension, String Date, String Pic);
    void __fastcall TOutputFrm::Populate();
};

//---------------------------------------------------------------------------
extern PACKAGE TOutputFrm *OutputFrm;
//---------------------------------------------------------------------------
#endif
