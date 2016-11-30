#ifndef AI_H
#define AI_H
#include "player.h"
#include <algorithm>

class AI : public Player {
private:
  Card discardTop;
  Suit playableSuit;
public:
  AI(wxString name);
  int play();
  int getHeartsCount();
  int getSpadesCount();
  int getDiamondsCount();
  int getClubsCount();
  Suit chooseSuit();
  void setDiscard(Card card);
  void setPlayableSuit(Suit suit);
};

#endif
