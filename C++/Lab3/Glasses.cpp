//
// Created by Chu Ha Thanh on 2025-01-02.
//

#include "Glasses.h"

Glasses::Glasses(const string& make, int basePrice) {
	this->make = make;
	this->basePrice = basePrice;
}

Glasses::Glasses():make("?"), basePrice(0){
}

Glasses::~Glasses() {
}

int Glasses::getBasePrice() const {
	return basePrice;
}

string Glasses::getMake() const {
	return make;
}

string Glasses::description() const {
	return "Glass make: " + make + " with base price" + to_string(basePrice);
}

int Glasses::calculateFinalPrice() const {
}
