#include"player.h"

Player::Player(wxPanel* handParent, wxPanel* infoParent, wxString newName, Direction dir)
{
  this->playerHandPanel = new wxPanel(handParent,wxID_ANY);
  this->playerInfoPanel = new wxPanel(infoParent, wxID_ANY);
  this->playerImage = new wxImagePanel(infoParent,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP);
  this->playerName = newName;
  this->readyButton = new wxButton(infoParent, wxID_ANY, wxT("Ready"));
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
  playerHandPanel->SetSizer(playerHandSizer);
  playerInfoSizer = new wxBoxSizer(wxVERTICAL);
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

void Player:setTurn(bool isTurn)
{
  isMyTurn = isTurn;
}

bool Player::getTurn()
{
  return isMyTurn;
}

wxPanel* getHandPanel()
{
  return playerHandPanel;
}

wxPanel* getInfoPanel()
{
  return playerInfoPanel();
}

void Player::updatePlayerHand()
{
  playerHandSizer->Clear(true); // remove all children
  // update card display depending on player's position
  switch(playerDirection)
  {
    case UP:
        for(auto i=0; i<playerHand.size())
        {
          if(i == 0)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
        }
        break;
    case DOWN:
        for(auto i=0; i<playerHand.size())
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardSpade7.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardDiamond2Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
        }
        break;
    case LEFT:
        for(auto i=0; i<playerHand.size())
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
        }
        break;
    case RIGHT:
        for(auto i=0; i<playerHand.size())
        {
          if(i == 0)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/card/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
        }
        break;
    default:
        break;
  }
  playerHandSizer->SetSizeHints(playerHandPanel);
}

void Player::updatePlayerInfo()
{
  playerInfoSizer->Clear(true); // remove all children
  playerInfoSizer->Add(readyButton, 0, wxALIGN_CENTER, 0);
  playerInfoSizer->Add(playerImage, 0, wxALIGN_CENTER, 0);
  playerInfoSizer->Add(playerName, 0, wxALIGN_CENTER, 0);
  playerInfoSizer->SetSizeHints(playerInfoPanel);
}
