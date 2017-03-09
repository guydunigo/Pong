#include "Rectangle.h"

Rectangle::Rectangle(float posX,float posY, float _width, float _height, int r, int g, int b, float celX, float celY, bool _isFixed):
	Shape(posX,posY,r,g,b,celX,celY, _isFixed),width(_width),height(_height), isCollided(false)
{
	updateMass();
}

void Rectangle::draw(sf::RenderWindow *win) const {
  int r,g,b;
  color.getRGB(r,g,b);
  sf::RectangleShape shape(sf::Vector2f(width, height));
  if (isCollided) shape.setFillColor(sf::Color(r / 2, g / 2, b / 2));
  else shape.setFillColor(sf::Color(r, g, b));
  shape.setPosition(pos[0],pos[1]);
  win->draw(shape);
}

void Rectangle::step(float dt, float gravityX, float gravityY, std::vector<Rectangle*> &rects, std::vector<Circle*> &circs, std::vector<Triangle*> &trigs, float width, float height)
{
	(void)rects;(void)circs;(void)trigs;
	(void)gravityX;(void)gravityY;
	if (!isFixed)
	{
	int i;
	float norm[2], tang[2], a;
	float new_pos[2] = {pos[0], pos[1]};
	float new_cel[2] = {cel[0], cel[1]};
	
	for (i = 0 ; i < 2 ; i++) {
		//new_cel[i] += gravity[i]*dt;
		new_pos[i] += new_cel[i]*dt;
	}
	if (new_pos[0] < 0 || new_pos[0] + this->width > width || new_pos[1] < 0 || new_pos[1] + this->height > height)
    {
		if (new_pos[0] < 0)
		{ // Left
			norm[0] = 1;
			norm[1] = 0; // tang = [0,-1]
			new_pos[0] = 0;
		}
		else if (new_pos[0] + this->width > width)
		{ // Right
			norm[0] = -1;
			norm[1] = 0; // tang = [0, 1]
			new_pos[0] = width - this->width;
		}
		else
		{
			norm[0] = 0;
			norm[1] = 0;
		}
		if (new_pos[1] < 0)
		{ // Top
			norm[0] += 0;
			norm[1] += 1; // tang = [1, 0]
			new_pos[1] = 0;
		}
		else if (new_pos[1] + this->height > height)
		{ // Bottom
			norm[0] += 0;
			norm[1] += -1; // tang = [-1,0]
			new_pos[1] = height - this->height;
		}

		getTang(norm, tang);

		a = (-1) * RECT_BOUNCE_COEF * (new_cel[0] * norm[0] + new_cel[1] * norm[1]);
		for (i = 0; i < 2; i++)
		{
			new_cel[i] = a * norm[i];
		}
    }

	// Actually updates values
	for (i = 0 ; i < 2 ; i++) {
		cel[i] = new_cel[i];
		pos[i] = new_pos[i];
	}
	}
}
