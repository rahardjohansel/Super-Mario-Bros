#include "Player.h"

Player::Player(sf::Sprite& sprite) : MarioAnimation(sprite, 0, 0, 240, 410)
{
	sprite.setTextureRect({ 0,0,240,418 });

}

Player::~Player()
{

}


void Player::SetDirection(const sf::Vector2f direction, sf::Vector2f& velocity, float& speed) 
{
	velocity = direction * speed;
}

void Player::Update(float dt, sf::Sprite& sprite, sf::Vector2f& velocity)
{
	sprite.move(velocity * dt); 
	MarioAnimation.Update(dt);
	MarioAnimation.ApplyToSprite(sprite);

}

