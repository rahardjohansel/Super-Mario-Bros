#include "MarioBros.h"
#include <cmath>
MarioBros::MarioBros() : player(Mario), background(BackGround), platform(Pipe), enemy(Bowser)
{
	image_path = "FinalSuperMario/Sprites/FinalMario.png";
	title = "Mario Bros";
	info_path = "FinalSuperMario/Information/info.txt";
	load_game();
	
}

void MarioBros::start(sf::RenderWindow& window)
{
	SizeX = window.getSize().x;
	SizeY = window.getSize().y;
	BackTexture.loadFromFile("FinalSuperMario/Sprites/FinalMario.png");
	BackGround.setTexture(BackTexture);
	BoxTexture.loadFromFile("FinalSuperMario/Sprites/box.png");
	
	PipeTexture.loadFromFile("FinalSuperMario/Sprites/MarioPipe.png");
	Pipe.setTexture(PipeTexture);
	MarioTexture.loadFromFile("FinalSuperMario/Sprites/SuperMario.png"); //2375 x 1707
	Mario.setTexture(MarioTexture);
	Floor.setTexture(BoxTexture);
	Transparent.loadFromFile("FinalSuperMario/Sprites/Transp.png");
	BowserTexture.loadFromFile("FinalSuperMario/Sprites/Bowser.png");
	FlagTexture.loadFromFile("FinalSuperMario/Sprites/Pole.png");
	MarioHealthTexture.loadFromFile("FinalSuperMario/Sprites/MarioHealth.png");
	GameEndTexture.loadFromFile("FinalSuperMario/Sprites/GameOver.png");
	
	MarioHealth.setTexture(MarioHealthTexture);
	MarioHealth.setScale(0.2f, 0.2f);
	MarioHealth.setPosition(30.0f, 0.0f);

	GameEnd.setTexture(GameEndTexture);
	GameEnd.setScale(5.0f, 5.0f);
	GameEnd.setPosition(200.0f, -50.0f);

	Flag.setTexture(FlagTexture);
	Flag.setScale(1.0f, 1.5f);
	Flag.setPosition(4500.0f, 300.0f);

	Box.setTexture(BoxTexture);
	Box.setScale(0.03f, 0.03f); //Scale always the same
	Box.setPosition(500.0f, 775.0f); //Change Position for next box to be beside it

	Plat1BotBox.setTexture(PipeTexture); //Copy the same 
	Plat1BotBox.setColor(sf::Color::Transparent);  //Don't copy
	Plat1BotBox.setScale(0.03f, 0.0009f); // Copy the same
	Plat1BotBox.setPosition(500.f, 827.62f); // Just change the x

	Plat1TopBox.setTexture(PipeTexture); //Just the same
	Plat1TopBox.setColor(sf::Color::Transparent); 
	Plat1TopBox.setScale(0.03f, 0.0009f); //Copy the same
	Plat1TopBox.setPosition(500.0f, 775.0f); // copy the same 

	Box2.setTexture(BoxTexture);
	Box2.setScale(0.03f, 0.03f); //Scale always the same
	Box2.setPosition(551.0f, 775.0f); //Change Position for next box to be beside 
	Plat2BotBox.setTexture(PipeTexture); //Copy the same 
	Plat2BotBox.setColor(sf::Color::Transparent);
	Plat2BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat2BotBox.setPosition(551.f, 827.62f); // Just change the 
	Plat2TopBox.setTexture(PipeTexture); //Just the same
	Plat2TopBox.setColor(sf::Color::Transparent);
	Plat2TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat2TopBox.setPosition(551.0f, 775.0f); // copy the same

	Box3.setTexture(BoxTexture);
	Box3.setScale(0.03f, 0.03f); //Scale always the same
	Box3.setPosition(602.0f, 775.0f); //Change Position for next box to be beside 
	Plat3BotBox.setTexture(PipeTexture); //Copy the same 
	Plat3TopBox.setColor(sf::Color::Transparent);
	Plat3BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat3BotBox.setPosition(602.f, 827.62f); // Just change the 
	Plat3TopBox.setTexture(PipeTexture); //Just the same
	Plat3BotBox.setColor(sf::Color::Transparent);
	Plat3TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat3TopBox.setPosition(602.0f, 775.0f); // copy the same

	Box4.setTexture(BoxTexture);
	Box4.setScale(0.03f, 0.03f); //Scale always the same
	Box4.setPosition(857.0f, 650.0f); //Change Position for next box to be beside 
	Plat4BotBox.setTexture(PipeTexture); //Copy the same 
	Plat4BotBox.setColor(sf::Color::Transparent);
	Plat4BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat4BotBox.setPosition(857.f, 702.62f); // Just change the 
	Plat4TopBox.setTexture(PipeTexture); //Just the same
	Plat4TopBox.setColor(sf::Color::Transparent);
	Plat4TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat4TopBox.setPosition(857.0f, 650.0f); // copy the same

	Box5.setTexture(BoxTexture);
	Box5.setScale(0.03f, 0.03f); //Scale always the same
	Box5.setPosition(908.0f, 650.0f); //Change Position for next box to be beside 
	Plat5BotBox.setTexture(PipeTexture); //Copy the same 
	Plat5BotBox.setColor(sf::Color::Transparent);
	Plat5BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat5BotBox.setPosition(908.f, 702.62f); // Just change the 
	Plat5TopBox.setTexture(PipeTexture); //Just the same
	Plat5TopBox.setColor(sf::Color::Transparent);
	Plat5TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat5TopBox.setPosition(908.0f, 650.0f); // copy the same

	Box6.setTexture(BoxTexture);
	Box6.setScale(0.03f, 0.03f); //Scale always the same
	Box6.setPosition(959.0f, 650.0f); //Change Position for next box to be beside 
	Plat6BotBox.setTexture(PipeTexture); //Copy the same 
	Plat6BotBox.setColor(sf::Color::Transparent);
	Plat6BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat6BotBox.setPosition(959.f, 702.62f); // Just change the 
	Plat6TopBox.setTexture(PipeTexture); //Just the same
	Plat6TopBox.setColor(sf::Color::Transparent);
	Plat6TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat6TopBox.setPosition(959.0f, 650.0f); // copy the same

	Box7.setTexture(BoxTexture);
	Box7.setScale(0.03f, 0.03f); //Scale always the same
	Box7.setPosition(1557.0f, 650.0f); //Change Position for next box to be beside 
	Plat7BotBox.setTexture(PipeTexture); //Copy the same 
	Plat7BotBox.setColor(sf::Color::Transparent);
	Plat7BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat7BotBox.setPosition(1557.f, 702.62f); // Just change the 
	Plat7TopBox.setTexture(PipeTexture); //Just the same
	Plat7TopBox.setColor(sf::Color::Transparent);
	Plat7TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat7TopBox.setPosition(1557.0f, 650.0f); // copy the same

	Box8.setTexture(BoxTexture);
	Box8.setScale(0.03f, 0.03f); //Scale always the same
	Box8.setPosition(1608.0f, 650.0f); //Change Position for next box to be beside 
	Plat8BotBox.setTexture(PipeTexture); //Copy the same 
	Plat8BotBox.setColor(sf::Color::Transparent);
	Plat8BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat8BotBox.setPosition(1608.f, 702.62f); // Just change the 
	Plat8TopBox.setTexture(PipeTexture); //Just the same
	Plat8TopBox.setColor(sf::Color::Transparent);
	Plat8TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat8TopBox.setPosition(1608.0f, 650.0f); // copy the same

	Box9.setTexture(BoxTexture);
	Box9.setScale(0.03f, 0.03f); //Scale always the same
	Box9.setPosition(1659.0f, 650.0f); //Change Position for next box to be beside 
	Plat9BotBox.setTexture(PipeTexture); //Copy the same 
	Plat9BotBox.setColor(sf::Color::Transparent);
	Plat9BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat9BotBox.setPosition(1659.f, 702.62f); // Just change the 
	Plat9TopBox.setTexture(PipeTexture); //Just the same
	Plat9TopBox.setColor(sf::Color::Transparent);
	Plat9TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat9TopBox.setPosition(1659.0f, 650.0f); // copy the same

	Box10.setTexture(BoxTexture);
	Box10.setScale(0.03f, 0.03f); //Scale always the same
	Box10.setPosition(1914.0f, 775.0f); //Change Position for next box to be beside 
	Plat10BotBox.setTexture(PipeTexture); //Copy the same 
	Plat10BotBox.setColor(sf::Color::Transparent);
	Plat10BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat10BotBox.setPosition(1914.f, 827.62f); // Just change the 
	Plat10TopBox.setTexture(PipeTexture); //Just the same
	Plat10TopBox.setColor(sf::Color::Transparent);
	Plat10TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat10TopBox.setPosition(1914.0f, 775.0f); // copy the same

	Box11.setTexture(BoxTexture);
	Box11.setScale(0.03f, 0.03f); //Scale always the same
	Box11.setPosition(1964.0f, 775.0f); //Change Position for next box to be beside 
	Plat11BotBox.setTexture(PipeTexture); //Copy the same 
	Plat11BotBox.setColor(sf::Color::Transparent);
	Plat11BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat11BotBox.setPosition(1964.f, 827.62f); // Just change the 
	Plat11TopBox.setTexture(PipeTexture); //Just the same
	Plat11TopBox.setColor(sf::Color::Transparent);
	Plat11TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat11TopBox.setPosition(1964.0f, 775.0f); // copy the same

	Box12.setTexture(BoxTexture);
	Box12.setScale(0.03f, 0.03f); //Scale always the same
	Box12.setPosition(2015.0f, 775.0f); //Change Position for next box to be beside 
	Plat12BotBox.setTexture(PipeTexture); //Copy the same 
	Plat12BotBox.setColor(sf::Color::Transparent);
	Plat12BotBox.setScale(0.03f, 0.001f); // Copy the same
	Plat12BotBox.setPosition(2015.f, 827.62f); // Just change the 
	Plat12TopBox.setTexture(PipeTexture); //Just the same
	Plat12TopBox.setColor(sf::Color::Transparent);
	Plat12TopBox.setScale(0.03f, 0.001f); //Copy the same
	Plat12TopBox.setPosition(2015.0f, 775.0f); // copy the same

	Pipe.setScale(0.09f, 0.09f);
	Pipe.setPosition(1200.0f, 800.0f);
	
	MidPlat.setTexture(BoxTexture);
	MidPlat.setColor(sf::Color::Transparent);
	MidPlat.setPosition(SizeX / 2, 0.0f);
	MidPlat.setScale(0.001f, 10.0f);

	BackGround.setPosition(0.0f, 0.0f);
	BackGround.setScale(SizeX / 1479.0f, SizeY / 833.0f);

	BackGround2.setTexture(BackTexture);
	BackGround2.setPosition(1920.0f, 0.0f);
	BackGround2.setScale(SizeX / 1479.0f, SizeY / 833.0f);

	BackGround3.setTexture(BackTexture);
	BackGround3.setPosition(3840.0f, 0.0f);
	BackGround3.setScale(SizeX / 1479.0f, SizeY / 833.0f);

	BackGround4.setTexture(BackTexture);
	BackGround4.setPosition(5760.0f, 0.0f);
	BackGround4.setScale(SizeX / 1479.0f, SizeY / 833.0f);

	BackGround5.setTexture(BackTexture);
	BackGround5.setPosition(7680.0f, 0.0f);
	BackGround5.setScale(SizeX / 1479.0f, SizeY / 833.0f);

	Mario.setScale(0.5f, 0.5f);
	Mario.setPosition(0.0f, 825.0f);

	Bowser.setTexture(BowserTexture);
	Bowser.setScale(1.5f, 1.5f);
	Bowser.setPosition(2100.0f, 850.0f); //1600,850

	Floor.setColor(sf::Color::Transparent);
	Floor.setScale(1.5f, 0.0009f);
	Floor.setPosition(0.0f, 1020.0f);

	RightBowserPlat.setTexture(PipeTexture);
	RightBowserPlat.setColor(sf::Color::Transparent);
	RightBowserPlat.setScale(0.0009f, 2.0f);
	RightBowserPlat.setPosition(2800.0f, 800.0f);

	LeftBowserPlat.setTexture(PipeTexture);
	LeftBowserPlat.setColor(sf::Color::Transparent);
	LeftBowserPlat.setScale(0.0009f, 2.0f);
	LeftBowserPlat.setPosition(2000.0f, 800.0f);


	//music.openFromFile("Audio/SuperMarioSound.ogg");
	//music.setVolume(50);

	//music.play();

	
}

