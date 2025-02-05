#include "BuddyBook.h"
#include <iostream>

using namespace std;

BuddyBook::BuddyBook(int initialCapacity)
{
	this->currentNrOf = 0;
	this->capacity = initialCapacity;
	this->buddies = new Buddy * [this->capacity] {nullptr};
}

BuddyBook::BuddyBook(const BuddyBook& origin)
{
	this->currentNrOf = origin.currentNrOf;
	this->capacity = origin.capacity;
	//this->buddies = origin.buddies; //kopiering av adress, ytlig kopiering, INTE OK!
	this->buddies = new Buddy * [this->capacity] {nullptr}; //djup kopiering, skapar en egen array

	for (int i = 0; i < this->currentNrOf; i++)
	{
		//this->buddies[i] = origin.buddies[i]; //ytlig kopiering, INTE OK!
		this->buddies[i] = new Buddy(*origin.buddies[i]); //skapa ett identiskt objekt med Buddy-klassens kopieringskonstuktor
	}
}

BuddyBook::~BuddyBook()
{
	for (int i = 0; i < this->currentNrOf; i++)
	{
		delete this->buddies[i]; //destruktorn för Buddy-objektet exekveras
	}
	delete[] this->buddies; //avallokerar arrayen som nås från pekaren buddies
	//man behöver bara har this-> när det är konfikt med variabels namn
}

void BuddyBook::addBuddy(string name, int age, float height)
{
	if (this->currentNrOf == this->capacity)
	{
		// expandera arrayen
		// 1. öka kapaciteten med 3
		this->capacity +=  3;

		// 2. använd en temporär pekare för att allokera en array med den nya kapaciteten
		Buddy** temp = new Buddy * [this->capacity] {nullptr};

		// 3. kopiera adresserna i buddies till den nya arrayen
		for (int i = 0; i < this->currentNrOf; i++)
		{
			temp[i] = this->buddies[i]; //kopierar adressen, sk.ytlig kopierar
		}

		// 4. avallokera arrayen som buddies har adressen till
		delete[] this->buddies;

		// 5. kopierar adress från den temporära pekaren adressen till buddies
		this->buddies = temp; //kopierar adressen
		//nu buddies och temp pekar på samma adress. Man får inte ta bort det med delete[] temp, då tar man bort allt.
		//temp levar bara här, på den funktionen så det gör inget.
	}
	//skapa Buddy objekt på heapen använder vi "new"
	buddies[this->currentNrOf++] = new Buddy(name, age, height);
	//man använder först sedan ökar på currentNrOf
	//kan skriva så här om man vill inte skriva ++ övanför: this->currentNrOf++

}

void BuddyBook::showBuddies() const
{
	cout << "Your " << this->currentNrOf << " buddies are: " << endl;
	for (int i = 0; i < this->currentNrOf; i++)
	{
		cout << this->buddies[i]->toString()<< endl;
	}
}

bool BuddyBook::removeBuddy(string name, int age, float height)
{
	bool didRemove = false;

	//vi bygger ett objekt för att kan jamföra
	Buddy temp(name, age, height);
	for (int i = 0; i < this->currentNrOf; i++)
	{
		if (temp == *this->buddies[i])
			//*this->buddies[i]:dereferar pekare och "når" därmed objektet
			//så vi kan jämföra dem. Nu är dem två objekt.
		{
			delete this->buddies[i]; //anropar destruktorn...
			this->currentNrOf--;

			//man har 2 altenativ: lägga den sista på den tomma som vi tagit bort
			//elller flyttar allt up. Här flyta man den sista på den tomma
			this->buddies[i] = this -> buddies[this->currentNrOf];

			this->buddies[this->currentNrOf] = nullptr;
			didRemove = true;
		}
	}
	return didRemove;
}
