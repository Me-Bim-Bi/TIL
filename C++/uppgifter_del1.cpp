// Programmeringsuppgift: Övningsuppgifter - Variabler, datatyper och uttryck
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Bestäm totala antalet sekunder för 50 minuter och 25 sekunder.
    int minuter = 50;
    int sekunder = 25;
    int minuter_to_sekunder = minuter * 60;
    int sum = static_cast<int>(minuter + minuter_to_sekunder);
    cout << sum << endl;

}

