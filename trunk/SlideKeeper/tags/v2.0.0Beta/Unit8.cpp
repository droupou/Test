//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "sqlConnection.h"#include "Unit8.h"

#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TNewUserFrm *NewUserFrm;
//---------------------------------------------------------------------------
__fastcall TNewUserFrm::TNewUserFrm(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::Cancel_btnClick(TObject *Sender){    this->DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::OK_btnClick(TObject *Sender){    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, sql2;
    // Initialize connection framwork
    // First build a query to check for the name to be sure it doesn't exist.    sql = "SELECT * FROM vrl.tb_employees WHERE tb_FirstName LIKE '";
    sql = sql + SQLParse(First_txt->Text) + "' AND tb_LastName LIKE '";
    sql = sql + SQLParse(Last_txt->Text) + "'";

    result = conn->query(sql);
    if(row = mysql_fetch_row(result)){        // Name Exists
    }
    else{
        sql = "INSERT INTO vrl.tb_employees set tb_FirstName = '";
        sql = sql + SQLParse(First_txt->Text) + "' , tb_LastName = '";
        sql = sql + SQLParse(Last_txt->Text) + "'";

        conn->execute(sql);
    }

    this->First_txt->Text = "";    this->Last_txt->Text = "";    delete(conn);
}
//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::FormCreate(TObject *Sender){    this->Height = (this->OK_btn->Height * 1.75) + (this->First_txt->Height * 1.75) + (this->Last_txt->Height * 1.75);
    this->Width = 199;
}

//---------------------------------------------------------------------------
void __fastcall TNewUserFrm::Onclose(TObject *Sender, TCloseAction &Action){
    this->DestroyWnd();
}
//---------------------------------------------------------------------------

