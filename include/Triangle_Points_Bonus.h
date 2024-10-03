#ifndef TRI_PTS_BON_H
#define TRI_PTS_BON_H

#include "Triangle.h"
#include "options.h"

class Circle;

class Triangle_Points_Bonus : public Triangle {
  public:
    Triangle_Points_Bonus(float posX = 0, float posY = 0, float _alpha = 0,
                          float _radius = 0, float celX = 0, float celY = 0,
                          float _rotZ = 0, bool _isFixed = true)
        : Triangle(posX, posY, _alpha, _radius, TRIG_POINTS_BON_COLOR, celX,
                   celY, _rotZ, _isFixed) {
        isOff = false;
    }
    inline void effects(Circle *circ) {
        circ->setPoints(circ->getPoints() + TRIG_POINTS_BON);
        isOff = true;
    }
};

#endif
