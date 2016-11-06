#include"crazyEights.h"

CrazyEights::CrazyEights(std::vector<Player>&  players, wxPanel* drawParent, wxPanel* discardParent)
{
   this->players = players;
   this->drawPilePanel = new wxPanel(drawParent, wxID_ANY);
   this->discardPilePanel = new wxPanel(discardParent, wxID_ANY);
   drawPileSizer = new wxBoxSizer(wxHORIZONTAL);
   drawPilePanel->SetSizer(drawPileSizer);
   discardPileSizer = new wxBoxSizer(wxHORIZONTAL);
   discardPilePanel->SetSizer(discardPileSizer);
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

wxPanel* CrazyEights::getDrawPilePanel()
{
  return drawPilePanel;
}

wxPanel* CrazyEights::getDiscardPilePanel()
{
  return discardPilePanel;
}

std::vector<Player> CrazyEights::getPlayers()
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
      player.addCard(drawPile.back()); // remove card from deck to each player
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

bool CrazyEights::isValidMove()
{
  return true;
}

void CrazyEights::nextTurn()
{
  // get next turn
}

void CrazyEights::playCard()
{
  // play card
}

void CrazyEights::drawCard()
{
  // draw card
}

void CrazyEights::updateState()
{
  // update state
}

void CrazyEights::gameOver()
{
  // game over
}

void CrazyEights::updateDecks()
{
  drawPileSizer->Clear(true); // remove all children
  drawPileSizer->Add(Player::makeCard(drawPilePanel, drawPile.back(), false, Direction::UP, false));
  drawPileSizer->SetSizeHints(drawPilePanel);
  drawPileSizer->Layout();

  discardPileSizer->Clear(true); // remove all children
  discardPileSizer->Add(Player::makeCard(discardPilePanel, discardPile.back(), true, Direction::UP, false));
  discardPileSizer->SetSizeHints(discardPilePanel);
  discardPileSizer->Layout();
}
