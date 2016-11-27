#include "frameManager.h"
#include <wx/app.h>

FrameManager::FrameManager() {
  loginFrame = nullptr;
  mainMenu = nullptr;
  crazyEightsScreen = nullptr;
  heartsScreen = nullptr;
  currentFrame = nullptr;
  switchScreens(wxT("login"));
}

void FrameManager::switchScreens(wxString newScreen) {
  wxFrame *oldFrame = currentFrame;
  if (newScreen == "login") {
    loginFrame = new LoginFrame("Please Log In ", this);
    currentFrame = loginFrame;
    ((LoginFrame *)currentFrame)->Show(true);
  }

  else if (newScreen == "main") {
    mainMenu = new MainMenu("Main Menu", this, "current User");
    currentFrame = mainMenu;
    ((MainMenu *)currentFrame)->Show(true);
  }

  else if (newScreen == "crazyEights") {
    crazyEightsScreen = new CrazyEightsScreen(
        "Crazy Eights", this, wxPoint(50, 50), wxSize(1080, 720));
    currentFrame = crazyEightsScreen;
    ((CrazyEightsScreen *)currentFrame)->Show(true);
  } else if (newScreen == "hearts") {
    heartsScreen =
        new HeartsScreen("Hearts", this, wxPoint(50, 50), wxSize(1080, 720));
    currentFrame = heartsScreen;
    ((HeartsScreen *)currentFrame)->Show(true);
  }
  if (oldFrame != nullptr)
    oldFrame->Destroy();
}

wxFrame *FrameManager::getCurrentFrame() { return currentFrame; }
