// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "Crawler.h"
#include "Eye.h"


class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;

public:
	Player myPlayer; //object of Player
	Crawler crawlers[MAX_CRAWLERS]; //object of Crawler
	Eye eye;//object of Eye
	Eye eyeTwo; //object of Eye
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Sprite m_bgSprite; //sprite for the background
	sf::Texture m_bgTexture; //texture for background
	int coolDown = 0;
	bool clicked = false;
	sf::Vector2f m_mouseEnd;

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	processEvents();
	void	processKeys(sf::Event t_event);
	void	update();
	void	processMouseDown(sf::Event t_event);
	void	processMouseUp(sf::Event t_event);
	void	draw();
	void	setUpCrawlers();
	
};
