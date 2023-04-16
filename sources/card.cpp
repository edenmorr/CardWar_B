#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <string>
#include "card.hpp"
using namespace std;

namespace ariel
{
	Card::Card(string s,int r)
	{
		this->suit = s;
		this->faceValue = r;
	}
	string Card::ToString()
	{
		if(this->faceValue == 11)
		{
			return "Jack of " + suit;
		}
		else if(this->faceValue == 12)
		{
			return "Queen of " + suit;
		}
		else if(this->faceValue == 13)
		{
			return "King of " + suit;
		}
		else
		{
			stringstream convert;
			convert << this->faceValue;
			return convert.str() + " of " + suit;
		}
	}
}
// Card::Card (Rank rank=ACE, Suit suit = diamond):
// Suit Card::getSuit() { return suit; }
// Rank Card::getRank() { return rank; }

// string getSuit(int value){
//     if(value <= 13) return "diamond";
//     if(value <= 26) return "spades";
//     if(value <= 39) return "hearts";
//     return "clubs";
// }
// string Card::RankName (Rank v) {
// 	switch(v) {
// 	case ACE: return "ACE";
// 	case TWO: return "TWO";
// 	case THREE: return "THREE";
// 	case FOUR: return "FOUR";
// 	case FIVE: return "FIVE";
// 	case SIX:  return "SIX";
// 	case SEVEN: return "SEVEN";
// 	case EIGHT: return "EIGHT";
// 	case NINE: return "NINE";
// 	case TEN: return "TEN";
// 	case JACK: return "JACK";
// 	case QUEEN: return "QUEEN";
// 	case KING: return "KING";
// 	default: throw std::out_of_range(" value out of range");
// 	}

// }