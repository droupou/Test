//---------------------------------------------------------------------------
#include <vcl.h>#include "sqlConnection.h"

#pragma hdrstop

#include "Unit4.h"#include "Unit6.cpp"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TFindFrm *FindFrm;sqlConnection *conn = NULL;
//---------------------------------------------------------------------------
__fastcall TFindFrm::TFindFrm(TComponent* Owner)        : TForm(Owner){
        ;
}
//---------------------------------------------------------------------------
void __fastcall TFindFrm::Cancel_btnClick(TObject *Sender){    this->DestroyWnd();
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::FormCreate(TObject *Sender){    this->Field_drp->AddItem(("Artist/Site"),this);
    this->Field_drp->AddItem(("Title"), this);
    this->Field_drp->AddItem(("Period Date of Material"), this);
    this->Field_drp->AddItem(("Materials"), this);
    this->Field_drp->AddItem(("Dimensions"), this);
    this->Field_drp->AddItem(("Date Entered"), this);
    this->Field_drp->AddItem(("Entered By"), this);
    this->Field_drp->AddItem(("All not yet approved"), this);

    this->Width = 315;    this->Height = 126;
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::Find_btnClick(TObject *Sender){    String sql, t1, t2, err, fname, lname;

    conn = new sqlConnection();
    char *char_ptr;    int index;

    MYSQL_RES *result;
    MYSQL_ROW row;
    // TMsgBox *Error;

    if ((SearchStr_txt->Text != "") || (Field_drp->Text == "All not yet approved")){        Application->CreateForm(__classid(TOutputFrm), &OutputFrm);

        sql = "SELECT tb_Header, tb_Title, tb_Title2, tb_materialDesc, ";
        sql = sql + "tb_PDateDesc, tb_Edate, ";
        sql = sql + "concat(emp.tb_FirstName , ' ' , emp.tb_LastName) as EnteredBy, ";
        sql = sql + "tb_IsApproved, ";
        sql = sql + "concat(emp2.tb_FirstName, ' ' , emp2.tb_LastName) as ApprovedBy, ";
        sql = sql + "tb_Artist, tb_Dimensions, Picture ";

        if(Field_drp->ItemIndex == 0){            // Artist/Site
            sql = sql + " FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey WHERE tb_Artist LIKE '";
            sql = sql + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 1){
            // Title
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE tb_Title LIKE '" + SQLParse(SearchStr_txt->Text)
                + "' OR tb_Title2 LIKE '";
            sql = sql + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 2){
            // Period Date of Material
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE tb_PDateDesc LIKE '";
            sql = sql + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 3){
            // Materials
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE tb_MaterialDesc LIKE '"
                + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 4){
            // Dimensions
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE tb_Dimensions LIKE '"
                + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 5){
            // Date Entered
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE date_format(tb_EDate, '%m/%d/%Y') LIKE '"
                + SQLParse(SearchStr_txt->Text) + "'";
        }
        else if(Field_drp->ItemIndex == 6){
            // Entered By
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE concat(emp.tb_FirstName , ' ' , emp.tb_LastName) = '";
            sql = sql + SearchStr_txt->Text + "'";

            /* fname, lname            fname = SearchStr_txt->Text;
            char_ptr = strchr(fname.c_str(), ' ');
            index = char_ptr - fname.c_str();
            lname = fname.SubString(index+2, fname.Length());
            fname = fname.SubString(0, index);

            if(fname == NULL){
                sql = sql + SQLParse(fname) + "' AND emp.tb_LastName LIKE '";
                sql = sql + SQLParse(lname) + "'";
            }
            else{
                sql = sql + "%' AND emp.tb_LastName LIKE '%'";
            }
            /*  */
        }
        else if(Field_drp->ItemIndex == 7){
            // Not yet approved
            sql = sql + "FROM tb_slides ";
            sql = sql + "join tb_Period ";
            sql = sql + "on tb_slides.tb_PDateKey = tb_Period.tb_PDateKey ";
            sql = sql + "join tb_materials ";
            sql = sql + "on tb_slides.tb_MaterialKey = tb_materials.tb_MaterialKey ";
            sql = sql + "join tb_employees emp ";
            sql = sql + "on tb_slides.tb_EmpKey = emp.tb_EmpKey ";
            sql = sql + "join tb_employees emp2 ";
            sql = sql + "on tb_slides.tb_AppEmpKey = emp2.tb_EmpKey ";
            sql = sql + "WHERE tb_IsApproved = 0";
        }

        sql  = sql + " Order By tb_Header";

        result = conn->query(sql);
        if(result != NULL){
            row = mysql_fetch_row(result);

            if(row != NULL){                while(row){
                    OutputFrm->AddLabel(row[0],row[1],row[2],row[3],row[4],
                        row[5],row[6],row[7],row[8],row[9],row[10], row[11]);
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
void __fastcall TFindFrm::Field_drpChange(TObject *Sender){    if(SearchStr_txt->Text != ""){
        Find_btn->Enabled = true;
    }
    else if(Field_drp->Text == "All not yet approved"){
        Find_btn->Enabled = true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::SearchStr_txtChange(TObject *Sender){    if(Field_drp->Text != "-- Select Field --")
        Find_btn->Enabled = True;
}

//---------------------------------------------------------------------------
void __fastcall TFindFrm::FormClose(TObject *Sender, TCloseAction &Action){    this->DestroyWnd();
}

//---------------------------------------------------------------------------
