#include "EnemyAnimation.h"

EnemyAnimation::EnemyAnimation(sf::Sprite& sprite, int x, int y, int width, int height)
{
	TextureFaceLeft.loadFromFile("FinalSuperMario/Sprites/Bowser.png");
	TextureFaceRight.loadFromFile("FinalSuperMario/Sprites/BowserFacingRight.png");


	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * width, y, width , height };
	}

	int counter(0);
	for (int j = 5; j > 0; j--)
	{
		frames2[counter++] = { x + j * width, y, width, height };
	}
}



EnemyAnimation::~EnemyAnimation()
{
}

void EnemyAnimation::ApplyToSprite(sf::Sprite& sprite, bool& Right)
{
	
	if (Right == false)
	{
		sprite.setTexture(TextureFaceRight);
		sprite.setTextureRect(frames2[iFrame]);

	}
	else
	{
		sprite.setTexture(TextureFaceLeft);
		sprite.setTextureRect(frames[iFrame]);

	}
}

void EnemyAnimation::Update(float dt)
{
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime;
		Advance();
	}
}

void EnemyAnimation::Advance()
{
	if (++iFrame >= nFrames)
	{
		iFrame = 0;
	}
}
