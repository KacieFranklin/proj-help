// Player class declaration
#pragma once

class Player
{
	// private data members
	sf::Sprite sprite;//sprite for player's body
	sf::Texture texture;//texture for player's texture
	int speed;//player's speed
	int health;//player's health
	sf::Vector2f location;
	

public:
	Player();
	sf::Sprite getBody();
	void setPosition();
	void setPosition(int posX,int posY);
	sf::Vector2f getPosition();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


};