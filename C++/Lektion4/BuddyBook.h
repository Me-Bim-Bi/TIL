#pragma once
#ifndef BUDDY_BOOK_H
#define BUDDY_BOOK_H
#include "Buddy.h" //möjliggöra relationen till Buddy
#include <iostream>
#include <string>

using namespace std;

class BuddyBook
{
private:
	Buddy* *buddies; //implementra relationen komposition
	int currentNrOf; //hur många kompisar vi har i heapen
	int capacity;
public:
	BuddyBook(int initialCapacity = 3); //överlagning. 3 stycker om jag inte säger något annat
	BuddyBook(const BuddyBook& origin); //När man har "&" bygger man inget kopiera, bara reference på det
	~BuddyBook();
	void addBuddy(string name, int age, float height);
	void showBuddies() const; //det ska inte bli ändras. Det för att visa alla kompisarna.
	bool removeBuddy(string name, int age, float height);
	int getCurrentNrOfBuddies() const;
	bool findBuddy(string name, int age, float height) const;
	//mer kommer 

};

#endif