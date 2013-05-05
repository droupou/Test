//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"


#pragma package(smart_init)

TFrmNewRec *FrmNewRec;
//---------------------------------------------------------------------------
__fastcall TFrmNewRec::TFrmNewRec(TComponent* Owner)
    l = new label();
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::Cancel_btnClick(TObject *Sender){
        delete(l);
        DestroyWnd();
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::Clear_btnClick(TObject *Sender){
        delete(l);
        l = new label();

        Header_txt->Text = "";
        PDate_drp->Text = "-- Select the date of the Piece --";
        Material_drp->Text = "-- Select Material --";

        Approved_btn->Text = "-- Approved By --";
        Approved_chk->Checked = false;
        Artist_txt->Text = "";
        Title2_txt->Text = "";
        Dimensions_txt->Text = "";
        Date_txt->Text = "";

        sqlConnection *conn = new sqlConnection();
        MYSQL_RES *res = conn->query("SELECT NOW()");
        MYSQL_ROW row;

        if (res != NULL){
            row = mysql_fetch_row(res);
            if(row){
                EDate_date->Text = VarToDateTime(row[0]);
            }
            mysql_free_result(res);
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::FormClose(TObject *Sender,
    if((Sender != NULL) || (Action != NULL)){
        DestroyWnd();
        delete(l);
    }
}

//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::OK_btnClick(TObject *Sender){
    String sql, sql2, trm;

    if(Sender == NULL)
            << mbOK,0);
    }
    else{
        sqlConnection *conn = new sqlConnection();

        MYSQL_RES *res = conn->query("SELECT NOW()");
        MYSQL_ROW row;
        String matNum, PDate, empId, approveEmpId;

        if (res != NULL){
            row = mysql_fetch_row(res);
            if(row){
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
        //* Get Material number
        sql = sql + SQLParse(Material_drp->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            row = mysql_fetch_row(res);
            if(row){
                matNum = row[0];
            }
            mysql_free_result(res);
        }

        sql = "SELECT tb_PDateKey FROM tb_period WHERE tb_PDateDesc = '";
        sql = sql + SQLParse(PDate_drp->Text) + "'";

        res = conn->query(sql);
        if (res != NULL){
            row = mysql_fetch_row(res);
            if(row){
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
            row = mysql_fetch_row(res);
            if(row){
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
            row = mysql_fetch_row(res);
            if(row){
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
            + "', " + matNum + ", " + PDate + ", STR_TO_DATE('" +
            SQLParse(EDate_date->Text) + "', '%m/%d/%Y %H:%i:%s'), '" +
            SQLParse(empId);

        if(Approved_chk->Checked == TRUE){
            sql = sql + "', '1', '" + SQLParse(approveEmpId) + "'";
        }
        else{
            sql = sql + "', '0', '1'";
        }

        sql = sql + ", '" + SQLParse(Artist_txt->Text) + "', '"
            + SQLParse(Dimensions_txt->Text) + "', '" + SQLParse(Date_txt->Text)
        conn->execute(sql);
        Material_drp->Text = "-- Select Material --";
        PDate_drp->Text = "-- Select the date of the Piece --";

        Approved_chk->Checked = false;
        Artist_txt->Text = "";
        Title2_txt->Text = "";
        Dimensions_txt->Text = "";
        Date_txt->Text = "";
        Path_txt->Text = "";
        Image1->Picture->LoadFromFile("C:\\VRL\\thevrl.jpg");

        res = conn->query("SELECT NOW()");

        if (res != NULL){
            row = mysql_fetch_row(res);
            if(row){
                EDate_date->Text = VarToDateTime(row[0]);
            }
            mysql_free_result(res);
        }
    }

    Header_txt->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::OnGetFocus(TObject *Sender){
    MYSQL_ROW row;

    if(Sender == NULL)
        return;
    
    sqlConnection *conn = new sqlConnection();
    unsigned int num_fields, i;
    int i2, i3;

    i2 = Material_drp->ItemIndex;

    // Get Material data
    if (result != NULL){
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

    i2 = PDate_drp->ItemIndex;

    // Get Date of Piece data
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

    i2 = PDate_drp->ItemIndex;
    Entered_drp->Clear();
    Approved_btn->Clear();

    // Get Name data
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
    EDate_date->Text = ctime(&current);
}
//---------------------------------------------------------------------------
void __fastcall TFrmNewRec::FormCreate(TObject *Sender){
    if(Sender != NULL){
        Height = 470;
        Width = 765;
        Top = 45;
        Left = 5;
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
           Path_txt->Text = OpenDialog1->FileName;
           Image1->Picture->LoadFromFile(Path_txt->Text);
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
