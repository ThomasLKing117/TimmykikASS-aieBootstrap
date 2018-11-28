#include "armor.h"

Armor::Armor()
{
}

Armor::Armor(std::string othername, float defense, float health, float strength)
{
	name = othername;
	defenseBoost = defense;
	health_Value = health;
	strength_Value = strength;
}
