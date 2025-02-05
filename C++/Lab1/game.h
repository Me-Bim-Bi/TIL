#include "Player.h"
#include "DiceRoller.h"
#include "DiceRollerFactory.h"
class Game
{
public:
	Game(DiceRollerFactory& rollerFactory);
	~Game();
	void addPlayer(Player* player);
	void run();
private:
	static const int DEFAULT_PLAYERS_CAPACITY = 2;
	DiceRollerFactory& rollerFactory;
	Player** players = nullptr;
	int nrOfPlayers = 0;
	int playersCapacity = 0;
	void increaseCapacity();
	void play(Player* player);
};
