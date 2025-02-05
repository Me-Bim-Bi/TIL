//
// Created by Chu Ha Thanh on 2025-01-02.
//

#ifndef SUNGLASSES_H
#define SUNGLASSES_H
#include <string>
#include "Glasses.h"

using namespace std;


class SunGlasses:public Glasses{
private:
	string colour;
public:
	SunGlasses(string make, int basePrice, string colour);
	SunGlasses();
	~SunGlasses();

	string getColour() const;

	string description() const override;
	int calculateFinalPrice() const override;
};



#endif //SUNGLASSES_H
