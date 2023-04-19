#include <iostream>
#include <string>
#pragma once
using std::string;
namespace ariel{
    


class Card {
	private://FIELEDS NAMES
		string suit;
		int faceValue;
public:
    Card(string suit, int faceValue);//: suit(s), faceValue(r){};

	string getSuit();
	int getFaceValue();

	string ToString();
};
}




