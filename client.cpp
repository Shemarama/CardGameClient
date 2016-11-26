// wxWidgets "Hello world" Program

// For compilers that support precompilation, includes "wx/wx.h".

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "frameManager.h"

// main app that uses main window
class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

// the main function and it starts MyApp via OnInit()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {

  FrameManager *frameManager = new FrameManager();
  frameManager->getCurrentFrame()->Show(true);

  wxInitAllImageHandlers();
  return true;
}
