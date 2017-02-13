#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Color.h"

#define PI 3.14159
#define MASS_PER_VOLUME_CIRC 1
#define MASS_PER_VOLUME_RECT 1
#define MASS_PER_VOLUME_TRI 1

#define FRICT_COEF	0.9
#define BOUNCE_COEF	0.9

#define CELERITY_LIM	5

class Rectangle;
class Circle;

class Shape {
	protected:
		float pos[2], cel[2], mass;
		Color color;
	public:
		Shape(float posX, float posY, int r, int g, int b, float celX, float celY);
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
		virtual void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, float, float) = 0;

		virtual void draw(sf::RenderWindow *win) const = 0;
};
#endif
