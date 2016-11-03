#include "gameScreen.h"


// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX)
{
  /*
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

  std::vector<Player> players;
  //players.push_back(Player(table, rootPanel, wxT("Bob"), Direction::LEFT));
  
  // create players
  std::vector<Player> players;
  players.push_back(Player(table, rootPanel, wxT("Me"), Direction::DOWN));
  players.push_back(Player(table, rootPanel, wxT("Bob"), Direction::LEFT));
  players.push_back(Player(table, rootPanel, wxT("Bob1"), Direction::UP));
  players.push_back(Player(table, rootPanel, wxT("Bob2"), Direction::RIGHT));
  
  // create game controller
  CrazyEights crazyEights = CrazyEights(players, table, table);
  
  // buttons for left side
  tableVBoxLeft->Add(crazyEights.getPlayers()[1].getHandPanel(), 1, wxALL, 1);
  tableVBoxLeft->SetSizeHints(table);

  // up
  tableHBoxUp->Add(crazyEights.getPlayers()[2].getHandPanel(), 1, wxALL, 1);
  tableHBoxUp->SetSizeHints(table);

  // decks
  
  wxBoxSizer* deckBox = new wxBoxSizer(wxHORIZONTAL);
  
  deckBox->Add(crazyEights.getDrawPilePanel(), 1, wxALL, 1);
  deckBox->Add(crazyEights.getDiscardPilePanel(), 1, wxALL, 1);

  tableHBoxDecks->Add(deckBox, 0, wxALL|wxEXPAND, 1);
  tableHBoxDecks->SetSizeHints(table);
  
  // down
  tableHBoxDown->Add(crazyEights.getPlayers()[0].getHandPanel(), 0, wxALL, 1);
  tableHBoxDown->SetSizeHints(table);

  // buttons for right side
  tableVBoxRight->Add(crazyEights.getPlayers()[3].getHandPanel(), 1, wxALL, 1);
  tableVBoxRight->SetSizeHints(table);

  // table middle rows
  tableVBoxMid->Add(tableHBoxUp, 0, wxALL | wxEXPAND, 1);
  tableVBoxMid->Add(tableHBoxDecks, 0, wxALL | wxEXPAND, 1);
  tableVBoxMid->Add(tableHBoxDown, 0, wxALL | wxEXPAND, 1);
  tableVBoxMid->SetSizeHints(table);
  
  // table columns
  tableHBox->Add(tableVBoxLeft, 1, wxEXPAND, 1);
  tableHBox->Add(tableVBoxMid, 2, wxEXPAND, 1);
  tableHBox->Add(tableVBoxRight, 1, wxEXPAND, 1);
  tableHBox->SetSizeHints(table);
  table->SetSizer(tableHBox);

  // add players and table position
  wxBoxSizer* rootVBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootVBoxLeftBottom = new wxBoxSizer(wxHORIZONTAL);
  rootVBoxLeft->Add(rootVBoxLeftTop, 1, wxEXPAND, 0);
  rootVBoxLeft->Add(crazyEights.getPlayers()[1].getInfoPanel(), 1, wxALL|wxEXPAND, 1);
  rootVBoxLeft->Add(rootVBoxLeftBottom, 1, wxEXPAND, 0);
  
  rootHBoxUp->Add(crazyEights.getPlayers()[2].getInfoPanel(), 0, wxALL, 1);
  rootHBoxTable->Add(table, 1, wxEXPAND|wxALL, 1);
  rootHBoxDown->Add(crazyEights.getPlayers()[0].getInfoPanel(), 0, wxALL, 1);
  rootVBoxRight->Add(crazyEights.getPlayers()[3].getInfoPanel(), 0, wxALL, 1);

  // add row sizers
  rootVBoxMid->Add(rootHBoxUp, 1, wxEXPAND, 1);
  rootVBoxMid->Add(rootHBoxTable, 2, wxEXPAND, 1);
  rootVBoxMid->Add(rootHBoxDown, 1, wxEXPAND, 1);

  // add column sizers
  hbox->Add(rootVBoxLeft, 0, wxALL|wxEXPAND, 20);
  hbox->Add(rootVBoxMid, 2, wxEXPAND, 1);
  hbox->Add(rootVBoxRight, 1, wxEXPAND, 1);
  */
  wxPanel* rootPanel = new wxPanel(this, -1);
  wxBoxSizer* rootHBox = new wxBoxSizer(wxHORIZONTAL);
  
  // card table
  wxImagePanel* table = new wxImagePanel(
    rootPanel, wxT("../resources/pictures/table/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP, 760, 480);
  
  wxBoxSizer* tableHBox = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* tableVBoxRight = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* tableHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* tableHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* rootVBoxLeft = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* rootVBoxMid = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  wxBoxSizer* rootVBoxRight = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* rootHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* rootHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  std::vector<Player> players;
  players.push_back(Player(table, rootPanel, wxT("Ryan"), Direction::DOWN));
  players.push_back(Player(table, rootPanel, wxT("Cameron"), Direction::LEFT));
  players.push_back(Player(table, rootPanel, wxT("Nick"), Direction::UP));
  players.push_back(Player(table, rootPanel, wxT("Shem"), Direction::RIGHT));
  
  tableHBoxLeftMid->Add(players[1].getHandPanel(), 0, wxEXPAND, 0);
  tableVBoxLeft->Add(tableHBoxLeftTop, 0, wxEXPAND, 0);
  tableVBoxLeft->Add(tableHBoxLeftMid, 0, wxEXPAND, 0);
  tableVBoxLeft->Add(tableHBoxLeftBot, 0, wxEXPAND, 0);
  
  tableHBoxMidTop->Add(players[2].getHandPanel(), 0, wxEXPAND, 0);
  tableHBoxMidBot->Add(players[0].getHandPanel(), 0, wxEXPAND, 0);
  tableVBoxMid->Add(tableHBoxMidTop, 0, wxEXPAND, 0);
  tableVBoxMid->Add(tableHBoxMidMid, 0, wxEXPAND, 0);
  tableVBoxMid->Add(tableHBoxMidBot, 0, wxEXPAND, 0);
  
  tableHBoxRightMid->Add(players[3].getHandPanel(), 0, wxEXPAND, 0);
  tableVBoxRight->Add(tableHBoxRightTop, 0, wxEXPAND, 0);
  tableVBoxRight->Add(tableHBoxRightMid, 0, wxEXPAND, 0);
  tableVBoxRight->Add(tableHBoxRightBot, 0, wxEXPAND, 0);

  tableHBox->Add(tableVBoxLeft, 0, wxEXPAND, 0);
  tableHBox->Add(tableVBoxMid, 0, wxEXPAND, 0);
  tableHBox->Add(tableVBoxRight, 0, wxEXPAND, 0);

  tableHBox->SetSizeHints(table);
  table->SetSizer(tableHBox);
  
  //wxPanel* blankPanel = new wxPanel(rootPanel, -1);
  //wxBoxSizer* blankSizer = new wxBoxSizer(wxHORIZONTAL);
  //rootHBoxLeftTop->Add(blankPanel, 0, wxEXPAND, 0);
  rootHBoxLeftMid->Add(players[1].getInfoPanel(), 0, wxALL, 0);
  //rootHBoxLeftBot->Add(blankPanel, 0, wxEXPAND, 0);

  //blankSizer->SetSizeHints(blankPanel);
  //blankPanel->SetSizer(blankSizer);

  rootVBoxLeft->Add(rootHBoxLeftTop, 0, wxEXPAND, 0);
  rootVBoxLeft->Add(rootHBoxLeftMid, 0, wxEXPAND, 0);
  rootVBoxLeft->Add(rootHBoxLeftBot, 0, wxEXPAND, 0);
  
  rootHBoxMidTop->Add(players[2].getInfoPanel(), 0, wxALL, 0);
  rootHBoxMidMid->Add(table, 0, wxALL, 50);
  rootHBoxMidBot->Add(players[0].getInfoPanel(), 0, wxALL, 0);
  rootVBoxMid->Add(rootHBoxMidTop, 0, wxALL, 5);
  rootVBoxMid->Add(rootHBoxMidMid, 0, wxALL, 5);
  rootVBoxMid->Add(rootHBoxMidBot, 0, wxALL, 5);
  
  rootHBoxRightMid->Add(players[3].getInfoPanel(), 0, wxALL, 0);
  rootVBoxRight->Add(rootHBoxRightTop, 0, wxEXPAND, 0);
  rootVBoxRight->Add(rootHBoxRightMid, 0, wxEXPAND, 0);
  rootVBoxRight->Add(rootHBoxRightBot, 0, wxEXPAND, 0);

  rootHBox->Add(rootVBoxLeft, 1, wxEXPAND, 0);
  rootHBox->Add(rootVBoxMid, 2, wxEXPAND, 0);
  rootHBox->Add(rootVBoxRight, 1, wxEXPAND, 0);

  // add sizer to root panel
  rootHBox->SetSizeHints(rootPanel);
  rootPanel->SetSizer(rootHBox);
  
  // set background color
  //table->SetBackgroundColour(wxColour(214,125,0));
  rootPanel->SetBackgroundColour(wxColour(0,65,225));

  //CrazyEights crazyEights = CrazyEights(players, table, table);
  // test displaying cards
  //crazyEights.setDeck();
  //crazyEights.dealCards();
  //crazyEights.updateDecks();
  for(unsigned int i=0; i<4; i++)
  {
    //crazyEights.getPlayers()[i].updatePlayerInfo();
    //crazyEights.getPlayers()[i].updatePlayerHand();
  }
  
  //Connect(wxEVT_LEFT_UP,
  //       wxMouseEventHandler(Player::mouseReleased));
  
  //Connect(wxEVT_LEFT_UP,
  //       wxMouseEventHandler(CardPanel::mouseReleased));

  Centre();
}

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
wxBEGIN_EVENT_TABLE(GameScreen, wxFrame) EVT_MENU(ID_Hello, GameScreen::OnHello)
  EVT_MENU(wxID_EXIT, GameScreen::OnExit)
    EVT_MENU(wxID_ABOUT, GameScreen::OnAbout) wxEND_EVENT_TABLE()
