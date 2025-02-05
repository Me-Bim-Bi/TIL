#include "Competition.h"
#include <string>

using namespace std;


Competition::Competition(const string& organizer, const string& date) {
	this->organizer = organizer;
	this->date = date;
	capacity = 20;
	currentNrOfSwimmers = 0;
	swimmers = new Swimmer *[capacity]{nullptr};
}

Competition::~Competition() {
	for(int i = 0; i < currentNrOfSwimmers; i++) {
		delete swimmers[i];
	}
	delete[] swimmers;
}

string Competition::getOrganizer() const {
	return this->organizer;
}

int Competition::getCurrentNrOfSwimmers() const {
	return this->currentNrOfSwimmers;
}

int Competition::nrOfSwimmersFromSpecificClub(const string &club) const {
	int nrOf = 0;
	for(int i = 0; i < currentNrOfSwimmers; i++) {
		if(swimmers[i]->getClub() == club) {
			nrOf++;
		}
	}
	return nrOf;
}

void Competition::addSwimmer(const string& name, const string& club, int birthYear) {
	if(currentNrOfSwimmers >= 0 && currentNrOfSwimmers < capacity) {
		this->swimmers[currentNrOfSwimmers++] = new Swimmer (name, club, birthYear);
	}
}

bool Competition::removeSwimmer(const string& name, const string& club, int birthYear) {
	bool didRemove = false;
	Swimmer temp(name, club, birthYear);
	for(int i = 0; i < currentNrOfSwimmers && !didRemove; i++) {
		if (*swimmers[i] == temp){
			delete swimmers[i];
			currentNrOfSwimmers--;
			swimmers[i] = swimmers[currentNrOfSwimmers];
			swimmers[currentNrOfSwimmers] = nullptr;
			didRemove = true;
		}
	}
	return didRemove;
}

string Competition::toString() const {
	return this->organizer + " on " + this->date + " have total: "
	+ to_string(this->currentNrOfSwimmers) + " simmers.";
}

Swimmer * Competition::swimmerAt(int index) {
	Swimmer * ptr = nullptr;
	if(index < this->currentNrOfSwimmers) {
		ptr = swimmers[index];
	}
	return ptr;
}
