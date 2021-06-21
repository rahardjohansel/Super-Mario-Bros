#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Sprite& sprite, int x, int y, int width, int height);
	~Animation();
	void ApplyToSprite(sf::Sprite& sprite); //can add const
	void Update(float dt);

private:
	void Advance();
private:
	sf::Texture TextureFaceLeft;
	sf::Texture TextureFaceRight;

	static constexpr int nFrames = 5;
	static constexpr float holdTime = 0.4f;
	sf::IntRect frames[nFrames];
	sf::IntRect frames2[nFrames];
	int iFrame = 0;
	int iFrame2 = 9;
	float time = 0.0f;
	bool flag = false;


};

