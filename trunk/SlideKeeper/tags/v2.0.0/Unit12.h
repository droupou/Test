//---------------------------------------------------------------------------
#ifndef Unit12H

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

#include <windows>
#include <mysql/mysql.h>
#include <string.h>

//---------------------------------------------------------------------------
class TMsgBox : public TForm{

    TLabel *Label1;
    TButton *OK_btn;

    void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
    String sql;
    __fastcall TMsgBox(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TMsgBox *MsgBox;
//---------------------------------------------------------------------------
#endif