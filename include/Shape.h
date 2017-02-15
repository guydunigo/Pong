#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <vector>
#include "options.h"
#include "SFML/Graphics.hpp"
#include "Color.h"

class Rectangle;
class Circle;
class Triangle;

class Shape {
	protected:
		bool isFixed;
		float pos[2], cel[2], mass;
		Color color;
	public:
		Shape(float posX, float posY, int r, int g, int b, float celX, float celY, bool _isFixed = true);
		virtual ~Shape(void) {};

		inline void getTang(const float norm[2], float tang[2]) const
		{
			// Here in '2d' : [normx,normy,0] vect [0,0,-1];
			tang[0] = norm[1]; tang[1] = -norm[0];
		}

		float getX(void) const;
		float getY(void) const;
		float getCelX(void) const;
		float getCelY(void) const;
		float getMass(void) const;
		Color& getColor(void);
		void setX(float);
		void setY(float);
		void setCelX(float);
		void setCelY(float);
		void setColor(const Color&);
		virtual void updateMass(void) = 0;

		void move(float, float);
		virtual void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, std::vector<Triangle*> &, float, float) = 0;

		virtual void draw(sf::RenderWindow *win) const = 0;
};
#endif
