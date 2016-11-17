#ifndef FRAMEMANAGER_H
#define FRAMEMANAGER_H
#include<wx/wx.h>
#include"loginFrame.h"
#include"mainMenu.h"
#include"gameScreen.h"
class FrameManager : public wxFrame
{
private:
    LoginFrame* loginFrame;
    MainMenu*  mainMenu;
    wxFrame* currentFrame;    


public:

FrameManager(); //want to initialize the first screen to be the login Screen
void switchScreens(wxString newScreen);  // "login" "main" "game"
wxFrame* getCurrentFrame();
};
#endif


