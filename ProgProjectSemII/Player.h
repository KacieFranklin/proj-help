// Player class declaration
#pragma once

class Player
{
	// private data members
	sf::Sprite sprite;//sprite for player's body
	sf::Texture texture;//texture for player's texture
	sf::Sprite bullet;//sprite for bullet
	sf::Texture bulletTexture;//texture for bullet
	int speed;//player's speed
	int health;//player's health
	sf::Vector2f location;
	sf::Vector2f bulletVelocity{ 2.0f,2.0f };
	sf::Vector2f bulletLocation { sprite.getPosition().x, sprite.getPosition().y };
	int direction;
	bool firing = false;

	

public:
	Player();
	sf::Sprite getBody();
	sf::Sprite getBullet();
	void setPosition();
	void setPosition(int posX,int posY);
	sf::Vector2f getPosition();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void shoot();
	void checkDirection();


};