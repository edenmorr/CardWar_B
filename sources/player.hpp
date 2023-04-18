#include <iostream>
#include <string>
#include "card.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#pragma once
namespace ariel{
    class Player{
        public:
        //coutns winning hands == points
        int cardsWon;
        // int wins;
        // int loos;
        std::vector<Card> WiningCardsPile;
        std::string name;
        std::vector<Card> cards; 
        //constuctors
        Player(){}
        Player(std::string name);
         // operations
        int cardesTaken(); //test
        int stacksize(); //test
        // int getWins();
        // int getLoos();
        void AddCards(Card card);
        // void winPile(Card& win);
        std::string getName();
        Card playCard();
        void SetCardsWon(int num);
        int getCardsWon();
        };
    }
