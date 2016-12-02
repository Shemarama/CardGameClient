#include "gameOverDialog.h"

GameOverDialog::GameOverDialog(const wxString &title, wxString message)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230)) {

  panel = new wxPanel(this, -1);

  vbox = new wxBoxSizer(wxVERTICAL);
  hbox1 = new wxBoxSizer(wxHORIZONTAL);
  hbox = new wxBoxSizer(wxHORIZONTAL);

  messageText = new wxStaticText(panel, wxID_ANY, message, wxPoint(0,0), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

  playAgainButton =
      new wxButton(this, wxID_OK, wxT("Play Again"), wxDefaultPosition, wxSize(100, 40));
  mainMenuButton = new wxButton(this, wxID_CANCEL, wxT("Main Menu"), wxDefaultPosition,
                             wxSize(100, 40));

  hbox->Add(playAgainButton, 1);
  hbox->Add(mainMenuButton, 1, wxLEFT, 5);

  hbox1->Add(panel, 2, wxALIGN_CENTER | wxALL, 5);
  vbox->Add(hbox1, 2, wxALIGN_CENTER | wxALL, 5);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

  SetSizer(vbox);

  Centre();
}
