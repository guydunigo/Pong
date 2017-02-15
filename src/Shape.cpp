#include "Shape.h"

Shape::Shape(float posX, float posY, int r, int g, int b, float celX, float celY, bool _isFixed): isFixed(_isFixed), color(r,g,b)
{
	pos[0] = posX;
	pos[1] = posY;
	cel[0] = celX;
	cel[1] = celY;
	mass = 42;
}

float Shape::getX(void) const
{
	return pos[0];
}
float Shape::getY(void) const
{
	return pos[1];
}
float Shape::getCelX(void) const
{
	return cel[0];
}
float Shape::getCelY(void) const
{
	return cel[1];
}
Color& Shape::getColor(void)
{
	return color;
}
float Shape::getMass(void) const
{
	return mass;
}
void Shape::setX(float val)
{
	pos[0]=val;
}
void Shape::setY(float val)
{
	pos[1]=val;
}
void Shape::setCelX(float val)
{
	cel[0]=val;
}
void Shape::setCelY(float val)
{
	cel[1]=val;
}
void Shape::setColor(const Color& col) {
	color = col;
}

void Shape::move(float dx, float dy){
	pos[0]+=dx;pos[1]+=dy;
}