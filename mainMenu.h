#ifndef MAINMENU_H
#define MAINMENU_H
#include <wx/wx.h>
class MainMenu : public wxFrame {

private:
  wxButton *crazyEightsButton;
  wxButton *heartsButton;
  wxButton *logoutButton;
  wxStaticText *usersName;
  wxStaticText *usersWins;
  wxStaticText *usersLosses;
  wxStaticText *usersWLratio;

  wxFrame *parentFrame;

  // All of the sizers for the window
  wxBoxSizer *frameGrid;
  // wxBoxSizer* hWindowLayout;
  wxBoxSizer *hTopPanelLayout;
  wxBoxSizer *hBottomPanelLayout;

public:
  MainMenu(const wxString &title, wxFrame *parentFrame,
           wxString currentUserName);
  void onClickC8Button(wxCommandEvent &event);
  void onClickHeartsButton(wxCommandEvent &event);
  void onClickLogoutButton(wxCommandEvent &event);
  DECLARE_EVENT_TABLE();
};

enum { crazyEightsButtonID = 1, heartsButtonID = 2, logoutButtonID = 3 };
#endif
