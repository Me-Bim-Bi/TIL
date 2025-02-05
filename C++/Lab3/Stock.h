#ifndef STOCK_H
#define STOCK_H
#include"Article.h"

class Stock {
private:
	Article* *articles;
	int nrOfArticles;
	int capacity;
	void expand();
	void freeMemory();
public:
	Stock(int capacity = 5);
	virtual~Stock();

	Stock(const Stock& other);
	void operator=(const Stock& other);

	int getNrOfArticles() const;
	void addToiletRolls(const string& articleNr, int nrOfRollsInPackage, float paperLength);
	void addNotepad(const string& articleNr, int nrOfPages, const string& cover);
	float totalPaperLengthOfToiletRolls() const;
	int nrOfNotepads() const;
	void showAllArticles() const;

	Article** getAccessToArray() const;
	Article* getAccessToArticleAt(int index) const;

};



#endif
