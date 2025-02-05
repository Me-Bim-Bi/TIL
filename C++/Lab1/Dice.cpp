#include "Dice.h"
#include <random>
#include <iostream>
using namespace std;
Dice::Dice(int sides) :
sides(sides),
value(1)
{
	//cout << "Dice()" << endl;
}
Dice::~Dice()
{
	//cout << "~Dice()" << endl;
}
int Dice::roll()
{
	this->value = rand() % this->sides + 1;
	return this->value;
}
int Dice::getValue() const
{
	return this->value;
}
bool Dice::operator>(const Dice& other)
{
	return this->value > other.value;
}
