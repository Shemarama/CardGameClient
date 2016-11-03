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
   setDeck();
   discardPile = std::vector<Card>();
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
    drawPile = std::vector<Card>();
    std::vector<Suit> suits = {HEARTS, SPADES, CLUBS, DIAMONDS};
    for(auto && suit : suits)
    {
        for(int i = 2; i < 15: i++)
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
      player.AddCard(drawPile.pop_back()); // remove card from deck to each player
    }
  }

  discardPile.push_back(drawPile.pop_back()); // present first playable card
}

void CrazyEights::updateDecks()
{
  drawPileSizer->Clear(true); // remove all children
  drawPileSizer->Add(new CardPanel(drawPilePanel, drawPile[drawPile.size()-1], wxT("../resources/pictures/card/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
  drawPileSizer->SetSizeHints(drawPilePanel);

  discardPileSizer->Clear(true); // remove all children
  discardPileSizer->Add(new CardPanel(discardPilePanel, discardPile[discardPile.size()-1], wxT("../resources/pictures/card/cardBack.png"), wxBITMAP_TYPE_PNG, Direction::UP, cardWidth, cardHeight), 0, wxALIGN_CENTER, 0);
  discardPileSizer->SetSizeHints(discardPilePanel);


}
