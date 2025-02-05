//
// Created by Chu Ha Thanh on 2024-11-26.
//

#ifndef WALLPAPER_H
#define WALLPAPER_H
#include <iostream>
#include <string>

using namespace std;


class Wallpaper {
private:
	string name;
	int nrOfRolls;
	int pris;
public:
	Wallpaper();
	Wallpaper(const string &name, int nrOfRolls, int pris);
	string getName() const;
	int getNrOfRolls() const;
	int getPris() const;
	void setName(const string& name);
	void setNrOfRolls(int nrOfRolls);
	void setPris(int pris);
	int totalCost() const;
	string toString() const;
	bool operator == (const Wallpaper &other) const;

};



#endif //WALLPAPER_H
