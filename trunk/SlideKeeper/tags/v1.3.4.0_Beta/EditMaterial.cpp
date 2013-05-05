//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditMaterial.h" 
#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>
#include "sqlConnection.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditMaterialFrm *EditMaterialFrm;
//---------------------------------------------------------------------------
__fastcall TEditMaterialFrm::TEditMaterialFrm(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::Cancel_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::FormCreate(TObject *Sender){
    if(Sender == NULL)
        return;

    ok_btn->Enabled = false;
    UpdateDrop();

    Show();
}
//---------------------------------------------------------------------------

bool TEditMaterialFrm::UpdateDrop(){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql;

    Material_drp->Clear();

    sql = "SELECT * FROM tb_materials ORDER BY tb_MaterialDesc";
    result = conn->query(sql);
    if(result != NULL){
        row = mysql_fetch_row(result);

        while(row){            Material_drp->AddItem(row[1], NULL);
            row = mysql_fetch_row(result);
        }
        Material_drp->Text = "-- Select Material --";
        NewMaterial_txt->Text = "";
    }
    else{
        // error message.
        String err = "No data available.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::Material_drpChange(TObject *Sender){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, name;

    if(Sender == NULL)
        return;

    if((Material_drp->Text != "-- Select Material --") && (Material_drp->Text != "")){
        ok_btn->Enabled = true;
        //--------------------------------------------------------
        //  Insert data into drop down.                         //
        //--------------------------------------------------------
        sql = "Select * from tb_materials WHERE tb_MaterialDesc = '";
        sql = sql + SQLParse(Material_drp->Text) + "'";
        result = conn->query(sql);
        if(result != NULL){
            row = mysql_fetch_row(result);
            if(row){
                NewMaterial_txt->Text = row[1];
            }        }
        else{
            // error message.
            String err = "No data available.";
            MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        }
       //-----------------------------------------------------
    }
    else{
        ok_btn->Enabled = false;
        NewMaterial_txt->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::OnKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift){

    if(Key != 9){
        TComboBox *Send = dynamic_cast <TComboBox*>(Sender);
        int len = Send->Text.Length();

        if(Send->ItemIndex == -1){
            Send->Text = Send->Text.SubString(1, len-1);
            Send->SelStart = len;
        }
    }
    Shift.Clear();
    Material_drpChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::ok_btnClick(TObject *Sender){
    sqlConnection *conn = new sqlConnection();

    String sql, name;

    if(Sender == NULL)
        return;

    sql = "UPDATE tb_materials set tb_MaterialDesc = '";
    sql = sql + NewMaterial_txt->Text + "' WHERE tb_MaterialDesc = '" +
         Material_drp->Text + "'";

    if(!conn->execute(sql)){
        // Error message.
        String err = "Update aborted.  If you continue to get this message, ";
        err = err + " please contact your system administrator.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
    }
    UpdateDrop();
}
//---------------------------------------------------------------------------

void __fastcall TEditMaterialFrm::FormClose(TObject *Sender,
      TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

