#include "cardPanel.h"
#include "crazyEightsScreen.h"

CardPanel::CardPanel(wxPanel *parent, Card &card, wxString file,
                     wxBitmapType format, Direction dir, int width, int height)
    : wxImagePanel(parent, file, format, dir, width, height) {
  this->parent = parent;
  this->card = card;
  this->direction = dir;
  this->width = width;
  this->height = height;
}

CardPanel::~CardPanel() {
  // std::cout << "Card Panel Destroyed\n";
}

void CardPanel::mouseReleased(wxMouseEvent &WXUNUSED(evt)) {
  // std::cout << "Inside cardPanel.cpp\n";
  // card.print();

  // cardPanel -> hands/decks -> table -> root -> gameScreen
  CrazyEightsScreen *gs =
      (CrazyEightsScreen *)parent->GetParent()->GetParent()->GetParent();
  if (gs->onClick(card)) {
    // delete this;
  }
}

Card CardPanel::getCard() { return card; }

Direction CardPanel::getDirection() { return direction; }

int CardPanel::getWidth() { return width; }

int CardPanel::getHeight() { return height; }
