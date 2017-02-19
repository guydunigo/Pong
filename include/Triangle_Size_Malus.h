#ifndef TRI_SIZE_MAL_H
#define TRI_SIZE_MAL_H

#include "options.h"
#include "Triangle.h"

class Circle;

class Triangle_Size_Malus: public Triangle
{
    public:
        Triangle_Size_Malus(float posX = 0,float posY = 0, float _alpha = 0, float _radius = 0, float celX = 0, float celY = 0, float _rotZ = 0, bool _isFixed = true)
            : Triangle(posX,posY,_alpha,_radius,TRIG_SIZE_MAL_COLOR, celX, celY, _rotZ, _isFixed)
        {
            isOff = false;
        }
        inline void effects(Circle* circ) {
            circ->setRadius(circ->getRadius() * TRIG_SIZE_MAL);
            isOff = true;
        }
};

#endif