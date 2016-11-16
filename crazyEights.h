#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include "player.h"
#include "ai.h"

class CrazyEights 
{
    private:
      std::vector<Card> drawPile;
      std::vector<Card> discardPile;
      std::vector<Player*> players;
      unsigned int turn; //index for player vector
      Suit currentSuit;
      
public:
    CrazyEights(std::vector<Player*>& players);
    void setCurrentSuit(Suit newSuit);
    Suit getCurrentSuit(); 
    void dealCards(); //will use drawPile, deal 5 cards to each 
    void setDeck();  //sets up the deck for the game
    void refillDeck();
    void shuffleDeck();
    bool isGameOver();
    bool isValidMove(Card& card);
    void nextTurn();// decide who goes next
    void playCard(Card& card);
    bool drawCard();
    void gameOver();// show end game screen
    bool getMove(Card& card);
    std::vector<Card> getDrawPile();
    std::vector<Card> getDiscardPile();
    std::vector<Player*> getPlayers();
};

#endif
