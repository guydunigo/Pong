#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Circle.h"

class Rectangle;

class Triangle : public Circle {
    protected:
        bool isOff;
    public:
        Triangle(float posX = 0,float posY = 0, float _alpha = 0, float _radius = 0, int r = 0, int g = 0, int b = 0, float celX = 0, float celY = 0, bool _isFixed = true);
        ~Triangle(void){}

        void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, std::vector<Triangle*> &, float,    float);
        void draw(sf::RenderWindow *win) const;

        inline bool getIsOff(void) const {
            return isOff;
        }
        inline void setIsOff(bool val) {
            isOff = val;
        }

        virtual void effects(Circle* circ) =0;
};
#endif