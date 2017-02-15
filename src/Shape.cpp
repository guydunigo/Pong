#include "Shape.h"

Shape::Shape(float posX, float posY, int r, int g, int b, float celX, float celY, bool _isFixed): isFixed(_isFixed), color(r,g,b)
{
	pos[0] = posX;
	pos[1] = posY;
	cel[0] = celX;
	cel[1] = celY;
	mass = 42;
}