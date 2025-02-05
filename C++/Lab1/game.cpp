#include "Game.h"
#include <iostream>
#include "utils.h"
using namespace std;
Game::Game(DiceRollerFactory& rollerFactory) : rollerFactory(rollerFactory)
{
	//this->playersCapacity = Game::DEFAULT_PLAYERS_CAPACITY;
	//this->players = new Player * [this->playersCapacity];
}
Game::~Game()
{
	for (int i = 0; i < this->nrOfPlayers; i++) {
		delete this->players[i];
	}
	delete[] this->players;
}
void Game::addPlayer(Player* player)
{
	if (this->nrOfPlayers >= this->playersCapacity) {
		this->increaseCapacity();
	}
	this->players[this->nrOfPlayers++] = player;
}
void Game::run()
{
	for (int i = 0; i < this->nrOfPlayers; i++) {
		this->players[i]->setDiceRoller(this->rollerFactory.create());
	}
	cout << "\nStarting new game!\n" << endl;
	// ---------------------------------------------------------
	// "Spel-loop"
	//
	bool isPlaying = true;
	while (isPlaying) {
		for (int i = 0; i < this->nrOfPlayers; i++) {
			this->play(this->players[i]);
		}
		isPlaying = askYesNo("Do you want to play another round? ");
	}
}
void Game::increaseCapacity()
{
	int newCapacity = this->playersCapacity + Game::DEFAULT_PLAYERS_CAPACITY;
	Player** newPlayers = new Player*[newCapacity];
	for (int i = 0; i < this->nrOfPlayers; i++) {
		newPlayers[i] = this->players[i];
	}
	delete[] this->players;
	this->players = newPlayers;
	this->playersCapacity = newCapacity;
}
void Game::play(Player* player)
{
	cout << "\n" << player->getName() << ":\n"
	<< "\tRolls my dices: ";
	player->rollDices();
	const DiceRoller& roller = player->getDiceRoller();
	cout << "\tSum: " << roller.getSum() << "\n"
	<< "\tMin: " << roller.getMin() << "\n"
	<< "\tMax: " << roller.getMax() << "\n"
	<< "\tMean value: " << roller.getMeanValue() << "\n";
}