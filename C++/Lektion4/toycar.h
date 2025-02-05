//
// Created by Chu Ha Thanh on 2024-11-24.
//

#ifndef TOYCAR_H
#define TOYCAR_H
#include <iostream>
#include <string>

using namespace std;

class ToyCar {
private:
	string model;
	string color;
public:
	ToyCar(string model, string color);
	ToyCar();
	string getModel() const;
	string getColor() const;
	void setColor(const string& color);
	string toString()const;
};



#endif //TOYCAR_H
