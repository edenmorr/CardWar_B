#include <iostream>
#include <string>
#pragma once
using std::string;
namespace ariel{
    
// enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
// enum Suit {diamond, club, heart, spade};


class Card {
	private://FIELEDS NAMES
		string suit;
		int faceValue;
public:
    Card(string s, int r);//: suit(s), faceValue(r){};

	string getSuit() { return suit; }
	int getRank() { return faceValue; }

	// static std::string suitName(Suit s);
	// static std::string RankName(Rank v);
	string ToString();
};
}




































//         public://constructors
//         Card();//initialize a card with given difult values
//         Card(suit,Rank);//initialize a card with given values
//         //datas filed
//         Rank rank;
//         suit suit;
//    // int values;
//    struct deck{
//      std::vector<Card> cards;
//      std::string card_back;
//      int max_deck=52;
//    };
//    void initialize(deck& deck);
        
 

//     //   int rank;     // hold rank of card
// 	//   string  deck; // hold deck of card           
//     //   int value;

//     //     void shuffle ();
//     //     string getSuit() const;
//     //     int getRank() const;
//     //     int getValue() const;

//     }
// }
