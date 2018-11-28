#include "attackitem.h"
#include <iostream>
AttackItem::AttackItem()
{
}

AttackItem::AttackItem(std::string nameofitem, int costofitem, Attack item)
{
	name = nameofitem;
	mCost = costofitem;
	newattack = item;
}
void AttackItem::viewstats()
{
	std::cout << name << "\n" << "Cost: " << mCost << "Damage: " << newattack.mDamage << "\n"<< "BP: " << newattack.usage << "\n";
}
std::ostream & operator<<(std::ostream & os, const AttackItem item)
{
	os << item.name << "\n" << "Cost: " << item.mCost;
	return os;
}
