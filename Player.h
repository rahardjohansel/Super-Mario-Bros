#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class Player
{
private:
	
public:
	Player(sf::Sprite& sprite);
	~Player();
	void SetDirection(const sf::Vector2f direction, sf::Vector2f& velocity, float& speed);
	void Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity);
	float MarioPosition(sf::Sprite& sprite)
	{
		return sprite.getPosition().x;
	}

	

private:
	Animation MarioAnimation;
	/*sf::Vector2f position;
	sf::Texture texture;*/


};

