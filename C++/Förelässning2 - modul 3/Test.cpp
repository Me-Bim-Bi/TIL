#include <iostream>
#include "Competitor.h"
#include "Runner.h"
#include <string>
#include "Jumper.h"
using namespace std;

int main()
{
	// Detektera minnesläckor genom att sätta denna flagga!
	// Starta programmet via debuggern så detekteras eventuella minnesläckor.

	/*Competitor comp1("Kalle", 123);*/

	//cout << comp1.getDescription() << endl;

	/*Runner run1("Bella", 333, 300);

	cout << run1.getStartNr() << endl;
	cout << run1.getDistance() << endl;

	cout << run1.getDescription() << endl;*/

	 /*Runner* runnerPtr = new Runner("Lisa", 111, 500);
	cout << runnerPtr->getName() << endl;
	Competitor* compPtr1 = new Competitor("Strunt", 888); //användning av basklasspekare
	cout << compPtr1->getStartNr() << endl;

	cout << compPtr1->getDescription() << endl;
	cout << runnerPtr->getDescription() << endl;

	compPtr1 = runnerPtr;

	cout << compPtr1->getDescription() << endl;
	cout << runnerPtr->getDescription() << endl;*/
	Competitor c1;
	Runner r1("Runner - Kalle", 1, 100);
	Jumper j1("Jumper-Lisa", 2);

	//användning av basklasspekare
	Competitor* pc1 = &r1;
	cout << pc1->getDescription() << endl;
	// vanligt kommer det till getDescription på "Competitor" för att det är pekare på Competitor
	// när vi skriver "virtual" på getDescription på "Competitor" => det kommer till getDescritption på "Runner" istället

	//vituella destruktorer
	Competitor* pc2 = new Jumper("Jumer_Nisse", 10, 3);


	delete pc2;
	return 0;
}