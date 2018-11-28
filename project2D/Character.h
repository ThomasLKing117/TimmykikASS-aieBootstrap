#pragma once
#include "Attack.h"
#include <string>
#include "Accuracy.h"

//Character is an abstract class that both hero an enemy inherit from
class Character
{
protected:
	std::string name;
	float mHealth;
	float mDefense;
	float mStrength;
	Accuracy mAccuracy;
	Attack listofattacks[3];
public:
	//The takeDamage function is called in the fight function and is only used to 
	//decrement the hero/enemy's health
	virtual void takeDamage(float) = 0;

	//The fight function calculates the total damage output of the hero/enemy that is about to attack and then calls the take damage function with that value as its argument
	virtual void fight(Character*,Attack) = 0;

	//checks the hero/enemy's health and returns true if health is greater than zero
	bool isAlive();
};