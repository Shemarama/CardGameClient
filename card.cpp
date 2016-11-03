#include "card.h"

Card::Card()
{
  this->suit = Suit::UNDEFINED;
  this->rank = Value::TWO;
}

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
