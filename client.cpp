// wxWidgets "Hello world" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// main app that uses main window
class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

// main window
class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
  // event handlers
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  // so the window can respond to events
  wxDECLARE_EVENT_TABLE();
};

// give commands unique identifiers
enum
{
  ID_Hello = 1
};

// maps unique identifiers to event handlers
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame) EVT_MENU(ID_Hello, MyFrame::OnHello)
  EVT_MENU(wxID_EXIT, MyFrame::OnExit) EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

  // the main function and it starts MyApp via OnInit()
  wxIMPLEMENT_APP(MyApp);

bool
MyApp::OnInit()
{
  MyFrame* frame =
    new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
  frame->Show(true);
  return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{
  // file menu
  wxMenu* menuFile = new wxMenu;
  // first string is displayed in menu slot
  // second string is displayed in bottom of window
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");

  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  // help menu
  wxMenu* menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  // holds all the menus
  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");
}

void
MyFrame::OnExit(wxCommandEvent& event)
{
  // true forces quit
  Close(true);
}

void
MyFrame::OnAbout(wxCommandEvent& event)
{
  // pop up window
  // body text, title, icons
  wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void
MyFrame::OnHello(wxCommandEvent& event)
{
  // pop up window with message
  wxLogMessage("Hello world from wxWidgets!");
}
