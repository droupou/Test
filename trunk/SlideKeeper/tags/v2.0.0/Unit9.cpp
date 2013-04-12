//---------------------------------------------------------------------------
#include <vcl.h>#pragma hdrstop

#include "Unit9.h"#include "sqlConnection.h"
#include <windows>#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TAddPeriodFrm *AddPeriodFrm;
//---------------------------------------------------------------------------
__fastcall TAddPeriodFrm::TAddPeriodFrm(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::Cancel_btnClick(TObject *Sender){    if(Sender == NULL)
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::FormCreate(TObject *Sender){    if(Sender == NULL)
        return;
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::OK_btnClick(TObject *Sender){    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;

    String sql, sql2;
    if(Sender == NULL)        return;

    sql = "SELECT * FROM vrl.tb_period WHERE tb_PDateDesc LIKE '";    sql = sql + SQLParse(Date_txt->Text) + "'";

    result = conn->query(sql);

    if(!(mysql_fetch_row(result))){
        sql = "INSERT INTO vrl.tb_period Set tb_PDateDesc = '";
        sql = sql + SQLParse(Date_txt->Text) + "'";
        conn->execute(sql);
    }

    Date_txt->Text = "";    delete(conn);
}

//---------------------------------------------------------------------------
void __fastcall TAddPeriodFrm::FormClose(TObject *Sender,      TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
