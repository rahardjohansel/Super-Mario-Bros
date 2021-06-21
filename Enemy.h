#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyAnimation.h"
class Enemy
{
private:

public:
	Enemy(sf::Sprite& sprite);
	~Enemy();
	void Update(float dt, sf::Sprite& sprite, bool& Right);
	float BowserPosition(sf::Sprite& sprite)
	{
		return sprite.getPosition().x;
	}

	void move(sf::Sprite& sprite, sf::Vector2f Velocity, float dt);

	void OutOfMap(sf::Sprite& sprite, sf::Vector2f velocity, float dt);

private:
	EnemyAnimation BowserAnimation;
	/*sf::Vector2f position;
	sf::Texture texture;*/


};

