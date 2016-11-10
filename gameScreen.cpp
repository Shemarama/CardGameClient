#include "gameScreen.h"


// constructor
GameScreen::GameScreen(const wxString& title, const wxPoint& pos,
                       const wxSize& size)
  : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxMAXIMIZE_BOX)
{
  // root panel
  rootPanel = new wxPanel(this, -1);
  rootHBox = new wxBoxSizer(wxHORIZONTAL);
  
  // card table
  table = new wxImagePanel(
    rootPanel, wxT("../resources/pictures/table/cardtableRect.png"), wxBITMAP_TYPE_PNG, Direction::UP, 760, 480);
  
  // sizers for table
  tableHBox = new wxBoxSizer(wxHORIZONTAL);
  
  tableVBoxLeft = new wxBoxSizer(wxVERTICAL);
  tableHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  tableHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  tableHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  tableVBoxMid = new wxBoxSizer(wxVERTICAL);
  tableHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  tableVBoxMidMid = new wxBoxSizer(wxVERTICAL);
  tableHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  tableHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  tableVBoxRight = new wxBoxSizer(wxVERTICAL);
  tableHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  tableHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  tableHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  // sizers for root panel
  rootVBoxLeft = new wxBoxSizer(wxVERTICAL);
  rootHBoxLeftTop = new wxBoxSizer(wxHORIZONTAL);
  rootHBoxLeftMid = new wxBoxSizer(wxHORIZONTAL);
  rootHBoxLeftBot = new wxBoxSizer(wxHORIZONTAL);
  
  rootVBoxMid = new wxBoxSizer(wxVERTICAL);
  rootHBoxMidTop = new wxBoxSizer(wxHORIZONTAL);
  rootVBoxMidMid = new wxBoxSizer(wxVERTICAL);
  rootHBoxMidMid = new wxBoxSizer(wxHORIZONTAL);
  rootHBoxMidBot = new wxBoxSizer(wxHORIZONTAL);
  
  rootVBoxRight = new wxBoxSizer(wxVERTICAL);
  rootHBoxRightTop = new wxBoxSizer(wxHORIZONTAL);
  rootHBoxRightMid = new wxBoxSizer(wxHORIZONTAL);
  rootHBoxRightBot = new wxBoxSizer(wxHORIZONTAL);
  
  
  // create players
  players.push_back(new Player(wxT("Ryan")));
  players.push_back(new AI(wxT("Cameron")));
  players.push_back(new AI(wxT("Nick")));
  players.push_back(new AI(wxT("Shem")));


  // create player panels
  for(unsigned int i=0; i<players.size(); ++i)
  {
    playerHandPanels.push_back(new wxPanel(table, wxID_ANY));
    playerInfoPanels.push_back(new wxPanel(rootPanel, wxID_ANY));
    playerImagePanels.push_back(new wxImagePanel(playerInfoPanels[i], wxT("../resources/pictures/player/playerIcon.png"), wxBITMAP_TYPE_PNG, Direction::UP, 55, 55));
    playerNames.push_back(new wxStaticText(playerInfoPanels[i], wxID_ANY, players[i]->getName()));
    playerReadyButtons.push_back(new wxButton(playerInfoPanels[i], wxID_ANY, wxT("Ready")));
    // if bottom or top player
    if(i == 0 || i == 2)
      playerHandSizers.push_back(new wxBoxSizer(wxHORIZONTAL));
    else
      playerHandSizers.push_back(new wxBoxSizer(wxVERTICAL));
    playerHandSizers[i]->SetSizeHints(playerHandPanels[i]);
    playerHandPanels[i]->SetSizer(playerHandSizers[i]);

    playerInfoSizers.push_back(new wxBoxSizer(wxVERTICAL));
    playerInfoSizers[i]->Add(playerReadyButtons[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->Add(playerImagePanels[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->Add(playerNames[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->SetSizeHints(playerInfoPanels[i]);
    playerInfoPanels[i]->SetSizer(playerInfoSizers[i]);
  }


  // create game logic
  CrazyEights ce = CrazyEights(players);
  crazyEights = ce;

  // create deck panels
  drawPilePanel = new wxPanel(table, wxID_ANY);
  discardPilePanel = new wxPanel(table, wxID_ANY);
  drawPileSizer = new wxBoxSizer(wxHORIZONTAL);
  drawPilePanel->SetSizer(drawPileSizer);
  discardPileSizer = new wxBoxSizer(wxHORIZONTAL);
  discardPilePanel->SetSizer(discardPileSizer);
  
  // table left
  tableHBoxLeftMid->Add(playerHandPanels[1], 0, wxALL|wxALIGN_CENTER, 0);
  tableVBoxLeft->Add(tableHBoxLeftTop, 1, wxALL|wxEXPAND, 0);
  tableVBoxLeft->Add(tableHBoxLeftMid, 1, wxALL|wxALIGN_CENTER, 0);
  tableVBoxLeft->Add(tableHBoxLeftBot, 1, wxALL|wxEXPAND, 0);
  
  // table middle
  tableHBoxMidTop->Add(playerHandPanels[2], 0, wxALL|wxALIGN_CENTER, 0);
  tableHBoxMidMid->Add(drawPilePanel, 0, wxRIGHT|wxALIGN_CENTER, 5);
  tableHBoxMidMid->Add(discardPilePanel, 0, wxLEFT|wxALIGN_CENTER, 5);
  tableVBoxMidMid->Add(tableHBoxMidMid, 0, wxALL|wxALIGN_CENTER, 5);
  tableHBoxMidBot->Add(playerHandPanels[0], 0, wxALL|wxALIGN_CENTER, 0);
  tableVBoxMid->Add(tableHBoxMidTop, 1, wxALL|wxALIGN_CENTER, 0);
  tableVBoxMid->Add(tableVBoxMidMid, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  tableVBoxMid->Add(tableHBoxMidBot, 1, wxALL|wxALIGN_CENTER, 0);
  
  // table right
  tableHBoxRightMid->Add(playerHandPanels[3], 0, wxALL|wxALIGN_CENTER, 0);
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
  rootHBoxLeftMid->Add(playerInfoPanels[1], 1, wxALL|wxALIGN_CENTER, 0);
  rootHBoxLeftBot->AddSpacer(50);
  rootVBoxLeft->Add(rootHBoxLeftTop, 1, wxALL|wxEXPAND, 0);
  rootVBoxLeft->Add(rootHBoxLeftMid, 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxLeft->Add(rootHBoxLeftBot, 1, wxALL|wxEXPAND, 0);
 // text box
wxBoxSizer* testVertBox = new wxBoxSizer(wxVERTICAL); 
  // root middle
  rootHBoxMidTop->Add(playerInfoPanels[2], 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxMidMid->Add(table, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  rootHBoxMidMid->Add(rootVBoxMidMid, 1, wxALL|wxEXPAND|wxALIGN_CENTER, 10);
  rootHBoxMidBot->Add(playerInfoPanels[0], 1, wxALL|wxALIGN_CENTER, 0);
  rootVBoxMid->Add(rootHBoxMidTop, 1, wxALL|wxALIGN_CENTER, 5);
  rootVBoxMid->Add(rootHBoxMidMid, 7, wxALL|wxEXPAND|wxALIGN_CENTER, 5);
  rootVBoxMid->Add(rootHBoxMidBot, 1, wxALL|wxALIGN_CENTER, 5);
  
  // root right
  rootHBoxRightTop->AddSpacer(50);
  rootHBoxRightMid->Add(playerInfoPanels[3], 1, wxALL|wxALIGN_CENTER, 0);
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
  updateTable();
  updatePlayerInfo();
  
  //Connect(wxEVT_LEFT_UP,
  //       wxMouseEventHandler(CardPanel::mouseReleased));

  Centre();
}

void GameScreen::updateTable()
{
  players = crazyEights.getPlayers();
  // for each player
  for(unsigned int i=0; i<players.size(); ++i)
  {
    playerHandSizers[i]->Clear(true); // remove all children
    // update card display depending on player's position
    switch(i)
    {
      case 0:
          // for cards in the bottom player's hand
          for(unsigned int j=0; j<players[i]->getHand().size(); ++j)
          {
            if(j == players[i]->getHand().size()-1)
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], true, Direction::UP, false));
            else
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], true, Direction::UP, true));
          }
          break;
      case 1:
          // for cards in the left player's hand
          for(unsigned int j=0; j<players[i]->getHand().size(); ++j)
          {
            if(j == players[i]->getHand().size()-1)
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::RIGHT, false));
            else
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::RIGHT, true));
          }
          break;
      case 2:
          // for cards in the top player's hand
          for(unsigned int j=0; j<players[i]->getHand().size(); ++j)
          {
            if(j == 0)
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::DOWN, false));
            else
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::DOWN, true));
          }
          break;
      case 3:
          // for cards in the right player's hand
          for(unsigned int j=0; j<players[i]->getHand().size(); ++j)
          {
            if(j == 0)
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::LEFT, false));
            else
              playerHandSizers[i]->Add(makeCard(playerHandPanels[i], players[i]->getHand()[j], false, Direction::LEFT, true));
          }
          break;
      default:
          break;
    }
    playerHandSizers[i]->SetSizeHints(playerHandPanels[i]);
    playerHandPanels[i]->Layout();
  }
  table->Layout();

  // draw pile
  drawPileSizer->Clear(true); // remove all children
  if(!crazyEights.getDrawPile().empty())
    drawPileSizer->Add(makeCard(drawPilePanel, crazyEights.getDrawPile().back(), false, Direction::UP, false));
  drawPileSizer->SetSizeHints(drawPilePanel);
  drawPileSizer->Layout();

  // discard pile
  discardPileSizer->Clear(true); // remove all children
  if(!crazyEights.getDiscardPile().empty())
    discardPileSizer->Add(makeCard(discardPilePanel, crazyEights.getDiscardPile().back(), true, Direction::UP, false));
  discardPileSizer->SetSizeHints(discardPilePanel);
  discardPileSizer->Layout();
}

