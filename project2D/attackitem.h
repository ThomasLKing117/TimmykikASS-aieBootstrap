#pragma once
#pragma once
#include <string>
#include "Attack.h"
#include "item.h"
//An attack item stores an attack that the hero can equip. Unlike normal attacks, attack items have a cost variable
//that is used to decrement the hero's gold
struct AttackItem:Item
{
	//Attack that the attack item has
	Attack newattack;

	AttackItem();
	AttackItem(std::string nameofitem, int costofitem, Attack item);
	friend std::ostream& operator<<(std::ostream& os, const AttackItem item);
	void viewstats();
};