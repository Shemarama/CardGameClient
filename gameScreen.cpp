#include "gameScreen.h"


// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX)
{
  // root panel
  wxPanel* rootPanel = new wxPanel(this, -1);
  wxBoxSizer* rootHBox = new wxBoxSizer(wxHORIZONTAL);
  
  // card table
  wxImagePanel* table = new wxImagePanel(
    rootPanel, wxT("../resources/pictures/table/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP, 760, 480);
  
  // sizers for table
  wxBoxSizer* tableHBox = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableVBoxMidMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxRight = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  // sizers for root panel
  wxBoxSizer* rootVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* rootVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootVBoxMidMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* rootVBoxRight = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  // create players
  std::vector<Player> players;
  players.push_back(Player(table, rootPanel, wxT("Ryan"), Direction::DOWN));
  players.push_back(Player(table, rootPanel, wxT("Cameron"), Direction::LEFT));
  players.push_back(Player(table, rootPanel, wxT("Nick"), Direction::UP));
  players.push_back(Player(table, rootPanel, wxT("Shem"), Direction::RIGHT));
  // create game logic
  CrazyEights crazyEights = CrazyEights(players, table, table);
  
  // table left
  tableHBoxLeftMid->Add(players[1].getHandPanel(), 0, wxALL|wxALIGN_CENTER, 0);
  tableVBoxLeft->Add(tableHBoxLeftTop, 1, wxALL|wxEXPAND, 0);
  tableVBoxLeft->Add(tableHBoxLeftMid, 1, wxALL|wxALIGN_CENTER, 0);
  tableVBoxLeft->Add(tableHBoxLeftBot, 1, wxALL|wxEXPAND, 0);
  
  // table middle
  tableHBoxMidTop->Add(players[2].getHandPanel(), 0, wxALL|wxALIGN_CENTER, 0);
  tableHBoxMidMid->Add(crazyEights.getDrawPilePanel(), 0, wxRIGHT|wxALIGN_CENTER, 5);
  tableHBoxMidMid->Add(crazyEights.getDiscardPilePanel(), 0, wxLEFT|wxALIGN_CENTER, 5);
  tableVBoxMidMid->Add(tableHBoxMidMid, 0, wxALL|wxALIGN_CENTER, 5);
  tableHBoxMidBot->Add(players[0].getHandPanel(), 0, wxALL|wxALIGN_CENTER, 0);
  tableVBoxMid->Add(tableHBoxMidTop, 1, wxALL|wxALIGN_CENTER, 0);
  tableVBoxMid->Add(tableVBoxMidMid, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  tableVBoxMid->Add(tableHBoxMidBot, 1, wxALL|wxALIGN_CENTER, 0);
  
  // table right
  tableHBoxRightMid->Add(players[3].getHandPanel(), 0, wxALL|wxALIGN_CENTER, 0);
  tableVBoxRight->Add(tableHBoxRightTop, 1, wxALL|wxEXPAND, 0);
  tableVBoxRight->Add(tableHBoxRightMid, 1, wxALL|wxALIGN_CENTER, 0);
  tableVBoxRight->Add(tableHBoxRightBot, 1, wxALL|wxEXPAND, 0);

  // table columns
  tableHBox->Add(tableVBoxLeft, 1, wxALL|wxEXPAND, 10);
  tableHBox->Add(tableVBoxMid, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  tableHBox->Add(tableVBoxRight, 1, wxALL|wxEXPAND, 10);

  tableHBox->SetSizeHints(table);
  table->SetSizer(tableHBox);
  
  // root left
  rootHBoxLeftTop->AddSpacer(50);
  rootHBoxLeftMid->Add(players[1].getInfoPanel(), 1, wxALL|wxALIGN_CENTER, 0);
  rootHBoxLeftBot->AddSpacer(50);
  rootVBoxLeft->Add(rootHBoxLeftTop, 1, wxALL|wxEXPAND, 0);
  rootVBoxLeft->Add(rootHBoxLeftMid, 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxLeft->Add(rootHBoxLeftBot, 1, wxALL|wxEXPAND, 0);
  
<<<<<<< HEAD
  // down
  std::vector<Card*> bottomPlayerHand;
  s = 6;
  for(int i=0; i<s; i++)
  {
    Card *btn;
    if(i == s-1)
      btn = new Card(
        table, Suit::SPADES, 7, wxT("../resources/pictures/cards/cardSpade7.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);

    else if( i == s - 2)
	btn = new Card(
         table, Suit::HEARTS, 3, wxT("../resources/pictures/cards/cardHeart3Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);

    else if(i == s - 3)
      
      btn = new Card(
        table, Suit::DIAMONDS, 2, wxT("../resources/pictures/cards/cardDiamond2Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);

    else if(i == s - 4)
      
      btn = new Card(
        table, Suit::CLUBS, 4, wxT("../resources/pictures/cards/cardClub4Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);

    else if(i == s - 5)
      
      btn = new Card(
        table, Suit::DIAMONDS,11, wxT("../resources/pictures/cards/cardDiamondJHalf.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);

    else
      btn = new Card(
        table, Suit::DIAMONDS, 13, wxT("../resources/pictures/cards/cardDiamondKHalf.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight);
    
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
=======
  // root middle
  rootHBoxMidTop->Add(players[2].getInfoPanel(), 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxMidMid->Add(table, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  rootHBoxMidMid->Add(rootVBoxMidMid, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  rootHBoxMidBot->Add(players[0].getInfoPanel(), 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxMid->Add(rootHBoxMidTop, 1, wxALL|wxALIGN_CENTER, 5);
  rootVBoxMid->Add(rootHBoxMidMid, 7, wxALL|wxEXPAND|wxALIGN_CENTER, 5);
  rootVBoxMid->Add(rootHBoxMidBot, 1, wxALL|wxALIGN_CENTER, 5);
>>>>>>> upstream/offline
  
  // root right
  rootHBoxRightTop->AddSpacer(50);
  rootHBoxRightMid->Add(players[3].getInfoPanel(), 1, wxALL|wxALIGN_CENTER, 0);
  rootHBoxRightBot->AddSpacer(50);
  rootVBoxRight->Add(rootHBoxRightTop, 1, wxALL|wxEXPAND, 0);
  rootVBoxRight->Add(rootHBoxRightMid, 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxRight->Add(rootHBoxRightBot, 1, wxALL|wxEXPAND, 0);

  // root columns
  rootHBox->Add(rootVBoxLeft, 1, wxALL|wxEXPAND, 20);
  rootHBox->Add(rootVBoxMid, 7, wxALL|wxEXPAND, 20);
  rootHBox->Add(rootVBoxRight, 1, wxALL|wxEXPAND, 20);

  rootHBox->SetSizeHints(rootPanel);
  rootPanel->SetSizer(rootHBox);
  
  // set background color
  table->SetBackgroundColour(wxColour(0,65,225)); // blue
  rootPanel->SetBackgroundColour(wxColour(0,65,225)); // blue

  // test displaying cards
  crazyEights.setDeck();
  crazyEights.dealCards();
  crazyEights.updateDecks();
  for(unsigned int i=0; i<4; i++)
  {
    crazyEights.getPlayers()[i].updatePlayerInfo();
    crazyEights.getPlayers()[i].updatePlayerHand();
  }
  
<<<<<<< HEAD
/*  Card *button11 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button12 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button13 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
  Card *button14 = new Card(
    rootPanel, Suit::UNDEFINED, -1, wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight);
*/

 //rootVBoxLeft->Add(button11, 0, wxLEFT, 10);
 // rootHBoxUp->Add(button13, 0, wxALL|wxEXPAND, 10);
  rootHBoxTable->Add(table, 0, wxALL, 30);
 // rootHBoxDown->Add(button14, 0, wxBOTTOM, 10);
 // rootVBoxRight->Add(button12, 0, wxRIGHT, 10);

  //hbox->Add(table, 0, wxALL, 50);
  rootVBoxMid->Add(rootHBoxUp, 1, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 10);
  rootVBoxMid->Add(rootHBoxTable, 2, wxEXPAND|wxLEFT|wxRIGHT, 10);
  rootVBoxMid->Add(rootHBoxDown, 1, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 10);
=======
  //Connect(wxEVT_LEFT_UP,
  //       wxMouseEventHandler(CardPanel::mouseReleased));
>>>>>>> upstream/offline

  Centre();
}

/*
void
GameScreen::OnExit(wxMouseEvent& event)
{
  // true forces quit
  std::cout << "clicked exit\n";
  //Close(true);
}

void
GameScreen::OnExit(wxCommandEvent& event)
{
  // true forces quit
  std::cout << "exit\n";
  //Close(true);
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
wxBEGIN_EVENT_TABLE(GameScreen, wxFrame)
  EVT_MENU(ID_Hello, GameScreen::OnHello)
  EVT_MENU(wxID_EXIT, GameScreen::OnExit)
  EVT_MENU(wxID_ABOUT, GameScreen::OnAbout)
wxEND_EVENT_TABLE()
*/
