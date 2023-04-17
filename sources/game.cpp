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

    void Game::playTurn() {
        if(p1.stacksize() == 0 || p2.stacksize()== 0)
        {
            throw "end of game";
        }
        if(&p1 == &p2)
        {
            throw "same player playing himself";
        }
        vector<Card> pileNumber1;
        vector<Card> pileNumber2;
        string turnHistory;//log
        Card p1Card = p1.playCard();
        Card p2Card = p2.playCard();
        while (p1.stacksize() != 0 && p2.stacksize() != 0){
        pileNumber1.push_back(p1.playCard());//puting the cards thet the players pop in two different piles
        pileNumber2.push_back(p2.playCard());
        turnHistory.clear();
        turnHistory = to_string(this->turns++)+")   "+p1.getName() + " played " + pileNumber1.front().ToString() + " " + p2.getName() + " played " + pileNumber2.front().ToString() +
              ".";
        //p1 wins 
        if((p1Card.getFaceValue() > p2Card.getFaceValue() && p2Card.getFaceValue() != 1) ||
        (p1Card.getFaceValue() == 1 && p2Card.getFaceValue() != 2) ||
        (p1Card.getFaceValue() == 2 && p2Card.getFaceValue() == 1))
        {
            p2.loos++;
            p1.wins++;
            turnHistory.append(" " + p1.getName() + " wins.");
              while (!pileNumber1.empty() && !pileNumber2.empty()) {
                p1.winPile(pileNumber2.front());
                p1.winPile(pileNumber1.front());
                pileNumber1.pop_back();
                pileNumber2.pop_back();
            }
            gameHisory.push_back(turnHistory);
            return;
        }
        //p2 wins 
        if((p2Card.getFaceValue() > p1Card.getFaceValue() && p1Card.getFaceValue() != 1) ||
        (p2Card.getFaceValue() == 1 && p1Card.getFaceValue() != 2) ||
        (p2Card.getFaceValue() == 2 && p1Card.getFaceValue() == 1))
        {
        p1.loos++;
        p2.wins++;
        turnHistory.append(" " + p2.getName() + " wins.");
           while (!pileNumber1.empty() && !pileNumber2.empty()) {
                p2.winPile(pileNumber2.front());
                p2.winPile(pileNumber1.front());
                pileNumber1.pop_back();
                pileNumber2.pop_back();

            }
            gameHisory.push_back(turnHistory);
            return;
        }
          else if  (p2.stacksize() == 0 || p1.stacksize() == 0) {

             while (!pileNumber1.empty() && !pileNumber2.empty()) {
                p2.winPile(pileNumber2.front());
                p1.winPile(pileNumber1.front());
                pileNumber1.pop_back();
                pileNumber2.pop_back();
                }


            } else {//draw
                turnHistory.append("Draw. ");
                pileNumber1.push_back(p1.playCard());
                pileNumber2.push_back(p2.playCard());
            }

        }
        gameHisory.push_back(turnHistory);
        cout<< turnHistory<<endl;
    }
    void Game::playAll(){
        try{
        while (this->p1.stacksize()!=0 && this->p2.stacksize()!=0) {
            playTurn();
        }
            }catch (const char *error) {
        std::cerr << "Error:check play turn! " << error << std::endl;
    }
    }
    void Game::printLastTurn(){
        cout << this->gameHisory.back();
    }
    void Game::printLog() {
        cout
            << "printing log..."
            << endl;
    for (string log: gameHisory) {
        cout << log << endl;
    }
    }
    void Game::printWiner(){
    if (this->p1.WiningCardsPile.size() > p2.WiningCardsPile.size()) {
        cout << p1.getName() << endl;
        return;
    }
    if (this->p1.WiningCardsPile.size() < p2.WiningCardsPile.size() ) {
        cout << p2.getName() << endl;
        return;
    } else {
        cout << "DRAW!" << endl;
    }
    }
    void Game::printStats(){
    cout << "player1:"<< endl;

      cout << "cards taken: " << p1.cardesTaken()<< endl;
                   cout<< "wins: "<<endl;
        cout << p1.getWins() << endl;
                    cout<<"loses: " << p1.getLoos() << endl;
        cout << "score:" << ((double)(p1.getWins())/(double)(p1.getLoos())) << endl;
                    cout<<"player2:"<< endl;
                   cout<< "cards taken: "<<endl;
         cout<< p2.cardesTaken() << endl;
                    cout<<"wins: " << p2.getWins() << endl;
                    cout<<"loses: " << p2.getLoos() << endl;
         cout<< "score:" << ((double)(p2.getWins())/(double)(p2.getLoos()));

    }
}




