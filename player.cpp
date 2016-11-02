#include"player.h"

Player::Player( wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName, Direction dir)
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

void Player::setPlayerHand(std::vector<Card*> &newHand)
{
  this->playerHand = newHand;
  /*for(auto i=0; i<newHand.size(); ++i)
  {
    Card *card;
    if(i == 0)
        card = new Card(newHand[i]->
  }
  */
  //for(auto&& card : playerHand)
  //{
  //  playerHandSizer->Add(card
  //} 
}

std::vector<Card*> Player::getPlayerHand()
{
  return playerHand;
}
