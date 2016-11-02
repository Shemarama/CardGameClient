#include "card.h"

Card::Card(Suit suit, int rank)
{
  this->suit = suit;
  this->rank = rank;
}

Suit Card::getSuit()
{
  return suit;
}

int Card::getRank()
{
  return rank;
}
