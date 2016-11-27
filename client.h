// wxWidgets "Hello world" Program

// For compilers that support precompilation, includes "wx/wx.h".
#ifndef CLIENT_H
#define CLIENT_H
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
#endif
