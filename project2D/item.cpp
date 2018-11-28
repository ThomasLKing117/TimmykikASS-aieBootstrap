#include "item.h"

Item::Item()
{
}

Item::Item(std::string nameofitem, int costofitem)
{
	name = nameofitem;
	mCost = costofitem;
}
