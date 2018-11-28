#include "Hero.h"
#include<iostream>
#include <time.h>

void Hero::takeDamage(float damageTaken)
{
	damageTaken = damageTaken - mDefense;

	//checks if the total damage output is less than or equal to zero if so hero recieves no damage
	if (damageTaken <= 0)
	{

		std::cout << name << " blocked!" << std::endl;
	}

	if (mHealth > 0)
	{
		mHealth = mHealth - damageTaken;
	}
}

void Hero::fight(Character*foe, Attack hit)
{
	float damageTaken;

	srand(time(NULL));

	//Creates a random value used to measure accuracy
	int Accuracy_Value = rand() % 100;

	//if the random accuracy value is less than the min required to land a hit no damage is dealt
	if (Accuracy_Value < mAccuracy.min)
	{
		std::cout << "You missed!" << std::endl;
	}

	//if the random accuracy value is more than the min required to land a hit and less than the maximum value required base damage is dealt
	else if (Accuracy_Value > mAccuracy.min && Accuracy_Value < mAccuracy.max)
	{
		damageTaken = hit.mDamage + (hit.mDamage * mStrength);

		foe->takeDamage(damageTaken);
	}

	//if the random accuracy value is more than the max value required to land a hit the player's damage is doubled
	else if (Accuracy_Value > mAccuracy.max)
	{
		damageTaken = (hit.mDamage + (hit.mDamage * mStrength) * 2);

		foe->takeDamage(damageTaken);
	}
}

void Hero::viewStats()
{
	std::cout << name << "'s stats" << std::endl;
	std::cout << "Health: " << mHealth << std::endl;
	std::cout << "Defense: " << mDefense << std::endl;
	std::cout << "Strength: " << mStrength << std::endl;
	std::cout << "Accuracy: " << mAccuracy.min << " - " << mAccuracy.max << std::endl;
}

void Hero::defend()
{
	int protection = 20;
	mDefense = mDefense + protection;
}

Hero::Hero()
{
}

//Takes the choice variable and uses it to access an index in the armorbag and then add the stats to the current stats
void Hero::equipArmor(int choice)
{
	mArmor = armorBag.at(choice);
	mDefense = mDefense + mArmor.defenseBoost;
	mHealth = mHealth + mArmor.health_Value;
	mStrength = mStrength + mArmor.strength_Value;
}

//removes current armor stats by subtracting the values
void Hero::unequipArmor()
{
	mDefense = mDefense - mArmor.defenseBoost;
	mHealth = mHealth - mArmor.health_Value;
	mStrength = mStrength - mArmor.strength_Value;
}

void Hero::buy_Attack(Shop& store, int choice)
{
	AttackItem item_Bought = store.sellattack(choice);
	mGold = mGold - item_Bought.mCost;
	attackBag.push_back(item_Bought.newattack);
}
//choice 1 is the item they want to equip choice two is what item are they replacing
void Hero::equipAttack(int choice1, int choice2)
{
	Attack* temp = new Attack;
	*temp = listofattacks[choice2];
	listofattacks[choice2] = attackBag.at(choice1);
	attackBag.at(choice1) = *temp;
	delete temp;
}

void Hero::unequipAttack(int choice)
{
	attackBag.push_back(listofattacks[choice]);
	Attack*ptr = new Attack;
	listofattacks[choice] = *ptr;
	delete ptr;
}

//needs to be looked at
void Hero::initalizeHero()
{
	mGold = 99999;
	mHealth = 100;
	mDefense = 5;
	mStrength = .05f;
	mAccuracy.min = 30;
	mAccuracy.max = 90;
}

