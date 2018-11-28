#include "Shop.h"
#include <vector>
#include <iostream>
Shop::Shop()
{
}

Shop::Shop(std::vector<DefenseItem> armor, std::vector<AttackItem> attack)
{
	armorstock = armor;
	attackstock = attack;
}
const char * Shop::speak(int num)
{
	const char* say;
	switch (shopstate)
	{
	case(welcome):
	{
		say = "Asher: Ah! Well if it isn't the warrior who dare challanges Dameon. How may I aid you today my suicidal friend?";
		return say;
	}
	case(viewAttackItems):
	{
		say = "Asher: Need a new move eh? I guess spamming the attack button wasn't enough?";
		return say;
	}
	case(viewDefenseItems):
	{
		say = "Asher: Please enjoy one of our mostly legal premium performance enhancing elixers.";
		return say;
	}
	case(viewUpgrades):
	{
		say = "Asher: So you need to get more physically fit? Hehe, why workout when you can pay me?";
		return say;
	}
	case(sell):
	{
		say = "Asher: Thank you,thank you! A fine choice my friend. Will you be buying more?";
		return say;
	}
	}
}
AttackItem Shop::sellattack(int choice)
{
	AttackItem item_Sold = attackstock.at(choice);
	attackstock.erase(attackstock.begin() + choice);
	return item_Sold;
}

DefenseItem Shop::selldefense(int choice)
{
	DefenseItem item_Sold = armorstock.at(choice);
	armorstock.erase(armorstock.begin() + choice);
	return item_Sold;
}

void Shop::viewAttacks()
{
	for (int i = 0; i < (attackstock.size()); i++)
	{
		std::cout << "(" << i << ") " << attackstock.at(i) << std::endl;
	}
}

void Shop::viewArmor()
{
	for (int i = 0; i < (armorstock.size()); i++)
	{
		std::cout << "(" << i << ") " << armorstock.at(i) << std::endl;
	}
}

void Shop::draw(aie::Renderer2D*renderer, int timer,aie::Font* font)
{
	renderer->drawSprite(shop, 600, 450, 500, 583);
	renderer->drawSprite(hero, 600, 400, 57, 92);
	keeprenderer->setUVRect(int(timer * 8) % 3 / 2.9f, 0.f, .33, 1);
	keeprenderer->drawSprite(shopkeep, 600, 720 - 70, 38, 54);
	keeprenderer->drawText(font, speak(shopstate), 300, 100, 100);
}
