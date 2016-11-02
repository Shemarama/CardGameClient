#include "gameScreen.h"


// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX)
{

  // root panel
  wxPanel* rootPanel = new wxPanel(this, -1);

  // root horizontal container
  wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

  // root vertical containers
  wxBoxSizer* rootVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootVBoxRight = new wxBoxSizer(wxVERTICAL);

  // root table containers for top player, card table, and bottom player
  wxBoxSizer* rootHBoxUp = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxTable = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxDown = new wxBoxSizer(wxHORIZONTAL);

  // card table
  wxImagePanel* table = new wxImagePanel(
    rootPanel, wxT("../resources/pictures/table/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP);

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

  wxBoxSizer* leftBox = new wxBoxSizer(wxVERTICAL);
  
  for(unsigned int i=0; i<leftPlayerHand.size(); i++)
  {
    //tableVBoxLeft->Add(leftPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
    //tableVBoxLeft->Add(leftPlayerHand[i], 0, wxALIGN_CENTER, 0);
    leftBox->Add(leftPlayerHand[i], 0, wxALIGN_CENTER, 0);
  }

  tableVBoxLeft->Add(leftBox, 0, wxALL, 20);

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

  wxBoxSizer* upBox = new wxBoxSizer(wxHORIZONTAL);

  for(unsigned int i=0; i<topPlayerHand.size(); i++)
  {
    //tableHBoxUp->Add(topPlayerHand[i], 1, wxEXPAND, 0);
    //tableHBoxUp->Add(topPlayerHand[i], 0, wxALIGN_CENTER, 0);
    upBox->Add(topPlayerHand[i], 0, wxALIGN_CENTER, 0);
  }
  
  tableHBoxUp->Add(upBox, 0, wxALL, 20);

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

  wxBoxSizer* deckBox = new wxBoxSizer(wxHORIZONTAL);
  //tableHBoxDecks->Add(button9, 0, wxALL, 20);
  //tableHBoxDecks->Add(button10, 0, wxALL, 20);
  deckBox->Add(button9, 0, wxALL, 20);
  deckBox->Add(button10, 0, wxALL, 20);

  tableHBoxDecks->Add(deckBox, 0, wxALL, 20);
  
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

  wxBoxSizer* downBox = new wxBoxSizer(wxHORIZONTAL);

  for(unsigned int i=0; i<bottomPlayerHand.size(); i++)
  {
    //tableHBoxDown->Add(bottomPlayerHand[i], 1, wxEXPAND, 0);
    //tableHBoxDown->Add(bottomPlayerHand[i], 0, wxALIGN_CENTER, 0);
    downBox->Add(bottomPlayerHand[i], 0, wxALIGN_CENTER, 0);
  }

  tableHBoxDown->Add(downBox, 0, wxALL, 20);
  
  tableHBoxDown->SetSizeHints(table);

  tableVBoxMid->Add(tableHBoxUp, 0, wxALL | wxEXPAND, 5);
  tableVBoxMid->Add(tableHBoxDecks, 0, wxALL | wxEXPAND, 5);
  tableVBoxMid->Add(tableHBoxDown, 0, wxALL | wxEXPAND, 5);

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

  wxBoxSizer* rightBox = new wxBoxSizer(wxVERTICAL);

  for(unsigned int i=0; i<rightPlayerHand.size(); i++)
  {
    //tableVBoxRight->Add(rightPlayerHand[i], 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 10);
    //tableVBoxRight->Add(rightPlayerHand[i], 0, wxALIGN_CENTER, 0);
    rightBox->Add(rightPlayerHand[i], 0, wxALIGN_CENTER, 0);
  }

  tableVBoxRight->Add(rightBox, 0, wxALL, 20);

  tableVBoxRight->SetSizeHints(table);

  tableHBox->Add(tableVBoxLeft, 1, wxEXPAND, 10);
  tableHBox->Add(tableVBoxMid, 2, wxEXPAND, 10);
  tableHBox->Add(tableVBoxRight, 1, wxEXPAND, 10);

  tableHBox->SetSizeHints(table);

  table->SetSizer(tableHBox);

  
  Card *button11 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button12 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button13 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button14 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);

  rootVBoxLeft->Add(button11, 0, wxLEFT, 10);
  rootHBoxUp->Add(button13, 0, wxALL|wxEXPAND, 10);
  rootHBoxTable->Add(table, 0, wxALL|wxEXPAND, 10);
  rootHBoxDown->Add(button14, 0, wxBOTTOM, 10);
  rootVBoxRight->Add(button12, 0, wxRIGHT, 10);

  //hbox->Add(table, 0, wxALL, 50);
  rootVBoxMid->Add(rootHBoxUp, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 10);
  rootVBoxMid->Add(rootHBoxTable, 2, wxEXPAND|wxLEFT|wxRIGHT, 10);
  rootVBoxMid->Add(rootHBoxDown, 1, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 10);

  hbox->Add(rootVBoxLeft, 1, wxEXPAND, 10);
  hbox->Add(rootVBoxMid, 2, wxEXPAND, 10);
  hbox->Add(rootVBoxRight, 1, wxEXPAND, 10);


  hbox->SetSizeHints(rootPanel);
  rootPanel->SetSizer(hbox);
  //table->SetBackgroundColour(wxColour(203,71,255));
  //rootPanel->SetBackgroundColour(wxColour(203,71,255));
  table->SetBackgroundColour(wxColour(136,20,11));
  rootPanel->SetBackgroundColour(wxColour(136,20,11));
  
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
