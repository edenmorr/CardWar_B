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
	string Card::getSuit() { return suit; }
	int Card::getFaceValue() { return faceValue; }
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
