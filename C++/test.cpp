#include <iostream>
#include <string>

using namespace std;

int main()
{
    string gatan; string address;
    int number;
    cout << "Insert the address number " << endl;
    cin >> number;
    cout << "Address is " << number << endl;
    cout << "Insert the name of road " << endl;
    cin.ignore(199,'\n');
    getline(cin, gatan);
    cout << "Address is " << gatan << " " << number << endl;
    return 0;
}