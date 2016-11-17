#include "mainMenu.h"
#include"frameManager.h"
BEGIN_EVENT_TABLE(MainMenu,wxFrame)
    EVT_BUTTON(crazyEightsButtonID,MainMenu::onClickC8Button)
    EVT_BUTTON(heartsButtonID,MainMenu::onClickHeartsButton)
    EVT_BUTTON(logoutButtonID,MainMenu::onClickLogoutButton)
END_EVENT_TABLE()


MainMenu::MainMenu(const wxString& title, wxFrame* parentFrame, wxString currentUserName) 
                    : wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(500,500))
{
   usersName = new wxStaticText(this, wxID_ANY, currentUserName); 
   this->parentFrame = parentFrame;
   this->SetBackgroundColour((wxColour(0,65,225))); 
   //hWindowLayout = new wxBoxSizer(wxHORIZONTAL);
   hTopPanelLayout = new wxBoxSizer(wxHORIZONTAL);
   hBottomPanelLayout = new wxBoxSizer(wxHORIZONTAL);
   frameGrid = new wxBoxSizer(wxVERTICAL);

  
  crazyEightsButton = new wxButton(this,crazyEightsButtonID,wxT("Play Crazy Eights"));
  heartsButton = new wxButton(this, heartsButtonID, wxT("Play Hearts"));
  logoutButton = new wxButton(this, logoutButtonID, wxT("Logout")); 

    
  hTopPanelLayout->Add(crazyEightsButton,0 , wxEXPAND | wxALL, 30);
  hTopPanelLayout->Add(heartsButton, 0,wxEXPAND | wxALL, 30);
  hBottomPanelLayout->Add(logoutButton, 0,wxEXPAND | wxALL, 30);
  frameGrid->Add(usersName, 0, wxALIGN_CENTRE ,0);
  frameGrid->Add(hTopPanelLayout, 2,  wxALIGN_CENTRE| wxRight, 30);
  frameGrid->Add(hBottomPanelLayout, 0,  wxALIGN_RIGHT | wxLeft, 30);
    
  this->SetSizer(frameGrid);
  Centre();
//   this->playerImage = new wxImagePanel(playerInfoPanel,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP, 55, 55); 

}

void MainMenu::onClickC8Button(wxCommandEvent& event)
{
    FrameManager* fm = (FrameManager*) parentFrame;
  fm->switchScreens(wxT("crazyEights"));
}

void MainMenu::onClickHeartsButton(wxCommandEvent& event)
{
  std::cout << "load Hearts" << std::endl;

}

void MainMenu::onClickLogoutButton(wxCommandEvent& event)
{

  FrameManager* fm =  (FrameManager*) parentFrame;
  fm ->switchScreens(wxT("login"));
}
/*
wxString* MainMenu::getUsersName()
{
return usersName;
}

wxString* MainMenu::getUsersWins()
{
  return usersWins;
}

wxString* MainMenu::getUsersLosses()
{
  return usersLosses;
}

wxString* MainMenu::getUsersWLratio()
{
  return usersWLratio;
}*/ 
