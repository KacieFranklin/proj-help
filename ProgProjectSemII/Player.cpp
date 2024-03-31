
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"   // include Player header file
#include <iostream>
// Player function definitions here

/// <summary>
/// default constructor for the player
/// </summary>
Player::Player()
{
	if (!texture.loadFromFile("ASSETS\\IMAGES\\player_down.png"))//loads texture
	{
		std::cout << "problem loading player_down.png";
	}
	sprite.setTexture(texture);
	sprite.setScale(1.8, 1.8);
	//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	//sprite.setTextureRect(sf::IntRect(0, 0, 100, 120));
	//sprite.setColor(sf::Color::Blue);
	setPosition();
	bulletLocation = location;

	speed = 3;//sets speed
	health = 6;//sets health
}

/// <summary>
/// Used to return the sprite to Game.cpp
/// </summary>
/// <returns></returns>
sf::Sprite Player::getBody()
{
	return sprite;
}

sf::Sprite Player::getBullet()
{
	return bullet;
}

/// <summary>
/// Sets the position of the player
/// </summary>
void Player::setPosition()
{
	sprite.setPosition(50, 50);
}

void Player::setPosition(int posX, int posY)
{
	sprite.setPosition(posX, posY);
}

/// <summary>
/// Returns the player's position to Crawler.cpp
/// </summary>
/// <returns></returns>
sf::Vector2f Player::getPosition()
{
	return location;
}

/// <summary>
/// Makes the player move up
/// </summary>
void Player::moveUp()
{
	location = sprite.getPosition();
	location.y--;
	sprite.setPosition(location.x, location.y - speed);
	direction = NORTH;
	if (location.y <= 0)//boundry checking
	{	
		
		sprite.setPosition(location.x, 0);
	}
	if (!texture.loadFromFile("ASSETS\\IMAGES\\player_up.png"))//loads texture
	{
		std::cout << "problem loading player_up.png";
	}
	sprite.setTexture(texture);
}

/// <summary>
/// makes the player move down
/// </summary>
void Player::moveDown()
{
	location = sprite.getPosition();
	location.y++;
	sprite.setPosition(location.x, location.y + speed);
	if (location.y + IMAGE_HEIGHT >= SCREEN_HEIGHT)//boundry checking
	{	
		direction = SOUTH;
		sprite.setPosition(location.x, SCREEN_HEIGHT - IMAGE_HEIGHT);
		
	}
	if (!texture.loadFromFile("ASSETS\\IMAGES\\player_down.png"))//loads texture
	{
		std::cout << "problem loading player_down.png";
	}
	sprite.setTexture(texture);
}

/// <summary>
/// makes the player move right
/// </summary>
void Player::moveRight()
{
	location = sprite.getPosition();
	location.x++;
	sprite.setPosition(location.x + speed, location.y);
	if (location.x + IMAGE_WIDTH >= SCREEN_WIDTH)//boundry checking
	{	
		direction = EAST;
		sprite.setPosition(SCREEN_WIDTH - IMAGE_WIDTH, location.y);
		
	}
	if (!texture.loadFromFile("ASSETS\\IMAGES\\player_right.png"))//loads textre
	{
		std::cout << "problem loading player_right.png";
	}
	sprite.setTexture(texture);
}

/// <summary>
/// player fires their weapon
/// </summary>
void Player::shoot()
{
	if (!firing)
	{
		bulletLocation = location;
		bullet.setPosition(bulletLocation);
		firing = true;
		checkDirection();
	}
	//std::cout << "" << direction;
	else {
		if (fireDirection == NORTH)
		{
			bulletLocation.y--;
			bullet.setPosition(bulletLocation);
		}
	}
}

void Player::checkDirection()
{
	if (direction == NORTH)
	{
		fireDirection = NORTH;
		if (!bulletTexture.loadFromFile("ASSETS\\IMAGES\\fireball_up.png"))
		{
			std::cout << "problem loading fireball_up.png";
		}
		bullet.setTexture(bulletTexture);
	}

	if (direction == SOUTH)
	{
		fireDirection = SOUTH;
		if (!bulletTexture.loadFromFile("ASSETS\\IMAGES\\fireball_down.png"))
		{
			std::cout << "problem loading fireball_down.png";
		}
		bullet.setTexture(bulletTexture);
	}
	if (direction == EAST)
	{
		fireDirection = EAST;
		if (!bulletTexture.loadFromFile("ASSETS\\IMAGES\\fireball_right.png"))
		{
			std::cout << "problem loading fireball_right.png";
		}
		bullet.setTexture(bulletTexture);
	}
	if (direction == WEST)
	{
		fireDirection = WEST;
		if (!bulletTexture.loadFromFile("ASSETS\\IMAGES\\fireball_left.png"))
		{
			std::cout << "problem loading fireball_left.png";
		}
		bullet.setTexture(bulletTexture);
	}
}

/// <summary>
/// makes the player move left
/// </summary>
void Player::moveLeft()
{

	location = sprite.getPosition();
	location.x--;
	sprite.setPosition(location.x - speed, location.y);
	if (location.x <= 0)//boundary checking
	{	
		direction = WEST;
		sprite.setPosition(0,location.y);
		
	}
	if (!texture.loadFromFile("ASSETS\\IMAGES\\player_left.png"))//loads texture
	{
		std::cout << "problem loading player_left.png";
	}
	sprite.setTexture(texture);
}
