#ifndef AI_H
#define AI_H
#include "player.h"

class AI : public Player {
private:
  Card discardTop;
public:
  AI(wxString name);
  void play();
  void setDiscard(Card card);
};

#endif
