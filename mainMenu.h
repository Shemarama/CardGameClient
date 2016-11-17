#ifndef MAINMENU_H
#define MAINMENU_H
#include<wx/wx.h>
class MainMenu : public wxFrame
{
    
private:

    wxButton* crazyEightsButton;
    wxButton* heartsButton;
    wxButton* logoutButton;
    wxStaticText* usersName;
    wxStaticText* usersWins;
    wxStaticText* usersLosses;
    wxStaticText* usersWLratio;
    //wxImagePanel* playerImage;
   
    wxFrame* parentFrame;
 
//All of the sizers for the window 
    wxBoxSizer* frameGrid;
    //wxBoxSizer* hWindowLayout;
    wxBoxSizer* hTopPanelLayout;
    wxBoxSizer* hBottomPanelLayout;
public:
    MainMenu(const wxString& title, wxFrame* parentFrame, wxString currentUserName);
    void onClickC8Button(wxCommandEvent& event);
    void onClickHeartsButton(wxCommandEvent& event);
    void onClickLogoutButton(wxCommandEvent& event);
   /* wxString* getUsersName();
    wxString* getUsersWins();
    wxString* getUsersLosses();
    wxString* getUsersWLratio();*/
    DECLARE_EVENT_TABLE();
    
};

enum
{
    crazyEightsButtonID = wxID_HIGHEST + 1,
    heartsButtonID = crazyEightsButtonID + 1,
    logoutButtonID = heartsButtonID + 1
};
#endif
