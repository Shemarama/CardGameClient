#include "gameScreen.h"

// the wxImagePanel class is taken from
// https://wiki.wxwidgets.org/An_image_panel
class wxImagePanel : public wxPanel
{
  wxImage image;
  wxBitmap resized;
  int w, h;

public:
  wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format);

  void paintEvent(wxPaintEvent& evt);
  void paintNow();
  void OnSize(wxSizeEvent& event);
  void render(wxDC& dc);

  // some useful events
  /*
          void mouseMoved(wxMouseEvent& event);
               void mouseDown(wxMouseEvent& event);
                    void mouseWheelMoved(wxMouseEvent& event);
                         void mouseReleased(wxMouseEvent& event);
                              void rightClick(wxMouseEvent& event);
                                   void mouseLeftWindow(wxMouseEvent& event);
                                        void keyPressed(wxKeyEvent& event);
                                             void keyReleased(wxKeyEvent&
     event);
                                                  */

  DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
// some useful events
/*
    EVT_MOTION(wxImagePanel::mouseMoved)
     EVT_LEFT_DOWN(wxImagePanel::mouseDown)
      EVT_LEFT_UP(wxImagePanel::mouseReleased)
       EVT_RIGHT_DOWN(wxImagePanel::rightClick)
        EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
         EVT_KEY_DOWN(wxImagePanel::keyPressed)
          EVT_KEY_UP(wxImagePanel::keyReleased)
           EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
            */

// catch paint events
EVT_PAINT(wxImagePanel::paintEvent)
// Size event
EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

// some useful events
/*
    void wxImagePanel::mouseMoved(wxMouseEvent& event) {}
     void wxImagePanel::mouseDown(wxMouseEvent& event) {}
      void wxImagePanel::mouseWheelMoved(wxMouseEvent& event) {}
       void wxImagePanel::mouseReleased(wxMouseEvent& event) {}
        void wxImagePanel::rightClick(wxMouseEvent& event) {}
         void wxImagePanel::mouseLeftWindow(wxMouseEvent& event) {}
          void wxImagePanel::keyPressed(wxKeyEvent& event) {}
           void wxImagePanel::keyReleased(wxKeyEvent& event) {}
            */

wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format)
  : wxPanel(parent)
{
  // load the file... ideally add a check to see if loading was successful
  image.LoadFile(file, format);
  w = -1;
  h = -1;
}

/*
    * Called by the system of by wxWidgets when the panel needs
     * to be redrawn. You can also trigger this call by
      * calling Refresh()/Update().
       */

void
wxImagePanel::paintEvent(wxPaintEvent& evt)
{
  // depending on your system you may need to look at double-buffered dcs
  wxPaintDC dc(this);
  render(dc);
}

/*
    * Alternatively, you can use a clientDC to paint on the panel
     * at any time. Using this generally does not free you from
      * catching paint events, since it is possible that e.g. the window
       * manager throws away your drawing when the window comes to the
        * background, and expects you will redraw it when the window comes
         * back (by sending a paint event).
          */
void
wxImagePanel::paintNow()
{
  // depending on your system you may need to look at double-buffered dcs
  wxClientDC dc(this);
  render(dc);
}

/*
    * Here we do the actual rendering. I put it in a separate
     * method so that it can work no matter what type of DC
      * (e.g. wxPaintDC or wxClientDC) is used.
       */
void
wxImagePanel::render(wxDC& dc)
{
  int neww, newh;
  dc.GetSize(&neww, &newh);

  if (neww != w || newh != h) {
    resized = wxBitmap(image.Scale(neww, newh /*, wxIMAGE_QUALITY_HIGH*/));
    w = neww;
    h = newh;
    dc.DrawBitmap(resized, 0, 0, true);
  } else {
    dc.DrawBitmap(resized, 0, 0, true);
  }
}

/*
    * Here we call refresh to tell the panel to draw itself again.
     * So when the user resizes the image panel the image should be resized too.
      */
void
wxImagePanel::OnSize(wxSizeEvent& event)
{
  Refresh();
  // skip the event.
  event.Skip();
}

GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size)
{

  // root panel
  wxPanel* panel = new wxPanel(this, -1);

  // root panel container
  wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

  // card table
  wxImagePanel* table = new wxImagePanel(
    panel, wxT("../resources/pictures/cardtable.png"), wxBITMAP_TYPE_PNG);

  // card table horizontal container
  wxBoxSizer* tableHBox = new wxBoxSizer(wxHORIZONTAL);

  // card table vertical containers
  wxBoxSizer* tableVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableVBoxRight = new wxBoxSizer(wxVERTICAL);

  // card table containers for up, decks, and down
  wxBoxSizer* tableHBoxUp = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxDecks = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxDown = new wxBoxSizer(wxHORIZONTAL);
  
  
  // buttons for left side
  wxButton *button1 =
     new wxButton(table, wxID_EXIT, wxT("Left"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  wxButton *button2 =
     new wxButton(table, wxID_EXIT, wxT("Left"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  tableVBoxLeft->Add(button1, 1, wxTOP|wxRIGHT, 10);
  tableVBoxLeft->Add(button2, 1, wxBOTTOM|wxRIGHT, 10);

  tableVBoxLeft->SetSizeHints(table);

  
  // up
  /*wxButton *button3 =
     new wxButton(table, wxID_EXIT, wxT("Up"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  wxButton *button4 =
     new wxButton(table, wxID_EXIT, wxT("Up"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  tableHBoxUp->Add(button3, 1, wxALIGN_CENTER, 0);
  tableHBoxUp->Add(button4, 1, wxALIGN_CENTER, 0);
  */

  // up
  std::vector<wxButton*> buttons;
  int s = 4;
  for(int i=0; i<s; i++)
  {
    wxButton *btn = new wxButton(table, wxID_EXIT, wxT("Up"), wxPoint(20, 20), wxSize(30, 80));
    Connect(wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(GameScreen::OnExit));
    tableHBoxUp->Add(btn, 1, wxALIGN_CENTER, 0);
  }

  tableHBoxUp->SetSizeHints(table);

  // decks
  wxButton *button9 =
     new wxButton(table, wxID_EXIT, wxT("Decks"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  wxButton *button10 =
     new wxButton(table, wxID_EXIT, wxT("Decks"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  tableHBoxDecks->Add(button9, 1, wxALL, 10);
  tableHBoxDecks->Add(button10, 1, wxALL, 10);
  
  tableHBoxDecks->SetSizeHints(table);
  
  // down
  wxButton *button7 =
     new wxButton(table, wxID_EXIT, wxT("Down"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  wxButton *button8 =
     new wxButton(table, wxID_EXIT, wxT("Down"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  tableHBoxDown->Add(button7, 1, wxALIGN_CENTER, 0);
  tableHBoxDown->Add(button8, 1, wxALIGN_CENTER, 0);
  
  tableHBoxDown->SetSizeHints(table);

  tableVBoxMid->Add(tableHBoxUp, 1, wxEXPAND, 0);
  tableVBoxMid->Add(tableHBoxDecks, 2, wxEXPAND, 0);
  tableVBoxMid->Add(tableHBoxDown, 1, wxEXPAND, 0);

  tableVBoxMid->SetSizeHints(table);

  
  // buttons for right side
  wxButton *button5 =
     new wxButton(table, wxID_EXIT, wxT("Right"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  wxButton *button6 =
     new wxButton(table, wxID_EXIT, wxT("Right"), wxPoint(20, 20));
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));

  tableVBoxRight->Add(button5, 1, wxTOP|wxLEFT, 10);
  tableVBoxRight->Add(button6, 1, wxBOTTOM|wxLEFT, 10);

  tableVBoxRight->SetSizeHints(table);

  tableHBox->Add(tableVBoxLeft, 1, wxEXPAND|wxALL, 10);
  tableHBox->Add(tableVBoxMid, 2, wxEXPAND|wxALL, 10);
  tableHBox->Add(tableVBoxRight, 1, wxEXPAND|wxALL, 10);

  tableHBox->SetSizeHints(table);

  

  //wxGridBagSizer* gbs = new wxGridBagSizer(3, 3);
  //gbs->SetEmptyCellSize(wxSize(10, 20));

  // wxButton *button =
  //    new wxButton(table, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
  // Connect(wxEVT_COMMAND_BUTTON_CLICKED,
  //        wxCommandEventHandler(GameScreen::OnExit));
  // gbs->Add(button, wxGBPosition(6, 6), wxGBSpan(1, 1), wxALIGN_CENTER, 50);

  // table->SetOwnBackgroundColour(wxColour(0, 0, 0, 1));
  table->SetSizer(tableHBox);

  hbox->Add(table, 1, wxALL | wxEXPAND, 140);
  hbox->SetSizeHints(panel);
  panel->SetSizer(hbox);
  // panel->SetOwnBackgroundColour(wxColour(0,0,0,1));

  // CreateStatusBar();
  Centre();
}

void
GameScreen::OnExit(wxCommandEvent& event)
{
  // true forces quit
  Close(true);
}

void
GameScreen::OnAbout(wxCommandEvent& event)
{
  // pop up window
  // body text, title, icons
  wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void
GameScreen::OnHello(wxCommandEvent& event)
{
  // pop up window with message
  wxLogMessage("Hello world from wxWidgets!");
}

// maps unique identifiers to event handlers
wxBEGIN_EVENT_TABLE(GameScreen, wxFrame) EVT_MENU(ID_Hello, GameScreen::OnHello)
  EVT_MENU(wxID_EXIT, GameScreen::OnExit)
    EVT_MENU(wxID_ABOUT, GameScreen::OnAbout) wxEND_EVENT_TABLE()
