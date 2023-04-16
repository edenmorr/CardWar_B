#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
#include <random>
using namespace std;

namespace ariel {
    void CreateAndDealPile(std::vector<Card> pile,Player& p1,Player& p2)
    {
        pile.clear();
        for(int i = 1; i <= 13;i++)
        {
            pile.push_back(Card("Hearts",i));
            pile.push_back(Card("Spades",i));
            pile.push_back(Card("Clubs",i));
            pile.push_back(Card("Diamonds",i));
        }
        // google !!! randomize deck
        random_device rand;
        mt19937 g(rand());
        shuffle(pile.begin(),pile.end(),g);

        for(unsigned long int i = 0;i<pile.size();i++)
        {
            if(i % 2 == 0){
                p1.AddCards(pile[i]);
            }
            else{
                p2.AddCards(pile[i]);
            }
        }
    }

    Game::Game(Player &p1, Player &p2) : p1(p1), p2(p2)
    {
        this->countdraws = 0;
        vector<Card> pile;
        CreateAndDealPile(pile,p1,p2);
    }

    // void Game::playTurn() {
    //     Card card1 = p1.playCard();
    //     Card card2 = p2.playCard();

    //     pile.push_back(card1);
    //     pile.push_back(card2);

    //     if (isDraw(card1, card2)) {
    //         countdraws++;
    //         gameLog << p1.getName() << " played " << card1.toString() << " " << p2.getName() << " played " << card2.toString() << ". Draw.\n";
    //         return;
    //     }

    //     Player &winner = (card1 > card2) ? player1 : player2;
    //     winner.takeCards(pile);
    //     printTurnResult(card1, card2, winner);
    //     pile.clear();
    // }

    // bool Game::isDraw(const Card &card1, const Card &card2) {
    //     return card1.getRank() == card2.getRank();
    // }

    // void Game::playAll() {
    //     while (player1.hasCards() && player2.hasCards()) {
    //         playTurn();
    //     }
    // }

    // void Game::printLastTurn() const {
    //     std::string lastTurn = gameLog.str();
    //     if (lastTurn.empty()) {
    //         std::cout << "No turns played yet." << std::endl;
    //     } else {
    //         std::cout << lastTurn;
    //     }
    // }

    // void Game::printLog() const {
    //     std::string log = gameLog.str();
    //     if (log.empty()) {
    //         std::cout << "No turns played yet." << std::endl;
    //     } else {
    //         std::cout << log;
    //     }
    // }

    // void Game::printTurnResult(const Card &card1, const Card &card2, const Player &winner) {
    //     gameLog << winner.getName() << " won " << pile.size() << " cards: ";
    //     for (const Card &card : pile) {
    //         gameLog << card.toString() << " ";
    //     }
    //     gameLog << "(" << card1.toString() << " vs " << card2.toString() << "). " << winner.getName() << " wins.\n";
    // }

    // void Game::printWiner() const {
    //     if (player1.stacksize() > player2.stacksize()) {
    //         std::cout << "The winner is " << player1.getName() << std::endl;
    //     } else if (player1.stacksize() < player2.stacksize()) {
    //         std::cout << "The winner is " << player2.getName() << std::endl;

    //     }
    // }
}


