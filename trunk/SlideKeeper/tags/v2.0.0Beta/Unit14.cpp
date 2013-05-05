//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>

#pragma hdrstop

#include "sqlConnection.h"
#include "skPicture.h"
#include "Unit14.h"

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

    result = conn->query("SELECT CONCAT(tb_FirstName , ' ' , tb_LastName) as Name FROM vrl.tb_employees");

    if (result != NULL){
        num_fields = mysql_num_fields(result);

        while(row = mysql_fetch_row(result)){
            for(i = 0; i < num_fields; i++){
                Entered_drp->AddItem(row[i], new TObject );
                Approved_btn->AddItem(row[i], new TObject );
            }
        }

        mysql_free_result(result);
    }
    Approved_btn->Text = "-- Approved By --";

    this->Entered_drp->Enabled = false;
    this->Height = 470;
    this->Width = 765;
    this->Top = 45;
    this->Left = 5;

    Material_drp->Clear();
    // Get Material data
    result = conn->query("SELECT tb_MaterialDesc FROM tb_Materials Order By tb_MaterialDesc");

    if (result != NULL){
        num_fields = mysql_num_fields(result);

        while(row = mysql_fetch_row(result)){
            for(i = 0; i < num_fields; i++){
                Material_drp->AddItem(row[i], new TObject );
            }
        }

        mysql_free_result(result);
    }
    Material_drp->Text = "-- Select Material --";

    PDate_drp->Clear();

    // Get Date of Piece data
    conn->query("SELECT tb_PDateDesc FROM tb_Period Order By tb_PDateDesc");
    if (result != NULL){
        num_fields = mysql_num_fields(result);

        while(row = mysql_fetch_row(result)){
            for(i = 0; i < num_fields; i++){
                PDate_drp->AddItem(row[i], new TObject );
            }
        }

        mysql_free_result(result);
    }
    PDate_drp->Text = "-- Select the date of the Piece --";

    delete(conn);
}
//---------------------------------------------------------------------------

