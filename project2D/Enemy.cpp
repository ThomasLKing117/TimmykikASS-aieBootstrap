#include "Enemy.h"
#include<iostream>
#include <time.h>

void Enemy::takeDamage(float damageTaken)
{
	damageTaken = damageTaken - mDefense;

	//checks if the total damage output is less than or equal to zero if so enemy recieves no damage
	if (damageTaken <= 0)
	{

		std::cout << name << " blocked!" << std::endl;
	}

	else if (mHealth > 0 && damageTaken >= 0)
	{
		mHealth = mHealth - damageTaken;
	}
}


void Enemy::fight(Character* foe, Attack hit)
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

	//if the random accuracy value is more than the max value required to land a hit the enemy's damage is doubled
	else if (Accuracy_Value > mAccuracy.max)
	{
		damageTaken = (hit.mDamage + (hit.mDamage * mStrength) * 2);

		foe->takeDamage(damageTaken);
	}
}


void Enemy::defend()
{
	int protection = 20;
	mDefense = mDefense + protection;
}


Enemy::Enemy()
{
}



Enemy::Enemy(std::string name, Attack otherlistofattacks[3], float health, float def, float str, int minAcc, int maxAcc)
{
	//(Stats:.. Can be changed later)
	mHealth = health;
	mDefense = def;
	mStrength = str;
	mAccuracy.min = minAcc;
	mAccuracy.max = maxAcc;


	this->name = name;
	for (int i = 0; i <= 2; i++)
	{
		listofattacks[i] = otherlistofattacks[i];
	}

}

//Enemy & Enemy::operator<=(Enemy & enemy)
//{
//
//	return ;
//}
