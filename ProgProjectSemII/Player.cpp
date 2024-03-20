
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"   // include Player header file

// Player function definitions here

Player::Player()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 100, 120));
	sprite.setColor(sf::Color::Blue);
	setPosition();


	speed = 3;
	health = 6;
}

sf::Sprite Player::getBody()
{
	return sprite;
}

void Player::setPosition()
{
	sprite.setPosition(50, 50);
}

void Player::setPosition(int posX, int posY)
{
	sprite.setPosition(posX, posY);
}

sf::Vector2f Player::getPosition()
{
	return location;
}

void Player::moveUp()
{
	location = sprite.getPosition();
	location.y--;
	sprite.setPosition(location.x, location.y - speed);
	if (location.y <= 0)
	{
		sprite.setPosition(location.x, 0);
	}
}

void Player::moveDown()
{
	location = sprite.getPosition();
	location.y++;
	sprite.setPosition(location.x, location.y + speed);
	if (location.y + IMAGE_HEIGHT >= SCREEN_HEIGHT)
	{
		sprite.setPosition(location.x, SCREEN_HEIGHT - IMAGE_HEIGHT);
	}
}

void Player::moveRight()
{
	location = sprite.getPosition();
	location.x++;
	sprite.setPosition(location.x + speed, location.y);
	if (location.x + IMAGE_WIDTH >= SCREEN_WIDTH)
	{
		sprite.setPosition(SCREEN_WIDTH - IMAGE_WIDTH, location.y);
	}
}

void Player::moveLeft()
{

	location = sprite.getPosition();
	location.x--;
	sprite.setPosition(location.x - speed, location.y);
	if (location.x <= 0)
	{
		sprite.setPosition(0,location.y);
	}
}
