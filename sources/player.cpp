#include <iostream>
#include "player.hpp"
namespace ariel{

Player::Player(std::string name)
{
    this->name = name;
    this->cardsWon = 0;
}

int Player::cardesTaken()
{
    return this->cardsWon;}

int Player::stacksize()
{
    return this->cards.size();}

std::string Player::getName()
{
    return this->name;}

void Player::AddCards(Card card)
{
    this->cards.push_back(card);
}
void Player::SetCardsWon(int num)
{
    this->cardsWon += num;//mvoe to cpp 
}
int Player::getCardsWon()
{
    return this->cardsWon;
}
int Player::getWins(){
    return this->wins;
}
    Card Player::playCard() {
		Card card = cards.front();// returns a referens to the first element in the vector
		cards.erase(cards.begin());// erase the first card in the vector 
		cards.shrink_to_fit(); // redouce the capacity i did it to save sapace
        return card;
	}
}