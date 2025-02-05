#include "DiceRollerFactory.h"
DiceRollerFactory& DiceRollerFactory::setnrOfDices(int nrOfDices)
{
	this->nrOfDices = nrOfDices;
	return *this;
}
DiceRollerFactory& DiceRollerFactory::setnrOfSides(int nrOfSides)
{
	this->nrOfSides = nrOfSides;
	return *this;
}
int DiceRollerFactory::getNrOfDices() const
{
	return this->nrOfDices;
}
int DiceRollerFactory::getNrOfSides() const
{
	return this->nrOfSides;
}
DiceRoller* DiceRollerFactory::create()
{
	DiceRoller* roller = new DiceRoller();
	for (int i = 0; i < this->nrOfDices; i++) {
		roller->addDice(this->nrOfSides);
	}
	return roller;
}
