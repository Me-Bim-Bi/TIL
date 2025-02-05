//
// Created by Chu Ha Thanh on 2025-01-02.
//

#include "StockGlasses.h"
#include "ReadingGlasses.h"
#include "SunGlasses.h"

void StockGlasses::freeMemory() {
	for(int i = 0; i < nrOf; i++) {
		delete glasses[i];
	}
}

StockGlasses::StockGlasses():nrOf(0),glasses{nullptr} {
}

StockGlasses::~StockGlasses() {
	freeMemory();
}

StockGlasses::StockGlasses(const StockGlasses &other):nrOf(other.nrOf), glasses{nullptr} {
	for(int i = 0; i < nrOf; i++) {
		SunGlasses* sunPtr = dynamic_cast<SunGlasses*>(other.glasses[i]);
		if(sunPtr != nullptr) {
			glasses[i] = new SunGlasses(*sunPtr);
		}
		else {
			ReadingGlasses* readPtr = dynamic_cast<ReadingGlasses*>(other.glasses[i]);
			if(readPtr != nullptr) {
				glasses[i] = new ReadingGlasses(*readPtr);
			}
		}
	}
}

StockGlasses & StockGlasses::operator=(const StockGlasses &other) {
	if(this != &other) {
		freeMemory();
		this->nrOf = other.nrOf;

		for(int i = 0; i < nrOf; i++) {
			SunGlasses* sunPtr = dynamic_cast<SunGlasses*>(other.glasses[i]);
			if(sunPtr != nullptr){
				this->glasses[i] = new SunGlasses(*sunPtr);
				}
			else{
				ReadingGlasses* readPtr = dynamic_cast<ReadingGlasses*>(other.glasses[i]);
				if(readPtr != nullptr) {
					this->glasses[i] = new ReadingGlasses(*readPtr);
				}
			}
		}
		return *this;
	}
}

bool StockGlasses::add(string make, int basePrice, string colour) {
	bool didAdd = false;
	if(nrOf < MAX) {
		glasses[nrOf++] = new SunGlasses(make, basePrice,colour);
		didAdd = true;
	}
	return didAdd;
}

bool StockGlasses::add(string make, int basePrice, float strength, string typeOfGlass) {
	bool didAdd = false;
	if(nrOf < MAX) {
		glasses[nrOf++] = new ReadingGlasses(make, basePrice,strength,typeOfGlass);
		didAdd = true;
	}
	return didAdd;
}

int StockGlasses::nrOfGlasses() const {
	return nrOf;
}

int StockGlasses::nrOfSunGlasses(string colour) const {
	int count = 0;
	for(int i = 0; i < nrOf; i++) {
		SunGlasses* sunPtr = dynamic_cast<SunGlasses*>(glasses[i]);
		if(sunPtr != nullptr && sunPtr->getColour() == colour)
			count++;
		}
	return count;
}

int StockGlasses::nrOfReadingGlassesWithStrengthAbove(float strength) const {
	int count = 0;
	for(int i = 0; i < nrOf; i++) {
		ReadingGlasses* readPtr = dynamic_cast<ReadingGlasses*>(glasses[i]);
		if(readPtr != nullptr && readPtr->getStrength() == strength) {
			count++;
		}
	}
	return count;
}

int StockGlasses::totalStockValue() const {
		int sum = 0;
		for(int i = 0; i < nrOf; i++) {
			sum += glasses[i]->calculateFinalPrice();
		}
		return sum;
	}

void StockGlasses::description() const {
	for(int i = 0; i < nrOf; i++) {
		cout << glasses[i]->description() << endl;
	}
}

/*
Glasses * StockGlasses::getAccessToGlassesAt(int index) {
	if (index < MAX) {
		return glasses[index];
	}
		return nullptr;
}*/





