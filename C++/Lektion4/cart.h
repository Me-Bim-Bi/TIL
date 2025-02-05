//
// Created by Chu Ha Thanh on 2024-11-26.
//

#ifndef CART_H
#define CART_H
#include "wallpaper.h"
#include <iostream>
#include <string>

using namespace std;
const int capacity = 10;
class Cart {
private:
	int cartid;
	string name;
	int nrOfWallPaper;
	Wallpaper* wallpaper[capacity];
public:
	explicit Cart(const string& name = "not yet set", int cartid = 0);
	~Cart();
	void addWallPaper(const string& name, int nrOfRoll, int pris);
	bool removeWallPaper(const string& name, int nrOfRoll, int pris);
	int totalOrderCost() const;
	void showString()const;
};



#endif //CART_H
