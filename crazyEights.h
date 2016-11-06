#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include "player.h"

class CrazyEights 
{
    private:
      std::vector<Card> drawPile;
      std::vector<Card> discardPile;
      wxPanel* drawPilePanel;
      wxPanel* discardPilePanel;
      wxBoxSizer* drawPileSizer;
      wxBoxSizer* discardPileSizer;

      std::vector<Player> players;
      int turn; //index for player vector
      Suit currentSuit;
      
public:
    CrazyEights(std::vector<Player>& players, wxPanel* drawParent, wxPanel* discardParent);
    void setCurrentSuit(Suit newSuit);
    Suit getCurrentSuit(); 
    void dealCards(); //will use drawPile, deal 5 cards to each 
    void setDeck();  //sets up the deck for the game 
    bool isGameOver();
    bool isValidMove();
    void nextTurn();// decide who goes next
    void playCard();
    void drawCard();
    void updateState(); //updates the entire field
    void gameOver();// show end game screen
    void updateDecks();
    std::vector<Card> getDrawPile();
    std::vector<Card> getDiscardPile();
    wxPanel* getDrawPilePanel();
    wxPanel* getDiscardPilePanel();
    std::vector<Player> getPlayers();
};

#endif
