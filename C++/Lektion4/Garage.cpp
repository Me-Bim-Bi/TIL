//
// Created by Chu Ha Thanh on 2024-12-13.
//

#include "Garage.h"
/*
Garage::Garage(const string& name): name(name),currentNrOfVehicles(0), vehicles{nullptr} {
}

Garage::~Garage() {
	for (int i = 0; i < currentNrOfVehicles; i++) {
		delete vehicles[i];
	}
}

string Garage::getName() const {
	return this->name;
}

int Garage::getCurrentNrofVehicles() const {
	this->currentNrOfVehicles;
}

int Garage::findVeheicle(string regPlate) {
	for(int i = 0; i < currentNrOfVehicles; i++) {
		if (vehicles[i]->getRegPlate() == regPlate) {
			return i;
		}
	}
	return -1;
}

bool Garage::addVehicleAt(string regPlate, string owner, int loadWeight, int index) {
	bool add = false;
	if(index < CAP && vehicles[index] == nullptr) {
		vehicles[index] = new Vehicle(regPlate, owner, loadWeight);
		currentNrOfVehicles++;
		add = true;
	}
	return add;
}

bool Garage::removeVeheicleAt(int index) {
	bool remove = false;
	if(index < currentNrOfVehicles && vehicles[index] != nullptr) {
		delete vehicles[index];
		vehicles[index] = vehicles[currentNrOfVehicles--];
		vehicles[currentNrOfVehicles] = nullptr;
		remove = true;
	}
	return remove;
}

Vehicle * Garage::VehicleAt(int index) {
	Vehicle* ptr = nullptr;
	if (index < currentNrOfVehicles)
		ptr = vehicles[index];
	return ptr;
}
*/