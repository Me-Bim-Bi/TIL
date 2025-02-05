#include "utils.h"
#include <iostream>

using namespace std;

bool askYesNo(string question) {
	string input;
	cout << question << " [y/n]";
	cin >> input;

	// Convert to lower character by character!
	for (int i = 0; i < input.size(); i++) {
		input[i] = std::tolower(input[i]);
	}
	return input == "y";
}
