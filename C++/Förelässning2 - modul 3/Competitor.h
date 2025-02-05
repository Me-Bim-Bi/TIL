#pragma once
#include <string>
using namespace std;

class Competitor
{
private:
	string name;
	int startNr;
public:
	Competitor(string name = "?", int startNr = -1);
	~Competitor();
	void setName(string name);
	void setStartNr(int startNr);
	string getName() const;
	int getStartNr() const;
	virtual string getDescription() const;//ändrar till virtual

	// virtual string getDescription() const = 0;
	// det betyder att om man har en virtual funktion => blir den här klassen abstract


};
