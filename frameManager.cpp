#include "frameManager.h"
#include <wx/app.h>

FrameManager::FrameManager() {
  currentFrame = new LoginFrame("Please Log In", this);
}

void FrameManager::switchScreens(wxString newScreen) {
  wxFrame *oldFrame = currentFrame;
  if (newScreen == "login") {
    loginFrame = new LoginFrame("Please Log In ", this);
    currentFrame = loginFrame;
  }

  else if (newScreen == "main") {
    mainMenu = new MainMenu("Main Menu", this, "current User");
    currentFrame = mainMenu;
  }

  else if (newScreen == "crazyEights") {
    // load the game board
    crazyEightsScreen = new CrazyEightsScreen(
        "Crazy Eights", this, wxPoint(50, 50), wxSize(1080, 720));
    currentFrame = crazyEightsScreen;
    // frame->Show(true);
  } else if (newScreen == "hearts") {
    // load the game board
    heartsScreen =
        new HeartsScreen("Hearts", this, wxPoint(50, 50), wxSize(1080, 720));
    currentFrame = heartsScreen;
    // frame->Show(true);
  }
  this->currentFrame->Show(true);
  oldFrame->Destroy();
}

wxFrame *FrameManager::getCurrentFrame() { return currentFrame; }
