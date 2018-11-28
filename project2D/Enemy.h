#pragma once
#include "Character.h"
#include "Hero.h"


class Enemy : public Character
{
public:
	//The takeDamage function is called in the fight function and is only used to 
	//decrement the hero's health
	void takeDamage(float) override;

	//The fight function calculates the total damage output of the enemy that is about to attack and then calls the take damage function with that value as its argument
	void fight(Character*, Attack) override;

	//Raises the enemy's defense by 20
	void defend();

	Enemy();

	Enemy(std::string name, Attack listofattacks[3], float health, float def, float str, int minAcc, int maxAcc, int placement);
	bool operator <= (Enemy rhs);
	bool operator != (Enemy rhs);
	bool operator == (Enemy rhs);

private:
	int mPlacement;
};