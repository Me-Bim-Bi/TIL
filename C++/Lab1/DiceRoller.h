#ifndef DICE_ROLLER_H
#define DICE_ROLLER_H
#include "Dice.h"
class DiceRoller
{
public:
	DiceRoller();
	~DiceRoller();
	void rollDices();
	// Getters should be const
	int getSum() const;
	int getMin() const;
	int getMax() const;
	double getMeanValue() const;
	void addDice(int sides = 6);
private:
	static const int NR_OF_DICES = 5;
	static const int MAX_NR_OF_DICES = 10;
	// Olika varianter av skapa "relationen" till de olika tärningarna
	//Dice dices[NR_OF_DICES]; // Statically allocated array of dices
	//Dice *dices; // Dynamically allocated array of dices
	//Dice* dices[NR_OF_DICES]; // Statically allocated array of Dice-pointers
	Dice** dices; // Dynamically allocated array of Dice-pointers (dubbelpekare)
	int nrOfDices = 0;
	int sum;
	int min;
	int max;
	double meanValue;
};
#endif