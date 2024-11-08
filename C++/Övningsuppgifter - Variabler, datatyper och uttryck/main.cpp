// Programmeringsuppgift: Övningsuppgifter - Variabler, datatyper och uttryck
#include <iostream>
#include <string>

using namespace std;

int total_sekunder()
{
    const int minuter = 50;
    const int sekunder = 25;
    const int minuter_to_sekunder = minuter * 60;
    const int sum = static_cast<int>(sekunder + minuter_to_sekunder);

    return sum;
}

float km_till_miles()
{
    const int km = 15;
    const float miles_to_km = 1.609344f;
    float miles_final = km/miles_to_km;

    return miles_final;
}

int multiplikation(int no1, int no2) {
    int multi = no1 * no2;

    return multi;
}

int main()
{
    // Bestäm totala antalet sekunder för 50 minuter och 25 sekunder.
    cout << "Total sekunder är " << total_sekunder() << " sekunder."<< endl;

    // Bestäm hur många miles 15 km motsvarar. (1 mile är 1.609344 km)
    cout << "Total miles är " << km_till_miles() << " miles."<< endl;

    /* Låt användaren mata in 2 heltal och beräkna och presentera produkten
     * (multiplikation) av talen. Ex. inmatning av 6 och 4 ger resultatet 24 */
    cout << "Please insert 2 number: " << endl;
    int number1; int number2;
    cin >> number1 >> number2;
    cout << "Multiplication av " << number1 << " och " << number2 << " är " << multiplikation(number1,number2) << endl;
}
