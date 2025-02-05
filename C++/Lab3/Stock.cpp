#include"Stock.h"
#include "Notepad.h"
#include "ToiletRolls.h"
#include<iostream>

using namespace std;

void Stock::expand() {
	this->capacity += 5;
	Article** temp = new Article * [this->capacity]{nullptr};
	for(int i = 0; i<nrOfArticles; i++) {
		temp[i] = articles[i];
	}
	delete[] articles;
	this->articles = temp;
}

void Stock::freeMemory() {
	for(int i = 0; i<nrOfArticles; i++) {
		delete articles[i];
	}
	delete[] articles;
}

Stock::Stock(int capacity)
: capacity(capacity), nrOfArticles(0), articles(new Article* [capacity]{nullptr}) {
}

Stock::~Stock() {
	freeMemory();
}

Stock::Stock(const Stock &other) {
	this->capacity = other.capacity;
	this->nrOfArticles = other.getNrOfArticles();
	articles = new Article* [other.capacity]{nullptr};
	for(int i = 0; i<nrOfArticles; i++) {
		Notepad* notepadPtr = dynamic_cast<Notepad*>(other.articles[i]);
		if(notepadPtr != nullptr) {
			this->articles[i] = new Notepad(*notepadPtr);
		}
		else {
			ToiletRolls* toiletRollsPtr = dynamic_cast<ToiletRolls*>(other.articles[i]);
			if(toiletRollsPtr != nullptr) {
				this->articles[i] = new ToiletRolls(*toiletRollsPtr);
			}
		}
	}

}

void Stock::operator=(const Stock &other) {
	if(this != &other) {
		this->freeMemory();

		this->capacity = other.capacity;
		this->nrOfArticles = other.nrOfArticles;
		this->articles = new Article * [this->capacity]{nullptr};
		for(int i = 0; i<nrOfArticles; i++) {
			Notepad* notepadPtr = dynamic_cast<Notepad*>(other.articles[i]);
			if(notepadPtr != nullptr) {
				this->articles[i] = new Notepad(*notepadPtr);
			}
			else {
				ToiletRolls* toilettRollsPtr = dynamic_cast<ToiletRolls*>(other.articles[i]);
				if(toilettRollsPtr != nullptr) {
					this->articles[i] = new ToiletRolls(*toilettRollsPtr);
				}
			}
		}
	}
}


int Stock::getNrOfArticles() const {
	return this->nrOfArticles;
}

void Stock::addToiletRolls(const string &articleNr, int nrOfRollsInPackage, float paperLength) {
	if(nrOfArticles==capacity) {
		expand();
	}
	articles[nrOfArticles++] = new ToiletRolls (articleNr, nrOfRollsInPackage, paperLength);
}

void Stock::addNotepad(const string& articleNr, int nrOfPages, const string &cover) {
	if(nrOfArticles==capacity) {
		expand();
	}
	articles[nrOfArticles++] = new Notepad (articleNr, nrOfPages, cover);
}

float Stock::totalPaperLengthOfToiletRolls() const {
	float sum = 0.0f;
	for(int i = 0; i<nrOfArticles; i++) {
		ToiletRolls* toiletRollsPtf = dynamic_cast<ToiletRolls*>(articles[i]);
		if(toiletRollsPtf != nullptr) {
			sum += (toiletRollsPtf->getPaperLength() * toiletRollsPtf->getNrOfRollsInPackage());
		}
	}
	return sum;
}

int Stock::nrOfNotepads() const {
	int count = 0;
	for (int i = 0; i<nrOfArticles; i++) {
		Notepad* notepadPtr = dynamic_cast<Notepad*>(this->articles[i]);
		if(notepadPtr != nullptr) {
			count++;
		}
	}
	return count;
}

void Stock::showAllArticles() const {
	for (int i = 0; i<nrOfArticles; i++) {
		cout << articles[i]->description() << endl;;
	}
}

Article ** Stock::getAccessToArray() const {
	return articles;

}

Article * Stock::getAccessToArticleAt(int index) const {
	Article* ptr = nullptr;
	if(index < this->nrOfArticles) {
		ptr = this->articles[index];
	}
	return ptr;
}