void Hero::AssignStartingPoints(std::string othername)
{
	int count = 0;
	int tempChoice = 0;
	while (count != 2)
	{
		char op;
		if (tempChoice > 0)
		{
			system("cls");
			std::cout << "Enter (1) to level up your Health\n";
			std::cout << "Enter (2) to level up your Defense\n";
			std::cout << "Enter (3) to level up your Accuracy\n";
			std::cout << "Enter (4) to level up your Strength\n\n";

			std::cout << "Enter (0) to not apply a skill point\n\n";
		}
		else if (count < 1)
		{
			std::cout << "Please input a name for your hero: "; std::cin >> othername;
			name = othername;
			std::cout << "Hello " << name << ", to start off i'm going to give you 2 free skill points.\n";
			std::cout << "You can use them however you want, or don't use them at all.\n";
			system("pause");

			std::cout << "\nEnter (1) to level up your Health\n";
			std::cout << "Enter (2) to level up your Defense\n";
			std::cout << "Enter (3) to level up your Accuracy\n";
			std::cout << "Enter (4) to level up your Strength\n\n";

			std::cout << "Enter (0) to not apply a skill point\n\n";
		}

		if (count == 1)
		{
			system("cls");
			std::cout << "You have 1 skill point left.\n\n";

			std::cout << "Enter (1) to level up your Health\n";
			std::cout << "Enter (2) to level up your Defense\n";
			std::cout << "Enter (3) to level up your Accuracy\n";
			std::cout << "Enter (4) to level up your Strength\n\n";

			std::cout << "Enter (0) to not apply a skill point\n\n";
		}

		std::cin >> op;

		switch (op)
		{
		case '0':
		{
			char temp;
			std::cout << "\nAre you sure you don't want to use this skill point.\n";
			std::cout << "Enter (Y) to confirm, enter anything else to cancel.\n\n";

			std::cin >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				break;
			}
			else
			{
				tempChoice++;
				system("cls");
				continue;
			}
		}

		case '1':
		{
			char temp;
			std::cout << "\nAre you sure you want to use this skill point here.\n";
			std::cout << "Enter (Y) to confirm, enter anything else to cancel.\n";

			std::cin >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				healthLVL++;

				if (healthLVL == 1)
				{
					mHealth = 150;
				}

				if (healthLVL == 2)
				{
					mHealth = 200;
				}

				break;
			}
			else
			{
				tempChoice++;
				system("cls");
				continue;
			}
		}

		case '2':
		{
			char temp;
			std::cout << "\nAre you sure you want to use this skill point here.\n";
			std::cout << "Enter (Y) to confirm, enter anything else to cancel.\n";

			std::cin >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				defenseLVL++;

				if (defenseLVL == 1)
				{
					mDefense = 10;
				}

				if (defenseLVL == 2)
				{
					mDefense = 15;
				}

				break;
			}
			else
			{
				tempChoice++;
				system("cls");
				continue;
			}
		}

		case '3':
		{
			char temp;
			std::cout << "\nAre you sure you want to use this skill point here.\n";
			std::cout << "Enter (Y) to confirm, enter anything else to cancel.\n";

			std::cin >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				accLVL++;

				if (accLVL == 1)
				{
					mAccuracy.min = 26;
					mAccuracy.max = 88;
				}

				if (accLVL == 2)
				{
					mAccuracy.min = 22;
					mAccuracy.max = 86;
				}

				break;
			}
			else
			{
				tempChoice++;
				system("cls");
				continue;
			}
		}

		case '4':
		{
			char temp;
			std::cout << "\nAre you sure you want to use this skill point here.\n";
			std::cout << "Enter (Y) to confirm, enter anything else to cancel.\n";

			std::cin >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				strengthLVL++;

				if (strengthLVL == 1)
				{
					mStrength = .10f;
				}

				if (strengthLVL == 2)
				{
					mStrength = .15f;
				}

				break;
			}
			else
			{
				tempChoice++;
				system("cls");
				continue;
			}
		}
		}
		system("cls");
		count++;
	}
}

bool Hero::upgrade(int pchoice)
{
	switch (pchoice)
	{
	case(1):
	{
		if (healthLVL == 5)
			return false;
		else
		mHealth += 100;
	}
	case (2):
	{
		if (defenseLVL == 5)
			return false;
		else
		mDefense += 5;
	}
	case(3):
	{
		if (strengthLVL == 5)
			return false;
		else
		mStrength += .05;
	}
	case(4):
	{
		if (accLVL == 5)
			return false;
		else
		mAccuracy.max -= 2;
		mAccuracy.min -= 4;
	}
	}
	return true;
}

void Hero::update()
{
}

std::string Hero::getName()
{
	return name;
}

//Can't initialize values in constructor. A possible solution would be to copy the argument list into initialize hero function and ask for name in assign skill point function
//Hero::Hero()
//{
//	//mHealth = 100;
//	//mDefense = 5;
//	//mStrength = .05f;
//	//mAccuracy.min = 30;
//	//mAccuracy.max = 90;
//}

//calls the sell function for the store to remove the item from its inventory and then adds it to to the players inventory
void Hero::buy_Armor(Shop& store, int choice)
{
	DefenseItem item_Bought = store.selldefense(choice);
	mGold = mGold - item_Bought.mCost;
	armorBag.push_back(item_Bought.suit);
}
