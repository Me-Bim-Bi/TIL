#include "Player.h"
Player::Player(std::string name) : name(name)
{
}
Player::~Player()
{
	delete this->roller;
}
void Player::setDiceRoller(DiceRoller* roller)
{
	this->roller = roller;
}
std::string Player::getName() const
{
	return this->name;
}
const DiceRoller& Player::getDiceRoller() const
{
	return *this->roller;
}
void Player::rollDices()
{
	this->roller->rollDices();
}
