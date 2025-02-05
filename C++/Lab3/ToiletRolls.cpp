#include "ToiletRolls.h"

ToiletRolls::ToiletRolls(string articleNr,int nrOfRollsInPackage, float papperLength)
	: Article(articleNr), nrOfRollsInPackage(nrOfRollsInPackage), papperLength(papperLength){
}

ToiletRolls::~ToiletRolls() {
}

float ToiletRolls::getPaperLength() const {
	return this->papperLength;
}

int ToiletRolls::getNrOfRollsInPackage() const {
	return this->nrOfRollsInPackage;
}

string ToiletRolls::description() const {
	return "Toiletrolls: " + Article::description()
	+ " has " + to_string(nrOfRollsInPackage) + " rolls in a pakackage "
	+ " and every rolls has " + to_string(papperLength) + " cm long.";
}
