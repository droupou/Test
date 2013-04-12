//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>

#pragma hdrstop

#include "sqlConnection.h"
#include "Unit14.h"
#include "RRUtil.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUpdForm *UpdForm;
//---------------------------------------------------------------------------
__fastcall TUpdForm::TUpdForm(TComponent* Owner)
        : TForm(Owner){
    ;
}

//---------------------------------------------------------------------------

void __fastcall TUpdForm::FormCreate(TObject *Sender){

    MYSQL_RES *result;
    MYSQL_ROW row;
    String err, sql, material, period, employee, fname, lname;

    sqlConnection *conn = new sqlConnection();

    unsigned int num_fields, i;

    if(Sender == NULL)
        return;

    result = conn->query("SELECT CONCAT(tb_FirstName , ' ' , tb_LastName) as Name FROM vrl.tb_employees");

    if (result != NULL){
        num_fields = mysql_num_fields(result);

        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                Entered_drp->AddItem(row[i], new TObject );
                Approved_btn->AddItem(row[i], new TObject );
            }
            row = mysql_fetch_row(result);
        }

        mysql_free_result(result);
    }
    Approved_btn->Text = "-- Approved By --";

    Entered_drp->Enabled = false;
    Height = 470;
    Width = 765;
    Top = 45;
    Left = 5;

    Material_drp->Clear();
    // Get Material data
    result = conn->query("SELECT tb_MaterialDesc FROM tb_Materials Order By tb_MaterialDesc");

    if (result != NULL){
        num_fields = mysql_num_fields(result);

        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                Material_drp->AddItem(row[i], new TObject );
            }
            row = mysql_fetch_row(result);
        }

        mysql_free_result(result);
    }
    Material_drp->Text = "-- Select Material --";

    PDate_drp->Clear();

    // Get Date of Piece data
    conn->query("SELECT tb_PDateDesc FROM tb_Period Order By tb_PDateDesc");
    if (result != NULL){
        num_fields = mysql_num_fields(result);

        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                PDate_drp->AddItem(row[i], new TObject );
            }
            row = mysql_fetch_row(result);
        }

        mysql_free_result(result);
    }
    PDate_drp->Text = "-- Select the date of the Piece --";

    delete(conn);
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Populate(){
    if(spres != NULL){
        Header_txt->Text = spres->header;
        Title_txt->Text = spres->title;
        Title2_txt->Text = spres->title2;

        Material_drp->ItemIndex = -1;
        while(Material_drp->Text != spres->Material)
            Material_drp->ItemIndex++;

        PDate_drp->ItemIndex = -1;
        while(PDate_drp->Text != spres->PDate)
            PDate_drp->ItemIndex++;

        if((spres->EDate != "0000-00-00 00:00:00") && (spres->EDate != "") &&
          (spres->EDate.SubString(0, 10) != "00/00/0000")){
            EDate_date->Text = VarToDateTime(spres->EDate);
        }
        else {
          sqlConnection *conn = new sqlConnection();
          MYSQL_RES *res = conn->query("SELECT NOW()");
          MYSQL_ROW row;

          if (res != NULL){
              row = mysql_fetch_row(res);
              if(row){
                EDate_date->Text = VarToDateTime(row[0]);
                spres->EDate = EDate_date->Text;
              }
              mysql_free_result(res);
          }
          // EDate_date->Text = "";
        }

        Entered_drp->ItemIndex = -1;
        while(Entered_drp->Text != spres->Enter)
            Entered_drp->ItemIndex++;

        if(spres->Is_Approved)
            Approved_chk->Checked = 1;

        Approved_btn->ItemIndex = -1;
        if(Approved_btn->Text != spres->Approve)
            Approved_btn->ItemIndex++;

        Artist_txt->Text = spres->Artist;
        Title2_txt->Text = spres->title2;
        Dimensions_txt->Text = spres->Dimension;
        Path_txt->Text = spres->Pic;
        if(Path_txt->Text != "")
            Image1->Picture->LoadFromFile(Path_txt->Text);
        else
            Image1->Picture->LoadFromFile("C:\\VRL\\thevrl.jpg");

        if(spres->prev == NULL){
            Prev_btn->Enabled = false;
        }
        else{
            Prev_btn->Enabled = true;
        }

        if(spres->next == NULL){
            Next_btn->Enabled = false;
        }
        else{
            Next_btn->Enabled = true;
        }
        Date_txt->Text = spres->ADate;
    }
}
//---------------------------------------------------------------------------
void __fastcall TUpdForm::Next_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    if(spres->next != NULL)
        spres = spres->next;

    while((spres->next != NULL) && (spres->Is_select == false)){
        spres = spres->next;
    }
    Populate();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Prev_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    spres = spres->prev;
    Populate();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Close_btnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::upd_btnClick(TObject *Sender){
    // Needs to update the information on hand.
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;
    String err, sql, material, period, employee, fname, lname, sql2, AppEmp;
    String temp, newloc;

    if(Sender == NULL)
        return;

    temp = Path_txt->Text;
    temp.Trim();
    if((temp == NULL) || (temp == "")){
      temp = "C:\\VRL\\thevrl.jpg";
    }
    Image1->Picture->LoadFromFile(temp);

    sql = "SELECT * FROM vrl.tb_Materials WHERE tb_MaterialDesc LIKE '";
    sql = sql + SQLParse(Material_drp->Text) + "'";

    result = conn->query(sql);
    if(result == NULL){
        // Error message here.
        err = "Materials do not exist.  Please enter the material into the database and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        row = mysql_fetch_row(result);
        while(row){
            material = row[0];
            row = mysql_fetch_row(result);
        }
    }

    sql = "SELECT * FROM vrl.tb_period where tb_PDateDesc LIKE '";
    sql = sql + SQLParse(PDate_drp->Text) + "'";

    result = conn->query(sql);
    if(result == NULL){
        // Error message here.
        err = "The Pieces creation date does not exist.  Please enter it into the database and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        row = mysql_fetch_row(result);
        while(row){
            period = row[0];
            row = mysql_fetch_row(result);
        }
    }

    sql = "SELECT tb_EmpKey FROM tb_employees WHERE ";
    sql = sql + "concat(concat(tb_FirstName, ' '), tb_LastName)  = '";
    sql = sql + SQLParse(Approved_btn->Text) + "'";

    result = conn->query(sql);
    if(result == NULL){
        // Error message here.
        err = "The Pieces creation date does not exist.  Please enter it into the database and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        row = mysql_fetch_row(result);
        while(row){
            AppEmp = row[0];
            row = mysql_fetch_row(result);
        }
    }

    // update the record
    sql = "UPDATE tb_slides SET tb_Header = '" + SQLParse(Header_txt->Text);
    sql = sql + "', tb_Title = '" + SQLParse(Title_txt->Text) + "', tb_Title2 = '"
      + SQLParse(Title2_txt->Text) + "', tb_MaterialKey = '" + SQLParse(material)
        + "', tb_PDateKey = '" + SQLParse(period) + "', "
        + " tb_EDate = STR_TO_DATE('" + SQLParse(EDate_date->Text)
        + "', '%m/%d/%Y %h:%i:%s %p')";

    if(Approved_chk->Checked){
        sql = sql + ", tb_IsApproved = '1";
        sql = sql + "', tb_AppEmpKey = '" + SQLParse(AppEmp);
    }
    else{
        sql = sql + ", tb_IsApproved = '0";
    }
    sql = sql + "', tb_Artist = '" + SQLParse(Artist_txt->Text);
    sql = sql + "', tb_Dimensions = '" + SQLParse(Dimensions_txt->Text);
    sql = sql + "', tb_Date = '" + SQLParse(Date_txt->Text) + "'";
    sql = sql + ", Picture = '" + SQLParse(temp);
    sql = sql + "' WHERE tb_Header LIKE '" + SQLParse(spres->header);
    sql = sql + "' AND tb_Title LIKE '" + SQLParse(spres->title);
    sql = sql + "' AND tb_Title2 LIKE '" + SQLParse(spres->title2);

    sql2 = "SELECT tb_MaterialKey FROM tb_materials WHERE tb_MaterialDesc LIKE '";
    sql2 = sql2 + SQLParse(spres->Material) + "'";
    result = conn->query(sql2);
    if(result == NULL){
        // Error message here.
        err = "The Material does not exist.  Please enter it into the database ";
        err = err + " and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        row = mysql_fetch_row(result);
        sql = sql + "' AND tb_MaterialKey LIKE '" + SQLParse(row[0]);

        mysql_free_result(result);
    }

    sql2 = "SELECT tb_PDateKey FROM tb_period WHERE tb_PDateDesc LIKE '";
    sql2 = sql2 + SQLParse(spres->PDate) + "'";
    result = conn->query(sql2);
    if(result == NULL){
        // Error message here.
        err = "The Material does not exist.  Please enter it into the database ";
        err = err + " and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        row = mysql_fetch_row(result);
        sql = sql + "' AND tb_PDateKey LIKE '" + SQLParse(row[0]);

        mysql_free_result(result);
    }

    sql = sql + "'";

    if(!conn->execute(sql)){
        // Error message here.
        err = "Cannot update this record.  Please try again!";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }

    //updates the present label.
    spres->header = Header_txt->Text;
    spres->title = Title_txt->Text;
    spres->title2 = Title2_txt->Text;
    spres->Material = Material_drp->Text;
    spres->PDate = PDate_drp->Text;
    spres->EDate = EDate_date->Text;
    spres->Enter = Entered_drp->Text;
    if(Approved_chk->Checked){
        spres->Is_Approved = true;
    }
    else{
        spres->Is_Approved = false;
    }
    spres->Approve = Approved_btn->Text;
    spres->Artist = Artist_txt->Text;
    spres->Dimension = Dimensions_txt->Text;
    spres->ADate = Date_txt->Text;

    Populate();
    MessageDlg("Done", mtInformation, TMsgDlgButtons() << mbOK, 0);

    delete(conn);
}
//---------------------------------------------------------------------------
void __fastcall TUpdForm::AssignHEAD(label *H){
    HEAD = H;
}
//---------------------------------------------------------------------------
void __fastcall TUpdForm::ResetPres(){
    pres = HEAD;
}
//---------------------------------------------------------------------------
void __fastcall TUpdForm::GetList(){
    pres = HEAD;
    while((pres != NULL) && (!pres->Is_select)){
        pres = pres->next;
    }

    if(pres != NULL){
        sHEAD = CopyLabel(pres);
        sHEAD->prev = NULL;

        spres = sHEAD;
        pres = pres->next;

        if(pres != NULL){
            while(pres->next != NULL){
                if(pres->Is_select){
                    spres->next = CopyLabel(pres);
                    spres->next->prev = spres;
                    spres = spres->next;
                }
                pres = pres->next;
            }


            if(pres->Is_select){
                spres->next = CopyLabel(pres);
                spres->next->prev = spres;
                spres = spres->next;
            }
            spres->next = NULL;
            spres = sHEAD;
        }
    }
    else{
        // Error message here.
        String err = "You must select something in the Output form!";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        this->DestroyWnd();
        return;
    }
}
//---------------------------------------------------------------------------
label* TUpdForm::CopyLabel(label* l){
    label* r;

    r = new label;

    r->prev = l->prev;
    r->header = l->header;
    r->title = l->title;
    r->title2 = l->title2;
    r->Material = l->Material;
    r->PDate = l->PDate;
    r->EDate = l->EDate;
    r->Enter = l->Enter;
    r->Is_Approved = l->Is_Approved;
    r->Approve = l->Approve;
    r->Artist = l->Artist;
    r->Dimension = l->Dimension;
    r->Is_select = l->Is_select;
    r->ADate = l->ADate;
    r->Pic = l->Pic;
    r->next = NULL;

    return r;
}

