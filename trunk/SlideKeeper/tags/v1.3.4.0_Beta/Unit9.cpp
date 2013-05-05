//---------------------------------------------------------------------------
#include <vcl.h>

#include "Unit9.h"

#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)

TAddPeriodFrm *AddPeriodFrm;
//---------------------------------------------------------------------------
__fastcall TAddPeriodFrm::TAddPeriodFrm(TComponent* Owner)
    ;
}
//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::Cancel_btnClick(TObject *Sender){
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::FormCreate(TObject *Sender){
        return;
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::OK_btnClick(TObject *Sender){
    MYSQL_RES *result;

    String sql, sql2;


    sql = "SELECT * FROM vrl.tb_period WHERE tb_PDateDesc LIKE '";

    result = conn->query(sql);

    if(!(mysql_fetch_row(result))){
        sql = "INSERT INTO vrl.tb_period Set tb_PDateDesc = '";
        sql = sql + SQLParse(Date_txt->Text) + "'";
        conn->execute(sql);
    }

    Date_txt->Text = "";
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::FormClose(TObject *Sender,
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------