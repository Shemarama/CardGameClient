#include "client.h"

// the main function and it starts MyApp via OnInit()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {

  wxInitAllImageHandlers();
  frameManager = new FrameManager();

  return true;
}
