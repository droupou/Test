//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "sqlConnection.h"
#include "Unit10.h"
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)

TAddMatFrm *AddMatFrm;
//---------------------------------------------------------------------------
__fastcall TAddMatFrm::TAddMatFrm(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::Cancel_btnClick(TObject *Sender){
}

//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::FormCreate(TObject *Sender){
        + (this->Material_txt->Height * 1.75);
    this->Width = 214;
}

//---------------------------------------------------------------------------
void __fastcall TAddMatFrm::OK_btnClick(TObject *Sender){
    MYSQL_ROW row;
    sqlConnection *conn = new sqlConnection();

    String sql, sql2;
    sql = "SELECT * FROM vrl.tb_Materials WHERE tb_MaterialDesc LIKE '";
    sql = sql + SQLParse(Material_txt->Text) + "'";

    result = conn->query(sql);
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
void __fastcall TAddMatFrm::FormClose(TObject *Sender,
    this->DestroyWnd();
}

//---------------------------------------------------------------------------