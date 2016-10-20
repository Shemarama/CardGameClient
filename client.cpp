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
  GameScreen* frame =
    new GameScreen("Hello World", wxPoint(50, 50), wxSize(450, 340));
  frame->Show(true);
  return true;
}

