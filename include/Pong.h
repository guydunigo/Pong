#ifndef PONG_H
#define PONG_H

#include <vector>
#include "options.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class Pong {
	private:
		int width, height;
		float gravityX, gravityY;
		std::vector<Shape*> shapes;
		std::vector<Rectangle*> rects;
		std::vector<Circle*> circs;
		std::vector<Triangle*> trigs;
		sf::RectangleShape* stars[NB_STARS];

	public:
		Pong(int _width = 0, int _height = 0, float _gravityX = 0, float _gravityY = ACCg);
		~Pong(void);

		unsigned int getWidth(void) const;
		void setWidth(unsigned int);
		unsigned int getHeight(void) const;
		void setHeight(unsigned int);

		float getGravityX(void) const;
		float getGravityY(void) const;
		void setGravityX(float);
		void setGravityY(float);

		void addRect(Rectangle*);
		void addCirc(Circle*);
		void addTrig(Triangle*);
		
		void moveAll(float, float);
		void drawAll(sf::RenderWindow *win) const;

		void step(float dt);

		int getPoints(void);
		void resetPoints(void);
};

#endif
