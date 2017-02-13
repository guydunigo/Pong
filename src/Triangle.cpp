#include "Triangle.h"

Triangle::Triangle(float posX, float posY, float _radius, int r, int g, int b, float celX, float celY, float _rotZ)
    : Shape(posX, posY, r, g, b, celX, celY), radius(_radius), rotZ(_rotZ), alpha(0)
{
    updateMass();
}

float Triangle::getRotZ(void) const
{
    return rotZ;
}
float Triangle::getRadius(void) const
{
    return radius;
}
void Triangle::setRadius(float val)
{
    radius = val;
    updateMass();
}
void Triangle::setRotZ(float val)
{
    rotZ = val;
}
void Triangle::updateMass(void)
{
    mass = PI * radius * radius * MASS_PER_VOLUME_TRI;
}

void Triangle::draw(sf::RenderWindow *win) const
{
    int r, g, b;
    color.getRGB(r, g, b);

    sf::CircleShape shape(radius, 3); //ici qu'on met le nbre de cotés?
    shape.setFillColor(sf::Color(r, g, b));
    shape.setPosition(pos[0], pos[1]);
    win->draw(shape);
}

void Triangle::step(float dt, float gravityX, float gravityY, std::vector<Rectangle*> &rects, std::vector<Circle*> &circs, float width, float height)
{
	(void)dt;
	(void)gravityX;
	(void)gravityY;
	(void)rects;
	(void)circs;
	(void)width;
	(void)height;
}