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

		inline float getX(void) const
		{
			return pos[0];
		}
		inline float getY(void) const
		{
			return pos[1];
		}
		inline float getCelX(void) const
		{
			return cel[0];
		}
		inline float getCelY(void) const
		{
			return cel[1];
		}
		inline float getMass(void) const
		{
			return mass;
		}
		inline Color& getColor(void);
		{
			return color;
		}
		inline void setX(float)
		{
			pos[0]=val;
		}
		inline void setY(float)
		{
			pos[1]=val;
		}
		inline void setCelX(float)
		{
			cel[0]=val;
		}
		inline void setCelY(float)
		{
			cel[1]=val;
		}
		inline void setColor(const Color&)
		{
			color = col;
		}
		virtual void updateMass(void) = 0;

		inline void move(float, float)
		{
			pos[0]+=dx;pos[1]+=dy;
		}
		virtual void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, std::vector<Triangle*> &, float, float) = 0;

		virtual void draw(sf::RenderWindow *win) const = 0;
};
#endif
