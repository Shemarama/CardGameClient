#ifndef LOGINFRAME_H
#define LOGINFRAME_H
#include <wx/wx.h>
class LoginFrame : public wxFrame {
private:
  wxButton *submitButton;
  wxButton *cancelButton;

  wxString userName;
  wxString userPassword;
  wxStaticText *userNameText; // static label that prompts the user to enter
                              // name
  wxStaticText
      *userPassText; // static label that prompts the user to enter password
  wxTextCtrl *userNameTextBox;
  wxTextCtrl *userPassTextBox;

  wxBoxSizer *vLayoutSizer;   // vertical parent sizer to hold the userName row,
                              // userPassword row and submit row
  wxBoxSizer *hUserNameSizer; // sizer in charge of the static text, txtctrl box
                              // for user entering name
  wxBoxSizer *hUserPassSizer; // sizer in charge of the static text, txtctrl box
                              // for user entering password
  wxBoxSizer *hSizerForButtons; // sizer for the submit and cancel buttons

  wxFrame *parentFrame;

public:
  LoginFrame(const wxString &title, wxFrame *parentFrame);
  void onSubmit(wxCommandEvent &event);
  void onCancel(wxCommandEvent &event);
  wxString getUserName();
  DECLARE_EVENT_TABLE();
};

enum {
  submitButtonID = 4,
  cancelButtonID = 5,
  userNameTextID = 6,
  userPassTextID = 7
};
#endif
