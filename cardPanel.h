#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "card.h"
#include "imagePanel.h"

class CardPanel : public wxImagePanel
{
  private:
    wxPanel* parent;
    Card card;
    Direction direction;
    int width;
    int height;

  public:
    CardPanel(wxPanel* parent, Card& card, wxString file, wxBitmapType format, Direction dir, int width, int height);
    ~CardPanel();

    void mouseReleased(wxMouseEvent& evt);
    wxString findHalfImage();
    wxString findFullImage();
    Card getCard();
    Direction getDirection();
    int getWidth();
    int getHeight();
};

#endif
