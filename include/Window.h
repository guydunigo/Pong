#ifndef WINDOW_H
#define WINDOW_H

#include "Circle.h"
#include "Pong.h"
#include "Rectangle.h"
#include "SFML/Graphics.hpp"
#include "Shape.h"
#include "Triangle.h"
#include "Triangle_Points_Bonus.h"
#include "options.h"
#include <string>

enum Game_state { Menu, Game, Over };

class Window {
  private:
    std::string _name;
    int _width, _height;
    sf::RenderWindow *_win;
    Pong *world;

  public:
    Window(std::string n = "Window", int w = 700, int h = 500);
    ~Window(void);

    void display(void);

    void addRect(Rectangle *rect);
    void addCirc(Circle *circ);

    void moveAll(float, float);
    void drawAll() const;

    void resetWorld(void);
};

#endif
