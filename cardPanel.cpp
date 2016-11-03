#include "cardPanel.h"

CardPanel::CardPanel(wxPanel* parent, Card card, wxString file, wxBitmapType format, Direction dir, int width, int height)
    : wxImagePanel(parent, file, format, dir)
{
  this->card = card;
  this->direction = dir;
  // switches width and height depending on direction
  switch(dir)
  {
    case UP:
    case DOWN:
        this->SetMinSize(wxSize(width, height));
        this->SetMaxSize(wxSize(width, height));
        break;
    case LEFT:
    case RIGHT:
        this->SetMinSize(wxSize(height, width));
        this->SetMaxSize(wxSize(height, width));
        break;
    default:
        break;
  }
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
