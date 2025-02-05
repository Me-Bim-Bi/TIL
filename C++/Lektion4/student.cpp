//
// Created by Chu Ha Thanh on 2024-11-26.
//

#include "student.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;
Student::Student() {
	maSinhVien = "SV001";
	hoTen = "Chu Ha Thanh";
	ngaySinh = "01/12/1987";
	lop = "PG24PW";
	gpa = 10.00;
}

Student::Student(string ma, string ten, string ngay, string lop, double gpa) {
	this->maSinhVien = ma;
	this->hoTen = ten;
	this->ngaySinh = ngay;
	this->lop = lop;
	this->gpa = gpa;
}

Student::~Student() {
	cout << "Ham huy tai day: " << this->maSinhVien << endl;
}

void Student::printInfomation() {
	cout << "Ma sinh vien: " <<  maSinhVien	<<". Ho ten: " << hoTen << ". Ngay sinh: "
	<< ngaySinh << ". Lop: " << lop << ". Diem GPA: " << fixed << setprecision(2) << gpa << "." << endl;
}

void Student::nameStandardization() {
	stringstream ss (hoTen);
	string res, w;
	while(ss >> w) {
		res += toupper(w[0]);
		for (int i = 1; i < w.size(); i++) {
			res += tolower(w[i]);
		}
		res += " ";
	}
	if(!res.empty()) {
		res.pop_back();
	}
	hoTen = res;
}

void Student::dateOfBirthStandardization() {
	const char slash = '/';
	if(ngaySinh[1] == slash) {
		ngaySinh = "0" + ngaySinh;
	}
	if(ngaySinh[4] == slash) {
		ngaySinh.insert(3,"0");
	}
}



