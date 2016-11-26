#include <wx/wx.h>
#include "card.h"

class SuitDialog : public wxDialog
{
  private:
    wxPanel *panel;
    wxBoxSizer *vbox;
    wxBoxSizer *hbox;
    wxStaticBox *st;
    wxRadioButton *rbHearts;
    wxRadioButton *rbSpades;
    wxRadioButton *rbDiamonds;
    wxRadioButton *rbClubs;
    wxButton *okButton;
    wxButton *closeButton;
  public:
    SuitDialog(const wxString& title);
    Suit getSuit();
};
