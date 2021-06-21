#include "Animation.h"

Animation::Animation(sf::Sprite& sprite, int x, int y, int width, int height)
{
	TextureFaceLeft.loadFromFile("FinalSuperMario/Sprites/SuperMario.png");
	TextureFaceRight.loadFromFile("FinalSuperMario/Sprites/SuperMarioFacingRight.png");


	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * width, y, width, height };
	}

	int counter(0);
	for (int j = 9; j > 4; j--)
	{
		frames2[counter++] = { x + j * width - 25, y, width - 9, height };
	}
}



Animation::~Animation()
{
}

void Animation::ApplyToSprite(sf::Sprite& sprite)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		flag = false;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		flag = true;

	}

	if (flag == false)
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

void Animation::Update(float dt)
{
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime;
		Advance();
	}
}

void Animation::Advance()
{
	if (++iFrame >= nFrames)
	{
		iFrame = 0;
	}
}
