#pragma once
#include <string>
struct Attack
{
	std::string name;
	float mDamage;
	int usage;
	Attack()
	{

	}
	Attack(std::string othername, float number,int usagenum)
	{
		name = othername;
		mDamage = number;
		usage = usagenum;
	}
};