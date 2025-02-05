//
// Created by Chu Ha Thanh on 2025-01-02.
//

#ifndef READINGGLASSES_H
#define READINGGLASSES_H
#include<iostream>
#include "Glasses.h"

using namespace std;

class ReadingGlasses : public Glasses {
private:
	float strength;
	string typeOfGlass;
public:
	ReadingGlasses(string make = "?", int basePrice = 0,
		float strength = 0.0f, string typeOfGlass = "enkelslipade");
	~ReadingGlasses();

	float getStrength() const;

	string description() const override;
	int calculateFinalPrice() const override;

};



#endif //READINGGLASSES_H
