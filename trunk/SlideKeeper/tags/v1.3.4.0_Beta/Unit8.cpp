//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "sqlConnection.h"

#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)

TNewUserFrm *NewUserFrm;
//---------------------------------------------------------------------------
__fastcall TNewUserFrm::TNewUserFrm(TComponent* Owner)
    ;
}
//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::Cancel_btnClick(TObject *Sender){
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::OK_btnClick(TObject *Sender){
    MYSQL_RES *result;

    String sql, sql2;

    if(Sender == NULL)
        return;

    // Initialize connection framwork
    // First build a query to check for the name to be sure it doesn't exist.
    sql = sql + SQLParse(First_txt->Text) + "' AND tb_LastName LIKE '";
    sql = sql + SQLParse(Last_txt->Text) + "'";

    result = conn->query(sql);
    if(!(mysql_fetch_row(result))){
        sql = "INSERT INTO vrl.tb_employees set tb_FirstName = '";
        sql = sql + SQLParse(First_txt->Text) + "' , tb_LastName = '";
        sql = sql + SQLParse(Last_txt->Text) + "'";

        conn->execute(sql);
    }

    First_txt->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::FormCreate(TObject *Sender){
        return;
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::Onclose(TObject *Sender, TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------
