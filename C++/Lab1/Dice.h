#ifndef DICE_H
#define DICE_H
class Dice
{
public:
	Dice(int sides = 6);
	~Dice();
	int roll();
	int getValue() const; // Får inte ändra medlemsvariabler, därav const.
	// Överlagrad större-än-operator:
	bool operator>(const Dice& other);
private:
	int value = 1;
	int sides;
};
#endif
