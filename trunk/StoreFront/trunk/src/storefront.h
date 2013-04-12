#ifndef _STOREFRONT_H_
#define _STOREFRONT_H_

/**
 * @short Application Main Window
 * @author Rick Runowski <StoreFront@ABYSS.Runowski.org>
 * @version 0.2
 */

class
StoreFrontapp : public wxApp
{
  public:
    virtual bool OnInit();
};

class
StoreFrontFrame : public wxFrame
{
  public:
    StoreFrontFrame( const wxString& title, const wxPoint& pos, const wxSize& pos );
    void OnQuit( wxCommandEvent& event );
    void OnAbout( wxCommandEvent& event );
    void OnTestSQL( wxCommandEvent& event );

  private:
    DECLARE_EVENT_TABLE();
};

enum
{
  Menu_File_Quit = 100,
  Menu_File_TestSQL = 110,
  Menu_File_About
};

#endif // _STOREFRONT_H_
