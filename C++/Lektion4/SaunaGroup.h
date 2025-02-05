#ifndef SAUNAGROUP_H
#define SAUNAGROUP_H
#include "Member.h"
#include <string>

using namespace std;

const int CAP = 12;

class SaunaGroup {
private:
	string nameOfGroup;
	int currentNrOfMembers;
	Member *members [CAP];
public:
	SaunaGroup(const string&nameOfGroup = "");
	~SaunaGroup();
	string getNameOfGroup();
	int getCurrentNrOfMembers();
	bool addMember(const string& name, int memberNr);
	bool removeMember(const string& name, int memberNr);
	Member* memberAt(int index);
};

#endif