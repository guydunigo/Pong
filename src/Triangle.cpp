#include "Triangle.h"

Triangle::Triangle(float posX, float posY, float _alpha, float _radius, int r,
                   int g, int b, float celX, float celY, float _rotZ,
                   bool _isFixed)
    : Circle(posX, posY, _alpha, _radius, r, g, b, celX, celY, _rotZ, _isFixed),
      isOff(false) {}

void Triangle::draw(sf::RenderWindow *win) const {
    if (!isOff) {
        int r, g, b;
        color.getRGB(r, g, b);

        sf::CircleShape shape(radius, 3);
        shape.setFillColor(sf::Color(r, g, b));
        shape.setPosition(pos[0], pos[1]);
        shape.rotate(alpha);
        win->draw(shape);
    }
}

void Triangle::step(float dt, float gravityX, float gravityY,
                    std::vector<Rectangle *> &rects,
                    std::vector<Circle *> &circs,
                    std::vector<Triangle *> &trigs, float width, float height) {
    (void)dt;
    (void)gravityX;
    (void)gravityY;
    (void)rects;
    (void)circs;
    (void)trigs;
    (void)width;
    (void)height;
    if (!isFixed) {
        pos[0] += cel[0] * dt;
        pos[1] += cel[1] * dt;
        alpha += rotZ * dt * 180 / PI;
        if (alpha > 360)
            alpha -= 360;
        else if (alpha < 360)
            alpha += 360;
        if (pos[0] < 2 * radius || pos[0] > width || pos[1] < 2 * radius ||
            pos[1] > height) {
            isOff = true;
        }
    }
}
