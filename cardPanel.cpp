#include "cardPanel.h"

CardPanel::CardPanel(wxPanel* parent, Card& card, wxString file, wxBitmapType format, Direction dir, int width, int height)
  : wxImagePanel(parent, file, format, dir, width, height)
{
  this->card = card;
  this->direction = dir;
  this->width = width;
  this->height = height;
}

void CardPanel::mouseReleased(wxMouseEvent& evt)
{
    std::cout << "Suit: ";

    switch(card.getSuit())
    {
        case Suit::HEARTS:
            std::cout << "Hearts\n";
            break;
        case Suit::SPADES:
            std::cout << "Spades\n";
            break;
        case Suit::CLUBS:
            std::cout << "Clubs\n";
            break;
        case Suit::DIAMONDS:
            std::cout << "Diamonds\n";
            break;
        case Suit::UNDEFINED:
        default:
            std::cout << "Undefined\n";
            break;
    }

    std::cout << "Rank: ";

    switch(card.getRank())
    {
        case 2:
            std::cout << "2\n";
            break;
        case 3:
            std::cout << "3\n";
            break;
        case 4:
            std::cout << "4\n";
            break;
        case 5:
            std::cout << "5\n";
            break;
        case 6:
            std::cout << "6\n";
            break;
        case 7:
            std::cout << "7\n";
            break;
        case 8:
            std::cout << "8\n";
            break;
        case 9:
            std::cout << "9\n";
            break;
        case 10:
            std::cout << "10\n";
            break;
        case 11:
            std::cout << "Jack\n";
            break;
        case 12:
            std::cout << "Queen\n";
            break;
        case 13:
            std::cout << "King\n";
            break;
        case 14:
            std::cout << "Ace\n";
            break;
        default:
            std::cout << "Undefined\n";
            break;
    }
    
    /*
    for(auto&& c : crazyEights.getDrawPile())
    {
      if(card == c)
          std::cout << "Inside the Draw Pile\n";
    }
    for(auto&& c : crazyEights.getDiscardPile())
    {
      if(card == c)
          std::cout << "Inside the Discard Pile\n";
    }
    for(auto&& player : crazyEights.getPlayers())
    {
      for(auto&& c : player.getPlayerHand())
      {
        if(card == c)
        {
          switch(player.getDirection())
          {
            case UP:
                std::cout << "Inside the Top Player's Hand\n";
                break;
            case DOWN:
                std::cout << "Inside the Bottom Player's Hand\n";
                break;
            case LEFT:
                std::cout << "Inside the Left Player's Hand\n";
                break;
            case RIGHT:
                std::cout << "Inside the Right Player's Hand\n";
                break;
            default:
                std::cout << "Error\n";
                break;
          }
        }
      }
    }
    */
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
