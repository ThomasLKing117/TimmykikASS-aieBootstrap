#pragma once
#include "Shop.h"
#include "Game.h"
#include "Application.h"
#include "Renderer2D.h"

class TowerofDameonApp :public aie::Application
{
protected:

	aie::Renderer2D*	m_2dRenderer;
	
	aie::Texture*		m_IdleShopKeeper;

	aie::Font*			m_font;

	Game* m_tower;
	Hero* player;
	float m_cameraX, m_cameraY;
	float m_timer;
	enum mode { newGame,inShop, inBattle, inContinue };
	mode gamestate =  newGame;
public:
	TowerofDameonApp();
	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	//linked list:
	/*unorderedList<Enemy> enemyLadder;
	Game(unorderedList<Enemy>);*/
};