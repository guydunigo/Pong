#ifndef TRI_CEL_BON_H
#define TRI_CEL_BON_H

#include "options.h"
#include "Triangle.h"

class Circle;

class Triangle_Cel_Bonus: public Triangle
{
    public:
        Triangle_Cel_Bonus(float posX = 0,float posY = 0, float _alpha = 0, float _radius = 0, float celX = 0, float celY = 0, float _rotZ = 0, bool _isFixed = true)
            : Triangle(posX,posY,_alpha,_radius,TRIG_CEL_BON_COLOR, celX, celY, _rotZ, _isFixed)
        {
            isOff = false;
        }
        inline void effects(Circle* circ) {
            circ->setCelX(circ->getPoints() * TRIG_CEL_BON);
            circ->setCelY(circ->getPoints() * TRIG_CEL_BON);
            isOff = true;
        }
};

#endif