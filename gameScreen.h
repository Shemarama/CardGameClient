#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "card.h"
#include "cardPanel.h"
#include "imagePanel.h"
#include "crazyEights.h"
#include "player.h"
#include <wx/gbsizer.h>
#include <wx/colour.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <vector>

class GameScreen : public wxFrame
{

// main window
public:
  GameScreen(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
  // event handlers
  void OnHello(wxCommandEvent& event);
  void OnExit(wxMouseEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  // so the window can respond to events
  wxDECLARE_EVENT_TABLE();
};

// give commands unique identifiers
enum
{
  ID_Hello = 1
};


#endif
