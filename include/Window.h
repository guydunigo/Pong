#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "Pong.h"
#include "Rectangle.h"
#include "Circle.h"

#define DELAY_TIME 0.01

class Window {
  private :
    std::string _name;
    int _width, _height;
    sf::RenderWindow *_win;
    Pong world;

  public :
    Window(std::string n="Window", int w=700, int h=500);
    ~Window(void);

    void display(void);
    
    void addRect(Rectangle* rect);
    void addCirc(Circle* circ);	

    void moveAll(float, float);
    void drawAll() const;
};

#endif