void MarioBros::addEvents(sf::RenderWindow& window)
{

	BackgroundVelocity.x = -300.0f;
	PipeVelocity.x = -250.0f;
	MarioVelocity.x = 0.0f;
	BowserPlatVelocity.x = -350.0f;
	
	if (Collision::PixelPerfectTest(Bowser, LeftBowserPlat))
	{
		BowserDirection = 1.0f;
	}
	
	if (Collision::PixelPerfectTest(Bowser, RightBowserPlat))
	{
		BowserDirection = -1.0f;
	}

	if (!Collision::PixelPerfectTest(Bowser, LeftBowserPlat) && Collision::PixelPerfectTest(Bowser, Floor) && BowserDirection < 0.0f)
	{
		BowserVelocity.x = -200.0f;
		enemy.Update(dt, Bowser, BowserSide);
		enemy.move(Bowser, BowserVelocity, dt);
		BowserSide = true;
	}

	if (BowserDirection > 0.0f && Collision::PixelPerfectTest(Bowser, Floor))
	{
		BowserVelocity.x = 200.0f;
		enemy.Update(dt, Bowser, BowserSide);
		enemy.move(Bowser, BowserVelocity, dt);
		BowserSide = false;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		MarioVelocity.x += speed;
		Direction.x = 1.0f; // Direction.x = MarioVelocity.x


	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MarioVelocity.x -= speed; // Direction.x = MarioVelocity.x 
		Direction.x = -1.0f;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		Gravity = 981.0f;
		canJump = false;
		MarioVelocity.y = -sqrtf(2.0f * Gravity * jumpHeight);
		Direction.y = 1.0f; 

	}
	Direction.y = -1.0f;

	MarioVelocity.y += Gravity * dt;

	player.Update(dt, Mario, MarioVelocity);

	if (Collision::PixelPerfectTest(Mario, MidPlat)) 
	{
		MarioVelocity.x = -250;
		MarioVelocity.y += Gravity * dt;
		background.Update(dt, BackGround, BackgroundVelocity);
		background.Update(dt, BackGround2, BackgroundVelocity);
		background.Update(dt, BackGround3, BackgroundVelocity);
		background.Update(dt, BackGround4, BackgroundVelocity);
		background.Update(dt, BackGround5, BackgroundVelocity);
		player.Update(dt, Mario, MarioVelocity);
		enemy.move(Bowser, PipeVelocity, dt);
		platform.Update(dt, Pipe, PipeVelocity);
		platform.Update(dt, Bowser, BowserVelocity);
		platform.Update(dt, Box, PipeVelocity);
		platform.Update(dt, Box2, PipeVelocity);
		platform.Update(dt, Box3, PipeVelocity);
		platform.Update(dt, Box4, PipeVelocity);
		platform.Update(dt, Box5, PipeVelocity);
		platform.Update(dt, Box6, PipeVelocity);
		platform.Update(dt, Box7, PipeVelocity);
		platform.Update(dt, Box8, PipeVelocity);
		platform.Update(dt, Box9, PipeVelocity);
		platform.Update(dt, Box10, PipeVelocity);
		platform.Update(dt, Box11, PipeVelocity);
		platform.Update(dt, Box12, PipeVelocity);
		platform.Update(dt, Plat1BotBox, PipeVelocity);
		platform.Update(dt, Plat1TopBox, PipeVelocity);
		platform.Update(dt, Plat2BotBox, PipeVelocity);
		platform.Update(dt, Plat2TopBox, PipeVelocity);
		platform.Update(dt, Plat3BotBox, PipeVelocity);
		platform.Update(dt, Plat3TopBox, PipeVelocity);
		platform.Update(dt, Plat4BotBox, PipeVelocity);
		platform.Update(dt, Plat4TopBox, PipeVelocity);
		platform.Update(dt, Plat5TopBox, PipeVelocity);
		platform.Update(dt, Plat5BotBox, PipeVelocity);
		platform.Update(dt, Plat6TopBox, PipeVelocity);
		platform.Update(dt, Plat6BotBox, PipeVelocity);
		platform.Update(dt, Plat7TopBox, PipeVelocity);
		platform.Update(dt, Plat7BotBox, PipeVelocity);
		platform.Update(dt, Plat8TopBox, PipeVelocity);
		platform.Update(dt, Plat8BotBox, PipeVelocity);
		platform.Update(dt, Plat9TopBox, PipeVelocity);
		platform.Update(dt, Plat9BotBox, PipeVelocity);
		platform.Update(dt, Plat10TopBox, PipeVelocity);
		platform.Update(dt, Plat10BotBox, PipeVelocity);
		platform.Update(dt, Plat11TopBox, PipeVelocity);
		platform.Update(dt, Plat11BotBox, PipeVelocity);
		platform.Update(dt, Plat12TopBox, PipeVelocity);
		platform.Update(dt, Plat12BotBox, PipeVelocity);
		platform.Update(dt, LeftBowserPlat, BowserPlatVelocity);
		platform.Update(dt, RightBowserPlat, BowserPlatVelocity);
		platform.Update(dt, Flag, PipeVelocity);


		
	}

	if (Collision::PixelPerfectTest(Mario, Box)|| Collision::PixelPerfectTest(Mario, Box2)|| Collision::PixelPerfectTest(Mario, Box3)|| Collision::PixelPerfectTest(Mario, Box4)|| Collision::PixelPerfectTest(Mario, Box5)|| Collision::PixelPerfectTest(Mario, Box6) || Collision::PixelPerfectTest(Mario, Box7) || Collision::PixelPerfectTest(Mario, Box8) || Collision::PixelPerfectTest(Mario, Box9) || Collision::PixelPerfectTest(Mario, Box10) || Collision::PixelPerfectTest(Mario, Box11) || Collision::PixelPerfectTest(Mario, Box12)) // or statement 
	{
		if (Direction.x > 0.0f)
		{
			MarioVelocity.x = -400.0f;
		}
		else
		{
			MarioVelocity.x = 400.0f;
		}
		player.Update(dt, Mario, MarioVelocity);
	}
	
	if ((Collision::PixelPerfectTest(Mario, Plat1TopBox)|| Collision::PixelPerfectTest(Mario, Plat2TopBox)|| Collision::PixelPerfectTest(Mario, Plat3TopBox)|| Collision::PixelPerfectTest(Mario, Plat4TopBox)|| Collision::PixelPerfectTest(Mario, Plat5TopBox)|| Collision::PixelPerfectTest(Mario, Plat6TopBox) || Collision::PixelPerfectTest(Mario, Plat7TopBox) || Collision::PixelPerfectTest(Mario, Plat8TopBox) || Collision::PixelPerfectTest(Mario, Plat9TopBox) || Collision::PixelPerfectTest(Mario, Plat10TopBox) || Collision::PixelPerfectTest(Mario, Plat11TopBox) || Collision::PixelPerfectTest(Mario, Plat12TopBox)) && Direction.y < 0.0f) // add or statement
	{
		MarioVelocity.y = -25.0f;
		if (Direction.x > 0.0f)
		{
			MarioVelocity.x = 400.0f;
		}
		else
		{
			MarioVelocity.x = -400.0f;
		}
		canJump = true;
		player.Update(dt, Mario, MarioVelocity);
	}
	
	if ((Collision::PixelPerfectTest(Mario, Plat1BotBox) || Collision::PixelPerfectTest(Mario, Plat2BotBox) || Collision::PixelPerfectTest(Mario, Plat3BotBox)||Collision::PixelPerfectTest(Mario, Plat4BotBox)|| Collision::PixelPerfectTest(Mario, Plat5BotBox)|| Collision::PixelPerfectTest(Mario, Plat6BotBox) || Collision::PixelPerfectTest(Mario, Plat7BotBox) || Collision::PixelPerfectTest(Mario, Plat8BotBox) || Collision::PixelPerfectTest(Mario, Plat9BotBox) || Collision::PixelPerfectTest(Mario, Plat10BotBox) || Collision::PixelPerfectTest(Mario, Plat11BotBox) || Collision::PixelPerfectTest(Mario, Plat1BotBox)) && Direction.y < 0.0f) // add or statement
	{
		MarioVelocity.y = 300.0f;
		
		player.Update(dt, Mario, MarioVelocity);
	}
		
	if (Collision::PixelPerfectTest(Mario, Pipe))
	{
		if (Direction.x < 0.0f && Collision::PixelPerfectTest(Mario,Floor) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
				//Collision on the Left
				MarioVelocity.x = 250.0f;
				player.Update(dt, Mario, MarioVelocity);
				
		}
		else if (Direction.y < 0.0f && Direction.x < 0.0f && (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) 
		{
			MarioVelocity.x = 0.0f;
			player.Update(dt, Mario, MarioVelocity);

		}

		if(Direction.x > 0.0f && Collision::PixelPerfectTest(Mario,Floor) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//Collision on the right
			MarioVelocity.x = -250.0f;
			player.Update(dt, Mario, MarioVelocity);
		}

		else if (Direction.y < 0.0f && Direction.x > 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			MarioVelocity.x = 0.0f;
			player.Update(dt, Mario, MarioVelocity);

		}
		
		if (Direction.y < 0.0f)
		{
			//Collision on the bottom
			MarioVelocity.y = 0.0f;
			canJump = true;
		}
		else if (Direction.y > 0.0f )
		{
			//Collision on the top

			MarioVelocity.y = 500.0f;
			canJump = false;
		}
		player.Update(dt, Mario, MarioVelocity);
		Gravity = 0.0f;

	}
	else
	{
		Gravity = 981.0f;
	}

	if (Collision::PixelPerfectTest(Bowser, Pipe))
	{
		BowserVelocity.x = 93.0f;
		enemy.move(Bowser, BowserVelocity, dt);
		DrawBowser = false;
	}

	if (Collision::PixelPerfectTest(Mario, Floor))
	{
		canJump = true;
		Gravity = 0.0f;
		MarioVelocity.y = 0.0f;
	}

	if (Collision::PixelPerfectTest(Mario, Bowser))
	{
		DrawBowser = false;
		health--;
		//restart game
	}

	if (Collision::PixelPerfectTest(Mario, Flag) && Direction.x > 0.0f)
	{
		MarioVelocity.x = -250.0f;
		player.Update(dt,Mario,MarioVelocity);
		DrawMario = false;

	}

	if (Mario.getGlobalBounds().left <= 0.0f)
	{
		MarioVelocity.x = 300.0f;
		player.Update(dt, Mario, MarioVelocity);
	}

	if (health == 0)
	{
		GameOver = true;
	}

}

	void MarioBros::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(BackGround);
	window.draw(BackGround2);
	window.draw(BackGround3);
	window.draw(BackGround4);
	window.draw(BackGround5);
	if (DrawMario && !GameOver)
	{
		window.draw(Mario); //Draws Mario
	}
	
	window.draw(Pipe); //Draws Pipe
	if (DrawBowser)
	{
		window.draw(Bowser);
	}
	window.draw(Box); //Draws First 
	window.draw(Plat1TopBox);
	window.draw(Plat1BotBox);
	window.draw(Box2); 
	window.draw(Plat2TopBox);
	window.draw(Plat2BotBox);
	window.draw(Box3);
	window.draw(Plat3TopBox);
	window.draw(Plat3BotBox); 
	window.draw(Box4);
	window.draw(Plat4TopBox);
	window.draw(Plat4BotBox);
	window.draw(Box5);
	window.draw(Plat5TopBox);
	window.draw(Plat5BotBox);
	window.draw(Box6);
	window.draw(Plat6TopBox);
	window.draw(Plat6BotBox);
	window.draw(Box7);
	window.draw(Plat7TopBox);
	window.draw(Plat7BotBox);
	window.draw(Box8);
	window.draw(Plat8TopBox);
	window.draw(Plat8BotBox);
	window.draw(Box9);
	window.draw(Plat9TopBox);
	window.draw(Plat9BotBox);
	window.draw(Box10);
	window.draw(Plat10TopBox);
	window.draw(Plat10BotBox);
	window.draw(Box11);
	window.draw(Plat11TopBox);
	window.draw(Plat11BotBox);
	window.draw(Box12);
	window.draw(Plat12TopBox);
	window.draw(Plat12BotBox);
	if (health >= 1)
	{
		window.draw(MarioHealth);
	}
	window.draw(RightBowserPlat);
	window.draw(LeftBowserPlat);
	window.draw(Floor); //Draws Floor Platform
	window.draw(MidPlat); //Draws Transparent Middle Plat
	window.draw(Flag);
	if (GameOver)
	{
		window.draw(GameEnd);
	}
}

	void MarioBros::exit()
	{
		music.stop();
	}

