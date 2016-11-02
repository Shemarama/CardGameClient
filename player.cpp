#include"player.h"

Player::Player( wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName)
{

this->playerHandPanel = new wxPanel(handParent,-1);
this->playerInfo = new wxPanel(infoParent, wx_ID_ANY);
this->playerImage = new wxImagePanel(infoParent,wxT("../resources/pictures/player/playerIcon.png"),wxBITMAP_TYPE_PNG,Direction::UP);
this->playerName = newName;

} 
