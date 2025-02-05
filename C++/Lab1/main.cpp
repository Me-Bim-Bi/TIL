//
// Created by Chu Ha Thanh on 2024-11-26.
//
#include <iostream>
#include <ctime>
#include "Dice.h"
#include "DiceRoller.h"
#include "Game.h"
#include "utils.h"
using namespace std;
int main()
{
	// Detektera minnesläckor genom att sätta denna flagga!
	// Starta programmet via debuggern så detekteras eventuella minnesläckor.
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "Welcome to the Dice Roller \"Game\"!" << endl;
	cout << "----------------------------------\n" << endl;
	// Seed for random number generation
	srand((unsigned int)time(nullptr));
	bool isPlaying = true;
	while (isPlaying) {
		DiceRollerFactory rollerFactory;
		Game game(rollerFactory);
		// Add players
		while (askYesNo("Do you want to add more players? ")) {
			string name;
			cout << "Player name: "; cin >> name;
			game.addPlayer(new Player(name));
		}
		// Ask for nr of dices and sides
		int nrOfDices = rollerFactory.getNrOfDices();
		int nrOfSides = rollerFactory.getNrOfSides();
		cout << "Number of dices [" << nrOfDices << "]?"; cin >> nrOfDices;
		cout << "Number of dice sides [" << nrOfSides << "]?"; cin >>
		nrOfSides;
		// Configure the DiceRollerFactory
		rollerFactory.setnrOfDices(nrOfDices).setnrOfSides(nrOfSides);
		// Start this game session!
		game.run();
		isPlaying = askYesNo("Do you want to start a new game? ");
	}
}