void __fastcall TUpdForm::FormClose(TObject *Sender, TCloseAction &Action){
    if((Sender == NULL) && (Action == NULL))
        return;

    DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Delete_btnclick(TObject *Sender){
    // Delete the current record.
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String err, tsql, sql, material, period, employee, fname, lname;
    label *deleted, *t2;

    if(Sender == NULL)
        return;

    sql = "DELETE FROM vrl.tb_Slides WHERE tb_Header ";
    if(spres->header == NULL){
        sql = sql + " IS NULL ";
    }
    else {
        sql = sql + "= '" + SQLParse(spres->header) + "' ";
    }
    sql = sql + " AND tb_Title ";
    if(spres->title == NULL){
        sql = sql + " IS NULL ";
    }
    else {
        sql = sql + " = '" + SQLParse(spres->title) + "' ";
    }
    sql = sql + " AND tb_Title2 ";
    if(spres->title2 == NULL){
        sql = sql + " IS NULL ";
    }
    else{
        sql = sql + "= '" + SQLParse(spres->title2) + "' ";
    }
    sql = sql + " AND tb_EDate ";
    if(spres->EDate == NULL){
        sql = sql + " IS NULL";
    }
    else{
        sql = sql + " = '" + SQLParse(spres->EDate) + "' ";
    }
    sql = sql + " AND tb_Artist ";
    if(spres->Artist == NULL){
        sql = sql + " IS NULL";
    }
    else {
        sql = sql + " = '" + SQLParse(spres->Artist) + "' ";
    }
    sql = sql + " AND tb_Dimensions ";
    if(spres->Dimension == NULL){
        sql = sql + " IS NULL";
    }
    else{
        sql = sql + " = '" + SQLParse(spres->Dimension) + "' ";
    }

    /********************************************************
    *  Grab the Material Key.                              *
    ********************************************************/
    tsql = "SELECT tb_MaterialKey FROM tb_materials WHERE tb_MaterialDesc ";
    if(spres->Material == NULL){
        tsql = tsql + " IS NULL";
    }
    else {
        tsql = tsql + " = '" + SQLParse(spres->Material) + "'";
    }
    result = conn->query(tsql);

    sql = sql + " AND tb_MaterialKey = ";
    if (result != NULL){
        row = mysql_fetch_row(result);
        if(row){
            sql = sql + (row[0]);
        }
        mysql_free_result(result);
    }
    else{
        sql = sql + " IS NULL ";
    }

    /********************************************************
    *  Grab the PDate Key.                                 *
    ********************************************************/
    tsql = "SELECT tb_PDateKey FROM vrl.tb_period WHERE tb_PDateDesc ";
    if(spres->PDate == NULL){
        tsql = tsql + " IS NULL";
    }
    else {
        tsql = tsql + " = '" + SQLParse(spres->PDate) + "'";
    }
    result = conn->query(tsql);

    sql = sql + " AND tb_PDateKey = ";
    if (result != NULL){
        row = mysql_fetch_row(result);
        if(row){
            sql = sql + (row[0]);
        }
        mysql_free_result(result);
    }
    else{
        sql = sql + " IS NULL ";
    }

    /********************************************************
    *  Grab the Approved by Employee Key.                  *
    ********************************************************/
    tsql = "SELECT tb_EmpKey FROM vrl.tb_employees WHERE";
    tsql = tsql + " concat(concat(tb_FirstName, ' '), tb_LastName) = '" +
         SQLParse(spres->Enter) + "'";

    result = conn->query(tsql);

    sql = sql + " AND tb_EmpKey = ";
    if (result != NULL){
        row = mysql_fetch_row(result);
        if(row){
            sql = sql + SQLParse(row[0]);
        }
        mysql_free_result(result);
    }
    else{
        sql = sql + " IS NULL ";
    }

    /********************************************************
    *  Grab the Approved by Employee Key.                  *
    ********************************************************/
    tsql = " SELECT tb_EmpKey FROM vrl.tb_employees WHERE ";
    tsql = tsql + " concat(concat(tb_FirstName, ' '), tb_LastName) = '" +
        SQLParse(spres->Approve) + "'";

    result = conn->query(tsql);

    sql = sql + " AND tb_AppEmpKey = ";

    if (result != NULL){
        row = mysql_fetch_row(result);
        if(row){
            sql = sql + SQLParse(row[0]);
        }
        mysql_free_result(result);
    }
    else{
        sql = sql + " IS NULL";
    }

    conn->execute(sql);

    deleted = spres;
    if(spres->prev != NULL){
        spres->prev->next = spres->next;
        if(spres->next != NULL)
            spres->next->prev = spres->prev;
            
        spres = spres->prev;
    }
    else{
        spres = spres->next;
        if(spres != NULL)
            spres->prev = NULL;
    }

    pres = HEAD;
    while((pres != NULL) && (pres->EDate != deleted->EDate))
        pres = pres->next;

    t2 = pres;
    if(pres == NULL){
        ;
    }
    else if(pres->prev != NULL){
        pres->prev->next = pres->next;
        pres = pres->prev;
    }
    else{
        pres = pres->next;
    }

    delete deleted;
    delete t2;
    DestroyWnd();
    delete(conn);
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Browse_BtnClick(TObject *Sender){
    if(Sender == NULL)
        return;

    OpenDialog1->Filter = "JPEG file | *.jpg; *.jpeg | BMP file | *.bmp ";

    if(OpenDialog1->Execute()){
        spres->Pic = OpenDialog1->FileName;
        Populate();
    }
}
//---------------------------------------------------------------------------


void __fastcall TUpdForm::OnKeyPress(TObject *Sender, char &Key){
    if((Sender == NULL) && (Key == NULL))
        return;
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::OnKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift){
    if((Sender == NULL) && (Key == NULL))
        return;

    TComboBox *Send = dynamic_cast <TComboBox*>(Sender);
    int len = Send->Text.Length();

    if(Send->ItemIndex == -1){
        Send->Text = Send->Text.SubString(1, len-1);
        Send->SelStart = len;
    }
    Shift.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::OnGetFocus(TObject *Sender){
    MYSQL_RES *result;
    MYSQL_ROW row;

    if(Sender == NULL)
        return;

    sqlConnection *conn = new sqlConnection();
    unsigned int num_fields, i;    time_t current;
    int i2, i3;

    i2 = Material_drp->ItemIndex;    Material_drp->Clear();

    // Get Material data    result = conn->query("SELECT tb_MaterialDesc FROM tb_Materials Order By tb_MaterialDesc");
    if (result != NULL){        num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                Material_drp->AddItem(row[i], new TObject );
            }
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
    }
    Material_drp->Text = "-- Select Material --";
    Material_drp->ItemIndex = i2;

    i2 = PDate_drp->ItemIndex;    PDate_drp->Clear();

    // Get Date of Piece data    result = conn->query("SELECT tb_PDateDesc FROM tb_Period Order By tb_PDateDesc");
    if (result != NULL){
        num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                PDate_drp->AddItem(row[i], new TObject );
            }
            row = mysql_fetch_row(result);
        }
        mysql_free_result(result);
    }
    PDate_drp->Text = "-- Select the date of the Piece --";
    PDate_drp->ItemIndex = i2;

    i2 = PDate_drp->ItemIndex;    i3 = Approved_btn->ItemIndex;
    Entered_drp->Clear();
    Approved_btn->Clear();

    // Get Name data    result = conn->query("SELECT CONCAT(tb_FirstName, ' ', tb_LastName) as Name FROM vrl.tb_employees");
    if (result != NULL){
        num_fields = mysql_num_fields(result);
        row = mysql_fetch_row(result);
        while(row){
            for(i = 0; i < num_fields; i++){
                Entered_drp->AddItem(row[i], new TObject );
                Approved_btn->AddItem(row[i], new TObject );
            }
        row = mysql_fetch_row(result);
    }
    mysql_free_result(result);
    }

    Approved_btn->Text = "-- Approved By --";
    PDate_drp->ItemIndex = i2;
    Approved_btn->ItemIndex = i3;

    time(&current);
    EDate_date->Text = ctime(&current);    delete(conn);

    if(spres != NULL){
        this->Populate();
    }

}
//---------------------------------------------------------------------------

