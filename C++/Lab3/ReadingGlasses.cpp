//
// Created by Chu Ha Thanh on 2025-01-02.
//

#include "ReadingGlasses.h"

ReadingGlasses::ReadingGlasses(string make, int basePrice, float strength, string typeOfGlass)
	:Glasses(make,basePrice), strength(strength), typeOfGlass(typeOfGlass){
}

ReadingGlasses::~ReadingGlasses() {
}

float ReadingGlasses::getStrength() const {
	return this->strength;
}

string ReadingGlasses::description() const {
	return "Reading glasses: " + Glasses::description() + " with strength "
	+ to_string(strength) + " and type "
	+ typeOfGlass + ", final price is: "
	+ to_string(calculateFinalPrice());
}

int ReadingGlasses::calculateFinalPrice() const {
	int total = getBasePrice();
	if(typeOfGlass == "dubbleslipade") {
		total += 1500;
	}
	return total;
}
