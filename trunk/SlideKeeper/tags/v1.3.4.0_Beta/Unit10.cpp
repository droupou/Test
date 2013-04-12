//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "sqlConnection.h"
#include "Unit10.h"#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TAddMatFrm *AddMatFrm;
//---------------------------------------------------------------------------
__fastcall TAddMatFrm::TAddMatFrm(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::Cancel_btnClick(TObject *Sender){    if(Sender == NULL)
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::FormCreate(TObject *Sender){    if(Sender == NULL)
        return;
    // TODO:  Remove sizing data.
    /*
    Height = (OK_btn->Height * 1.75)
        + (Material_txt->Height * 1.75);
    Width = 214;
    /*  */
}

//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::OK_btnClick(TObject *Sender){    MYSQL_RES *result;
    sqlConnection *conn = new sqlConnection();

    String sql, sql2;

    if(Sender == NULL)
        return;

    sql = "SELECT * FROM vrl.tb_Materials WHERE tb_MaterialDesc LIKE '";
    sql = sql + SQLParse(Material_txt->Text) + "'";

    result = conn->query(sql);    if(result != NULL){        if(mysql_fetch_row(result)){
            // Material Exists
            MessageDlg( "This material already exists in the database." ,
               mtError,TMsgDlgButtons() << mbOK,0);
        }
        else{
            sql = "INSERT INTO vrl.tb_materials Set tb_MaterialDesc = '";
            sql = sql + SQLParse(Material_txt->Text) + "'";
            conn->execute(sql);
        }
    }

    Material_txt->Text = "";
    delete(conn);
}

//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::FormClose(TObject *Sender,    TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
