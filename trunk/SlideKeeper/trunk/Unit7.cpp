//---------------------------------------------------------------------------#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrame7 *Frame7;
String sql;
bool *printrec;
int LocCnt;

//---------------------------------------------------------------------------__fastcall TFrame7::TFrame7(TComponent* Owner)
        : TFrame(Owner){
    ;
}
//---------------------------------------------------------------------------void __fastcall TFrame7::AddLine(String CB, String LB){

    TCheckBox *theBox;    TLabel *theLabel;
    int i;
    char labelName[10];

    for(i = 0; i < 20; i++){        sprintf(labelName, "Label%d", i);
        theLabel = static_cast<TLabel*>(FindComponent(labelName));
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
            Increment();
        }
    }
}

//---------------------------------------------------------------------------void __fastcall TFrame7::SetSQL(String nstr){
    sql = nstr;
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::ResetCnt(){    LocCnt = 0;

    if (printrec != NULL){        for(int c = 0; printrec[c] != NULL; c++){
            printrec[c] = false;
        }
    }
}

//---------------------------------------------------------------------------
String __fastcall TFrame7::GetSQL(){    return sql;
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::Increment(){    LocCnt++;
}

//---------------------------------------------------------------------------
int __fastcall TFrame7::GetCnt(){    return LocCnt;
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::CreatePrintRec(int max){    printrec = new bool[max];
}

//---------------------------------------------------------------------------
void __fastcall TFrame7::AlterPrintRec(int index){    printrec[index] = !printrec[index];
}

//---------------------------------------------------------------------------

