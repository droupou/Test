#include <wx/wx.h>
#include "storefront.h"

BEGIN_EVENT_TABLE( StoreFrontFrame, wxFrame )
	EVT_MENU( Menu_File_Quit, StoreFrontFrame::OnQuit )
	EVT_MENU( Menu_File_About, StoreFrontFrame::OnAbout )
END_EVENT_TABLE()

IMPLEMENT_APP(StoreFrontapp)
	

bool 
StoreFrontapp::OnInit()
{
	StoreFrontFrame *frame = new StoreFrontFrame( wxT( "Hello World" ), wxPoint(50,50), wxSize(450,340) );

	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
} 

StoreFrontFrame::StoreFrontFrame( const wxString& title, const wxPoint& pos, const wxSize& size )
	: wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	
	menuFile->Append( Menu_File_About, wxT( "&About..." ) );
	menuFile->AppendSeparator();
	menuFile->Append( Menu_File_Quit, wxT( "E&xit" ) );
	
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, wxT( "&File" ) );
	
	SetMenuBar( menuBar );
	
	CreateStatusBar();
	SetStatusText( wxT( "Welcome to Kdevelop wxWidgets app!" ) );
}

void 
StoreFrontFrame::OnQuit( wxCommandEvent& WXUNUSED( event ) )
{
	Close(TRUE);
}

void 
StoreFrontFrame::OnAbout( wxCommandEvent& WXUNUSED( event ) )
{
	wxMessageBox( wxT( "This is a wxWidgets Hello world sample" ),
			wxT( "About Hello World" ), wxOK | wxICON_INFORMATION, this );
}

