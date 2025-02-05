#include "Jumper.h"
#include <iostream>

using namespace std;

Jumper::Jumper(string name, int startNr, int totalNrOfJumps) : Competitor(name, startNr), totalNrOfJumps(totalNrOfJumps), nrOfMadeJumps(0), jumps{ 0 }
{
    //alternativ till initiering via initeringslistan
    /*for (int i = 0; i < this->totalNrOfJumps; i++)
    {
        jumps[i] = 0;
    }*/
    cout << "Constructor Jumper" << endl;
}

Jumper::~Jumper()
{
    cout << "Destructor Jumper" << endl;
}

void Jumper::addJumpResult(int length, int jumpNr)
{
    // kontrollera g�rna att jumpNr �r inom antalet m�jliga hopp
    // och att length �r rimligt
    this->jumps[jumpNr] = length;
}

int Jumper::getNrOfMadeJumps() const
{
    return this->nrOfMadeJumps;
}

int Jumper::getTotalNrOfJumps() const
{
    return this->totalNrOfJumps;
}

void Jumper::setTotalNrOfJumps(int totalNrOfJumps)
{
    // kontrollera g�rna rimligheten i totalNrOfJumps, dvs h�gst 7
    this->totalNrOfJumps = totalNrOfJumps;
}

int Jumper::bestJump() const
{
    int best = jumps[0];
    for (int i = 1; i < this->totalNrOfJumps; i++)
    {
        if (this->jumps[i] > best)
        {
            best = this->jumps[i];
        }
    }
    return best;
}

string Jumper::getDescription() const
{
    return Competitor::getDescription() + " had the best jump of " + to_string(this->bestJump()) + " cm";
}
