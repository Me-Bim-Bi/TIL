//
// Created by Chu Ha Thanh on 2024-12-03.
//

#ifndef MILK_H
#define MILK_H
#include "Product.h"
#include <string>

using namespace std;

const int CPA = 10;

class Milk : public Product {
private:
	float enhetenLiter;
	Milk *milk [CPA];
	int nrCurrentMilk;
public:
	Milk(float pris = 0, string artikelnummer = "?", float enhetenLiter = 0);
	~Milk();
	void addMilk(float pris, string artikelnummer, float enhetenLiter);
	float getEnhetenLiter () const;
	void setEnhetenLiter(float enhetenLiter);
	string getDescription () const;
	string getDescriptionArray() const;

};



#endif //MILK_H
