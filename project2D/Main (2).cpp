#include <iostream>
#include <vector>
#include "attack.h"
#include "Character.h"
#include "Enemy.h"
#include "Hero.h"
#include "item.h"
#include <string>
#include "Shop.h"
#include "attackitem.h"
#include "defenseitem.h"
#include "iterator.h"
#include "list.h"
#include "nodetype.h"
#include"unorderedlist.h"
#include "Game.h"


int main()
{
	//Just a quickly made list of enemy attacks:
	//can mix n match.

	///////////////////////////////////
	//The Juggler's Attacks
	Attack throwball;
	throwball.mDamage = 15;

	Attack cynicalSlap;
	cynicalSlap.mDamage = 35;

	Attack balloonBomb;
	balloonBomb.mDamage = 18;
	///////////////////////////////////
	//Kusunoki Masashige's Attacks
	Attack samuraiSlash;
	samuraiSlash.mDamage = 45;

	Attack shuriken;
	shuriken.mDamage = 24;

	Attack shogunRage;
	shogunRage.mDamage = 60;
	///////////////////////////////////
	//Jann's Attacks
	Attack whirlwind;
	whirlwind.mDamage = 22;

	Attack shapeShift;
	shapeShift.mDamage = 33;

	Attack demonicScream;
	demonicScream.mDamage = 12;
	///////////////////////////////////
	//Deogen's Attacks
	Attack unholyBlast;
	unholyBlast.mDamage = 55;

	Attack silentDash;
	silentDash.mDamage = 18;

	Attack spookyClaw;
	spookyClaw.mDamage = 20;
	///////////////////////////////////
	//George Sands' Attacks
	Attack houndBite;
	houndBite.mDamage = 12;

	Attack werewolfSlash;
	werewolfSlash.mDamage = 30;

	Attack fullMoonWrath;
	fullMoonWrath.mDamage = 46;
	///////////////////////////////////
	//Dameon The Necromancer's Attacks
	Attack shadowBurst;
	shadowBurst.mDamage = 22;

	Attack undeadCasting;
	undeadCasting.mDamage = 66;

	Attack necromancingStorm;
	necromancingStorm.mDamage = 46;

	//possible critical move or a boss type move:
	Attack apocalypticPlague;
	apocalypticPlague.mDamage = 70;
	///////////////////////////////////

	Attack jugglerAttacks[3] = { throwball , cynicalSlap, balloonBomb };
	Attack kusunokiAttacks[3] = { samuraiSlash , shuriken, shogunRage };
	Attack jannAttacks[3] = { whirlwind , shapeShift, demonicScream };
	Attack deogenAttacks[3] = { unholyBlast , silentDash, spookyClaw };
	Attack georgeAttacks[3] = { houndBite, werewolfSlash, fullMoonWrath };
	Attack dameonAttacks[4] = { shadowBurst, undeadCasting, necromancingStorm, apocalypticPlague };

																	  //H	 //D  //S  //A	//P
	Enemy* enemy1 = new Enemy("The Juggler",jugglerAttacks,			  100.0, 5.0, .2,  20,90, 1);
	Enemy* enemy2 = new Enemy("Kusunoki Masashige", kusunokiAttacks,  150.0, 20.0,.15, 15,93, 2);
	Enemy* enemy3 = new Enemy("Jann", jannAttacks,					  300.0, 35.0, .1, 10,90, 3);
	Enemy* enemy4 = new Enemy("Deogen", deogenAttacks,				  350.0, 15.0, .1,  5,85, 4);
	Enemy* enemy5 = new Enemy("George Sands", georgeAttacks,		  400.0, 40.0,.16, 30,95, 5);
	Enemy* boss = new Enemy("Dameon The Necromancer", dameonAttacks,  400.0, 24.0, .3, 35,80, 6);

	//Opertors need to be overloaded before implementation
	/*unorderedList<Enemy> ladder;
	ladder.initialize();
	ladder.insertfirst(enemy1);*/



	Hero *hero1;
	Game tower;
	hero1->initalizeHero();
	std::string theirname;
	hero1->AssignStartingPoints(theirname);
	tower.initializeshop();
	tower.shop(hero1);
	enemy1->fight(hero1, jugglerAttacks[0]);

	return 0;
}