#include "DiceRoller.h"
#include <string>
class Player
{
public:
	Player(std::string name);
	~Player();
	void setDiceRoller(DiceRoller* roller);
	const DiceRoller& getDiceRoller() const;
	std::string getName() const;
	void rollDices();
private:
	std::string name;
	DiceRoller* roller = nullptr;
};
