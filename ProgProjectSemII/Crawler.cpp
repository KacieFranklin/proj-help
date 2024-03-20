#include "Crawler.h"
#include "Player.h"

/// <summary>
/// default constructor for the Crawler
/// </summary>
Crawler::Crawler()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	sprite.setPosition(100, 100);
	sprite.setColor(sf::Color::Red);

	health = 3;
	speed = 2;
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
		sprite.setPosition(location.x + speed, location.y);
	}
	if (playerLocation.x < location.x)
	{
		sprite.setPosition(location.x - speed, location.y);
	}
	if (playerLocation.y > location.y)
	{
		sprite.setPosition(location.x, location.y + speed);
	}
	if (playerLocation.y < location.y)
	{
		sprite.setPosition(location.x, location.y - speed);
	}
}