#pragma once
#pragma once
#include <string>
#include "Attack.h"
#include "item.h"
#include "armor.h"
//An defense item stores armor that the hero can equip. Unlike normal armor, defense items have a cost variable
//that is used to decrement the hero's gold
struct DefenseItem : Item
{
	//Armor that the defense item has
	Armor suit;
	DefenseItem();
	DefenseItem(std::string nameofitem, int costofitem, Armor item);
	friend std::ostream& operator<<(std::ostream& os, const DefenseItem item);
	void viewstats();
};