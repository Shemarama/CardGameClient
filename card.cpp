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
  return this->suit;
}

Value Card::getRank()
{
  return this->rank;
}

bool Card::operator==(Card& otherCard)
{
  if(this->suit == otherCard.getSuit() && this->rank == otherCard.getRank())
      return true;
  else
      return false;
}

