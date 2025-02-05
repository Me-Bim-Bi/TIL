#pragma once
#include "Competitor.h"

class Jumper: public Competitor 
{
private:
	int jumps[7];
	int nrOfMadeJumps;
	int totalNrOfJumps; // olika beroende på tävling
public:
	Jumper(string name, int startNr, int totalNrOfJumps = 5);
	~Jumper();
	void addJumpResult(int length, int jumpNr);
	int getNrOfMadeJumps() const;
	int getTotalNrOfJumps() const;
	void setTotalNrOfJumps(int totalNrOfJumps);
	int bestJump() const;
	string getDescription() const override;
};

