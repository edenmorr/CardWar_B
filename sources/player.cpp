#include <iostream>
#include "player.hpp"
namespace ariel{

Player::Player(std::string name)
{
    this->name = name;
}

int Player::cardesTaken()
{
    return this->WiningCardsPile.size();}

int Player::stacksize()
{
    return this->cards.size();}

void Player::winPile(Card& win) {
    this->WiningCardsPile.push_back(win);
}
std::string Player::getName()
{
    return this->name;}

void Player::AddCards(Card card)
{
    this->cards.push_back(card);
}

int Player::getWins() {
    return wins;
}

int Player::getLoos() {
    return loos;
}
    Card Player::playCard() {
		Card card = cards.front();// returns a referens to the first element in the vector
		cards.erase(cards.begin());// erase the first card in the vector 
		cards.shrink_to_fit(); // redouce the capacity i did it to save sapace
        return card;
	}
	
}