//---------------------------------------------------------------------------
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrame7 *Frame7;
String sql;
bool *printrec;
int LocCnt;

//---------------------------------------------------------------------------
        : TFrame(Owner){
    ;
}
//---------------------------------------------------------------------------

    TCheckBox *theBox;
    int i; //, count;
    char labelName[10];

    for(i = 0; i < 20; i++){
        theLabel = static_cast<TLabel*>(this->FindComponent(labelName));
        if(theLabel){
            if(theLabel->Visible == false){
                theLabel->Visible = true;
                theLabel->Caption = LB;
                sprintf(labelName, "CheckBox%d", i);
                theBox = static_cast<TCheckBox*>(FindComponent(labelName));
                theBox->Visible = true;
                theBox->Caption = CB;
                return;
            }
            this->Increment();
        }
    }
}

//---------------------------------------------------------------------------
    sql = nstr;
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::ResetCnt(){

    if (printrec != NULL){
            printrec[c] = false;
        }
    }
}

//---------------------------------------------------------------------------
String __fastcall TFrame7::GetSQL(){
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::Increment(){
}

//---------------------------------------------------------------------------
int __fastcall TFrame7::GetCnt(){
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::CreatePrintRec(int max){
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::AlterPrintRec(int index){
}

//---------------------------------------------------------------------------
bool __fastcall TFrame7::GetPrintRec(int index){
}
