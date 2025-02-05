//
// Created by Chu Ha Thanh on 2024-11-26.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>


using namespace std;
class Student {
private:
	string maSinhVien, hoTen, ngaySinh, lop;
	double gpa;
public:
	Student();
	Student(string ma, string ten, string ngay, string lop, double gpa);
	~Student();
	void printInfomation();
	void nameStandardization();
	void dateOfBirthStandardization();
};



#endif //STUDENT_H
