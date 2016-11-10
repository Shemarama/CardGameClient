#include "cardPanel.h"
#include "gameScreen.h"

CardPanel::CardPanel(wxPanel* parent, Card& card, wxString file, wxBitmapType format, Direction dir, int width, int height)
  : wxImagePanel(parent, file, format, dir, width, height)
{
  this->parent = parent;
  this->card = card;
  this->direction = dir;
  this->width = width;
  this->height = height;
}

void CardPanel::mouseReleased(wxMouseEvent& evt)
{
    // card -> place on table -> table -> root -> gameScreen
    GameScreen *gs = (GameScreen *) parent->GetParent()->GetParent()->GetParent();
    gs->test(card);
}

Card CardPanel::getCard()
{
  return card;
}

Direction CardPanel::getDirection()
{
  return direction;
}

int CardPanel::getWidth()
{
  return width;
}

int CardPanel::getHeight()
{
  return height;
}
