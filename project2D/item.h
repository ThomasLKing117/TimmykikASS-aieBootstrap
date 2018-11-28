#pragma once
#include <string>
#include "Attack.h"
struct Item
{
	std::string name;
	int mCost;
	Item();
	Item(std::string nameofitem, int costofitem);
};