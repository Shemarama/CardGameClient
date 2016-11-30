#include "suitDialog.h"

SuitDialog::SuitDialog(const wxString &title)
    : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230)) {

  panel = new wxPanel(this, -1);

  vbox = new wxBoxSizer(wxVERTICAL);
  hbox = new wxBoxSizer(wxHORIZONTAL);

  st = new wxStaticBox(panel, -1, wxT("Suit Choices"), wxPoint(5, 5),
                       wxSize(240, 150));
  rbHearts = new wxRadioButton(panel, wxID_ANY, wxT("Hearts"), wxPoint(15, 30),
                               wxDefaultSize, wxRB_GROUP);

  rbSpades = new wxRadioButton(panel, wxID_ANY, wxT("Spades"), wxPoint(15, 55));
  rbDiamonds =
      new wxRadioButton(panel, wxID_ANY, wxT("Diamonds"), wxPoint(15, 80));
  rbClubs = new wxRadioButton(panel, wxID_ANY, wxT("Clubs"), wxPoint(15, 105));

  okButton =
      new wxButton(this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxSize(70, 30));
  closeButton = new wxButton(this, wxID_CANCEL, wxT("Close"), wxDefaultPosition,
                             wxSize(70, 30));

  hbox->Add(okButton, 1);
  hbox->Add(closeButton, 1, wxLEFT, 5);

  vbox->Add(panel, 1);
  vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

  SetSizer(vbox);

  Centre();
  // ShowModal();

  // Destroy();
}

Suit SuitDialog::getSuit() {
  if (rbHearts->GetValue())
    return Suit::HEARTS;
  else if (rbSpades->GetValue())
    return Suit::SPADES;
  else if (rbDiamonds->GetValue())
    return Suit::DIAMONDS;
  else if (rbClubs->GetValue())
    return Suit::CLUBS;
  else
    return Suit::HEARTS;
}
