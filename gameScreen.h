#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/gbsizer.h>
#include <wx/colour.h>
#include <wx/sizer.h>
#include <vector>
#include <wx/button.h>

class GameScreen : public wxFrame
{

// main window
public:
  GameScreen(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
  const int cardWidth = 70;
  const int cardHeight = 98;
  const int cardHalfWidth = 25;
  const int cardHalfHeight = 98;
  
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
