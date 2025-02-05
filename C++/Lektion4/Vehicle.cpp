//
// Created by Chu Ha Thanh on 2024-12-13.
//

#include "Vehicle.h"
#include<iostream>
#include<string>

using namespace std;

Vehicle::Vehicle(const string& regPlate, const string& owner, int loadWeight): regPlate(regPlate), owner(owner), loadWeight(loadWeight) {
}

void Vehicle::setRegPlate(const string &regPlate){
	if (regPlate.size() == 6) {
		this->regPlate = regPlate;
	}
}

void Vehicle::setOwner(const string& owner) {
	this->owner = owner;
}

void Vehicle::setLoadWeight(int loadWeighet) {
	this->loadWeight = loadWeight;
}

string Vehicle::getRegPlate() const {
	return this->regPlate;
}

string Vehicle::description() const {
	return "Reg Plate: " + this->regPlate + " owner: " + this->owner
	+ " load weight: " + to_string(this->loadWeight);
}

bool Vehicle::operator==(Vehicle &other) {
	if (regPlate == other.regPlate
		&& owner == other.owner
		&& loadWeight == other.loadWeight)
		return true;
	return false;
}

bool Vehicle::operator<(Vehicle &other) {
	if (loadWeight < other.loadWeight)
		return true;
	return false;
}
