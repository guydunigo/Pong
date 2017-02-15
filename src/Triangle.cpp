#include "Triangle.h"

Triangle::Triangle(float posX, float posY, float _alpha, float _radius, int r, int g, int b, float celX, float celY, bool _isFixed)
    : Circle(posX, posY, alpha, _radius, r, g, b, celX, celY, 0, _isFixed), isOff(false)
{
    (void)_alpha;
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

void Triangle::step(float dt, float gravityX, float gravityY, std::vector<Rectangle*> &rects, std::vector<Circle*> &circs, std::vector<Triangle*> &trigs, float width, float height)
{
	(void)dt;
	(void)gravityX;
	(void)gravityY;
	(void)rects;
	(void)circs;
	(void)trigs;
	(void)width;
	(void)height;
    if (!isFixed)
    {
        pos[0] = cel[0]*dt;
        pos[1] = cel[1]*dt;
        if (pos[0] < 2*radius || pos[0] > width || pos[1] < 2*radius || pos[1] > height)
        {
            isOff = true;
        }
    }
}