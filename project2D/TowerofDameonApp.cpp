#include "TowerofDameonApp.h"
#include <time.h>
#include <iostream>
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include "Application.h"



TowerofDameonApp::TowerofDameonApp()
{
}

bool TowerofDameonApp::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	m_tower = new Game;
	m_tower->item_Shop.keeprenderer = new aie::Renderer2D();
	m_tower->item_Shop.shop = new aie::Texture("./textures/shop.png");
	m_tower->item_Shop.shopkeep = new aie::Texture("./textures/sell.png");
	m_tower->item_Shop.hero = new aie::Texture("./textures/sprites/Hero1Back.png");
	m_font = new aie::Font("./font/myfont.ttf", 32);
	
	m_tower->initializeshop();
	
	player = new Hero;
	player->initalizeHero();
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}


void TowerofDameonApp::shutdown()
{
	delete m_2dRenderer;
	delete m_tower->item_Shop.keeprenderer;
	delete m_tower->item_Shop.shop;
	delete m_tower->item_Shop.shopkeep;
}

void TowerofDameonApp::update(float deltaTime)
{
	
	
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

		switch (gamestate)
		{
		case newGame:
		{
			std::string name;
			player->AssignStartingPoints(name);
		}
		case(inShop):
		{
			m_tower->shop(player);
		}
		case(inBattle):
		{
			m_tower->battleladder();
		}
		case(inContinue):
		{

		}
		}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void TowerofDameonApp::draw()
{
	// wipe the screen to the background colour
	clearScreen();
	float newcam1 = 0;
	float newcam2 = 0;
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	//m_keeprenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_tower->draw(m_2dRenderer,gamestate,m_timer, m_font);

	

	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	m_2dRenderer->end();

	m_2dRenderer->begin();
	m_2dRenderer->setUVRect(int(m_timer * 8) % 3 / 2.9f, 0.f, .33, 1);
	m_2dRenderer->drawSprite(m_IdleShopKeeper, 600, getWindowHeight() - 70, 38, 54);
	m_2dRenderer->drawText(m_font, "ASHER : Hello young Hero! How may I aid you today on your quest?", 300, 100, 100);
	
	m_2dRenderer->end();
}