void GameScreen::updatePlayerInfo()
{
  players = crazyEights.getPlayers();
  // for each player
  for(unsigned int i=0; i<players.size(); ++i)
  {
    playerInfoSizers[i]->Clear(false); // remove all children
    playerInfoSizers[i]->Add(playerReadyButtons[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->Add(playerImagePanels[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->Add(playerNames[i], 0, wxALIGN_CENTER, 1);
    playerInfoSizers[i]->SetSizeHints(playerInfoPanels[i]);
    playerInfoSizers[i]->Layout();
  }
}

CardPanel* GameScreen::makeCard(wxPanel* parent, Card& card, bool show, Direction dir, bool isHalf)
{
  if(isHalf)
  {
    wxString imgPath = findHalfImage(card, show);
    return new CardPanel(parent, card, imgPath, wxBITMAP_TYPE_PNG, dir, cardHalfWidth, cardHalfHeight);
  }
  else
  {
    wxString imgPath = findFullImage(card, show);
    return new CardPanel(parent, card, imgPath, wxBITMAP_TYPE_PNG, dir, cardWidth, cardHeight);
  }
}

wxString GameScreen::findHalfImage(Card& card, bool show)
{
  if(!show)
    return wxT("../resources/pictures/cards/cardBackHalf.png");
  
  if(card.getSuit() == Suit::HEARTS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardHeart2Half.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardHeart3Half.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardHeart4Half.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardHeart5Half.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardHeart6Half.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardHeart7Half.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardHeart8Half.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardHeart9Half.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardHeart10Half.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardHeartJHalf.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardHeartQHalf.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardHeartKHalf.png");
    else // ace
        return wxT("../resources/pictures/cards/cardHeartAHalf.png");
  }
  else if(card.getSuit() == Suit::SPADES)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardSpade2Half.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardSpade3Half.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardSpade4Half.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardSpade5Half.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardSpade6Half.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardSpade7Half.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardSpade8Half.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardSpade9Half.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardSpade10Half.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardSpadeJHalf.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardSpadeQHalf.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardSpadeKHalf.png");
    else // ace
        return wxT("../resources/pictures/cards/cardSpadeAHalf.png");
  }
  else if(card.getSuit() == Suit::DIAMONDS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardDiamond2Half.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardDiamond3Half.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardDiamond4Half.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardDiamond5Half.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardDiamond6Half.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardDiamond7Half.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardDiamond8Half.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardDiamond9Half.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardDiamond10Half.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardDiamondJHalf.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardDiamondQHalf.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardDiamondKHalf.png");
    else // ace
        return wxT("../resources/pictures/cards/cardDiamondAHalf.png");
  }
  else if(card.getSuit() == Suit::CLUBS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardClub2Half.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardClub3Half.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardClub4Half.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardClub5Half.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardClub6Half.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardClub7Half.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardClub8Half.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardClub9Half.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardClub10Half.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardClubJHalf.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardClubQHalf.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardClubKHalf.png");
    else // ace
        return wxT("../resources/pictures/cards/cardClubAHalf.png");
  }
  else // UNDEFINED
      return wxT("../resources/pictures/cards/cardBackHalf.png");
}


wxString GameScreen::findFullImage(Card& card, bool show)
{
  if(!show)
      return wxT("../resources/pictures/cards/cardBack.png");
  
  if(card.getSuit() == Suit::HEARTS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardHeart2.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardHeart3.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardHeart4.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardHeart5.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardHeart6.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardHeart7.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardHeart8.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardHeart9.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardHeart10.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardHeartJ.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardHeartQ.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardHeartK.png");
    else // ace
        return wxT("../resources/pictures/cards/cardHeartA.png");
  }
  else if(card.getSuit() == Suit::SPADES)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardSpade2.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardSpade3.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardSpade4.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardSpade5.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardSpade6.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardSpade7.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardSpade8.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardSpade9.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardSpade10.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardSpadeJ.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardSpadeQ.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardSpadeK.png");
    else // ace
        return wxT("../resources/pictures/cards/cardSpadeA.png");
  }
  else if(card.getSuit() == Suit::DIAMONDS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardDiamond2.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardDiamond3.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardDiamond4.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardDiamond5.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardDiamond6.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardDiamond7.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardDiamond8.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardDiamond9.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardDiamond10.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardDiamondJ.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardDiamondQ.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardDiamondK.png");
    else // ace
        return wxT("../resources/pictures/cards/cardDiamondA.png");
  }
  else if(card.getSuit() == Suit::CLUBS)
  {
    if(card.getRank() == 2)
        return wxT("../resources/pictures/cards/cardClub2.png");
    else if(card.getRank() == 3)
        return wxT("../resources/pictures/cards/cardClub3.png");
    else if(card.getRank() == 4)
        return wxT("../resources/pictures/cards/cardClub4.png");
    else if(card.getRank() == 5)
        return wxT("../resources/pictures/cards/cardClub5.png");
    else if(card.getRank() == 6)
        return wxT("../resources/pictures/cards/cardClub6.png");
    else if(card.getRank() == 7)
        return wxT("../resources/pictures/cards/cardClub7.png");
    else if(card.getRank() == 8)
        return wxT("../resources/pictures/cards/cardClub8.png");
    else if(card.getRank() == 9)
        return wxT("../resources/pictures/cards/cardClub9.png");
    else if(card.getRank() == 10)
        return wxT("../resources/pictures/cards/cardClub10.png");
    else if(card.getRank() == 11)
        return wxT("../resources/pictures/cards/cardClubJ.png");
    else if(card.getRank() == 12)
        return wxT("../resources/pictures/cards/cardClubQ.png");
    else if(card.getRank() == 13)
        return wxT("../resources/pictures/cards/cardClubK.png");
    else // ace
        return wxT("../resources/pictures/cards/cardClubA.png");
  }
  else // UNDEFINED
      return wxT("../resources/pictures/cards/cardBack.png");
}

void GameScreen::test(Card& card)
{
  players = crazyEights.getPlayers();
  if(!crazyEights.getMove(card))
      return;
  updateTable();
  crazyEights.nextTurn();
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
