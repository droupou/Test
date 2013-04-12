//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditUser.h"
#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include <string.h>
#include "sqlConnection.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditUserFrm *EditUserFrm;
//---------------------------------------------------------------------------
__fastcall TEditUserFrm::TEditUserFrm(TComponent* Owner)
        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TEditUserFrm::FormCreate(TObject *Sender){
    if(Sender == NULL)
        return;

    ok_btn->Enabled = false;
    UpdateDrop();

    Show();
}
//---------------------------------------------------------------------------

bool TEditUserFrm::UpdateDrop(){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, name;

    Name_drp->Clear();
    
    sql = "SELECT * FROM tb_employees ORDER BY tb_FirstName";
    result = conn->query(sql);
    if(result != NULL){
        row = mysql_fetch_row(result);

        while(row){            name = row[1];
            name = name + " " + row[2];
            Name_drp->AddItem(name, NULL);
            row = mysql_fetch_row(result);
        }
        Name_drp->Text = "--Select User to Edit --";  
        FirstName_txt->Text = "";
        LastName_txt->Text = "";
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

void __fastcall TEditUserFrm::Cancel_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::Name_drpChange(TObject *Sender){
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String sql, name;

    if(Sender == NULL)
        return;

    if((Name_drp->Text != "--Select User to Edit --") && (Name_drp->Text != "")){
        ok_btn->Enabled = true;
        //--------------------------------------------------------
        //  Insert data into drop down.                         //
        //--------------------------------------------------------
        sql = "Select * from tb_employees WHERE concat(tb_FirstName, ' ', ";
        sql = sql + "tb_LastName) = '" + SQLParse(Name_drp->Text) + "'";
        result = conn->query(sql);
        if(result != NULL){
            row = mysql_fetch_row(result);
            if(row){
                FirstName_txt->Text = row[1];
                LastName_txt->Text = row[2];
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
        FirstName_txt->Text = "";
        LastName_txt->Text = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::OnKeyUp(TObject *Sender, WORD &Key,
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
    Name_drpChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::ok_btnClick(TObject *Sender){
    sqlConnection *conn = new sqlConnection();

    String sql, name;

    if(Sender == NULL)
        return;

    sql = "UPDATE tb_employees set tb_FirstName = '" + FirstName_txt->Text;
    sql = sql + "', tb_LastName =  '" + LastName_txt->Text +
        "' WHERE concat(tb_FirstName, ' ', tb_LastName) = '" + Name_drp->Text +
        "'";

    if(!conn->execute(sql)){
        // Error message.
        String err = "Update aborted.  If you continue to get this message, ";
        err = err + " please contact your system administrator.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
    }
    UpdateDrop();
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::FirstName_txtChange(TObject *Sender){
   if(Sender == NULL)
        return;
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::LastName_txtChange(TObject *Sender){
   if(Sender == NULL)
        return;
}
//---------------------------------------------------------------------------

void __fastcall TEditUserFrm::FormClose(TObject *Sender,
      TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

