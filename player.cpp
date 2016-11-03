#include"player.h"

Player::Player(wxPanel* handParent, wxPanel* infoParent, wxString newName, Direction dir)
{
  cardWidth = 70;
  cardHeight = 98;
  cardHalfWidth = 25;
  cardHalfHeight = 98;

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
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardWidth, cardHeight), 0, wxALIGN_CENTER, 1);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::DOWN, cardHalfWidth, cardHalfHeight), 0, wxALIGN_CENTER, 1);
        }
        break;
    case DOWN:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardSpade7.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight), 0, wxALIGN_CENTER, 1);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardDiamond2Half.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardHalfWidth, cardHalfHeight), 0, wxALIGN_CENTER, 1);
        }
        break;
    case LEFT:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == playerHand.size()-1)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 1);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::RIGHT, cardHalfWidth, cardHalfHeight), 0, wxALIGN_CENTER, 1);
        }
        break;
    case RIGHT:
        for(unsigned int i=0; i<playerHand.size(); ++i)
        {
          if(i == 0)
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardWidth, cardHeight), 0, wxALIGN_CENTER, 1);
          else
            playerHandSizer->Add(new CardPanel(playerHandPanel, playerHand[i], wxT("../resources/pictures/cards/cardBackHalf.png"), wxBITMAP_TYPE_PNG, Direction::LEFT, cardHalfWidth, cardHalfHeight), 0, wxALIGN_CENTER, 1);
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

void Player::mouseReleased(wxMouseEvent& evt)
{
  std::cout << "testing\n";
}
