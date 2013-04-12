//---------------------------------------------------------------------------
#ifndef Unit12H#define Unit12H

//---------------------------------------------------------------------------
#include <Classes.hpp>#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

#include <windows>#include <winsock>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
class TMsgBox : public TForm{__published:	// IDE-managed Components

    TLabel *Label1;    TEdit *Edit1;
    TButton *OK_btn;

    void __fastcall FormCreate(TObject *Sender);    void __fastcall OK_btnClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
    String sql;    bool Done;
    __fastcall TMsgBox(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TMsgBox *MsgBox;
//---------------------------------------------------------------------------
#endif
