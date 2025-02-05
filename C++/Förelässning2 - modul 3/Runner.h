#pragma once
#include "Competitor.h"

class Runner:public Competitor // Runner ärver Competitor som är en basklass, Runner är en subklass
{
private:
	int distance;
	float raceTime;
public:
	Runner(string name, int startNr, int distance);
	Runner();
	~Runner();
	void setDistance(int distance);
	void setRaceTime(float time);
	int getDistance() const;
	float getRaceTime() const;
	string getDescription() const override;
};
