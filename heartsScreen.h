#ifndef HEARTS_SCREEN_H
#define HEARTS_SCREEN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "cardPanel.h"
#include "crazyEights.h"
#include "suitDialog.h"

class HeartsScreen : public wxFrame {

  // main window
public:
  HeartsScreen(const wxString &title, wxFrame *parent, const wxPoint &pos,
               const wxSize &size, wxString playerName);
  void updateTable();
  void updatePlayerInfo();
  CardPanel *makeCard(wxPanel *parent, Card &card, bool show, Direction dir,
                      bool isHalf);
  wxString findHalfImage(Card &card, bool show);
  wxString findFullImage(Card &card, bool show);
  void displaySuitChoice();
  bool onClick(Card card);

private:
  wxFrame *parentFrame;
  // card image width and height
  const int cardWidth = 70;
  const int cardHeight = 98;
  const int cardHalfWidth = 25;
  const int cardHalfHeight = 98;

  // root and table panels
  wxPanel *rootPanel;
  wxBoxSizer *rootHBox;
  wxImagePanel *table;
  wxBoxSizer *tableHBox;

  // table sizers
  wxBoxSizer *tableVBoxLeft;
  wxBoxSizer *tableHBoxLeftTop;
  wxBoxSizer *tableHBoxLeftMid;
  wxBoxSizer *tableHBoxLeftBot;

  wxBoxSizer *tableVBoxMid;
  wxBoxSizer *tableHBoxMidTop;
  wxBoxSizer *tableVBoxMidMid;
  wxBoxSizer *tableHBoxMidMid;
  wxBoxSizer *tableHBoxMidBot;

  wxBoxSizer *tableVBoxRight;
  wxBoxSizer *tableHBoxRightTop;
  wxBoxSizer *tableHBoxRightMid;
  wxBoxSizer *tableHBoxRightBot;

  // root sizers
  wxBoxSizer *rootVBoxLeft;
  wxBoxSizer *rootHBoxLeftTop;
  wxBoxSizer *rootHBoxLeftMid;
  wxBoxSizer *rootHBoxLeftBot;

  wxBoxSizer *rootVBoxMid;
  wxBoxSizer *rootHBoxMidTop;
  wxBoxSizer *rootVBoxMidMid;
  wxBoxSizer *rootHBoxMidMid;
  wxBoxSizer *rootHBoxMidBot;

  wxBoxSizer *rootVBoxRight;
  wxBoxSizer *rootHBoxRightTop;
  wxBoxSizer *rootHBoxRightMid;
  wxBoxSizer *rootHBoxRightBot;

  // players
  std::vector<Player *> players;

  // player panels
  std::vector<wxPanel *> playerHandPanels;
  std::vector<wxBoxSizer *> playerHandSizers;
  std::vector<wxPanel *> playerInfoPanels;
  std::vector<wxBoxSizer *> playerInfoSizers;
  std::vector<wxImagePanel *> playerImagePanels;
  std::vector<wxStaticText *> playerNames;
  std::vector<wxButton *> playerReadyButtons;

  // game logic
  CrazyEights crazyEights = CrazyEights(players);

  // player name
  wxString playerName;
  // draw and discard panels
  wxPanel *drawPilePanel;
  wxPanel *discardPilePanel;
  wxBoxSizer *drawPileSizer;
  wxBoxSizer *discardPileSizer;
  // event handlers

  void OnExit(wxCommandEvent &event);

  // so the window can respond to events
  // wxDECLARE_EVENT_TABLE();
};

// give commands unique identifiers
/*enum TEST {
  ID_Hello = 1,
};
*/

#endif
