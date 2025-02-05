//
// Created by Chu Ha Thanh on 2024-11-26.
//

#include "wallpaper.h"

Wallpaper::Wallpaper() {
	this->name = "?";
	this->nrOfRolls = 0;
	this->pris = 0;
}

Wallpaper::Wallpaper(const string &name, int nrOfRolls, int pris) {
	this->name = name;
	this->nrOfRolls = nrOfRolls;
	this->pris = pris;
}


string Wallpaper::getName() const {
	return this-> name;
}

int Wallpaper::getNrOfRolls() const {
	return this->nrOfRolls;
}

int Wallpaper::getPris() const {
	return this->pris;
}

void Wallpaper::setName(const string &name) {
	this->name = name;
}

void Wallpaper::setNrOfRolls(int nrOfRolls) {
	this->nrOfRolls = nrOfRolls;
}

void Wallpaper::setPris(int pris) {
	this->pris = pris;
}

int Wallpaper::totalCost() const {
	return this->nrOfRolls * this->pris;
}

string Wallpaper::toString() const {
	string result = name + " has sold: " + to_string(nrOfRolls) +
		" rolls and the pris per roll is: " + to_string(pris);
	return result;
}

bool Wallpaper::operator==(const Wallpaper &other) const {
	return this->name == other.name &&
		this->nrOfRolls == other.nrOfRolls &&
			this->pris == other.pris;
}


