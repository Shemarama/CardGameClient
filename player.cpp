#include"player.h"

Player::Player(wxString newName)
{
  this->hand = std::vector<Card>();
  this->name = newName;
  this->isReady = false;
  this->isMyTurn = false;
} 

void Player::addCard(Card& card)
{
  hand.push_back(card);
}

Card Player::removeCard()
{
  Card c = hand.back();
  hand.pop_back();
  return c;
}

wxString Player::getName()
{
  return name;
}

void Player::setName(wxString name)
{
  this->name = name;
}

std::vector<Card> Player::getHand()
{
  return hand;
}

void Player::setTurn(bool isTurn)
{
  isMyTurn = isTurn;
}

bool Player::getTurn()
{
  return isMyTurn;
}

void Player::setReady(bool isReady)
{
  this->isReady = isReady;
}

bool Player::getReady()
{
  return isReady;
}
