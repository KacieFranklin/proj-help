#pragma once
//declaration for Eye-stationary enemy
#include "SFML/Graphics.hpp"
#pragma once

class Eye
{
private:

	sf::Sprite sprite;//sprite for the eye
	sf::Texture texture;//texture for the eye
	int cooldown = 0;

public:
	Eye();
	sf::Sprite getBody();
	void setPosition();
	void setPosition(int posX,int posY);
	void coolDown();
};
