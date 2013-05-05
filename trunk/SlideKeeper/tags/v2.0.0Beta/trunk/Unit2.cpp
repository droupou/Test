//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"#include "label.h"#include "sqlConnection.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)#pragma resource "*.dfm"

TFrmNewRec *FrmNewRec;
//---------------------------------------------------------------------------
__fastcall TFrmNewRec::TFrmNewRec(TComponent* Owner)        : TForm(Owner){
    l = new label();
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::Cancel_btnClick(TObject *Sender){    if(Sender != NULL){
        delete(l);
        this->DestroyWnd();
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::Clear_btnClick(TObject *Sender){    if(Sender != NULL){
        delete(l);
        l = new label();

        Header_txt->Text = "";        Title_txt->Text = "";
        PDate_drp->Text = "-- Select the date of the Piece --";
        Material_drp->Text = "-- Select Material --";

        Approved_btn->Text = "-- Approved By --";        EDate_date->Text = "";
        Approved_chk->Checked = false;
        Artist_txt->Text = "";
        Title2_txt->Text = "";
        Dimensions_txt->Text = "";
        Date_txt->Text = "";

        sqlConnection *conn = new sqlConnection();
        MYSQL_RES *res = conn->query("SELECT NOW()");
        MYSQL_ROW row;

        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                EDate_date->Text = VarToDateTime(row[0]);
            }
            mysql_free_result(res);
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::FormClose(TObject *Sender,      TCloseAction &Action){
    if((Sender != NULL) || (Action != NULL)){
        this->DestroyWnd();
        delete(l);
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::OK_btnClick(TObject *Sender){    sqlConnection *conn = new sqlConnection();
    String sql, sql2, trm;

    if(Sender == NULL)        return;            if((Header_txt->Text == "") || (Header_txt == NULL)){        MessageDlg("Header is a required field.", mtError, TMsgDlgButtons()            << mbOK, 0);    }    else if ((Material_drp->Text == "-- Select Material --") ||        (Material_drp->Text == "") || (Material_drp->Text == NULL)){        MessageDlg("Material Type is a required field.", mtError,            TMsgDlgButtons() << mbOK, 0);    }    else if ((PDate_drp->Text == "-- Select the date of the Piece --") ||        (PDate_drp->Text == "") || (PDate_drp->Text == NULL)){        MessageDlg("Period Date is a required field.", mtError, TMsgDlgButtons()            << mbOK, 0);    }    else if((Entered_drp->Text == "-- Entered By --") ||        (Entered_drp->Text == "") || (Entered_drp->Text == NULL)){        MessageDlg("Entered by is a required field.",mtError,TMsgDlgButtons()
            << mbOK,0);
    }
    else{
        sqlConnection *conn = new sqlConnection();

        MYSQL_RES *res = conn->query("SELECT NOW()");
        MYSQL_ROW row;
        String matNum, PDate, empId, approveEmpId;

        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                EDate_date->Text = VarToDateTime(row[0]);
            }
            mysql_free_result(res);
        }

        l->header = Header_txt->Text;
        l->title = Title_txt->Text;
        l->title2 = Title2_txt->Text;
        l->Material = Material_drp->Text;
        l->PDate = PDate_drp->Text;
        l->Enter = Entered_drp->Text;
        l->Is_Approved = Approved_chk->Checked;
        l->Artist = Artist_txt->Text;
        l->Dimension = Dimensions_txt->Text;
        l->EDate = EDate_date->Text;

        //----------------------------------------------------------------------
        //* Get Material number        sql = "SELECT tb_MaterialKey FROM tb_materials WHERE tb_MaterialDesc = '";
        sql = sql + SQLParse(Material_drp->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                matNum = row[0];
            }
            mysql_free_result(res);
        }
        //* Get Period Date number
        sql = "SELECT tb_PDateKey FROM tb_period WHERE tb_PDateDesc = '";
        sql = sql + SQLParse(PDate_drp->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                PDate = row[0];
            }
            mysql_free_result(res);
        }

        //* Get Entered by number
        sql = "SELECT tb_EmpKey FROM tb_employees WHERE ";
        sql = sql + "concat(concat(tb_FirstName, ' '), tb_LastName)  = '";
        sql = sql + SQLParse(Entered_drp->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                empId = row[0];
            }
            mysql_free_result(res);
        }

        //* Get Approved by Employee number
        sql = "SELECT tb_EmpKey FROM tb_employees WHERE ";
        sql = sql + "concat(concat(tb_FirstName, ' '), tb_LastName)  = '";
        sql = sql + SQLParse(Approved_btn->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                approveEmpId = row[0];
            }
            mysql_free_result(res);
        }

        //-------------------------------------------------------------------

        sql = "INSERT INTO vrl.tb_slides (tb_Header, tb_Title, tb_Title2, ";
        sql = sql + "tb_MaterialKey, tb_PDateKey, tb_EDate, tb_EmpKey, " +
            "tb_IsApproved, tb_AppEmpKey, tb_Artist, tb_Dimensions, " +
            "tb_Date, Picture) VALUES ('" + SQLParse(Header_txt->Text) + "', '"
            + SQLParse(Title_txt->Text) + "', '" + SQLParse(Title2_txt->Text)
            + "', " + matNum + ", " + PDate + ", '" + SQLParse(EDate_date->Text)
            + "', '" +
            SQLParse(empId);

        if(Approved_chk->Checked == TRUE){
            sql = sql + "', '1', '" + SQLParse(approveEmpId) + "'";
        }
        else{
            sql = sql + "', '0', '1'";
        }

        sql = sql + ", '" + SQLParse(Artist_txt->Text) + "', '"
            + SQLParse(Dimensions_txt->Text) + "', '" + SQLParse(Date_txt->Text)            + "', '" + SQLParse(Path_txt->Text) + "')";
        conn->execute(sql);        Header_txt->Text = "";        Title_txt->Text = "";
        Material_drp->Text = "-- Select Material --";
        PDate_drp->Text = "-- Select the date of the Piece --";

        Approved_chk->Checked = false;        Approved_btn->Text = "-- Approved By --";
        Artist_txt->Text = "";
        Title2_txt->Text = "";
        Dimensions_txt->Text = "";
        Date_txt->Text = "";
        Path_txt->Text = "";
        Image1->Picture->LoadFromFile("C:\\VRL\\thevrl.jpg");

        res = conn->query("SELECT NOW()");

        if (res != NULL){
            if(row = mysql_fetch_row(res)){
                EDate_date->Text = VarToDateTime(row[0]);
            }
            mysql_free_result(res);
        }
    }

    Header_txt->SetFocus();    delete(conn);
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::OnGetFocus(TObject *Sender){    MYSQL_RES *result;
    MYSQL_ROW row;

    if(Sender == NULL)
        return;
    
    sqlConnection *conn = new sqlConnection();
    unsigned int num_fields, i;    time_t current;
    int i2, i3;

    i2 = Material_drp->ItemIndex;    Material_drp->Clear();

    // Get Material data    result = conn->query("SELECT tb_MaterialDesc FROM tb_Materials Order By tb_MaterialDesc");
    if (result != NULL){        num_fields = mysql_num_fields(result);
        while(row = mysql_fetch_row(result)){
            for(i = 0; i < num_fields; i++){
                Material_drp->AddItem(row[i], new TObject );
            }
        }
        mysql_free_result(result);
    }
    Material_drp->Text = "-- Select Material --";
    Material_drp->ItemIndex = i2;

    i2 = PDate_drp->ItemIndex;    PDate_drp->Clear();

    // Get Date of Piece data    result = conn->query("SELECT tb_PDateDesc FROM tb_Period Order By tb_PDateDesc");
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
    PDate_drp->ItemIndex = i2;

    i2 = PDate_drp->ItemIndex;    i3 = Approved_btn->ItemIndex;
    Entered_drp->Clear();
    Approved_btn->Clear();

    // Get Name data    result = conn->query("SELECT CONCAT(tb_FirstName, ' ', tb_LastName) as Name FROM vrl.tb_employees");
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
    PDate_drp->ItemIndex = i2;
    Approved_btn->ItemIndex = i3;

    time(&current);
    EDate_date->Text = ctime(&current);    delete(conn);
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::FormCreate(TObject *Sender){
    if(Sender != NULL){
        this->Height = 470;
        this->Width = 765;
        this->Top = 45;
        this->Left = 5;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmNewRec::Browse_btnClick(TObject *Sender){
    FILE *fp;

    if(Sender == NULL)
        return;
    
    OpenDialog1->Filter = "JPEG file | *.jpg; *.jpeg | BMP file | *.bmp ";

    if(OpenDialog1->Execute()){
       fp = fopen(OpenDialog1->FileName.c_str(), "r");
       if(fp != NULL){
           fclose(fp);
           this->Path_txt->Text = OpenDialog1->FileName;
           this->Image1->Picture->LoadFromFile(this->Path_txt->Text);
       }
       else{
           MessageDlg("File Doesn't exist, please try again.", mtError,
               TMsgDlgButtons() << mbOK,0);
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrmNewRec::OnKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
    if((Sender == NULL) || (Key == NULL) || (Shift.Empty()))
        return;
}
//---------------------------------------------------------------------------

void __fastcall TFrmNewRec::Material_drpChange(System::TObject *){
    ;
}
//---------------------------------------------------------------------------


void __fastcall TFrmNewRec::OnOnKeyUp(TObject *Sender, WORD &Key,
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
}
//---------------------------------------------------------------------------

