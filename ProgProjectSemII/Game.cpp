// Name: Kacie Franklin
// Login: C00299407@setu.ie
// Date: 16/03/2024
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file
#include <ctime>
#include <cstdlib>


int main()
{	
	srand(time(nullptr));//Only run once 
	Game aGame;
	aGame.loadContent();
	aGame.run();

return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	eyeTwo.setPosition(900, 50);
	setUpCrawlers();
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	if (!m_bgTexture.loadFromFile("ASSETS\\IMAGES\\floor.png"))//load texture
	{
		std::cout << "problem loading floor.png";
	}
	m_bgSprite.setTexture(m_bgTexture);
	m_bgSprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
	m_bgSprite.setScale(1.9, 1.34);
}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			processEvents();
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::processEvents()
{
	sf::Event newEvent;

	while (window.pollEvent(newEvent))
	{
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			processMouseDown(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			processMouseUp(newEvent);
		}
	}
}

void Game::processKeys(sf::Event t_event)
{
}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myPlayer.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myPlayer.moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myPlayer.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myPlayer.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		myPlayer.shoot();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		myPlayer.shoot();
	}
	for (int i = 0; i < MAX_CRAWLERS; i++)
	{
		crawlers[i].move(myPlayer);
	}

	if (myPlayer.firing == true)
	{
		myPlayer.shoot();
	}

	eye.coolDown();
	eyeTwo.coolDown();
	

	// update any game variables here ...

}

void Game::processMouseDown(sf::Event t_event)
{
}

void Game::processMouseUp(sf::Event t_event)
{
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	m_message.setString("Game Play");
	window.draw(m_bgSprite);
	window.draw(m_message); // write message to the screen	;
	window.draw(myPlayer.getBody());
	for (int i = 0; i < MAX_CRAWLERS; i++)
	{
		window.draw(crawlers[i].getBody());
	}
	if (myPlayer.firing == true)
	{
		window.draw(myPlayer.getBullet());
	}
	window.draw(eye.getBody());
	window.draw(eyeTwo.getBody());
	
	window.display();
}

/// <summary>
/// set up Crawlers in a random position
/// </summary>
void Game::setUpCrawlers()
{
	for (int i = 0; i < MAX_CRAWLERS; i++)
	{
		sf::Vector2f randLocation;
		randLocation.x = (rand() % 1509) + 1;
		randLocation.y = (rand() % 809) + 1;
		crawlers[i].setPosition(randLocation.x, randLocation.y);
	}
}
