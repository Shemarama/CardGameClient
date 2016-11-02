#include"crazyEights.h"

CrazyEights::CrazyEights(std::vector<Player>&  players)
{
   this->players = players;
   setDeck();
   discardPile = std::vector<Card* >();
   turn = 0;
   gameOver = false;

}

void CrazyEights::setCurrentSuit(Suit newSuit)
{
    currentSuit = newSuit;

}

Suit CrazyEights::getCurrentSuit()
{
 return currentSuit;
}

void CrazyEights::setDeck()
{
    drawPile = std::vector<Card* >();
    std::vector<Suit> suits = {HEARTS, SPADES, CLUBS, DIAMONDS};
    for(auto && suit : suits)
    {
        for(int i = 2; i < 15: i++)
            drawPile.push_back(new Card(suit, static_cast<Value>(i)));
    }
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(drawPile.begin(), drawPile.end(), generator);
}

void CrazyEights::dealCard()
{
     
}
