//---------------------------------------------------------------------------
#include <vcl.h>#include "sqlConnection.h"

#pragma hdrstop

#include "Unit4.h"#include "Unit6.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TFindFrm *FindFrm;sqlConnection *conn = NULL;
//---------------------------------------------------------------------------
__fastcall TFindFrm::TFindFrm(TComponent* Owner)        : TForm(Owner){
    ;
}
//---------------------------------------------------------------------------
void __fastcall TFindFrm::Cancel_btnClick(TObject *Sender){    if(Sender == NULL)
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::FormCreate(TObject *Sender){    if(Sender == NULL)
        return;

    SearchString_drp->Visible = false;
    
    Field_drp->AddItem(("Artist/Site"),this);
    Field_drp->AddItem(("Title"), this);
    Field_drp->AddItem(("Period Date of the Subject"), this);
    Field_drp->AddItem(("Materials"), this);
    Field_drp->AddItem(("Dimensions"), this);
    Field_drp->AddItem(("Date Entered"), this);
    Field_drp->AddItem(("Entered By"), this);
    Field_drp->AddItem(("All not yet approved"), this);



    Width = 315;    Height = 126;
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::Find_btnClick(TObject *Sender){    String sql, t1, t2, err, fname, lname;

    conn = new sqlConnection();

    MYSQL_RES *result;
    MYSQL_ROW row;

    if(Sender == NULL)        return;

    if ((SearchStr_txt->Text != "") ||      (Field_drp->Text == "All not yet approved")||      (SearchString_drp->Text != "")){        Application->CreateForm(__classid(TOutputFrm), &OutputFrm);

        sql = "SELECT tb_Header, tb_Title, tb_Title2, tb_materialDesc, ";
        sql = sql + "tb_PDateDesc, DATE_FORMAT(tb_Edate,'%m/%d/%Y %h:%i:%s %p') as "
          + "tb_EDate, concat(emp.tb_FirstName , ' ' , emp.tb_LastName) as "
          + "EnteredBy, tb_IsApproved, concat(emp2.tb_FirstName, ' ' , "
          + "emp2.tb_LastName) as ApprovedBy, tb_Artist, tb_Dimensions, tb_Date, Picture "
          + "FROM tb_slides join tb_Period on tb_slides.tb_PDateKey = "
          + "tb_Period.tb_PDateKey join tb_materials on tb_slides.tb_MaterialKey "
          + "= tb_materials.tb_MaterialKey join tb_employees emp on "
          + "tb_slides.tb_EmpKey = emp.tb_EmpKey join tb_employees emp2 on "
          + "tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";

        if(Field_drp->ItemIndex == 0){            // Artist/Site
            sql = sql + " WHERE tb_Artist LIKE '";
            sql = sql + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 1){
            // Title
            sql = sql + " WHERE tb_Title LIKE '" + SQLParse(SearchStr_txt->Text)
                + "' OR tb_Title2 LIKE '";
            sql = sql + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 2){
            // Period Date of Material
            sql = sql + " WHERE tb_PDateDesc LIKE '";
            sql = sql + SQLParse(SearchString_drp->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 3){
            // Materials
            sql = sql + " WHERE tb_MaterialDesc LIKE '"
                + SQLParse(SearchString_drp->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 4){
            // Dimensions
            sql = sql + " WHERE tb_Dimensions LIKE '"
                + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 5){
            // Date Entered
            sql = sql + " WHERE date_format(tb_EDate, '%m/%d/%Y') LIKE '"
                + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 6){
            // Entered By
            sql = sql + " WHERE concat(emp.tb_FirstName , ' ' , emp.tb_LastName) = '";
            sql = sql + SearchString_drp->Text + "'";
        }
        else if(Field_drp->ItemIndex == 7){
            // Not yet approved
            sql = sql + " WHERE tb_IsApproved = 0";
        }

        sql  = sql + " Order By tb_Title";

        result = conn->query(sql);
        if(result != NULL){
            row = mysql_fetch_row(result);

            if(row != NULL){                while(row){
                    OutputFrm->AddLabel(row[0],row[1],row[2],row[3],row[4],
                        row[5],row[6],row[7],row[8],row[9],row[10], row[11], row[12]);
                    row = mysql_fetch_row(result);
                }
            }
            else{
                OutputFrm->FormClose();
                err = "No data available.";
                MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
                return;
            }
        }
        OutputFrm->Populate();
    }
    else{
        err = "Must enter search criteria.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        exit(1);
    }

    delete(conn);
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::Field_drpChange(TObject *Sender){    String err;    conn = new sqlConnection();

    MYSQL_RES *result;
    MYSQL_ROW row;

    if(Sender == NULL)
        return;

    SearchString_drp->Clear();
    SearchStr_txt->Clear();

    if((SearchStr_txt->Text != "") || (Field_drp->Text == "All not yet approved")
      || (SearchString_drp->Text != "")){
        Find_btn->Enabled = true;
    }
    else {
        Find_btn->Enabled = false;
    }

    if(Field_drp->Text == "Period Date of the Subject"){
      result = conn->query("SELECT tb_PDateDesc as Date FROM tb_period") ;
      if(result != NULL){
        row = mysql_fetch_row(result);

        if(row != NULL){          while(row){
            SearchString_drp->AddItem(row[0], this);
            row = mysql_fetch_row(result);
          }
        }
        else{
          OutputFrm->FormClose();
          err = "No data available.";
          MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
      }
      SearchString_drp->Visible = true;
      SearchStr_txt->Visible = false;
    } else if(Field_drp->Text == "Materials"){
      result = conn->query("SELECT tb_MaterialDesc FROM tb_materials") ;
      if(result != NULL){
        row = mysql_fetch_row(result);

        if(row != NULL){          while(row){
            SearchString_drp->AddItem(row[0], this);
            row = mysql_fetch_row(result);
          }
        }
        else{
          OutputFrm->FormClose();
          err = "No data available.";
          MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
      }
      SearchString_drp->Visible = true;
      SearchStr_txt->Visible = false;
    } else if(Field_drp->Text == "Entered By"){
      result = conn->query("SELECT concat(tb_FirstName, ' ', tb_LastName) as Name FROM tb_employees") ;
      if(result != NULL){
        row = mysql_fetch_row(result);

        if(row != NULL){          while(row){
            SearchString_drp->AddItem(row[0], this);
            row = mysql_fetch_row(result);
          }
        }
        else{
          OutputFrm->FormClose();
          err = "No data available.";
          MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
          return;
        }
      }
      SearchString_drp->Visible = true;
      SearchStr_txt->Visible = false;
    } else{
      SearchString_drp->Visible = false;
      SearchStr_txt->Visible = true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::SearchStr_txtChange(TObject *Sender){    if(Sender == NULL)
        return;

    if(((Field_drp->Text != "-- Select Field --") && (SearchStr_txt->Text != ""))
      || (Field_drp->Text == "All not yet approved"))
        Find_btn->Enabled = true;
    else
        Find_btn->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::FormClose(TObject *Sender, TCloseAction &Action){    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}

//---------------------------------------------------------------------------

void __fastcall TFindFrm::SearchString_drpChange(TObject *Sender){
    if(Sender == NULL)
        return;

    if (
          (Field_drp->Text != AnsiString("-- Select Field --")) &&
          (
            (SearchStr_txt->Text != AnsiString("")) ||
            (Field_drp->Text == AnsiString("All not yet approved")) ||
            (SearchString_drp->Text != AnsiString(""))
          )
       )

        Find_btn->Enabled = true;
    else
        Find_btn->Enabled = false;
}
//---------------------------------------------------------------------------

