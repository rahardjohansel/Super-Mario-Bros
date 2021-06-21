#include "Background.h"

Background::Background(sf::Sprite& sprite)
{
	
}

Background::~Background()
{
}

void Background::Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity)
{
	sprite.move(velocity * dt); //take - if it doesn't work
}

