//
// Created by Chu Ha Thanh on 2024-12-03.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include<string>

using namespace std;

class Product {
private:
	float pris;
	string artikelnummer;
public:
	Product(float pris = 0, string artikelnummer = "?");
	float getPris() const;
	string getArtikelNummer() const;
	void setPris(int pris);
	void setArtikelNummer(const string& artikelnummer);
	string getDescription() const;

};



#endif //PRODUCT_H
