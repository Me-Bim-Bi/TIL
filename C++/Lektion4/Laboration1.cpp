//
// Created by Chu Ha Thanh on 2024-12-13.
//
#include "Laboration1.h"
#include<fstream>
#include<iostream>


void doubleUp(int &number) {
	number = number * 2;
}

void readStringFromFile(string fileName, string arr[], int currentNr) {
	ifstream in;
	in.open(fileName);
	if (in.is_open()) {
		for (int i = 0; i < currentNr; i++) {
			getline(in, arr[i]);
		}
	}
	in.close();

}

int nrOfValuesBiggerThan(int arr[], int nrOf, int nrCompare) {
	int count = 0;
	for (int i = 0; i < nrOf; i++) {
		if (arr[i] > nrCompare)
		{
			count++;
		}
	}
	return count;
}
