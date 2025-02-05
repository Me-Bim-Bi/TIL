#include <iostream>
#include<string>
#include "generic_func.h"
#include "Stack.h"
#include <vector>
#include <cassert>
#include <stdexcept>

#include <memory>

using namespace std;
/*
//template mallar
int add(int a, int b) {
	return a + b;
}

float add(float a, float b) {
	return a + b;
}
*/

//i header fil

int main() {
	/* funktion mall och klass mall
	int result1 = add(1,2);
	cout << "int add: " << result1 << endl;

	float result2 = add(1.3f,2.5f);
	cout << "float add: " << result2 << endl;

	Stack<string> strStack;

	strStack.push("Kalle");
	strStack.push("Pelle");
	strStack.push("Stina");

	cout << strStack.pop() << endl;
	*/

	vector<int> numbers {0,1,2,3,4};
	assert(numbers[1] == 1);
	assert(numbers.at(1) == 1);

	//kollar gärna om exception. Felhantering. Kasta och fånga felet.
	try {
		assert(numbers[1] == 1); //vet inte, kan not hantera fånga felet: assert(numbers[100] == 1).
		assert(numbers.at(100) == 1);
	}
	catch(out_of_range e) {
		cout << e.what() << endl;
	}
	catch(exception e) {
		cout << e.what() << endl;
	}

	int* number = new int(5);
	delete number;

	unique_ptr<int> iPtr(new int(5));
	auto iPtr2 = make_unique<int>(5);
	cout << *iPtr << endl;


	return 0;
}