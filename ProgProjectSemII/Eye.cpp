#include "Eye.h"

Eye::Eye()
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 400, 100));
	sprite.setColor(sf::Color::Green);
	setPosition();
}

sf::Sprite Eye::getBody()
{
	return sprite;
}

void Eye::setPosition(){
	sprite.setPosition(200, 50);
}

void Eye::setPosition(int posX, int posY)
{
	sprite.setPosition(posX, posY);
}

void Eye::coolDown()
{
	if (cooldown > 10)
	{
		sprite.setColor(sf::Color::Red);
		cooldown = 0;
	}
	sprite.setColor(sf::Color::Green);

}
