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
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::OK_btnClick(TObject *Sender){
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, sql2;
    // Initialize connection framwork
    // First build a query to check for the name to be sure it doesn't exist.
    sql = sql + SQLParse(First_txt->Text) + "' AND tb_LastName LIKE '";
    sql = sql + SQLParse(Last_txt->Text) + "'";

    result = conn->query(sql);
    if(row = mysql_fetch_row(result)){
    }
    else{
        sql = "INSERT INTO vrl.tb_employees set tb_FirstName = '";
        sql = sql + SQLParse(First_txt->Text) + "' , tb_LastName = '";
        sql = sql + SQLParse(Last_txt->Text) + "'";

        conn->execute(sql);
    }

    this->First_txt->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::FormCreate(TObject *Sender){
    this->Width = 199;
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::Onclose(TObject *Sender, TCloseAction &Action){
    this->DestroyWnd();
}
//---------------------------------------------------------------------------
