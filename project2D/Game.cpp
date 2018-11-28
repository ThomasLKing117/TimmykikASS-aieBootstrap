
#include <time.h>
#include "Game.h"
#include<iostream>
void Game::initializeshop()
{

	std::vector<DefenseItem> armor_Stock;
	std::vector<AttackItem> attack_stock;

	Armor bestArmor("Drink Of The Gods", -20.0, 200.0, .10);
	Armor exhealing_Elixer("Fairy Elixer", -10.0, 100.0, .10);
	Armor healing_Elixer("Ahlian Water", 0.0, 30.0, .03);

	Armor exhealing_Potion("Super Health Potion", -5.0, 60.0, 0);
	Armor healing_Potion("Health Potion", 0.0, 30.0, 0);

	Armor exstrength_Elixer("Titan Elixer", 10.0, -30.0, .10);
	Armor strength_Elixer("Goliath Elixer", 5.0, 0.0, 0.05);

	Armor exstrength_potion("Mighty Potion", 0.0, -50.0, 0.6);
	Armor strength_Potion("Strength Potion", 0.0, 0.0, 0.03);

	Armor exdefense_Potion("Super Defense Potion", 12.0, 0.0, -0.2);
	Armor defense_potion("Defense Potion", 5.0, 0.0, 0.0);


	DefenseItem bestArmor_Item("Drink Of The Gods", 1200, bestArmor);
	DefenseItem exhealing_Elixer_Item("Fairy Elixer", 200, exhealing_Elixer);
	DefenseItem healing_Elixer_Item("Ahlian Water", 150, healing_Elixer);

	DefenseItem exhealing_Potion_Item("Super Health Potion", 110, exhealing_Potion);
	DefenseItem  healing_Potion_Item("Health Potion", 50, healing_Potion);

	DefenseItem exstrength_Elixer_Item("Titan Elixer", 200, exstrength_Elixer);
	DefenseItem strength_Elixer_Item("Goliath Elixer", 150, strength_Elixer);

	DefenseItem exstrength_Potion_Item("Mighty Potion", 110, exstrength_potion);
	DefenseItem strength_Potion_Item("Strength Potion", 50, strength_Potion);

	DefenseItem exdefense_Potion_Item("Super Defense Potion", 110, exdefense_Potion);
	DefenseItem defense_Potion_Item("Defense Potion", 50, defense_potion);


	armor_Stock.push_back(defense_Potion_Item);
	armor_Stock.push_back(exdefense_Potion_Item);
	armor_Stock.push_back(strength_Potion_Item);
	armor_Stock.push_back(exstrength_Potion_Item);
	armor_Stock.push_back(strength_Elixer_Item);
	armor_Stock.push_back(exstrength_Elixer_Item);
	armor_Stock.push_back(healing_Potion_Item);
	armor_Stock.push_back(exhealing_Potion_Item);
	armor_Stock.push_back(healing_Elixer_Item);
	armor_Stock.push_back(exhealing_Elixer_Item);
	armor_Stock.push_back(bestArmor_Item);
	srand(time(NULL));


	Attack ultimate3("Nova Strike", 100.0, 2);
	Attack ultimate2("Earth Shattering Strike", 50 * rand() % 2, 3);
	Attack ultimate1("Revenger Assault", 25 * rand() % 5, 2);

	Attack intermediate3("Sonic Rush", 35.0, 7);
	Attack intermediate2("Lightning Kick", 25.0, 10);
	Attack intermediate1("Axle Combination", 30.0, 5);

	Attack basic3("Force Palm", 5.0, 30);
	Attack basic2("Focus Punch", 12.0, 12);
	Attack basic1("Close Combat", 10.0, 15);



	AttackItem basicitem1("Close Combat", 50, basic1);
	AttackItem basicitem2("Focus Punch", 50, basic2);
	AttackItem basicitem3("Force Palm", 50, basic3);

	AttackItem intermediateitem1("Axle Combination", 150, intermediate1);
	AttackItem intermediateitem2("Lightning Kick", 150, intermediate2);
	AttackItem intermediateitem3("Sonic Rush", 150, intermediate3);

	AttackItem ultimateitem1("Revenger Assault", 200, ultimate1);
	AttackItem ultimateitem2("Earth Shattering Strike", 200, ultimate2);
	AttackItem ultimateitem3("Nova Strike", 200, ultimate3);


	attack_stock.push_back(basicitem1);
	attack_stock.push_back(basicitem2);
	attack_stock.push_back(basicitem3);
	attack_stock.push_back(intermediateitem1);
	attack_stock.push_back(intermediateitem2);
	attack_stock.push_back(intermediateitem3);
	attack_stock.push_back(ultimateitem1);
	attack_stock.push_back(ultimateitem2);
	attack_stock.push_back(ultimateitem3);

	item_Shop = { armor_Stock, attack_stock };

}

void Game::ladder()
{
}



void Game::draw(aie::Renderer2D * renderer, int state,int timer,aie::Font*font)
{
	Shop::storestate a = Shop::storestate::welcome;
	switch (state)
	{
	case inShop:
	{
		item_Shop.draw(renderer, timer, font);
		break;
	}
	case inBattle:
	{
		
	}
	case inContinue:
	{

	}
	}
}


void Game::battleladder()
{
}



Game::Game()
{
}

void Game::shop(Hero* &player)
{
	switch (item_Shop.shopstate)
	{
	case 0: 
	{
		
	}
	}

	/*system("cls");
	char pinput;
	char pchoice;
	std::cout << "Asher: Ah! Well if it isn't " << player->getName() << "! \n" <<
		"How may I aid you today my suicidal friend? \n";
	std::cout << "\n";
	std::cout << " Press 1 to look at new attacks, 2 for a new potion, 3 for upgrades, or q to quit.\n ";
	std::cin >> pchoice;
	while (pchoice != 'q')
	{

		switch (pchoice)
		{
		case(1):

		{	system("cls");
		std::cout << "Asher: Need a new move eh? I guess spamming the attack button wasn't enough? \n";

		item_Shop.viewAttacks();
		std::cout << "\n";
		std::cout << "Input the number of the item you want or press b to go back:  "; std::cin >> pchoice;
		if (pchoice < 'b')
		{
			player->buy_Attack(item_Shop, pchoice);
			break;
		}
		else
		{
			break;
		}
		}

		case(2):
		{
			system("cls");
			std::cout << "Asher: Please enjoy one of our premium performance enhancing elixers. Now with only 25,000 calories! \n";

			item_Shop.viewArmor();
			std::cout << "\n";
			std::cout << "Input the number of the item you want or press b to go back:  "; std::cin >> pchoice;
			if (pchoice < 'b')
			{
				player->buy_Armor(item_Shop, pchoice);
				break;
			}
			else
			{
				break;
			}
		}

		case(3):
		{
			system("cls");
			std::cout << "Asher: So you need to get more physically fit? Hehe, why workout when you can pay me? \n";

			std::cout << "Enter (1) to level up your Health\n";
			std::cout << "Enter (2) to level up your Defense\n";
			std::cout << "Enter (3) to level up your Accuracy\n";
			std::cout << "Enter (4) to level up your Strength\n\n";
			std::cout << "\n";
			std::cout << "Input the number of the item you want or press b to go back:  "; std::cin >> pchoice;
			if (pchoice < 'b')
			{
				player->upgrade(pchoice);
				break;
			}
			else
			{
				break;
			}
		}
		}
		system("cls");
		std::cout << " Press 1 to look at new attacks, 2 for a new potion, 3 for upgrades, or q to quit.\n ";
		std::cin >> pchoice;
	}*/

}
