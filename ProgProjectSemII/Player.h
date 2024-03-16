// Player class declaration
#pragma once

class Player
{
	sf::Sprite sprite;//sprite for player's body
	sf::Texture texture;//texture for player's texture
	int speed;//player's speed
	int health;//player's health
	sf::Vector2f location;
	
	// private data members


public:
	Player();
	sf::Sprite getBody();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};