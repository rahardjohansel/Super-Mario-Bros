#include "Platform.h"

Platform::Platform(sf::Sprite& sprite)
{

}

Platform::~Platform()
{
}

void Platform::Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity)
{
	sprite.move(velocity * dt); //take - if it doesn't work
}

