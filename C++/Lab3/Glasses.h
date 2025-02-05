//
// Created by Chu Ha Thanh on 2025-01-02.
//

#ifndef GLASSES_H
#define GLASSES_H
#include <iostream>

using namespace std;

class Glasses {
private:
	int basePrice;
	string make;
public:
	Glasses(const string& make, int basePrice);
	Glasses();
	virtual ~Glasses();

	int getBasePrice() const;
	string getMake() const;

	virtual string description() const = 0;
	virtual int calculateFinalPrice() const = 0;
};


#endif //GLASSES_H
