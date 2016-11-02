#ifndef CARD_H
#define CARD_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS, UNDEFINED};

class Card
{
  private:
    Suit suit;
    int rank;
  public:
    Card(Suit suit, int rank);
    Suit getSuit();
    int getRank();
}

#endif
