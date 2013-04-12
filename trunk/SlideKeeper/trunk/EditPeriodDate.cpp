//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditPeriodDate.h"  
#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>
#include "sqlConnection.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditPDateFrm *EditPDateFrm;
//---------------------------------------------------------------------------
__fastcall TEditPDateFrm::TEditPDateFrm(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TEditPDateFrm::FormCreate(TObject *Sender){
    if(Sender == NULL)
        return;

    ok_btn->Enabled = false;
    UpdateDrop();

    Show();
}
//---------------------------------------------------------------------------

bool TEditPDateFrm::UpdateDrop(){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql;

    PDate_drp->Clear();

    sql = "SELECT * FROM tb_period ORDER BY tb_PDateDesc";
    result = conn->query(sql);
    if(result != NULL){
        row = mysql_fetch_row(result);

        while(row){            PDate_drp->AddItem(row[1], NULL);
            row = mysql_fetch_row(result);
        }
        PDate_drp->Text = "-- Select Period Date --";
        NewPDate_txt->Text = "";
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
void __fastcall TEditPDateFrm::Cancel_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------
void __fastcall TEditPDateFrm::PDate_drpChange(TObject *Sender){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, name;

    if(Sender == NULL)
        return;

    if((PDate_drp->Text != "-- Select Period Date --")
      && (PDate_drp->Text != "")){
      
        ok_btn->Enabled = true;
        //-------------------------------------------------------
        //  Insert data into dropdown.
        //-------------------------------------------------------
        sql = "Select * from tb_period WHERE tb_PDateDesc = '";
        sql = sql  + SQLParse(PDate_drp->Text) + "'";
        result = conn->query(sql);
        if(result != NULL){
            row = mysql_fetch_row(result);
            if(row){
                NewPDate_txt->Text = row[1];
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
        NewPDate_txt->Text = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TEditPDateFrm::OnKeyUp(TObject *Sender, WORD &Key,
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
    PDate_drpChange(this);
}
//---------------------------------------------------------------------------
void __fastcall TEditPDateFrm::ok_btnClick(TObject *Sender){
    sqlConnection *conn = new sqlConnection();

    String sql, name;

    if(Sender == NULL)
        return;

    sql = "UPDATE tb_period SET tb_PDateDesc = '" + NewPDate_txt->Text;
    sql = sql + "' WHERE tb_PDateDesc = '" + PDate_drp->Text + "'";

    if(!conn->execute(sql)){
        // Error message.
        String err = "Update aborted.  If you continue to get this message, ";
        err = err + " please contact your system administrator.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
    }
    UpdateDrop();
}
//---------------------------------------------------------------------------
void __fastcall TEditPDateFrm::FormClose(TObject *Sender,
      TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

