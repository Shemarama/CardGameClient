#include"player.h"

Player::Player(wxPanel* handParent, wxPanel* infoParent, wxString newName, Direction dir)
{
  //cardWidth = 70;
  //cardHeight = 98;
  //cardHalfWidth = 25;
  //cardHalfHeight = 98;

  this->playerHandPanel = new wxPanel(handParent,wxID_ANY);
  this->playerInfoPanel = new wxPanel(infoParent, wxID_ANY);
  this->playerImage = new wxImagePanel(playerInfoPanel,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP, 55, 55);
  this->playerName = new wxStaticText(playerInfoPanel, wxID_ANY, newName);
  this->readyButton = new wxButton(playerInfoPanel, wxID_ANY, wxT("Ready"));
  this->playerDirection = dir;
  
  switch(playerDirection)
  {
    case UP:
    case DOWN:
        playerHandSizer = new wxBoxSizer(wxHORIZONTAL);
        break;
    case LEFT:
    case RIGHT:
        playerHandSizer = new wxBoxSizer(wxVERTICAL);
        break;
    default:
        playerHandSizer = new wxBoxSizer(wxHORIZONTAL);
        break;
  }
  playerHandSizer->SetSizeHints(playerHandPanel);
  playerHandPanel->SetSizer(playerHandSizer);
  
  playerInfoSizer = new wxBoxSizer(wxVERTICAL);
  playerInfoSizer->Add(readyButton, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->Add(playerImage, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->Add(playerName, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->SetSizeHints(playerInfoPanel);
  playerInfoPanel->SetSizer(playerInfoSizer);
} 

void Player::addCard(Card& card)
{
  playerHand.push_back(card);
}

void Player::setPlayerHand(std::vector<Card> &newHand)
{
  this->playerHand = newHand;
  updatePlayerHand(); // update hand graphics
}

std::vector<Card> Player::getPlayerHand()
{
  return playerHand;
}

void Player::setTurn(bool isTurn)
{
  isMyTurn = isTurn;
}

bool Player::getTurn()
{
  return isMyTurn;
}

wxString Player::getPlayerName()
{
  return playerName->GetLabel();
}

wxPanel* Player::getHandPanel()
{
  return playerHandPanel;
}

wxPanel* Player::getInfoPanel()
{
  return playerInfoPanel;
}

void Player::updatePlayerHand()
{
  playerHandSizer->Clear(true); // remove all children
  // update card display depending on player's position
  switch(playerDirection)
  {
    case UP:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == 0)
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::DOWN, false));
          else
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::DOWN, true));
        }
        break;
    case DOWN:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], true, Direction::UP, false));
          else
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], true, Direction::UP, true));
        }
        break;
    case LEFT:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::RIGHT, false));
          else
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::RIGHT, true));
        }
        break;
    case RIGHT:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == 0)
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::LEFT, false));
          else
            playerHandSizer->Add(makeCard(playerHandPanel, playerHand[i], false, Direction::LEFT, true));
        }
        break;
    default:
        break;
  }
  playerHandSizer->SetSizeHints(playerHandPanel);
  playerHandSizer->Layout();
}

void Player::updatePlayerInfo()
{
  playerInfoSizer->Clear(false); // remove all children
  playerInfoSizer->Add(readyButton, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->Add(playerImage, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->Add(playerName, 0, wxALIGN_CENTER|wxSHAPED, 1);
  playerInfoSizer->SetSizeHints(playerInfoPanel);
  playerInfoSizer->Layout();
}

CardPanel* Player::makeCard(wxPanel* parent, Card& card, bool show, Direction dir, bool isHalf)
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

wxString Player::findHalfImage(Card& card, bool show)
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

wxString Player::findFullImage(Card& card, bool show)
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

void Player::mouseReleased(wxMouseEvent& evt)
{
  std::cout << "testing\n";
}
