#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.h"

class Circle;

class Rectangle : public Shape {
  protected :
	  float width,height;
  public :
	  Rectangle(float posX = 0,float posY = 0, float _w = 0, float _h = 0, int r = 0, int g = 0, int b = 0, float celX = 0, float celY = 0, bool _isFixed = true);
	  ~Rectangle(void){}

	  inline float getWidth(void) const {
		  return width;
	  }
	  inline float getHeight(void) const {
		  return height;
	  }
	  inline void setWidth(float val) {
		  width = val;
		  updateMass();
	  }
	  inline void setHeight(float val) {
		  height=val;
		  updateMass();
	  }

	  inline void updateMass(void) {
		  mass = width * height * MASS_PER_VOLUME_RECT;
	   }
	   
	  void step(float, float, float, std::vector<Rectangle*> &, std::vector<Circle*> &, std::vector<Triangle*> &, float, float);
	  void draw(sf::RenderWindow *win) const;
};
#endif
