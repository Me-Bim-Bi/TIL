//
// Created by Chu Ha Thanh on 2024-12-03.
//

#include "Product.h"

Product::Product(float pris, string artikelnummer):pris(pris), artikelnummer(artikelnummer) {
}

float Product::getPris() const {
	return this->pris;
}

string Product::getArtikelNummer() const {
	return this->artikelnummer;
}

void Product::setPris(int pris) {
	this->pris = pris;
}

void Product::setArtikelNummer(const string &artikelnummer) {
	this->artikelnummer = artikelnummer;
}

string Product::getDescription() const{
	return "artikelnummer: " + this->getArtikelNummer() + " and price " + to_string(this->getPris());
}
