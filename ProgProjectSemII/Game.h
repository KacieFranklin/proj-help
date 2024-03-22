// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "Crawler.h"


class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;

public:
	Player myPlayer; //object of Player
	Crawler crawlers[MAX_CRAWLERS]; //object of Crawler
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Sprite m_bgSprite; //sprite for the background
	sf::Texture m_bgTexture; //texture for background

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
	void	setUpCrawlers();
};
