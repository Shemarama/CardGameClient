#include "gameScreen.h"




// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{

  // root panel
  wxPanel* panel = new wxPanel(this, -1);

  // root panel container
  wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

  // card table
  wxImagePanel* table = new wxImagePanel(
    panel, wxT("../resources/pictures/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP);

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
  std::vector<Card*> leftPlayerHand;
  int s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardWidth, cardHeight);
    else
      btn = new Card(
        table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardHalfWidth, cardHalfHeight);
      
    leftPlayerHand.push_back(btn);
  }

  for(int i=0; i<leftPlayerHand.size(); i++)
  {
    tableVBoxLeft->Add(leftPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
  }

  tableVBoxLeft->SetSizeHints(table);

  
  // up
  std::vector<Card*> topPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == 0)
      btn = new Card(
        table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardWidth, cardHeight);
    else
      btn = new Card(
        table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardHalfWidth, cardHalfHeight);
      
    topPlayerHand.push_back(btn);
  }

  for(int i=0; i<topPlayerHand.size(); i++)
  {
    tableHBoxUp->Add(topPlayerHand[i], 1, wxEXPAND, 0);
  }
  

  tableHBoxUp->SetSizeHints(table);

  // decks
  
  Card *button9 = new Card(
    table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  
  Connect(wxEVT_COMMAND_BUTTON_CLICKED,
         wxCommandEventHandler(GameScreen::OnExit));
  
  Card *button10 = new Card(
    table, Suit::HEARTS, 14, wxT("../resources/pictures/cards/cardHeartA.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Connect(wxEVT_LEFT_UP,
         wxMouseEventHandler(Card::mouseReleased));

  tableHBoxDecks->Add(button9, 1, wxALL|wxEXPAND, 20);
  tableHBoxDecks->Add(button10, 1, wxALL|wxEXPAND, 20);
  
  tableHBoxDecks->SetSizeHints(table);
  
  // down
  std::vector<Card*> bottomPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::SPADES, 7, wxT("../resources/pictures/cards/cardSpade7.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
    else
      btn = new Card(
        table, Suit::DIAMONDS, 2, wxT("../resources/pictures/cards/cardDiamond2Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);
    
    bottomPlayerHand.push_back(btn);
  }

  for(int i=0; i<bottomPlayerHand.size(); i++)
  {
    tableHBoxDown->Add(bottomPlayerHand[i], 1, wxEXPAND, 0);
  }
  
  tableHBoxDown->SetSizeHints(table);

  tableVBoxMid->Add(tableHBoxUp, 1, wxEXPAND|wxALL, 5);
  tableVBoxMid->Add(tableHBoxDecks, 2, wxEXPAND|wxALL, 5);
  tableVBoxMid->Add(tableHBoxDown, 1, wxEXPAND|wxALL, 5);

  tableVBoxMid->SetSizeHints(table);

  
  // buttons for right side
  std::vector<Card*> rightPlayerHand;
  s = 10;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == 0)
      btn = new Card(table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardWidth, cardHeight);
    else
      btn = new Card(table, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardHalfWidth, cardHalfHeight);
      
    rightPlayerHand.push_back(btn);
  }

  for(int i=0; i<rightPlayerHand.size(); i++)
  {
    tableVBoxRight->Add(rightPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
  }

  tableVBoxRight->SetSizeHints(table);

  tableHBox->Add(tableVBoxLeft, 1, wxEXPAND|wxALL, 0);
  tableHBox->Add(tableVBoxMid, 2, wxEXPAND|wxALL, 0);
  tableHBox->Add(tableVBoxRight, 1, wxEXPAND|wxALL, 0);

  tableHBox->SetSizeHints(table);

  table->SetSizer(tableHBox);

  hbox->Add(table, 1, wxALL | wxEXPAND, 50);
  hbox->SetSizeHints(panel);
  panel->SetSizer(hbox);
  
  Centre();
}

void
GameScreen::OnExit(wxMouseEvent& event)
{
  // true forces quit
  std::cout << "clicked exit\n";
  Close(true);
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
