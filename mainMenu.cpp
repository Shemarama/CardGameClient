#include "mainMenu.h"
#include "frameManager.h"
BEGIN_EVENT_TABLE(MainMenu, wxFrame)
EVT_BUTTON(crazyEightsButtonID, MainMenu::onClickC8Button)
EVT_BUTTON(heartsButtonID, MainMenu::onClickHeartsButton)
EVT_BUTTON(logoutButtonID, MainMenu::onClickLogoutButton)
END_EVENT_TABLE()

MainMenu::MainMenu(const wxString &title, wxFrame *parentFrame,
                   wxString currentUserName)
    : wxFrame(parentFrame, wxID_ANY, title, wxDefaultPosition,
              wxSize(500, 500)) {
  // set static text and modify the size
  usersName = new wxStaticText(
      this, wxID_ANY, wxT("Welcome \n" + currentUserName), wxDefaultPosition,
      wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
  wxFont font = usersName->GetFont();
  font.SetPointSize(16);
  usersName->SetFont(font);
  // set parent frame
  this->parentFrame = parentFrame;

  // set main sizers
  hTopPanelLayout = new wxBoxSizer(wxHORIZONTAL);
  hBottomPanelLayout = new wxBoxSizer(wxHORIZONTAL);
  frameGrid = new wxBoxSizer(wxVERTICAL);
  // set buttons
  crazyEightsButton =
      new wxButton(this, crazyEightsButtonID, wxT("Play Crazy Eights Offline"));
  heartsButton = new wxButton(this, heartsButtonID, wxT("Play Hearts Offline"));
  logoutButton = new wxButton(this, logoutButtonID, wxT("Logout"));

  // add to layout
  hTopPanelLayout->Add(crazyEightsButton, 0, wxALL, 30);
  hTopPanelLayout->Add(heartsButton, 0, wxALL, 30);
  hBottomPanelLayout->Add(logoutButton, 0, wxEXPAND | wxALL, 30);
  frameGrid->Add(usersName, 0, wxALIGN_CENTRE | wxTOP, 50);
  frameGrid->Add(hTopPanelLayout, 2, wxALIGN_CENTRE | wxTOP, 120);
  frameGrid->Add(hBottomPanelLayout, 0, wxALIGN_RIGHT | wxLeft, 30);

  this->SetSizer(frameGrid);
  Centre();
}

void MainMenu::onClickC8Button(wxCommandEvent &WXUNUSED(event)) {
  FrameManager *fm = (FrameManager *)parentFrame;
  fm->switchScreens(wxT("crazyEights"));
}

void MainMenu::onClickHeartsButton(wxCommandEvent &WXUNUSED(event)) {
  std::cout << "load Hearts" << std::endl;
  FrameManager *fm = (FrameManager *)parentFrame;
  fm->switchScreens(wxT("hearts"));
}

void MainMenu::onClickLogoutButton(wxCommandEvent &WXUNUSED(event)) {

  FrameManager *fm = (FrameManager *)parentFrame;
  fm->switchScreens(wxT("login"));
}
