#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "player.hpp"
namespace ariel{
    class Game{
    public:
    Player& p1;
    Player& p2;
    std::vector<Card> pile;
    std::vector<string> gameHisory;

    // void printTurnResult( Card &card1,  Card &card2, Player &winner);
    // bool isDraw( Card &card1,  Card &card2);
    int countdraws;
        public :
        //constrcturs
        Game();
        Game(Player& p1, Player& p2);
        // operations
        void playTurn();
        void playAll();
        void printLastTurn() const;
        void printLog() const;
        void printWiner() const;
        void printStats() const;

};
}
