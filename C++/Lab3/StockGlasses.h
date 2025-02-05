//
// Created by Chu Ha Thanh on 2025-01-02.
//

#ifndef STOCKGLASSES_H
#define STOCKGLASSES_H
#include "Glasses.h"



class StockGlasses {
private:
	static const int MAX = 20;
	Glasses* glasses[MAX];
	int nrOf;
	void freeMemory();
public:
	StockGlasses();
	~StockGlasses();

	StockGlasses (const StockGlasses& other);
	StockGlasses& operator=(const StockGlasses& other);

	bool add(string make, int basePrice, string colour);
	bool add(string make, int basePrice, float strength, string typeOfGlass);
	int nrOfGlasses() const;
	int nrOfSunGlasses(string colour) const;
	int nrOfReadingGlassesWithStrengthAbove(float strength) const;
	int totalStockValue() const;

	void description() const;

	//Glasses* getAccessToGlassesAt(int index) const;




};



#endif //STOCKGLASSES_H
