#include "Runner.h"
#include <iostream>
Runner::Runner(string name, int startNr, int distance):
    Competitor(name, startNr), distance(distance), raceTime(-1)
{
    /*this->distance = distance;
    this->raceTime = -1;*/
    cout << "Constructor Runner" << endl;
}

Runner::Runner() :
    Competitor(), distance(0), raceTime(-1)
{
}

Runner::~Runner()
{
    cout << "Destructor Runner" << endl;
}

void Runner::setDistance(int distance)
{
    this->distance = distance;
}

void Runner::setRaceTime(float time)
{
    this->raceTime = time;
}

int Runner::getDistance() const
{
    return this->distance;
}

float Runner::getRaceTime() const
{
    return this->raceTime;
}

string Runner::getDescription() const // Överskuggning av funktionen i basklassen
{
    return Competitor::getDescription() + " distance " + to_string(this->distance) + " m, time " 
        + to_string(this->raceTime) + " sec";
}
