#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
#include <random>
#include <cstring>
#include <algorithm>
using namespace std;

namespace ariel {
    void Game::CreateAndDealPile(std::vector<Card>& pile,Player& p1,Player& p2)
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
        // pile = test_deck();
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
        string turnHistory;//log
        Card p1Card = p1.playCard();
        Card p2Card = p2.playCard();
        if(p1Card.getFaceValue() == p2Card.getFaceValue())
        {
            turnHistory = p1.getName() + " played " + p1Card.ToString() + " " + p2.getName() + " played " + p2Card.ToString() +
            ". draw.";
            gameHisory.push_back(turnHistory);
            turns++;
            this->tempcountDraw ++;
            this->countdraws ++ ;
            //draw and end
            if(this->p1.stacksize() == 0)
            {
                // 1 for the first open hand
                // this->tempcountDraw -1)  * 2
                this->p1.SetCardsWon(1 + ((this->tempcountDraw -1)  * 2));
                this->p2.SetCardsWon(1 + ((this->tempcountDraw -1)  * 2));
            }
            //draw put card face down end 
            else if(this->p1.stacksize() == 1)
            {
                this->p1.SetCardsWon((this->tempcountDraw)  * 2);
                this->p2.SetCardsWon((this->tempcountDraw)  * 2);
                this->p1.playCard();
                this->p2.playCard();
            }
            //middel
            else
            {
                this->p1.playCard();
                this->p2.playCard();
                playTurn();
            }
        }
        //p1 wins 
        if((p1Card.getFaceValue() > p2Card.getFaceValue() && p2Card.getFaceValue() != 1) ||
        (p1Card.getFaceValue() == 1 && p2Card.getFaceValue() != 2) ||
        (p1Card.getFaceValue() == 2 && p2Card.getFaceValue() == 1))
        {

            // add points 
            this->p1.SetCardsWon(2 + (tempcountDraw)*4); 
            // reset tempcountdraw
            if(tempcountDraw!=0){
            tempcountDraw=0;
            }
            turnHistory = p1.getName() + " played " + p1Card.ToString() + " " + p2.getName() + " played " + p2Card.ToString() +
                "." +p1.getName() + " win.";
            gameHisory.push_back(turnHistory);
            turns++;
            return;
        }
        //p2 wins 
        if((p2Card.getFaceValue() > p1Card.getFaceValue() && p1Card.getFaceValue() != 1) ||
        (p2Card.getFaceValue() == 1 && p1Card.getFaceValue() != 2) ||
        (p2Card.getFaceValue() == 2 && p1Card.getFaceValue() == 1))
        {
            // add points 
            this->p2.SetCardsWon(2 + (tempcountDraw)*4);
            // reset tempcountdraw
            if(tempcountDraw!=0){
            tempcountDraw=0;
            }
            turnHistory = p1.getName() + " played " + p1Card.ToString() + " " + p2.getName() + " played " + p2Card.ToString() +
                "." +p2.getName() + " win.";
            gameHisory.push_back(turnHistory);
            turns++;
            return;
        }
        }
    void Game::playAll()
    {
        while (p1.stacksize()!=0 && p2.stacksize()!=0) {
            playTurn();
        }
    }
    void Game::printLastTurn(){
        int index = this->gameHisory.size()-1;
        if(index == -1)
        {
            throw "log is empty" ;
        }
        //only one log in game log 
        if(index == 0)
        {
            // print
            cout << this->gameHisory.back() << endl;
        }
        //now index is the last entry to log
        //index at least  >= 1
        //get one before last
        index --;
        string temp = this->gameHisory[static_cast<unsigned long int>(index)];
        while(temp.substr(temp.length() - 4) != "win."&& index > 0)
        {
            index --;
          temp = this->gameHisory[static_cast<unsigned long int>(index)];

        }
        //temp is not draw temp is win !!!
        //start printing from index + 1
        for (unsigned long int i = static_cast<unsigned long int>(index + 1); i < this->gameHisory.size(); i++)
        {
            cout << this->gameHisory[i] ;
        }
        cout << endl;
    }
    void Game::printLog() {
        cout
            << "printing log..."
            << endl;
    for (string log: gameHisory) {
        if(log.substr(log.size()-5 ) == "draw.")
        {
            cout << log ;
        }
        if(log.substr(log.size()-4 )== "win.")
        {
            cout << log << endl;
        }
        }
        string last= this->gameHisory[this->gameHisory.size()-1];
        if(last.substr(last.size()-5) == "draw.")
        {
            cout << endl; 
        }
    }
    void Game::printWiner(){
    if (this->p1.getCardsWon() > this->p2.getCardsWon()) {
        cout << p1.getName() << endl;
    }
    else if (this->p1.getCardsWon() < this->p2.getCardsWon()) {
        cout << p2.getName() << endl;
    } else {
        cout << "DRAW!" << endl;
    }
    }
    void Game::printStats(){
    cout<<turns<<endl;
    cout<< "amount of draws: "<<countdraws<<endl;
    cout << "player1:"<< endl;
    cout << "cards taken: " << p1.cardesTaken()<< endl;
    cout<< "draw rate: "<<(countdraws/turns)<<endl;
    cout<< "score rate: "<<(int)(turns/p1.cardesTaken())<<endl;
    cout << "player2:"<< endl;
    cout << "cards taken: " << p2.cardesTaken()<< endl;
    cout<< "draw rate: "<<(countdraws/turns)<<endl;
    cout<< "win rate: " <<(p2.cardesTaken()/turns)<<endl;
    }
}




