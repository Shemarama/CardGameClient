#include"crazyEights.h"

CrazyEights::CrazyEights(std::vector<Player*>& players)
{
   this->players = players;
   // create cards and place in deck
   setDeck();
   discardPile = std::vector<Card>();
   turn = 0;
}

void CrazyEights::setCurrentSuit(Suit newSuit)
{
    currentSuit = newSuit;
}

Suit CrazyEights::getCurrentSuit()
{
  return currentSuit;
}

std::vector<Card> CrazyEights::getDrawPile()
{
  return drawPile;
}

std::vector<Card> CrazyEights::getDiscardPile()
{
  return discardPile;
}

std::vector<Player*> CrazyEights::getPlayers()
{
  return players;
}

void CrazyEights::setDeck()
{
    drawPile = std::vector<Card>();
    std::vector<Suit> suits = {HEARTS, SPADES, CLUBS, DIAMONDS};
    for(auto && suit : suits)
    {
        for(int i = 2; i < 15; i++)
            drawPile.push_back(Card(suit, static_cast<Value>(i)));
    }
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(drawPile.begin(), drawPile.end(), generator);
}

void CrazyEights::dealCards()
{
  for(auto&& player : players)
  {
    for(auto i=0; i<5; ++i)
    {
      player->addCard(drawPile.back()); // remove card from deck to each player
      drawPile.pop_back();
    }
  }

  discardPile.push_back(drawPile.back()); // present first playable card
  drawPile.pop_back();
}

bool CrazyEights::isGameOver()
{
  return false;
}

bool CrazyEights::isValidMove(Card& card)
{
  card.print();
  // search each player's hand
  for(unsigned int i=0; i<players.size(); ++i)
  {
    for(unsigned int j=0; j<players[i]->getHand().size(); ++j)
    {
      if((card == players[i]->getHand()[j]) && (i == turn))
      {
        std::cout << "Clicked a card in player " << i << "'s hand\n";
        playCard(card);
        return true;
      }
    }
  }

  // check the draw pile
  if(card == drawPile.back())
  {
    std::cout << "Clicked on the draw pile\n";
    return drawCard();
  }

  // check the discard pile
  if(card == discardPile.back())
  {
    std::cout << "Clicked on the discard pile\n";
    return false;
  }

  return false;
}

void CrazyEights::playCard(Card& card)
{
  // play card
  std::cout << players[turn]->getName() << " is playing a card\n";
  discardPile.push_back(players[turn]->removeCard(card));
}

bool CrazyEights::drawCard()
{
  // draw card
  std::cout << players[turn]->getName() << " is drawing a card\n";
  if(drawPile.empty())
  {
      std::cout << "Draw pile is empty\n";
      return false;
  }
  
  players[turn]->addCard(drawPile.back());
  drawPile.pop_back();
  return true;
}

void CrazyEights::gameOver()
{
  // game over
}

bool CrazyEights::getMove(Card& card)
{
  return isValidMove(card);
}

void CrazyEights::nextTurn()
{
  turn = (turn+1) % players.size();
}
