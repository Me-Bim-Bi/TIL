//
// Created by Chu Ha Thanh on 2024-12-13.
//
/*
#ifndef GARAGE_H
#define GARAGE_H
#include <string>

#include "Vehicle.h"

using namespace std;

static const int CAP = 10;

class Garage {
private:
	string name;
	int currentNrOfVehicles;
	Vehicle* vehicles[CAP];
public:
	Garage(const string& name = "?");
	~Garage();
	string getName() const;
	int getCurrentNrofVehicles() const;
	int findVeheicle(const string& regPlate);
	bool addVehicleAt(const string& regPlate, const string& owner, int loadWeight, int index);
	bool removeVeheicleAt(int index);

	Vehicle* VehicleAt(int index)const;


};



#endif //GARAGE_H
*/