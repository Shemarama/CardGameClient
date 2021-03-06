#include "crazyEights.h"

CrazyEights::CrazyEights(std::vector<Player *> &players) {
  this->players = players;
  // create cards and place in deck
  setDeck();
  discardPile = std::vector<Card>();
  turn = 0;
  timesDrawn = 0;
}

void CrazyEights::setCurrentSuit(Suit newSuit) { currentSuit = newSuit; }

Suit CrazyEights::getCurrentSuit() { return currentSuit; }

std::vector<Card> CrazyEights::getDrawPile() { return drawPile; }

std::vector<Card> CrazyEights::getDiscardPile() { return discardPile; }

std::vector<Player *> CrazyEights::getPlayers() { return players; }

Player* CrazyEights::getCurrentPlayer()
{
  return players[turn];
}

void CrazyEights::refillDeck() {
  Card card = discardPile.back();
  discardPile.pop_back(); // for no duplicate card

  while (!discardPile.empty()) {
    drawPile.push_back(discardPile.back());
    discardPile.pop_back();
  }
  shuffleDeck();
  discardPile.push_back(card);
  setCurrentSuit(discardPile.back().getSuit());
}

void CrazyEights::shuffleDeck() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::shuffle(drawPile.begin(), drawPile.end(), generator);
}

void CrazyEights::setDeck() {
  drawPile = std::vector<Card>();
  std::vector<Suit> suits = {HEARTS, SPADES, CLUBS, DIAMONDS};
  for (auto &&suit : suits) {
    for (int i = 2; i < 15; i++)
      drawPile.push_back(Card(suit, static_cast<Value>(i)));
  }
  shuffleDeck();
}

void CrazyEights::dealCards() {
  for (auto &&player : players) {
    for (auto i = 0; i < 5; ++i) {
      player->addCard(drawPile.back()); // remove card from deck to each player
      drawPile.pop_back();
    }
  }

  discardPile.push_back(drawPile.back()); // present first playable card
  drawPile.pop_back();
  setCurrentSuit(discardPile.back().getSuit());
}

Player *CrazyEights::getWinner() {
  for (auto &&player : players) {
    if (player->getHand().size() == 0)
      return player;
  }
  return nullptr;
}

// check if a player has no cards in their hand
bool CrazyEights::isGameOver() {
  for (auto &&player : players) {
    if (player->getHand().size() == 0)
      return true;
  }
  return false;
}

// check if a card is in a player's hand
bool CrazyEights::isInHand(Card &card) {
  for (auto &&c : players[turn]->getHand()) {
    if (card == c) {
      return true;
    }
  }
  return false;
}

// check if a card is in the top of the draw pile
bool CrazyEights::isInDrawPile(Card &card) {
  if (card == drawPile.back()) {
    return true;
  } else
    return false;
}

// check if a card is in the top of the discard pile
bool CrazyEights::isInDiscardPile(Card &card) {
  if (card == discardPile.back()) {
    std::cout << "Clicked on the discard pile\n";
    return true;
  } else
    return false;
}

// check if a chosen card is valid
bool CrazyEights::isValidMove(Card &card) {
  //card.print();
  // search each player's hand
  if (isInHand(card))
    return true;

  // check the draw pile
  if (isInDrawPile(card))
    return true;

  // check the discard pile
  if (isInDiscardPile(card))
    return false;

  return false;
}

// play a card from the current player's hand to the discard pile
bool CrazyEights::playCard(Card &card) {
  // play card
  std::cout << players[turn]->getName() << " is playing a card\n\n";

  // if rank or suit matches or is an 8
  if( (card.getRank() == discardPile.back().getRank()) || 
      (card.getSuit() == currentSuit) ||
      (card.getRank() == Value::EIGHT) )
  {
    discardPile.push_back(players[turn]->removeCard(card));
    setCurrentSuit(discardPile.back().getSuit());
    timesDrawn = 0;
    return true;
  }

  // else, is invalid
  std::cout << "Invalid Move\n";
  return false;
}

bool CrazyEights::drawCard() {
  // draw card
  std::cout << players[turn]->getName() << " is drawing a card\n\n";
  if (drawPile.empty()) {
    std::cout << "Draw pile is empty\n";
    return false;
  }

  if(timesDrawn > 2)
  {
    std::cout << "Ran out of draws\n";
    timesDrawn = 0;
    return false;
  }

  players[turn]->addCard(drawPile.back());
  drawPile.pop_back();
  timesDrawn++;
  
  return true;
}

bool CrazyEights::getMove(Card &card) {
  if (isValidMove(card)) {
    if (isInHand(card))
      return playCard(card);
    if (isInDrawPile(card))
      return drawCard();
  }

  return false;
}

// gets next player's turn
void CrazyEights::nextTurn() { turn = (turn + 1) % players.size(); }

// resets the game
void CrazyEights::reset() {
  while (!drawPile.empty()) {
    drawPile.pop_back();
  }

  while (!discardPile.empty()) {
    discardPile.pop_back();
  }

  for (auto &&player : players) {
    player->clearHand();
  }

  turn = 0;
}
