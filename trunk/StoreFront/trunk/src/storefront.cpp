#include <wx/wx.h>
#include "storefront.h"
#include "SFSQL.hpp"

BEGIN_EVENT_TABLE( StoreFrontFrame, wxFrame )
  EVT_MENU( Menu_File_Quit, StoreFrontFrame::OnQuit )
  EVT_MENU( Menu_File_About, StoreFrontFrame::OnAbout )
  EVT_MENU( Menu_File_TestSQL, StoreFrontFrame::OnTestSQL)
END_EVENT_TABLE()

IMPLEMENT_APP(StoreFrontapp)


bool StoreFrontapp::OnInit(){
  StoreFrontFrame *frame = new StoreFrontFrame( wxT( "Store Front" ), wxPoint(50,50), wxSize(800,600) );

  frame->Show(TRUE);
  SetTopWindow(frame);
  return TRUE;
}

StoreFrontFrame::StoreFrontFrame( const wxString& title, const wxPoint& pos, const wxSize& size )
  : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  wxMenu *menuFile = new wxMenu;

  menuFile->Append( Menu_File_TestSQL, wxT( "&Test SQL") );
  menuFile->AppendSeparator();
  menuFile->Append( Menu_File_About, wxT( "&About..." ) );
  menuFile->AppendSeparator();
  menuFile->Append( Menu_File_Quit, wxT( "E&xit" ) );

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append( menuFile, wxT( "&File" ) );

  SetMenuBar( menuBar );

  CreateStatusBar();
  SetStatusText( wxT( "Welcome to the Store Front!" ) );
}

void StoreFrontFrame::OnQuit( wxCommandEvent& WXUNUSED( event ) )
{
  Close(TRUE);
}

void StoreFrontFrame::OnAbout( wxCommandEvent& WXUNUSED( event ) )
{
  //wxMessageDialog(this, "StoreFront version 0.0.0.1", "About StoreFront", wxOK | wxICON_INFORMATION);
  wxMessageBox( wxT( "StoreFront version 0.0.0.2" ),
       wxT( "About StoreFront" ), wxOK | wxICON_INFORMATION, this );
}

void StoreFrontFrame::OnTestSQL( wxCommandEvent& WXUNUSED( event ) ){
  // Connect to the SQL server and send a simple query.
}
