#include"gameScreen.h"


GameScreen::GameScreen(const wxString& title, const wxPoint& pos, const wxSize& size)
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
GameScreen::OnExit(wxCommandEvent& event)
{
  // true forces quit
  Close(true);
}

void
GameScreen::OnAbout(wxCommandEvent& event)
{
  // pop up window
  // body text, title, icons
  wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void
GameScreen::OnHello(wxCommandEvent& event)
{
  // pop up window with message
  wxLogMessage("Hello world from wxWidgets!");
}


// maps unique identifiers to event handlers
wxBEGIN_EVENT_TABLE(GameScreen, wxFrame) EVT_MENU(ID_Hello, GameScreen::OnHello)
  EVT_MENU(wxID_EXIT, GameScreen::OnExit) EVT_MENU(wxID_ABOUT, GameScreen::OnAbout)
wxEND_EVENT_TABLE()

