//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit6.h"#include "Unit11.h"
#include "Unit12.h"
#include "label.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma link "Unit7"
#pragma resource "*.dfm"

TOutputFrm *OutputFrm;
//---------------------------------------------------------------------------
__fastcall TOutputFrm::TOutputFrm(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Cancel_btnClick(TObject *Sender){    if(Sender != NULL)
        DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::FormCreate(TObject *Sender){    update = true;
    if(Sender == NULL)
        return;
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::OnResize(TObject *Sender){    if(Sender == NULL)        return;}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::FormClose(TObject *Sender,      TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::FormClose(){    DestroyWnd();
}
//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Next_btnClick(TObject *Sender){    if(Sender == NULL)        return;    TLabel *lbl;
    TCheckBox *CB;
    AnsiString lblS, cbs;
    int count, lft, hgh;

    update = false;

    number = 0;
    Previous_btn->Enabled = true;    Next_btn->Enabled = true;

    count = 1;    hgh = 5;    Frame71->Label211->Top = 5;    Frame71->Label212->Top = 5;    Frame71->Label213->Top = 5;    hgh += 15;

    if(clabel != NULL)
        tHEAD = clabel;

    for(int i = 1; ((i < 20) && (clabel != NULL)); i++){
        number++;
        cbs = "CheckBox";
        cbs = cbs + i;
        CB = dynamic_cast <TCheckBox*>(Frame71->FindComponent(cbs));
        CB->Caption = clabel->header;
        CB->Checked = clabel->Is_select;

        CB->Visible = true;
        CB->Top = hgh;

        lblS = "Label";        lblS = lblS + count;

        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));        lbl->Visible = true;
        lbl->Top = hgh;
        lbl->Caption = clabel->title;

        lblS = "Label";        count++;
        lblS = lblS + count;
        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));
        lbl->Visible = true;
        lbl->Top = hgh;

        lbl->Caption = clabel->title2;
        count += 9;
        hgh += 15;
        if(clabel->next == NULL){
            Next_btn->Enabled = false;
            i++;
            while(i < 20){
                cbs = "CheckBox";
                cbs = cbs + i;
                CB = dynamic_cast <TCheckBox*>(Frame71->FindComponent(cbs));
                CB->Checked = false;
                CB->Visible = false;
                CB->Top = hgh;

                lblS = "Label";                lblS = lblS + count;

                lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));                lbl->Visible = false;
                lbl->Top = hgh;

                lblS = "Label";                count++;
                lblS = lblS + count;
                lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));
                lbl->Visible = false;
                lbl->Top = hgh;

                count += 9;                hgh += 15;
                i++;
            }

        }
        else{
            clabel = clabel->next;
        }
    }
    update = true;}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Print_btnClick(TObject *Sender){    if(Sender == NULL)        return;    TPrinter *prntr = Printer();
    TRect rect = Rect(10, 10, prntr->PageWidth - 10, prntr->PageHeight - 10);
    int CPH, RPH, C, R;
    label *lblptr;

    lblptr = HEAD;    C = 615;
    R = 145;

    Application->CreateForm(__classid(TPrintview_frm), &Printview_frm);
    Printview_frm->Show();    Printview_frm->Width = 315;
    Printview_frm->Height = 157;

    Printview_frm->Frame131->Height = 157;    Printview_frm->Frame131->Width = 315;

    prntr->BeginDoc();    prntr->Canvas->FillRect(rect);
    prntr->Canvas->Brush->Color = clBlack;
    RPH = 130;

    while(RPH <= (200 * 20)){        CPH = 60;

        while((lblptr != NULL) && (!lblptr->Is_select))            lblptr = lblptr->next;

        if(lblptr != NULL){
            // Row
            Printview_frm->Frame131->Label1->Caption = lblptr->header;
            Printview_frm->Frame131->Label2->Caption = lblptr->Artist;
            Printview_frm->Frame131->Label3->Caption = lblptr->title;
            Printview_frm->Frame131->Label4->Caption = lblptr->PDate;
            Printview_frm->PaintTo(prntr->Handle, CPH, RPH);
            CPH += C;

            lblptr = lblptr->next;            while((lblptr != NULL) && (!lblptr->Is_select))
                lblptr = lblptr->next;

            if(lblptr != NULL){                Printview_frm->Frame131->Label1->Caption = lblptr->header;
                Printview_frm->Frame131->Label2->Caption = lblptr->Artist;
                Printview_frm->Frame131->Label3->Caption = lblptr->title;
                Printview_frm->Frame131->Label4->Caption = lblptr->PDate;

                Printview_frm->PaintTo(prntr->Handle, CPH, RPH);                CPH += C;

                lblptr = lblptr->next;                while((lblptr != NULL) && (!lblptr->Is_select))
                    lblptr = lblptr->next;

                if(lblptr != NULL){                    Printview_frm->Frame131->Label1->Caption = lblptr->header;
                    Printview_frm->Frame131->Label2->Caption = lblptr->Artist;
                    Printview_frm->Frame131->Label3->Caption = lblptr->title;
                    Printview_frm->Frame131->Label4->Caption = lblptr->PDate;

                    Printview_frm->PaintTo(prntr->Handle, CPH, RPH);                    CPH += C;

                    lblptr = lblptr->next;                    while((lblptr != NULL) && (!lblptr->Is_select))
                        lblptr = lblptr->next;

                    if(lblptr != NULL){                        Printview_frm->Frame131->Label1->Caption = lblptr->header;
                        Printview_frm->Frame131->Label2->Caption = lblptr->Artist;
                        Printview_frm->Frame131->Label3->Caption = lblptr->title;
                        Printview_frm->Frame131->Label4->Caption = lblptr->PDate;

                        Printview_frm->PaintTo(prntr->Handle, CPH, RPH);                    }
                    lblptr = lblptr->next;
                }
            }
        }
        RPH += R;
    }
    prntr->EndDoc();
    Printview_frm->Close();
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Populate(){    TLabel *lbl;
    TCheckBox *CB;
    AnsiString lblS, cbs;
    int count, lft, hgh;
    bool cont = true;

    number = 0;
    clabel = tHEAD = HEAD;    Previous_btn->Enabled = false;
    Next_btn->Enabled = true;

    count = 1;    hgh = 5;    Frame71->Label211->Top = 5;    Frame71->Label212->Top = 5;    Frame71->Label213->Top = 5;    hgh += 15;
    for(int i = 1; ((i < 20) && (clabel != NULL) && cont); i++){
        number++;
        cbs = "CheckBox";
        cbs = cbs + i;
        CB = dynamic_cast <TCheckBox*>(Frame71->FindComponent(cbs));
        CB->Caption = clabel->header;

        CB->Checked = clabel->Is_select;        CB->Visible = true;
        CB->Top = hgh;

        lblS = "Label";        lblS = lblS + count;

        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));        lbl->Visible = true;
        lbl->Top = hgh;
        lbl->Caption = clabel->title;

        lblS = "Label";        count++;
        lblS = lblS + count;
        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));
        lbl->Visible = true;
        lbl->Top = hgh;

        lbl->Caption = clabel->title2;
        count += 9;
        hgh += 15;
        if(clabel->next != NULL){
            clabel = clabel->next;
        }
        else {
            cont = false;
        }
        //--> Test line:
        // this->Repaint();
    }
    if(clabel->next == NULL)
        Next_btn->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::AddLabel(String header, String title, String title2,        String Material, String PDate, String EDate, String Enter, bool Is_Approved,
        String Approve, String Artist, String Dimension, String Pic){

    if(clabel == NULL){
        HEAD = new label;
        HEAD->prev = NULL;
        clabel = HEAD;
    }
    else{
        clabel->next = new label;
        clabel->next->prev = clabel;
        clabel = clabel->next;
    }
    clabel->header = header;
    clabel->title = title;
    clabel->title2 = title2;
    clabel->Material = Material;
    clabel->PDate = PDate;
    clabel->EDate = EDate;
    clabel->Enter = Enter;
    clabel->Is_Approved = Is_Approved;
    clabel->Approve = Approve;
    clabel->Artist = Artist;
    clabel->Is_select = false;
    clabel->next = NULL;
    clabel->Dimension = Dimension;
    clabel->Pic = Pic;
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Previous_btnClick(TObject *Sender){    if(Sender == NULL)        return;    TLabel *lbl;
    TCheckBox *CB;
    AnsiString lblS, cbs;
    int count, lft, hgh, max;

    update = false;

    Previous_btn->Enabled = true;    Next_btn->Enabled = true;

    if(clabel == NULL){        clabel = HEAD;        while(clabel->next != NULL)            clabel = clabel->next;    }    max = 20 + number;    for(int i = 1; i < max; i++){        if(clabel->prev != NULL){
            clabel = clabel->prev;
        }
        else{
            Previous_btn->Enabled = false;
        }
    }


    number = 0;

    count = 1;    hgh = 5;    Frame71->Label211->Top = 5;    Frame71->Label212->Top = 5;    Frame71->Label213->Top = 5;    hgh += 15;
    for(int i = 1; (i < 20); i++){
        number++;
        cbs = "CheckBox";
        cbs = cbs + i;
        CB = dynamic_cast <TCheckBox*>(Frame71->FindComponent(cbs));
        CB->Caption = clabel->header;
        CB->Checked = false;

        if(clabel->Is_select)
            CB->Checked = true;

        CB->Checked = clabel->Is_select;        CB->Visible = true;
        CB->Top = hgh;

        lblS = "Label";        lblS = lblS + count;

        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));        lbl->Visible = true;
        lbl->Top = hgh;
        lbl->Caption = clabel->title;

        lblS = "Label";        count++;
        lblS = lblS + count;
        lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));
        lbl->Visible = true;
        lbl->Top = hgh;

        lbl->Caption = clabel->title2;
        count += 9;
        hgh += 15;
        clabel = clabel->next;
        if(clabel == NULL){
            while(i < 20){
                cbs = "CheckBox";
                cbs = cbs + i;
                CB = dynamic_cast <TCheckBox*>(Frame71->FindComponent(cbs));
                CB->Checked = false;
                CB->Visible = false;
                CB->Top = hgh;

                lblS = "Label";                lblS = lblS + count;

                lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));                lbl->Visible = false;
                lbl->Top = hgh;

                lblS = "Label";                count++;
                lblS = lblS + count;
                lbl = dynamic_cast <TLabel*>(Frame71->FindComponent(lblS));
                lbl->Visible = false;
                lbl->Top = hgh;

                count += 9;                hgh += 15;
                i++;
            }

        }
    }
    if (clabel == NULL){        Next_btn->Enabled = false;
    }
    update = true;
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox1Click(TObject *Sender){    if(Sender == NULL)        return;    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox2Click(TObject *Sender){    if(Sender == NULL)        return;    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 1) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox3Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 2) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox4Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 3) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox5Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 4) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox6Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 5) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox7Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 6) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox8Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 7) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox9Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 8) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox10Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 9) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox11Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 10) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox12Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 11) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox13Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 12) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox14Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 13) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox15Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 14) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox16Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 15) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox17Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 16) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox18Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 17) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Frame71CheckBox19Click(TObject *Sender){    if(Sender == NULL)
        return;

    if(update){
        for(; ((clabel != tHEAD) && (clabel->prev != NULL)
          && (clabel != NULL) && (number >= 0)); number--){
            clabel = clabel->prev;
        }

        for(int c = 0; ((c < 18) && (clabel->next != NULL)); c++){
            number++;
            clabel = clabel->next;
        }

        clabel->Is_select = !clabel->Is_select;

        for(; ((number < 20) && (clabel->next != NULL)); number++){
            clabel = clabel->next;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::Details_btnClick(TObject *Sender){    if(Sender == NULL)
        return;

    Application->CreateForm(__classid(TUpdForm), &UpdForm);

    UpdForm->AssignHEAD(HEAD);
    UpdForm->ResetPres();
    UpdForm->GetList();
    UpdForm->Populate();
    UpdForm->Show();
    if(UpdForm != NULL)
        DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TOutputFrm::OnMouseUp(System::TObject*, Controls::TMouseButton,
    System::Set<Classes::Classes__1,0,6>, int, int){
    ;
}
void __fastcall TOutputFrm::OnClose(TObject *Sender, TCloseAction &Action){
    DestroyWnd();
}
//---------------------------------------------------------------------------

