/****************************************************************************
 *      Project:        Slide Keeper                                        *
 *      Programmer:     Rick Runowski                                       *
 *      Client:         Oklahoma State University Art Department            *
 *      Date Started:   June 14, 2003                                       *
 *      0.4.0 Release:  August 17, 2003                                     *
 *      2.0.0 Release:  January 1, 2005					    *
 *                                                                          *
 *      Description:    Slide Keeper is a program designed to track slides  *
 *        created by the art department Visual Resources Lab (VRL).  The    *
 *        slides contain a Header, two title lines, material type, artist,  *
 *        the date of the art shown in the slide, who entered the data,     *
 *        the date the entry was made, and the Dimensions of the art shown. *
 *      The GUI is split up into two menus.  The main menu allows the user  *
 *        to enter in a new slide into the system or Find a slide or slides *
 *        based on criteria the user set's forth.  The Manage menu allows a *
 *        user to enter in new materials, Users or period dates as necessary*
 *        so they will show up in the drop down menu's.                     *
 *                                                                          *
 ****************************************************************************/

//---------------------------------------------------------------------------
#include <windows>
#include <winsock>

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

USEFORM("Unit1.cpp", frmMain);
USEFORM("Unit2.cpp", FrmNewRec);
USEFORM("Unit3.cpp", frmAbout);
USEFORM("Unit4.cpp", FindFrm);
USEFORM("Unit5.cpp", DataModule5); /* TDataModule: File Type */
USEFORM("Unit6.cpp", OutputFrm);
USEFORM("Unit7.cpp", Frame7); /* TFrame: File Type */
USEFORM("Unit8.cpp", NewUserFrm);
USEFORM("Unit9.cpp", AddPeriodFrm);
USEFORM("Unit10.cpp", AddMatFrm);
USEFORM("Unit12.cpp", MsgBox);
USEFORM("Unit11.cpp", Printview_frm);
USEFORM("Unit13.cpp", Frame13); /* TFrame: File Type */
USEFORM("Unit14.cpp", UpdForm);
USEFORM("EditUser.cpp", EditUserFrm);
//---------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine
	, int nShowCmd){
    try{
        Application->Initialize();
        Application->Title = "Slide Keeper";
        Application->CreateForm(__classid(TfrmMain), &frmMain);
        //Application->CreateForm(__classid(TEditUserFrm), &EditUserFrm);
        Application->Run();
    }
    catch (Exception &exception){
        Application->ShowException(&exception);
    }
    catch (...){
        try{
            throw Exception("");
        }
        catch (Exception &exception){
            Application->ShowException(&exception);
        }
    }
    return 0;
}

