#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "player.hpp"
namespace ariel{
    class Game{
    public:
    Player &p1;
    Player &p2;
    std::vector<Card> pile;
    std::vector<string> gameHisory;
    int turns=0;
    // void printTurnResult( Card &card1,  Card &card2, Player &winner);
    // bool isDraw( Card &card1,  Card &card2);
    int countdraws;
        public :
        //constrcturs
        Game(Player& p1, Player& p2);
        // operations
        void playTurn();
        void playAll();
        void printLastTurn() ;
        void printLog() ;
        void printWiner() ;
        void printStats() ;

};
}
