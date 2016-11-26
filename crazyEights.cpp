#include "crazyEights.h"

CrazyEights::CrazyEights(std::vector<Player *> &players) {
  this->players = players;
  // create cards and place in deck
  setDeck();
  discardPile = std::vector<Card>();
  turn = 0;
}

void CrazyEights::setCurrentSuit(Suit newSuit) { currentSuit = newSuit; }

Suit CrazyEights::getCurrentSuit() { return currentSuit; }

std::vector<Card> CrazyEights::getDrawPile() { return drawPile; }

std::vector<Card> CrazyEights::getDiscardPile() { return discardPile; }

std::vector<Player *> CrazyEights::getPlayers() { return players; }

void CrazyEights::refillDeck() {
  Card card = discardPile.back();
  discardPile.pop_back(); // for no duplicate card

  while (!discardPile.empty()) {
    drawPile.push_back(discardPile.back());
    discardPile.pop_back();
  }
  shuffleDeck();
  discardPile.push_back(card);
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
      std::cout << "Clicked a card in " << players[turn]->getName()
                << "'s hand\n";
      // playCard(card);
      return true;
    }
  }
  return false;
}

// check if a card is in the top of the draw pile
bool CrazyEights::isInDrawPile(Card &card) {
  if (card == drawPile.back()) {
    std::cout << "Clicked on the draw pile\n";
    // return drawCard();
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
  card.print();
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
void CrazyEights::playCard(Card &card) {
  // play card
  std::cout << players[turn]->getName() << " is playing a card\n";
  discardPile.push_back(players[turn]->removeCard(card));
}

bool CrazyEights::drawCard() {
  // draw card
  std::cout << players[turn]->getName() << " is drawing a card\n";
  if (drawPile.empty()) {
    std::cout << "Draw pile is empty\n";
    return false;
  }

  players[turn]->addCard(drawPile.back());
  drawPile.pop_back();

  return true;
}

void CrazyEights::gameOver() {
  // game over
}

bool CrazyEights::getMove(Card &card) {
  if (isValidMove(card)) {
    if (isInHand(card))
      playCard(card);
    if (isInDrawPile(card))
      drawCard();
    return true;
  } else
    return false;
}

void CrazyEights::nextTurn() { turn = (turn + 1) % players.size(); }
