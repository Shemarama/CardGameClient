#ifndef PLAYER_H
#define PLAYER_H
#include <wx/wx.h>
#include "imagePanel.h"
#include "card.h"
#include "cardPanel.h"
#include <vector>


class Player 
{
   private:
    //This holds the hand and is what we will reference when we render a players hand
    wxPanel* playerHandPanel;
    //This hold the player icon and name
    wxPanel* playerInfoPanel; 
    // box sizer for player's hand
    wxBoxSizer* playerHandSizer;
    // box sizer for player's info
    wxBoxSizer* playerInfoSizer;
    // player's hand
    std::vector<Card> playerHand; 
    // player's name
    wxStaticText* playerName;
    // player's avatar
    wxImagePanel* playerImage;
    // ready up button to start the game
    wxButton* readyButton;
    // player position on the table
    Direction playerDirection;
    // flag to tell if it is the user's turn
    bool isMyTurn = false;
   
   public:
    Player(wxPanel* handParent, wxPanel* infoParent, wxImagePanel* playerImage, wxString newName, Direction dir); 
    
    void addCard(Card card);
    void setPlayerHand(std::vector<Card>& newHand); //set hand when ready button is pressed
    std::vector<Card> getPlayerHand();
    void setTurn(bool isTurn);
    bool getTurn(); //will let us know when it's is our turn
    void updatePlayerHand();
    void updatePlayerInfo();
};
#endif
