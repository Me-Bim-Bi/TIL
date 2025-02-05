//
// Created by Chu Ha Thanh on 2024-12-04.
//

#include "EggPackage.h"
#include<iostream>

using namespace std;

EggPackage::EggPackage(float pris, string artikelnummer, string storleken,  int numberOfEggs):Product(pris, artikelnummer), storleken(storleken),numberOfEggs(numberOfEggs) {
}

EggPackage::~EggPackage() {
	cout << "Destruktion EggPackate" << endl;
}

string EggPackage::getStorleken() const {
	return	this->storleken;
}

int EggPackage::getNumberOfEggs() const {
	return this->numberOfEggs;
}

void EggPackage::setStorleken(const string &storleken) {
	this->storleken = storleken;
}

void EggPackage::setNumberOfEggs(int numberOfEggs) {
	this->numberOfEggs = numberOfEggs;
}

string EggPackage::getDescription() const {
	return "Egg package size " + this->storleken + " containing " + to_string(this->numberOfEggs)
	+ " eggs has " + Product::getDescription();
}
