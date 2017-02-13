#include "Rectangle.h"

Rectangle::Rectangle(float posX,float posY, float _width, float _height, int r, int g, int b, float celX, float celY):
	Shape(posX,posY,r,g,b,celX,celY),width(_width),height(_height)
{
	updateMass();
}

float Rectangle::getWidth(void) const
{
	return width;
}
float Rectangle::getHeight(void) const
{
	return height;
}
void Rectangle::setWidth(float val)
{
	width=val;
	updateMass();
}
void Rectangle::setHeight(float val)
{
	height=val;
	updateMass();
}
void Rectangle::updateMass(void) {
	mass = width * height * MASS_PER_VOLUME_RECT;
}

void Rectangle::draw(sf::RenderWindow *win) const {
  int r,g,b;
  color.getRGB(r,g,b);
  sf::RectangleShape shape(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color(r, g, b));
  shape.setPosition(pos[0],pos[1]);
  win->draw(shape);
}

void Rectangle::step(float dt, float gravityX, float gravityY, std::vector<Rectangle*> &rects, std::vector<Circle*> &circs, float width, float height)
{
	(void)gravityX;(void)gravityY;
	(void)rects;(void)circs;
	(void)width;(void)height;
	pos[0] += cel[0]*dt;
	pos[1] += cel[1]*dt;
}
