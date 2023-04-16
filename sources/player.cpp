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
    // void Player::addCard(Card card) { // push to the end of the vector
    //     cards.push_back(card);
    // }

    // void Player::takeCards(std::vector<Card> &cards) { // this function is for when the player that will win the round thak the cards 
    //     this->cards_drawn += cards.size(); 
    //     for (Card &card : cards) { 
    //         addCard(card); 
    // }
	// }

    // bool Player::hasCards() { // to cheack if the players has cards to desids how wins  
    //     return !cards.empty();
    // }
	
    // Card Player::playCard() {
	// 	if(hasCards())
	// 	{
	// 	Card card = cards.front();// returns a referens to the first element in the vector
	// 	cards.erase(cards.begin());// erase the first card in the vector 
	// 	cards.shrink_to_fit(); // redouce the capacity i did it to save sapace
    //     return card;
	// 	}
	//     throw std::out_of_range("Player " + name + " has no cards!");
	// }
	
}