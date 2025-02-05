#include "DiceRoller.h"
#include <iostream>
using namespace std;

DiceRoller::DiceRoller() :
sum(0), min(0), max(0), meanValue(0), nrOfDices(0) // Initializer list
{
	//this->dices = new Dice[this->NR_OF_DICES]; // Dynamically allocated array of Dices
	//for (int i = 0; i < NR_OF_DICES; i++) { // Statically allocated array of Dice-pointers
	// dices[i] = new Dice();
	//}
	this->dices = new Dice* [MAX_NR_OF_DICES]; // Dynamically allocated array of Dice-pointers
	}
DiceRoller::~DiceRoller()
{
	//delete[] this->dices;
	//for (int i = 0; i < NR_OF_DICES; i++) {
	// Delete the allocated Dices
	for (int i = 0; i < nrOfDices; i++) {
		delete dices[i];
	}
	delete [] dices; // Also delete the allocated Dice-pointers
}
void DiceRoller::rollDices()
{
	//for (int i = 0; i < this->NR_OF_DICES; i++) {
	for (int i = 0; i < this->nrOfDices; i++) {
		//this->dices[i].roll();
		this->dices[i]->roll();
	}
	this->sum = 0;
	this->min = 1000;
	this->max = 0;
	this->meanValue = 0;
	//for (int i = 0; i < this->NR_OF_DICES; i++) {
	for (int i = 0; i < this->nrOfDices; i++) {
		//int value = this->dices[i].getValue();
		int value = this->dices[i]->getValue();
		cout << value << ", ";
		this->sum += value;
		if (value < min) {
			min = value;
		}
		else if (value > max) {
			max = value;
		}
	}
	cout << endl;
	this->meanValue = static_cast<double>(this->sum) / this->NR_OF_DICES;
}
int DiceRoller::getSum() const
{
	return this->sum;
}
int DiceRoller::getMin() const
{
	return this->min;
}
int DiceRoller::getMax() const
{
	return this->max;
}
double DiceRoller::getMeanValue() const
{
	return this->meanValue;
}
void DiceRoller::addDice(int sides)
{
	// TODO: expand the list of dices when needed
	if (this->nrOfDices < this->MAX_NR_OF_DICES) {
		Dice* dice = new Dice(sides);
		this->dices[nrOfDices] = dice;
		this->nrOfDices++;
	}
}

