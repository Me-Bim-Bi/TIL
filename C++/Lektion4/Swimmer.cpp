#include "Swimmer.h"
#include <string>

using namespace std;

Swimmer::Swimmer(const string& name, const string& club, int birthYear):name(name), club(club), birthYear(birthYear){
}

void Swimmer::setName(const string &name) {
	this->name = name;
}

void Swimmer::setClub(const string &club) {
	this->club = club;
}

void Swimmer::setBirthYear(int birthYear) {
	if(birthYear >= 1990 && birthYear <= 2024) {
		this->birthYear = birthYear;
	}
}

string Swimmer::getName() const {
	return this->name;
}

string Swimmer::getClub() const {
	return this->club;
}

string Swimmer::getBirthYearAsString() const {
	return to_string(this->birthYear);
}

bool Swimmer::operator<(const Swimmer &other) const {
	return this->birthYear < other.birthYear;
}

bool Swimmer::operator==(const Swimmer &other) const {
	return this->birthYear == other.birthYear &&
		this->name == name &&
			this->club == club;
}
