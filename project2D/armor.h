#pragma once
#include "Character.h"
#include <string>
struct Armor
{
	std::string name;
	float defenseBoost;
	float health_Value;
	float strength_Value;
	Armor();
	Armor(std::string name,float defense, float health, float strength);
};