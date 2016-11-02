#include"player.h"

Player::Player( wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName, Direction dir)
{

  this->playerHandPanel = new wxPanel(handParent,-1);
  this->playerInfo = new wxPanel(infoParent, wxID_ANY);
  this->playerImage = new wxImagePanel(infoParent,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP);
  this->playerName = newName;
  this->readyButton = new wxButton(infoParent, wxID_ANY, wxT("Ready"));
  this->playerDirection = dir;
} 

void Player::setPlayerHand(std::vector<Card*> &newHand)
{
  this->playerHand = newHand;
  
}

std::vector<Card*> Player::getPlayerHand()
{
  return playerHand;
}
