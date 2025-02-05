#include "SaunaGroup.h"
#include <string>

using namespace std;

SaunaGroup::SaunaGroup(const string &nameOfGroup): nameOfGroup(nameOfGroup), currentNrOfMembers(0),members{nullptr}{
}

SaunaGroup::~SaunaGroup() {
	for(int i = 0; i < this->currentNrOfMembers; i++) {
		delete members[i];
	}
}

string SaunaGroup::getNameOfGroup() {
	return this->nameOfGroup;
}

int SaunaGroup::getCurrentNrOfMembers() {
	return this->currentNrOfMembers;
}

bool SaunaGroup::addMember(const string &name, int memberNr) {
	bool didAdd = false;
	if(currentNrOfMembers < CAP) {
		members[this->currentNrOfMembers] = new Member (name, memberNr);
		currentNrOfMembers++;
		didAdd = true;
	}
	return didAdd;
}

bool SaunaGroup::removeMember(const string &name, int memberNr) {
	bool didRemove = false;
	Member temp (name, memberNr);
	for(int i = 0; i < this->currentNrOfMembers && !didRemove; i++) {
		if(temp == *members[i]) {
			delete members[i];
			this->currentNrOfMembers--;
			members[i] = members[this->currentNrOfMembers];
			members[this->currentNrOfMembers] = nullptr;
			didRemove = true;
		}
	}
	return didRemove;
}

Member * SaunaGroup::memberAt(int index) {
	Member* ptr = nullptr;
	if (index < this->currentNrOfMembers)
	{
	  ptr = this->members[index];
	}
	return ptr;

}

