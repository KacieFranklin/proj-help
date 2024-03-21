#include "Crawler.h"
#include "Player.h"
#include <iostream>

/// <summary>
/// default constructor for the Crawler
/// </summary>
Crawler::Crawler()
{
	if (!texture.loadFromFile("ASSETS\\IMAGES\\enemy2_down.png"))
	{
		std::cout << "problem loading enemy2_down.png";
	}
	sprite.setTexture(texture);
	sprite.setScale(3.0, 3.0);
	//sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	sprite.setPosition(100, 100);
	//sprite.setColor(sf::Color::Red);

	health = 3;//sets Crawler's health
	speed = 2;//sets Crawler's speed
}

/// <summary>
/// returns the sprite for game.cpp
/// </summary>
/// <returns></returns>
sf::Sprite Crawler::getBody()
{
	return sprite;
}

/// <summary>
/// the crawler follows after the player
/// </summary>
/// <param name="player"></param>
void Crawler::move(Player player)
{
	location = sprite.getPosition();
	sf::Vector2f playerLocation = player.getPosition();

	if (playerLocation.x > location.x)
	{
		sprite.setPosition(location.x + speed, location.y);//Crawler goes right
		if (!texture.loadFromFile("ASSETS\\IMAGES\\enemy2_right.png"))//load texture
		{
			std::cout << "problem loading enemy2_right.png";
		}
		sprite.setTexture(texture);
	}
	if (playerLocation.x < location.x)
	{
		sprite.setPosition(location.x - speed, location.y);//Crawler goes left
		if (!texture.loadFromFile("ASSETS\\IMAGES\\enemy2_left.png"))//load texture
		{
			std::cout << "problem loading enemy2_left.png";
		}
		sprite.setTexture(texture);
	}
	if (playerLocation.y > location.y)
	{
		sprite.setPosition(location.x, location.y + speed);//Crawler goes down
		if (!texture.loadFromFile("ASSETS\\IMAGES\\enemy2_down.png"))//load texture
		{
			std::cout << "problem loading enemy2_down.png";
		}
		sprite.setTexture(texture);
	}
	if (playerLocation.y < location.y)
	{
		sprite.setPosition(location.x, location.y - speed);//Crawler goes up
		if (!texture.loadFromFile("ASSETS\\IMAGES\\enemy2_up.png"))//load texture
		{
			std::cout << "problem loading enemy2_up.png";
		}
		sprite.setTexture(texture);
	}
}