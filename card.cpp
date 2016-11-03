#include "card.h"

Card::Card(Suit suit, Value rank)
{
  this->suit = suit;
  this->rank = rank;
}

Suit Card::getSuit()
{
  return suit;
}

Value Card::getRank()
{
  return rank;
}
