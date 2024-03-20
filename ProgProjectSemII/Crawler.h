//declaration for Crawler-follower enemy
#include "SFML/Graphics.hpp"
#include "Player.h"
#pragma once

class Crawler
{
private:

	sf::Sprite sprite;//sprite for crawler's body
	sf::Texture texture;//texture for crawler's body
	int health;//crawler's health
	int speed;//crawler's defaullt speed
	sf::Vector2f location;

public:
	Player player;
	Crawler();
	sf::Sprite getBody();
	void move(Player player);
};
