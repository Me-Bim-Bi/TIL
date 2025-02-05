//
// Created by Chu Ha Thanh on 2024-11-26.
//

#include "cart.h"
#include "wallpaper.h"

Cart::Cart(const string& name, int cartid):name(name), cartid(cartid),nrOfWallPaper(0),wallpaper{nullptr}{
}

Cart::~Cart() {
	for (int i = 0; i < nrOfWallPaper; i++) {
		delete this->wallpaper[i];
	}
}

void Cart::addWallPaper(const string &name, int nrOfRoll, int pris) {
	if(nrOfWallPaper == capacity)
	{cout << "The cart is full! Do not insert more item!" << endl;}
	else if(nrOfWallPaper != capacity)
	{this->wallpaper[nrOfWallPaper++] = new Wallpaper (name, nrOfRoll, pris);}
}

bool Cart::removeWallPaper(const string &name, int nrOfRoll, int pris) {
	Wallpaper temp (name, nrOfRoll, pris);
	bool didRemove = false;
	for (int i = 0; i < nrOfWallPaper && !didRemove; i++) {
		if(temp == *this->wallpaper[i]) {
			delete wallpaper[i];
			nrOfWallPaper--;
			wallpaper[i] = wallpaper[nrOfWallPaper];
			wallpaper[nrOfWallPaper] = nullptr;
			didRemove = true;
		}
	}
	return didRemove;
}

int Cart::totalOrderCost() const {
	int sum = 0;
	for(int i = 0; i<nrOfWallPaper;i++) {
		sum += wallpaper[i]->totalCost();
	}
	return sum;
}


void Cart::showString() const {
	cout << "Customer: " + this->name + " . ID number: " + to_string(this->cartid) + " has bought: " + to_string(nrOfWallPaper) + " items: " << endl;
	for(int i = 0; i<nrOfWallPaper;i++) {
		cout << this->wallpaper[i]->toString() << endl;
	}
	cout << "The total pris is: " << totalOrderCost() << endl;
	cout << "==========" << endl << endl;

}






