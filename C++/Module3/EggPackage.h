//
// Created by Chu Ha Thanh on 2024-12-04.
//

#ifndef EGGPACKAGE_H
#define EGGPACKAGE_H
#include "Product.h"
#include<string>

using namespace std;

class EggPackage: public Product{
private:
	string storleken;
	int numberOfEggs;
public:
	EggPackage(float pris = 0, string artikelnummer = "?", string storleken = "?", int numberOfEggs = 0);
	~EggPackage();
	string getStorleken() const;
	int getNumberOfEggs() const;
	void setStorleken(const string& storleken);
	void setNumberOfEggs(int numberOfEggs);
	string getDescription() const;


};



#endif //EGGPACKAGE_H
