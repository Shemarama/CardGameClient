#ifndef PLAYER_H
#define PLAYER_H
#include<wx/wx.h>
#include"imagePanel.h"
#include"card.h"
#include<vector>


class Player 
{
   private:
    //This holds the hand and is what we will reference when we render a players hand
    wxPanel* playerHandPanel;

    //This hold the player icon and name
    wxPanel* playerInfo; 

    std::vector<Card> playerHand; 
    wxStaticText* playerName;
    wxImagePanel* playerImage;
    wxButton* = readyButton;
    bool isMyTurn = false;
   
   public:
    Player( wxPanel* handParent, wxPanel* infoParent,wxImagePanel* playerImage, wxString newName); 
    void setPlayerHand(std::vector<Cards>& newHand); //set hand when ready button is pressed
    void setTurn(bool isTurn);
    bool getTurn(); //will let us know when its is our turn
};
#endif
