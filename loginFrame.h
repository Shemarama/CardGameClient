#ifndef LOGINFRAME_H
#define LOGINFRAME_H
#include<wx/wx.h>
class LoginFrame : public wxFrame
{
    private:
       wxButton* submitButton;
       wxButton* cancelButton;

       wxString userName;
       wxString userPassword;
       wxStaticText*  userNameText; //static lable that prompts the user to enter name
       wxStaticText*  userPassText; //static lable that promt the user to enter password
      wxTextCtrl*  userNameTextBox; 
      wxTextCtrl*  userPassTextBox;

      wxBoxSizer*  vLayoutSizer; // vertical parent sizer where I will place the userName row, userPassword row and submit row
      wxBoxSizer* hUserNameSizer; // sizer in charge of the static text, txtctrl box for user entering name
      wxBoxSizer* hUserPassSizer; // sizer in charge of the static text, txtctrl box for user entering password
      wxBoxSizer* hSizerForButtons; // sizer for the submit and cancel buttons

     wxFrame* parentFrame;
public:
       LoginFrame(const wxString& title, wxFrame* parentFrame);
       void onSubmit(wxCommandEvent& event);
       void onCancel(wxCommandEvent& event);
       wxString getUserName();
      DECLARE_EVENT_TABLE();

};

enum
{
    submitButtonID = wxID_HIGHEST + 1,
    cancelButtonID = submitButtonID + 1,
    userNameTextID = cancelButtonID + 1,
    userPassTextID = cancelButtonID + 1
    



};
#endif
