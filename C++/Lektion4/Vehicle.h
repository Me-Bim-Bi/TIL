//
// Created by Chu Ha Thanh on 2024-12-13.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>

using namespace std;

class Vehicle {
private:
	string regPlate;
	string owner;
	int loadWeight;
public:
	Vehicle(const string& regPlate = "?", const string& owner = "?", int loadWeight = 0);
	void setRegPlate(const string& regPlate);
	void setOwner(const string& owner);
	void setLoadWeight(int loadWeighet);
	string getRegPlate() const;
	string description() const;
	bool operator ==(Vehicle &other);
	bool operator <(Vehicle &other);





};



#endif //VEHICLE_H
