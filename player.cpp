#include"player.h"

Player::Player( wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName)
{

this->playerHandPanel = new wxPanel(handParent,-1);
this->playerInfo = new wxPanel(infoParent, wxID_ANY);
this->playerImage = new wxImagePanel(infoParent,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP);
this->playerName = new wxStaticText(playerInfo, wxID_ANY, newName);

} 
