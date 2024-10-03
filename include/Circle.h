#ifndef CIRCLE_H
#define CIRCLE_H

#include "options.h"

#include "Rectangle.h"
#include "Shape.h"

class Triangle;

class Circle : public Shape {
  protected:
    float radius, rotZ, alpha;
    int points;

  public:
    Circle(float posX = 0, float posY = 0, float _alpha = 0, float _radius = 0,
           int r = 0, int g = 0, int b = 0, float celX = 0, float celY = 0,
           float _rotZ = 0, bool _isFixed = false);
    ~Circle(void) {}

    inline float getRotZ(void) const { return rotZ; }
    inline float getRadius(void) const { return radius; }
    inline int getPoints(void) const { return points; }
    inline void setRotZ(float val) { rotZ = val; }
    inline void setRadius(float val) {
        radius = val;
        updateMass();
    }
    inline void setPoints(int val) { points = val; }
    inline void resetPoints(void) { points = 0; }
    inline void updateMass(void) {
        mass = PI * radius * radius * MASS_PER_VOLUME_CIRC;
    }

    virtual void step(float, float, float, std::vector<Rectangle *> &,
                      std::vector<Circle *> &, std::vector<Triangle *> &, float,
                      float);
    virtual void draw(sf::RenderWindow *win) const;
};

#endif
