#include "DiceRoller.h"
class DiceRollerFactory
{
public:
	DiceRollerFactory& setnrOfDices(int nrOfDices);
	DiceRollerFactory& setnrOfSides(int nrOfSides);
	int getNrOfDices() const;
	int getNrOfSides() const;
	DiceRoller* create();
private:
	int nrOfDices = 1;
	int nrOfSides = 6;
};
