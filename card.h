#ifndef CARD_H
#define CARD_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS, UNDEFINED};

enum Value
{
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9,
  TEN = 10,
  JACK = 11,
  QUEEN = 12,
  KING = 13,
  ACE = 14
};

class Card
{
  private:
    Suit suit;
    Value rank;
  public:
    Card();
    Card(Suit suit, Value rank);
    Suit getSuit();
    Value getRank();
    bool operator==(Card& otherCard);
};

#endif
