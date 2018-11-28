#include "defenseitem.h"
#include <iostream>
DefenseItem::DefenseItem()
{
}

DefenseItem::DefenseItem(std::string nameofitem, int costofitem, Armor item)
{
	name = nameofitem;
	mCost = costofitem;
	suit = item;
}

void DefenseItem::viewstats()
{
	std::cout << name << "\n" << "Defense Boost: " << suit.defenseBoost << "\n" <<
		"Health Boost: " << suit.health_Value << "\n" << "Strength Multiplier: x" << suit.strength_Value << std::endl;
}

std::ostream & operator<<(std::ostream & os, const DefenseItem item)
{
	os << item.name << "\n" << "Cost: " << item.mCost << "\n";
	return os;
}
