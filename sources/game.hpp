#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "player.hpp"
namespace ariel{
    class Game{
    private:
    Player &p1;
    Player &p2;
    std::vector<Card> pile;
    std::vector<string> gameHisory;
    int turns=0;
    int tempcountDraw = 0;
    int countdraws = 0;
        public :
        //constrcturs
        Game(Player& player1, Player& player2);
        void CreateAndDealPile(std::vector<Card>& pile,Player& player1,Player& player2);
        // operations
        void playTurn();
        void playAll();
        void printLastTurn() ;
        void printLog() ;
        void printWiner() ;
        void printStats() ;

};
}
