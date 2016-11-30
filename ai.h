#ifndef AI_H
#define AI_H
#include "player.h"
#include <algorithm>

class AI : public Player {
private:
  Card discardTop;
public:
  AI(wxString name);
  int play();
  int getHeartsCount();
  int getSpadesCount();
  int getDiamondsCount();
  int getClubsCount();
  Suit chooseSuit();
  void setDiscard(Card card);
};

#endif
