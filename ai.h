#ifndef AI_H
#define AI_H
#include "player.h"

class AI : public Player {
private:
public:
  AI(wxString name);
  void play();
};

#endif
