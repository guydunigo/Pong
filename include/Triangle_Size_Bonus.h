#ifndef TRI_SIZE_BON_H
#define TRI_SIZE_BON_H

#include "options.h"
#include "Triangle.h"

class Circle;

class Triangle_Size_Bonus: public Triangle
{
    public:
        Triangle_Size_Bonus(float posX = 0,float posY = 0, float _alpha = 0, float _radius = 0, float celX = 0, float celY = 0, float _rotZ = 0, bool _isFixed = true)
            : Triangle(posX,posY,_alpha,_radius,TRIG_SIZE_BON_COLOR, celX, celY, _rotZ, _isFixed)
        {
            isOff = false;
        }
        inline void effects(Circle* circ) {
            float newSize = circ->getRadius() * TRIG_SIZE_BON;
            if (newSize < 200 && newSize > 5) circ->setRadius(newSize);
            isOff = true;
        }
};

#endif