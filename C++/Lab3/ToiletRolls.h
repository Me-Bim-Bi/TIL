#ifndef TOILETROLLS_H
#define	TOILETROLLS_H
#include "Article.h"

class ToiletRolls:public Article {
private:
	int nrOfRollsInPackage;
	float papperLength;
public:
	ToiletRolls(string articleNr = "?", int nrOfRollsInPackage = 0, float papperLength = 0.0f);
	virtual~ToiletRolls();

	float getPaperLength() const;
	int getNrOfRollsInPackage() const;

	string description() const override;
};



#endif
