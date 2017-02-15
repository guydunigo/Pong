#include <iostream>
#include "Window.h"
#include "Rectangle.h"

using namespace std;

Window::Window(std::string n, int w, int h) : _name(n), _width(w), _height(h), 
                                         _win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name, sf::Style::Titlebar | sf::Style::Close)), world(w,h)
{}

Window::~Window(void) {
  // detruire les objects graphiques

  delete _win;
}

void Window::display(void)
{
  sf::Clock clock;
  sf::Event event;
  sf::Font font;
  sf::Text play;  sf::Text quit; sf::Text gameOver;
  Game_state state(Menu);
  int selected(0);

// Draw the Play !/Quit button :
// Font : Vonique 64 by Sharkshock

if (!font.loadFromFile("Vonique 64.ttf"))
{
	_win->close();
	return;
}
play.setFont(font);
play.setCharacterSize(50);
play.setFillColor(sf::Color(0,255,0));
play.setPosition((_win->getSize().x - play.getGlobalBounds().width)/2, (_win->getSize().y/2 - play.getGlobalBounds().height));
play.setString("Play !");

quit.setFont(font);
quit.setCharacterSize(50);
quit.setFillColor(sf::Color(255,255,255));
quit.setPosition((_win->getSize().x - play.getGlobalBounds().width)/2, (_win->getSize().y/2 + play.getGlobalBounds().height));
quit.setString("Quit");

gameOver.setFont(font);
gameOver.setCharacterSize(60);
gameOver.setFillColor(sf::Color(255,255,255));
gameOver.setString("Game Over !");
gameOver.setPosition((_win->getSize().x - play.getGlobalBounds().width)/2, (_win->getSize().y/2 + play.getGlobalBounds().height /2));



  while (_win->isOpen())
  {
    _win->clear(sf::Color(10, 10, 10));
    
    // Dessiner ici les formes géométriques
    drawAll();
    world.step(clock.restart().asSeconds());

	if (state == Menu)
	{
		_win->draw(play);
		_win->draw(quit);
	}
	else if (state == Over)
	{
		_win->draw(gameOver);
	}

    _win->display();

    sf::sleep(sf::seconds(DELAY_TIME));

    if(_win->pollEvent(event))
    {
	  switch(event.type)
	  {
		case sf::Event::Closed :
			_win->close();
			break;
		case sf::Event::Resized :
			world.setWidth(_win->getSize().x);
			world.setHeight(_win->getSize().y);
			break;
		default:
			break;
	  }

	  if (state == Menu)
	  {
		if (selected == 0)
		{
			play.setFillColor(sf::Color(0,255,0));
			quit.setFillColor(sf::Color(255,255,255));
		}
		else if (selected == 1)
		{
			quit.setFillColor(sf::Color(0,255,0));
			play.setFillColor(sf::Color(255,255,255));
		}
		else if (selected < 0) selected = 0;
		else if (selected > 1) selected = 1;

		if (event.type == sf::Event::KeyPressed)
		{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					selected--;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					selected++;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					if (selected == 0)
					{
						state = Game;
					}
					else
					{
						_win->close();
						break;
					}
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					_win->close();
					break;
				}
		 }
	  }
	  else if (state == Game)
	  {
		if (event.type == sf::Event::KeyPressed)
		{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					// déplacer ici les formes à gauche
					world.setGravityX(-ACCg);
					world.setGravityY(0);
					//world.moveAll(-10,0);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					// déplacer ici les formes à droite
					world.setGravityX(ACCg);
					world.setGravityY(0);
					//world.moveAll(10,0);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					// déplacer ici les formes en haut
					world.setGravityX(0);
					world.setGravityY(-ACCg);
					//world.moveAll(0,-10);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					// déplacer ici les formes en bas
					world.setGravityX(0);
					world.setGravityY(ACCg);
					//world.moveAll(0,10);
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					state = Menu;
				}
		}
		}
		else if (state == Over)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				state = Menu;
			}
		}
	  }
    }
}

void Window::moveAll(float dx, float dy) {
	world.moveAll(dx, dy);
}

void Window::drawAll() const {
	world.drawAll(_win);
}

void Window::addRect(Rectangle* rect) {
	world.addRect(rect);
}

void Window::addCirc(Circle* circ) {
	world.addCirc(circ);
}
