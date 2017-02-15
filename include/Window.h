#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "SFML/Graphics.hpp"
#include "options.h"
#include "Pong.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

enum Game_state { Menu, Game, Over };

class Window {
  private :
    std::string _name;
    int _width, _height;
    sf::RenderWindow *_win;
    Pong* world;

  public :
    Window(std::string n="Window", int w=700, int h=500);
    ~Window(void);

    void display(void);
    
    void addRect(Rectangle* rect);
    void addCirc(Circle* circ);	

    void moveAll(float, float);
    void drawAll() const;

    void resetWorld(void);
};

#endif