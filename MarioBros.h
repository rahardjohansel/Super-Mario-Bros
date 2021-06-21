#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <chrono>
#include "../Game/Game.h"
#include "Animation.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Background.h"
#include "Platform.h"



class MarioBros : public Game
{
private: //All Sprites
	float SizeX, SizeY;
	sf::Texture MarioTexture;
	sf::Texture GameEndTexture;
	sf::Texture BowserTexture;
	sf::Texture BoxTexture;
	sf::Texture BackTexture;
	sf::Texture PipeTexture;
	sf::Texture Transparent;
	sf::Texture FlagTexture;
	sf::Texture MarioHealthTexture;

	sf::Sprite Mario;
	sf::Sprite MarioHealth;
	sf::Sprite GameEnd;
	sf::Sprite Flag;
	sf::Sprite Box;
	sf::Sprite Plat1TopBox;
	sf::Sprite Plat1BotBox;
	sf::Sprite Box2;
	sf::Sprite Plat2TopBox;
	sf::Sprite Plat2BotBox; 
	sf::Sprite Box3; 
	sf::Sprite Plat3TopBox; 
	sf::Sprite Plat3BotBox; 
	sf::Sprite Box4;
	sf::Sprite Plat4TopBox;
	sf::Sprite Plat4BotBox;
	sf::Sprite Box5;
	sf::Sprite Plat5TopBox;
	sf::Sprite Plat5BotBox;
	sf::Sprite Box6;
	sf::Sprite Plat6TopBox;
	sf::Sprite Plat6BotBox;
	sf::Sprite Box7;
	sf::Sprite Plat7TopBox;
	sf::Sprite Plat7BotBox;
	sf::Sprite Box8;
	sf::Sprite Plat8TopBox;
	sf::Sprite Plat8BotBox;
	sf::Sprite Box9;
	sf::Sprite Plat9TopBox;
	sf::Sprite Plat9BotBox;
	sf::Sprite Box10;
	sf::Sprite Plat10TopBox;
	sf::Sprite Plat10BotBox;
	sf::Sprite Box11;
	sf::Sprite Plat11TopBox;
	sf::Sprite Plat11BotBox;
	sf::Sprite Box12;
	sf::Sprite Plat12TopBox;
	sf::Sprite Plat12BotBox;
	sf::Sprite MidPlat;
	sf::Sprite Floor;
	sf::Sprite BackGround;
	sf::Sprite BackGround2;
	sf::Sprite BackGround3;
	sf::Sprite BackGround4;
	sf::Sprite BackGround5;
	sf::Sprite Pipe;
	sf::Sprite PipeTopPlat;
	sf::Sprite Bowser;
	sf::Sprite LeftBowserPlat;
	sf::Sprite RightBowserPlat;

	Player player;
	Enemy enemy;
	Background background;
	Platform platform;

	sf::Vector2f MarioVelocity;
	sf::Vector2f BowserVelocity;
	sf::Vector2f BowserPlatVelocity;
	sf::Vector2f BackgroundVelocity;
	sf::Vector2f PipeVelocity;
	sf::Vector2f Direction;
	//sf::Music music;

	int health = 1;
	float BowserDirection = -1.0f;
	bool DrawBowser = true;
	bool MoveBowser = true;
	float speed = 250.0f;
	float dt = 1.0f / 60.0f;
	bool FaceRight;
	float Gravity = 981.0f;
	bool canJump = true;
	float jumpHeight = 275.0f;
	bool BowserSide = true;
	bool DrawMario = true;
	bool GameOver = false;

public:
	MarioBros();
	virtual void start(sf::RenderWindow& window);
	virtual void addEvents(sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void exit();



	
};