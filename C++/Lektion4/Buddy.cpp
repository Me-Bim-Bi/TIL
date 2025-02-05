#include "Buddy.h"
#include <iostream>

using namespace std;

Buddy::Buddy(string name, int age, float height)
{
    this->name = name; //this är en pekare som har adressen till objektet själv, dvs pekar på sig själv
    this->age = age;
    this->height = height;
}

Buddy::Buddy()
{
    this->name = "?";
    this->age = 0;
    this->height = 0.0f;
}

Buddy::~Buddy()
{
    cout << "Destroying " << this->toString() << endl;
}

string Buddy::getName() const
{
    
    return this->name;
}

/* int Buddy::getAge()
{
    return this->age;
}
*/

float Buddy::getHeight() const
{
    return this->height;
}

void Buddy::setName(const string& name)
{
    this->name = name;
}

void Buddy::setHeight(float height)
{
    if (height > 0.45)
    {
        this->height = height;
    }
}

void Buddy::growOlder()
{
    this->age++;
}

string Buddy::toString() const
{
    string resultString;
    resultString = "Name is " + this->name + " and age is " + to_string(this->age)
        + " and height is " + to_string(this->height);

    return resultString;
}


//build operator: vad betyder "==", ">".... osv...
bool Buddy::operator==(const Buddy& other) const
{
    bool isEqual = false;
    if (this->name == other.name
        && this->age == other.age
        && this->height == other.height)
    {
        isEqual = true;
    }
    return isEqual;
}

bool Buddy::operator<(const Buddy& other) const
{
    
    return this->age < other.age;
}

bool Buddy::operator>(const Buddy& other) const
{
    return this->age > other.age;
}
