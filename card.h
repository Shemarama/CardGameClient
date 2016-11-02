#ifndef CARD_H
#define CARD_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "imagePanel.h"

enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS, UNDEFINED};

class Card : public wxImagePanel
{
  private:
    Suit suit;
    int rank;
    Direction direction;
    int width;
    int height;

  public:
    Card(wxPanel* parent, Suit suit, int rank, wxString file, wxBitmapType format, Direction dir, int width, int height);

    void mouseReleased(wxMouseEvent& evt);
    Suit getSuit();
    int getRank();
    Direction getDirection();
    int getWidth();
    int getHeight();
};

#endif
