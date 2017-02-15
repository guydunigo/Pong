#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

class Circle : public Shape {
	protected :
		float radius,rotZ, alpha;
	public:
		Circle(float posX = 0,float posY = 0, float _radius = 0, int r = 0, int g = 0, int b = 0, float celX = 0, float celY = 0, float _rotZ = 0, bool _isFixed = false);
		~Circle(void) {}

		float getRotZ(void) const;
		float getRadius(void) const;
		void setRotZ(float);
		void setRadius(float);

		void updateMass(void);
		void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, std::vector<Triangle*> &, float, float);
		void draw(sf::RenderWindow *win) const;
};

#endif
