#include "Enemy.h"

Enemy::Enemy(sf::Sprite& sprite) : BowserAnimation(sprite, 23, 150, 128, 145)
{
	sprite.setTextureRect({ 23,150,128,145 });

}

Enemy::~Enemy()
{

}


void Enemy::Update(float dt, sf::Sprite& sprite, bool& Right)
{
	BowserAnimation.Update(dt);
	BowserAnimation.ApplyToSprite(sprite, Right);
}

void Enemy::move(sf::Sprite& sprite, sf::Vector2f Velocity, float dt)
{
	sprite.move(Velocity * dt);
}

void Enemy::OutOfMap(sf::Sprite& sprite, sf::Vector2f velocity, float dt)
{
	sprite.move(velocity * dt);
}