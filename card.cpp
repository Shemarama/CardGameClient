#include "card.h"

Card::Card() {
  this->suit = Suit::UNDEFINED;
  this->rank = Value::TWO;
}

Card::Card(Suit suit, Value rank) {
  this->suit = suit;
  this->rank = rank;
}

Suit Card::getSuit() { return this->suit; }

Value Card::getRank() { return this->rank; }

bool Card::operator==(Card &otherCard) {
  if (this->suit == otherCard.getSuit() && this->rank == otherCard.getRank())
    return true;
  else
    return false;
}

void Card::print() {
  std::cout << "Suit: ";

  switch (suit) {
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

  switch (rank) {
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
