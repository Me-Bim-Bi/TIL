#ifndef COMPETITION_H
#define COMPETITION_H
#include "Swimmer.h"
#include <string>

using namespace std;

class Competition {
private:
	string organizer;
	int currentNrOfSwimmers;
	string date;
	int capacity;
	Swimmer * *swimmers;
public:
	Competition(const string& organizer = "?", const string& date = "?");
	~Competition();
	string getOrganizer() const;
	int getCurrentNrOfSwimmers() const;
	int nrOfSwimmersFromSpecificClub(const string& club) const;
	void addSwimmer(const string& name, const string& club, int birthYear);
	bool removeSwimmer(const string& name, const string& club, int birthYear);
	string toString() const;
	Swimmer* swimmerAt(int index);
};


#endif