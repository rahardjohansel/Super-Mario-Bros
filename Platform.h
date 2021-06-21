#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
	public:
		Platform(sf::Sprite& sprite);
		~Platform();
		void Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity);
		void SetPosition(sf::Vector2f position);

	private:
		float SizeX, SizeY;


};