__fastcall TUpdForm::Populate(){
    this->Header_txt->Text = this->spres->header;
    this->Title_txt->Text = spres->title;
    this->Title2_txt->Text = spres->title2;
    this->Material_drp->Text = spres->Material;
    this->PDate_drp->Text = spres->PDate;
    if((spres->EDate != "0000-00-00 00:00:00") && (spres->EDate != "")){
        this->EDate_date->Text = VarToDateTime(spres->EDate);
    }
    else {
        this->EDate_date->Text = "";
    }
    this->Entered_drp->Text = spres->Enter;

    if(spres->Is_Approved)
        this->Approved_chk->Checked = 1;

    this->Approved_btn->Text = spres->Approve;
    this->Artist_txt->Text = spres->Artist;
    this->Title2_txt->Text = spres->title2;
    this->Dimensions_txt->Text = spres->Dimension;
    this->Path_txt->Text = spres->Pic;
    if(this->Path_txt->Text != "")
        this->Image1->Picture->LoadFromFile(this->Path_txt->Text);
    else
        this->Image1->Picture->LoadFromFile("C:\\VRL\\thevrl.jpg");

    if(spres->prev == NULL){
        this->Prev_btn->Enabled = false;
    }
    else{
        this->Prev_btn->Enabled = true;
    }

    if(spres->next == NULL){
        this->Next_btn->Enabled = false;
    }
    else{
        this->Next_btn->Enabled = true;
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TUpdForm::Next_btnClick(TObject *Sender){
    if(this->spres->next != NULL)
        this->spres = this->spres->next;

    while((this->spres->next != NULL) && (this->spres->Is_select == false)){
        this->spres = this->spres->next;
    }
    this->Populate();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Prev_btnClick(TObject *Sender){
    this->spres = this->spres->prev;
    this->Populate();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Close_btnClick(TObject *Sender){
    this->DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::upd_btnClick(TObject *Sender){
    // Needs to update the information on hand.
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;
    String err, sql, material, period, employee, fname, lname, sql2, AppEmp;
    String temp, newloc;
    char *buffer, *tbuffer;
    int i2, c;
    FILE *in, *out;
    fstream *inPic;
    fstream *outPic;

    unsigned int num_fields, i;
    unsigned long *lengths;

    int count;
    time_t current;

    temp = this->Path_txt->Text;
    temp.Trim();
    Image1->Picture->LoadFromFile(temp);

    sql = "SELECT * FROM vrl.tb_Materials WHERE tb_MaterialDesc LIKE '";
    sql = sql + SQLParse(this->Material_drp->Text) + "'";

    result = conn->query(sql);
    if(result == NULL){
        // Error message here.
        err = "Materials do not exist.  Please enter the material into the database and try again.";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }
    else{
        // Query worked.
        num_fields = mysql_num_fields(result);
        count = 1;

        while(row = mysql_fetch_row(result)){
            lengths = mysql_fetch_lengths(result);
            material = row[0];
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
        num_fields = mysql_num_fields(result);
        count = 1;

        while(row = mysql_fetch_row(result)){
            lengths = mysql_fetch_lengths(result);
            period = row[0];
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
        num_fields = mysql_num_fields(result);
        count = 1;

        while(row = mysql_fetch_row(result)){
            lengths = mysql_fetch_lengths(result);
            AppEmp = row[0];
        }
    }

    // update the record
    sql = "UPDATE tb_slides SET tb_Header = '" + SQLParse(Header_txt->Text);
    sql = sql + "', tb_Title = '" + SQLParse(Title_txt->Text);
    sql = sql + "', tb_Title2 = '" + SQLParse(Title2_txt->Text);
    sql = sql + "', tb_MaterialKey = '" + SQLParse(material)
        + "', tb_PDateKey = '" + SQLParse(period) + "', tb_Edate = '"
        + SQLParse(EDate_date->Text);
    if(this->Approved_chk->Checked){
        sql = sql + "', tb_IsApproved = '1";
        sql = sql + "', tb_AppEmpKey = '" + SQLParse(AppEmp);
    }
    else{
        sql = sql + "', tb_IsApproved = '0";
    }
    sql = sql + "', tb_Artist = '" + SQLParse(Artist_txt->Text);
    sql = sql + "', tb_Dimensions = '" + SQLParse(Dimensions_txt->Text);
    sql = sql + "', tb_Date = '" + SQLParse(Date_txt->Text);
    sql = sql + "', Picture = '" + SQLParse(temp);
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

    sql = sql + "' AND tb_EDate LIKE '" + SQLParse(spres->EDate) + "'";

    if(!conn->execute(sql)){
        // Error message here.
        err = "Cannot update this record.  Please try again!";
        MessageDlg(err,mtError,TMsgDlgButtons() << mbOK,0);
        return;
    }

    //updates the present label.
    this->spres->header = this->Header_txt->Text;
    this->spres->title = this->Title_txt->Text;
    this->spres->title2 = this->Title2_txt->Text;
    this->spres->Material = this->Material_drp->Text;
    this->spres->PDate = this->PDate_drp->Text;
    this->spres->EDate = this->EDate_date->Text;
    this->spres->Enter = this->Entered_drp->Text;
    if(this->Approved_chk->Checked){
        this->spres->Is_Approved = true;
    }
    else{
        this->spres->Is_Approved = false;
    }
    this->spres->Approve = this->Approved_btn->Text;
    this->spres->Artist = this->Artist_txt->Text;
    this->spres->Dimension = this->Dimensions_txt->Text;

    this->Populate();
    MessageDlg("Done", mtInformation, TMsgDlgButtons() << mbOK, 0);

    delete(conn);
}
//---------------------------------------------------------------------------
__fastcall TUpdForm::AssignHEAD(label *H){
    HEAD = H;
}
//---------------------------------------------------------------------------
__fastcall TUpdForm::ResetPres(){
    this->pres = this->HEAD;
}
//---------------------------------------------------------------------------
__fastcall TUpdForm::GetList(){
    pres = HEAD;
    while(!this->pres->Is_select){
        this->pres = this->pres->next;
    }
    sHEAD = CopyLabel(pres);
    sHEAD->prev = NULL;

    spres = sHEAD;
    pres = pres->next;

    if(this->pres != NULL){
        while(this->pres->next != NULL){
            if(this->pres->Is_select){
                spres->next = CopyLabel(this->pres);
                spres->next->prev = this->spres;
                spres = spres->next;
            }
            pres = pres->next;
        }


        if(this->pres->Is_select){
            spres->next = CopyLabel(this->pres);
            spres->next->prev = this->spres;
            spres = spres->next;
        }
        spres->next = NULL;
        spres = sHEAD;
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
    r->Pic = l->Pic;
    r->next = NULL;

    return r;
}

void __fastcall TUpdForm::FormClose(TObject *Sender, TCloseAction &Action){
    this->DestroyWnd();
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Delete_btnclick(TObject *Sender){
    // Delete the current record.
    sqlConnection *conn = new sqlConnection();
    MYSQL_RES *result;
    MYSQL_ROW row;

    String err, tsql, sql, material, period, employee, fname, lname;
    label *t, *t2;

    unsigned int num_fields, i;
    unsigned long *lengths;

    int count;
    time_t current;

    sql = "DELETE FROM vrl.tb_Slides WHERE tb_Header ";
    if(this->spres->header == NULL){
        sql = sql + " IS NULL ";
    }
    else {
        sql = sql + "= '" + SQLParse(spres->header) + "' ";
    }
    sql = sql + " AND tb_Title ";
    if(this->spres->title == NULL){
        sql = sql + " IS NULL ";
    }
    else {
        sql = sql + " = '" + SQLParse(spres->title) + "' ";
    }
    sql = sql + " AND tb_Title2 ";
    if(this->spres->title2 == NULL){
        sql = sql + " IS NULL ";
    }
    else{
        sql = sql + "= '" + SQLParse(spres->title2) + "' ";
    }
    sql = sql + " AND tb_EDate ";
    if(this->spres->EDate == NULL){
        sql = sql + " IS NULL";
    }
    else{
        sql = sql + " = '" + SQLParse(spres->EDate) + "' ";
    }
    sql = sql + " AND tb_Artist ";
    if(this->spres->Artist == NULL){
        sql = sql + " IS NULL";
    }
    else {
        sql = sql + " = '" + SQLParse(spres->Artist) + "' ";
    }
    sql = sql + " AND tb_Dimensions ";
    if(this->spres->Dimension == NULL){
        sql = sql + " IS NULL";
    }
    else{
        sql = sql + " = '" + SQLParse(spres->Dimension) + "' ";
    }

    /*
    sql = sql + " AND Picture ";
    if((this->spres->Pic == NULL) || (this->spres->Pic == "")){
        sql = sql + " IS NULL";
    }
    else{
        sql = sql + " = '" + this->spres->Pic + "'";
    }
    /*  */

    /********************************************************
    *  Grab the Material Key.                              *
    ********************************************************/
    tsql = "SELECT tb_MaterialKey FROM tb_materials WHERE tb_MaterialDesc ";
    if(this->spres->Material == NULL){
        tsql = tsql + " IS NULL";
    }
    else {
        tsql = tsql + " = '" + SQLParse(spres->Material) + "'";
    }
    result = conn->query(tsql);

    sql = sql + " AND tb_MaterialKey = ";
    if (result != NULL){
        if(row = mysql_fetch_row(result)){
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
    if(this->spres->PDate == NULL){
        tsql = tsql + " IS NULL";
    }
    else {
        tsql = tsql + " = '" + SQLParse(spres->PDate) + "'";
    }
    result = conn->query(tsql);

    sql = sql + " AND tb_PDateKey = ";
    if (result != NULL){
        if(row = mysql_fetch_row(result)){
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
        if(row = mysql_fetch_row(result)){
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
        if(row = mysql_fetch_row(result)){
            sql = sql + SQLParse(row[0]);
        }
        mysql_free_result(result);
    }
    else{
        sql = sql + " IS NULL";
    }

    conn->execute(sql);

    t = this->spres;
    if(this->spres->prev != NULL){
        this->spres->prev->next = this->spres->next;
        this->spres->next->prev = this->spres->prev;
        this->spres = this->spres->prev;
    }
    else{
        this->spres = this->spres->next;
        if(this->spres != NULL)
            this->spres->prev = NULL;
    }

    this->pres = this->HEAD;
    while(this->pres->EDate != t->EDate)
        this->pres = this->pres->next;

    t2 = this->pres;
    if(this->pres->prev != NULL){
        this->pres->prev->next = this->pres->next;
        this->pres = this->pres->prev;
    }
    else{
        this->pres = this->pres->next;
    }

    delete t;
    delete t2;
    this->DestroyWnd();
    delete(conn);
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::Browse_BtnClick(TObject *Sender){
    OpenDialog1->Filter = "JPEG file | *.jpg; *.jpeg | BMP file | *.bmp ";

    if(OpenDialog1->Execute()){
        spres->Pic = OpenDialog1->FileName;
        this->Populate();
    }
}
//---------------------------------------------------------------------------


void __fastcall TUpdForm::OnKeyPress(TObject *Sender, char &Key){
    ;
}
//---------------------------------------------------------------------------

void __fastcall TUpdForm::OnKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift){
    TComboBox *Send = dynamic_cast <TComboBox*>(Sender);
    int len = Send->Text.Length();

    if(Send->ItemIndex == -1){
        Send->Text = Send->Text.SubString(1, len-1);
        Send->SelStart = len;
    }
}
//---------------------------------------------------------------------------

