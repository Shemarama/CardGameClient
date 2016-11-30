#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <vector>
#include <wx/wx.h>

class Player {
protected:
  // player's hand
  std::vector<Card> hand;
  // player's name
  wxString name;
  // flag to tell if it is the user's turn
  bool isMyTurn;
  bool isReady;

public:
  Player(wxString newName);
  void addCard(Card &card);
  Card removeCard(Card &card);
  void clearHand();
  wxString getName();
  void setName(wxString name);
  std::vector<Card> getHand();
  void setTurn(bool isTurn);
  bool getTurn(); // will let us know when it's is our turn
  void setReady(bool isReady);
  bool getReady();
};
#endif
