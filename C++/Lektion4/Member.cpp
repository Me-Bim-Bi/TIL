//
// Created by Chu Ha Thanh on 2024-11-28.
//

#include "Member.h"

Member::Member(const string& name, int memberNr) {
	this->name = name;
	this->memberNr = memberNr;
}

void Member::setName(const string &name) {
	this->name = name;
}

void Member::setMemberNr(int memberNr) {
	if (memberNr >=0) {
		this->memberNr = memberNr;
	}
}

string Member::getName() const {
	return this->name;
}

string Member::toString() const {
	return "Medlem's name is: " + this -> name + "and the medlem's number is: " + to_string(this->memberNr);
}

bool Member::operator > (const Member &other) const {
	return this->memberNr > other.memberNr;
}

bool Member::operator==(const Member &other) const {
	return this->memberNr == other.memberNr && this->name == other.name;
}
