#include "Competitor.h"
#include <iostream>
using namespace std;

Competitor::Competitor(string name, int startNr): name(name), startNr(startNr)
{
    /*this->name = name;
    this->startNr = startNr;*/
    cout<<"Constructor Competitor"<<endl;
}

Competitor::~Competitor()
{
    cout << "Destructor Competitor" << endl;
}

void Competitor::setName(string name)
{
    this->name = name;
}

void Competitor::setStartNr(int startNr)
{
    this->startNr = startNr;
}

string Competitor::getName() const
{
    return this->name;
}

int Competitor::getStartNr() const
{
    return this->startNr;
}

string Competitor::getDescription() const
{
    return to_string(this->startNr) + ": " + this->name;
}
