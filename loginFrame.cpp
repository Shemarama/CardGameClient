#include "loginFrame.h"
#include "frameManager.h"
BEGIN_EVENT_TABLE(LoginFrame, wxFrame)
EVT_BUTTON(submitButtonID, LoginFrame::onSubmit)
EVT_BUTTON(cancelButtonID, LoginFrame::onCancel)
END_EVENT_TABLE()

LoginFrame::LoginFrame(const wxString &title, wxFrame *parentFrame)
    : wxFrame(parentFrame, wxID_ANY, title, wxDefaultPosition,
              wxSize(450, 300)) {
  this->parentFrame = parentFrame;

  vLayoutSizer = new wxBoxSizer(wxVERTICAL);
  hUserNameSizer = new wxBoxSizer(wxHORIZONTAL);
  hUserPassSizer = new wxBoxSizer(wxHORIZONTAL);
  hSizerForButtons = new wxBoxSizer(wxHORIZONTAL);

  userPassText = new wxStaticText(this, wxID_ANY, "User Password: ");
  userNameText = new wxStaticText(this, wxID_ANY, "User Name:     ");
  userNameTextBox = new wxTextCtrl(this, userNameTextID, " ");
  userPassTextBox = new wxTextCtrl(this, userPassTextID, " ", wxDefaultPosition,
                                   wxDefaultSize, wxTE_PASSWORD);
  submitButton = new wxButton(this, submitButtonID, " Submit ");
  cancelButton = new wxButton(this, cancelButtonID, " Cancel ");

  hUserNameSizer->Add(userNameText, 0, wxALL, 10);
  hUserNameSizer->Add(userNameTextBox, 0, wxALL, 10);
  hUserPassSizer->Add(userPassText, 0, wxALL, 10);
  hUserPassSizer->Add(userPassTextBox, 0, wxALL, 10);

  hSizerForButtons->Add(submitButton, 0, wxALL, 30);
  hSizerForButtons->Add(cancelButton, 0, wxALL, 30);
  vLayoutSizer->Add(hUserNameSizer, 0, wxALIGN_CENTER | wxALL, 10);
  vLayoutSizer->Add(hUserPassSizer, 0, wxALIGN_CENTER | wxALL, 10);
  vLayoutSizer->Add(hSizerForButtons, 0, wxALIGN_CENTER, 10);
  this->SetSizer(vLayoutSizer);
  Centre();
}

void LoginFrame::onSubmit(wxCommandEvent &WXUNUSED(event)) {
  userName = userNameTextBox->GetLineText(0);
  userPassword = userPassTextBox->GetLineText(0);
  wxPuts(userName);
  std::cout << userName << std::endl;
  std::cout << userPassword << std::endl;

  FrameManager *fm = (FrameManager *)parentFrame;
  fm->switchScreens(wxT("main"));
  return;
}

void LoginFrame::onCancel(wxCommandEvent &WXUNUSED(event)) { Close(true); }

wxString LoginFrame::getUserName() { return userName; }
