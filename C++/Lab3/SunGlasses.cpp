//
// Created by Chu Ha Thanh on 2025-01-02.
//

#include "SunGlasses.h"

SunGlasses::SunGlasses(string make, int basePrice, string colour):Glasses(make,basePrice),colour(colour) {
}

SunGlasses::SunGlasses(): colour("?") {
}

SunGlasses::~SunGlasses() {
}

string SunGlasses::getColour() const {
	return this->colour;
}

string SunGlasses::description() const {
	return "Sunglasses: " + Glasses::description()
	+ " with colour " + colour + " has final price: "
	+ to_string(calculateFinalPrice());
}

int SunGlasses::calculateFinalPrice() const {
	int total = getBasePrice();
	if(colour == "gul" || colour == "lila") {
		total += 200;
	}
	return total;
};
