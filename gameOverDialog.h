#ifndef GAME_OVER_DIALOG_H
#define GAME_OVER_DIALOG_H
#include "card.h"
#include <wx/wx.h>

class GameOverDialog : public wxDialog {
private:
  wxPanel *panel;
  wxBoxSizer *vbox;
  wxBoxSizer *hbox1;
  wxBoxSizer *hbox;
  
  wxStaticText *messageText;
  wxButton *playAgainButton;
  wxButton *mainMenuButton;

public:
  GameOverDialog(const wxString &title, wxString message);
};
#endif
