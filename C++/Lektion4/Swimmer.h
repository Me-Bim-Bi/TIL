#ifndef SWIMMER_H
#define SWIMMER_H
#include<string>

using namespace std;

class Swimmer {
private:
	int birthYear;
	string name;
	string club;
public:
	Swimmer(const string& name = "?", const string& club = "?", int birthYear = 0);
	void setName(const string& name);
	void setClub(const string& club);
	void setBirthYear(int birthYear);
	string getName() const;
	string getClub() const;
	string getBirthYearAsString() const;
	bool operator < (const Swimmer& other) const;
	bool operator == (const Swimmer& other) const;
};



#endif