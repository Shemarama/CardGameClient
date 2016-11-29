#ifndef FRAMEMANAGER_H
#define FRAMEMANAGER_H
#include "crazyEightsScreen.h"
#include "heartsScreen.h"
#include "loginFrame.h"
#include "mainMenu.h"
#include <wx/wx.h>

class FrameManager : public wxFrame {
private:
  LoginFrame *loginFrame;
  MainMenu *mainMenu;
  CrazyEightsScreen *crazyEightsScreen;
  HeartsScreen *heartsScreen;
  wxFrame *currentFrame;

public:
  FrameManager(); // want to initialize the first screen to be the login Screen
  void switchScreens(wxString newScreen); // to switch between screens
  wxFrame *getCurrentFrame();
};
#endif
