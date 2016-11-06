// wxWidgets "Hello world" Program

// For compilers that support precompilation, includes "wx/wx.h".

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include"gameScreen.h"


// main app that uses main window
class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};


  // the main function and it starts MyApp via OnInit()
  wxIMPLEMENT_APP(MyApp);

bool
MyApp::OnInit()
{
  wxInitAllImageHandlers();
  GameScreen* frame =
    //new GameScreen("Card Game", wxPoint(50, 50), wxSize(1080, 680));
    new GameScreen("Card Game", wxPoint(50, 50), wxSize(1080, 720));
  frame->Show(true);
  return true;
}

