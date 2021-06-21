#pragma once
#include <SFML/Graphics.hpp>
class Background
{


public:
	Background(sf::Sprite& sprite);
	~Background();
	void Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity);
	void SetPosition(sf::Vector2f position);

private:
	float SizeX, SizeY;


};

