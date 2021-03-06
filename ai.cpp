#include "ai.h"

AI::AI(wxString name) : Player(name) {
  // setup bot
}

int AI::play() {
  // search for same Suit
  for(unsigned int i=0; i<hand.size(); ++i)
    if(hand[i].getSuit() == playableSuit)
      return i;
  
  // search for same Rank
  for(unsigned int i=0; i<hand.size(); ++i)
    if(hand[i].getRank() == discardTop.getRank())
      return i;
  
  // search for 8
  for(unsigned int i=0; i<hand.size(); ++i)
    if(hand[i].getRank() == Value::EIGHT)
      return i;

  // draw
  return -1;
}

int AI::getHeartsCount()
{
  int count = 0;
  for(auto&& card : hand)
  {
    if(card.getSuit() == Suit::HEARTS)
      count++;
  }
  return count;
}

int AI::getSpadesCount()
{
  int count = 0;
  for(auto&& card : hand)
  {
    if(card.getSuit() == Suit::SPADES)
      count++;
  }
  return count;
}
int AI::getDiamondsCount()
{
  int count = 0;
  for(auto&& card : hand)
  {
    if(card.getSuit() == Suit::DIAMONDS)
      count++;
  }
  return count;
}
int AI::getClubsCount()
{
  int count = 0;
  for(auto&& card : hand)
  {
    if(card.getSuit() == Suit::CLUBS)
      count++;
  }
  return count;
}

Suit AI::chooseSuit()
{
  int heartsCount = getHeartsCount();
  int spadesCount = getSpadesCount();
  int diamondsCount = getDiamondsCount();
  int clubsCount = getClubsCount();

  if( (heartsCount > spadesCount) && (heartsCount > diamondsCount) && (heartsCount > clubsCount) )
  {
    std::cout << name + " chose Hearts\n";
    return Suit::HEARTS;
  }
  else if( (spadesCount > heartsCount) && (spadesCount > diamondsCount) && (spadesCount > clubsCount) )
  {
    std::cout << name + " chose Spades\n";
    return Suit::SPADES;
  }
  else if( (diamondsCount > heartsCount) && (diamondsCount > spadesCount) && (diamondsCount > clubsCount) )
  {
    std::cout << name + " chose Diamonds\n";
    return Suit::DIAMONDS;
  }
  else
  {
    std::cout << name + " chose Clubs\n";
    return Suit::CLUBS;
  }
}

void AI::setDiscard(Card card)
{
  discardTop = card;
}

void AI::setPlayableSuit(Suit suit)
{
  playableSuit = suit;
}
