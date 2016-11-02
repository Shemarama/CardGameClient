#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H
#include<vector>
#include"player.h"

class CrazyEights 
{
    private:
      std::vector<Card> drawPile;
      std::vector<Card> discardPile;

      std::vector<Player> players;
      int turn; //index for player vecotor
      bool gameOver;
      Suit currentSuit;

public:
    CrazyEights(std::vector<Player>& players);
    void setCurrentSuit(Suit newSuit);
    Suit getCurrentSuit(); 
    void dealCard(); //will use drawPile, deal 5 cards to each 
    void setDeck();  //sets up the deck for the game 
    bool isGameOver();
    bool isValidMove();
    void nextTurn();// decide who goes next
    void playCard();
    void drawCard();
    void updateState(); //updates the entire field
    void gameOver();// show end game screen
}

#endif
