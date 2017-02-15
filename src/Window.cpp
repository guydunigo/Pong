#include <iostream>
#include "Window.h"
#include "Rectangle.h"

using namespace std;

Window::Window(std::string n, int w, int h) : _name(n), _width(w), _height(h), 
                                         _win(new sf::RenderWindow(sf::VideoMode(_width, _height), _name)), world(w,h)
{}

Window::~Window(void) {
  // detruire les objects graphiques

  delete _win;
}

void Window::display(void)
{
  sf::Clock clock;
  sf::Event event;
  while (_win->isOpen())
  {
    _win->clear(sf::Color(10, 10, 10));
    
    // Dessiner ici les formes géométriques
    drawAll();
    world.step(clock.restart().asSeconds());

    _win->display();

    sf::sleep(sf::seconds(DELAY_TIME));

    if(_win->pollEvent(event))
    {
      switch (event.type) 
      {
        case sf::Event::Closed :
             _win->close();
             break;
	case sf::Event::Resized :
	     world.setWidth(_win->getSize().x);
	     world.setHeight(_win->getSize().y);
	     break;
        case sf::Event::KeyPressed:
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		cout<< "A" <<endl;
	     }
	     if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
		cout<< "B" <<endl;
	     }

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
             break;
        default:
             break;
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
