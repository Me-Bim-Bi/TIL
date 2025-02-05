#ifndef BUDDY_H
#define BUDDY_H
#include <string>

using namespace std;

class Buddy
{
private:	
	//varje insekten har eget ...
	string name;
	int age;
	float height;
public:
	Buddy(string name, int age, float height); //konstruktor
	Buddy();//default konstruktor, no-argument contructor
	~Buddy();

	string getName() const; //konstant medlemsfunktion => ändrar inte i objektet
	//int getAge();
	float getHeight() const;
	//string toString();
	void setName(const string& name);
	void setHeight(float height);
	void growOlder();//öka ålder
	string toString() const; //returnera en sträng med alla egenskaperna

	//operatorer
	bool operator==(const Buddy& other) const; //man kan kalla som other eller rightHand eller någonting som mam vill

	//gör själv != operatorn
	bool operator<(const Buddy& other) const; //ska baseras på ålder

	//gör själv >, <= och >= operatorn
	bool operator > (const Buddy& other)const;
};

#endif