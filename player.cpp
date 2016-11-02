#include"player.h"

Player::Player(wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName, Direction dir)
{

  this->playerHandPanel = new wxPanel(handParent,-1);
  this->playerInfo = new wxPanel(infoParent, wxID_ANY);
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
  playerInfo->SetSizer(playerInfoSizer);
} 

void Player::setPlayerHand(std::vector<Card> &newHand)
{
  this->playerHand = newHand;
  updatePlayerHand();
}

std::vector<Card> Player::getPlayerHand()
{
  return playerHand;
}

void Player::updatePlayerHand()
{
  playerHandPanel->Clear(true); // remove all children
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
}

void Player:setTurn(bool isTurn)
{
  isMyTurn = isTurn;
}

bool Player::getTurn()
{
  return isMyTurn;
}
