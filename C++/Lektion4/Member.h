//
// Created by Chu Ha Thanh on 2024-11-28.
//

#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>

using namespace std;

class Member {
private:
	string name;
	int memberNr;
public:
	Member(const string& name = "", int memberNr = 0);
	void setName(const string& name);
	void setMemberNr(int memberNr);
	string getName() const;
	string toString() const;
	bool operator > (const Member& other) const;
	bool operator == (const Member& other) const;

};



#endif //MEMBER_H
