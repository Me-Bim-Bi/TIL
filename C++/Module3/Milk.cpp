//
// Created by Chu Ha Thanh on 2024-12-03.
//

#include "Milk.h"
#include "Product.h"
#include <string>
#include<iostream>

using namespace std;

Milk::Milk(float pris, string artikelnummer, float enhetenLiter): Product(pris, artikelnummer), enhetenLiter(enhetenLiter),milk{nullptr},nrCurrentMilk(0){
}

Milk::~Milk() {
	for(int i = 0; i<CPA; i++) {
		delete milk[i];
	};
}

void Milk::addMilk(float pris, string artikelnummer, float enhetenLiter) {
	if (this->nrCurrentMilk < CPA) {
		milk[nrCurrentMilk] = new Milk (pris, artikelnummer, enhetenLiter);
		nrCurrentMilk++;
	}
}

float Milk::getEnhetenLiter() const {
	return	this->enhetenLiter;
}

void Milk::setEnhetenLiter(float enhetenLiter) {
	this->enhetenLiter = enhetenLiter;
}

string Milk::getDescription() const {
	return "Milk " + to_string(this->enhetenLiter) + " l has " + Product::getDescription();
}

string Milk::getDescriptionArray() const {
	string result;
	for (int i = 0; i < nrCurrentMilk; i++) {
		result += (milk[i]->getDescription());
	}
	return result;
}


