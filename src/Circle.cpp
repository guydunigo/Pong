#include "Circle.h"

Circle::Circle(float posX, float posY, float _radius, int r, int g, int b, float celX, float celY, float _rotZ)
    : Shape(posX, posY, r, g, b, celX, celY), radius(_radius), rotZ(_rotZ), alpha(0)
{
    updateMass();
}

float Circle::getRotZ(void) const
{
    return rotZ;
}
float Circle::getRadius(void) const
{
    return radius;
}
void Circle::setRadius(float val)
{
    radius = val;
    updateMass();
}
void Circle::setRotZ(float val)
{
    rotZ = val;
}
void Circle::updateMass(void)
{
    mass = PI * radius * radius * MASS_PER_VOLUME_CIRC;
}

void Circle::draw(sf::RenderWindow *win) const
{
    int r, g, b;
    color.getRGB(r, g, b);

    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color(r, g, b));
    shape.setPosition(pos[0], pos[1]);
    win->draw(shape);

    //sf::CircleShape p(radius/2);
    sf::RectangleShape p(sf::Vector2f(radius, radius));
    p.setFillColor(sf::Color(255 - r, 255 - g, 255 - b));
    p.setPosition(pos[0] + radius, pos[1] + radius);
    p.rotate(alpha);
    win->draw(p);
}

void Circle::step(float dt, float gravityX, float gravityY, std::vector<Rectangle *> &rects, std::vector<Circle *> &circs, float width, float height)
{
    float massO(0), radO(0), gravity[2], norm[2], tang[2], new_pos[2], new_cel[2], new_rotZ(rotZ), a(0), b(0), c(0), d(0);
    int i(0);
    Circle *other;
    Rectangle *rec;
    bool collision = false;

    gravity[0] = gravityX;
    gravity[1] = gravityY;

    for (i = 0; i < 2; i++)
    {
		new_cel[i] = cel[i] + gravity[i] * dt;
		new_pos[i] = pos[i] + new_cel[i] * dt;
		norm[i] = tang[i] = 0;
    }
    alpha += rotZ*dt*360/(3.14159*2);
    if (alpha > 360)
	alpha -= 360;
    if (alpha < -360)
	alpha += 360;

    // Bouncing against the walls
    if (new_pos[0] < 0 || new_pos[0] + radius * 2 > width || new_pos[1] < 0 || new_pos[1] + radius * 2 > height)
    {
	if (new_pos[0] < 0)
	{ // Left
	    norm[0] = 1;
	    norm[1] = 0; // tang = [0,-1]
	    new_pos[0] = 0;
	    //new_cel[1] = (2*radius*new_rotZ + 5*new_cel[1])/7;
	}
	else if (new_pos[0] + radius * 2 > width)
	{ // Right
	    norm[0] = -1;
	    norm[1] = 0; // tang = [0, 1]
	    new_pos[0] = width - radius * 2;
	    //new_cel[1] = (-2*radius*new_rotZ + 5*new_cel[1])/7;
	}
	else
	{
	    norm[0] = 0;
	    norm[1] = 0;
	}
	if (new_pos[1] < 0)
	{ // Top
	    norm[0] += 0;
	    norm[1] += 1; // tang = [1, 0]
	    new_pos[1] = 0;
	    //new_cel[0] = (-2*radius*new_rotZ + 5*new_cel[0])/7;
	}
	else if (new_pos[1] + radius * 2 > height)
	{ // Bottom
	    norm[0] += 0;
	    norm[1] += -1; // tang = [-1,0]
	    new_pos[1] = height - radius * 2;
	    //new_cel[0] = (2*radius*new_rotZ + 5*new_cel[0])/7;
	}

	getTang(norm, tang);

	new_rotZ = (2 * radius * new_rotZ - 5 * (new_cel[0] * tang[0] + new_cel[1] * tang[1])) / (7 * radius);
	a = new_cel[0] * norm[0] + new_cel[1] * norm[1];
	for (i = 0; i < 2; i++)
	{
	    new_cel[i] = (-1) * BOUNCE_COEF * a * norm[i] - rotZ * radius * tang[i];
	}
    }

    // Bouncing against Rectangles
    for (unsigned int i = 0; i < rects.size(); i++)
    {
	rec = rects[i];
	collision = false;
	// Detect if in the rect
	// Components of the vector from the ball to the other one :
	a = new_pos[0] + radius - rec->getX() - rec->getWidth() / 2;
	b = new_pos[1] + radius - rec->getY() - rec->getHeight() / 2;
	c = sqrtf(a * a + b * b); //Norm of this vector

	// Vertical collision :
	if (new_pos[0] + radius > rec->getX() && new_pos[0] + radius < rec->getX() + rec->getWidth())
	{
	    // Collision on a (moving) plane
	    if (new_pos[1] + 2 * radius > rec->getY() && new_pos[1] < rec->getY())
	    {
		collision = true;
		// Top collision
		norm[0] += 0;
		norm[1] += -1; // tang = [-1,0]
		new_pos[1] = rec->getY() - 2 * radius;
		//new_cel[0] = (2*radius*new_rotZ + 5*new_cel[0])/7;
	    }
	    else if (new_pos[1] + 2 * radius > rec->getY() + rec->getHeight() && new_pos[1] < rec->getY() + rec->getHeight())
	    {
		collision = true;
		// Bottom collision
		norm[0] += 0;
		norm[1] += 1; // tang = [1, 0]
		new_pos[1] = rec->getY() + rec->getHeight();
		//new_cel[0] = (-2*radius*new_rotZ + 5*new_cel[0])/7;
	    }
	}
	// Horizontal collision :
	else if (new_pos[1] + radius > rec->getY() && new_pos[1] + radius < rec->getY() + rec->getHeight())
	{
	    // Collision on a (moving) plane
	    if (new_pos[0] + 2 * radius > rec->getY() && new_pos[0] < rec->getY())
	    {
			collision = true;
			// Left collision
			norm[0] = -1;
			norm[1] = 0; // tang = [0, 1]
			new_pos[0] = rec->getX() - radius * 2;
			//new_cel[1] = (-2*radius*new_rotZ + 5*new_cel[1])/7;
	    }
	    else if (new_pos[0] + 2 * radius > rec->getY() + rec->getHeight() && new_pos[0] < rec->getY() + rec->getHeight())
	    {
			collision = true;
			// Right collision
			norm[0] = 1;
			norm[1] = 0; // tang = [0,-1]
			new_pos[0] = rec->getX() + rec->getWidth();
			//new_cel[1] = (2*radius*new_rotZ + 5*new_cel[1])/7;
	    }
	}
	else
	{
	    if ((a > 0 && b < 0))
	    {
			a = new_pos[0] + radius - rec->getX() - rec->getWidth();
			b = new_pos[1] + radius - rec->getY();
			c = sqrtf(a * a + b * b); //Norm of this vector
			// Collision on an corner (like a little sphere or a 45° plane ?)
			if (c < radius)
			{
				collision = true;
				std::cout << "Top right corner collision" << std::endl;
			}
	    }
	    else if ((a > 0 && b > 0))
	    {
			a = new_pos[0] + radius - rec->getX() - rec->getWidth();
			b = new_pos[1] + radius - rec->getY() - rec->getHeight();
			c = sqrtf(a * a + b * b); //Norm of this vector
			// Collision on an corner (like a little sphere or a 45° plane ?)
			if (c < radius)
			{
				collision = true;
				std::cout << "Bottom right corner collision" << std::endl;
			}
	    }
	    else if ((a < 0 && b < 0))
	    {
			a = new_pos[0] + radius - rec->getX();
			b = new_pos[1] + radius - rec->getY();
			c = sqrtf(a * a + b * b); //Norm of this vector
			// Collision on an corner (like a little sphere or a 45° plane ?)
			if (c < radius)
			{
				collision = true;
				std::cout << "Top left corner collision" << std::endl;
			}
	    }
	    else if ((a < 0 && b > 0))
	    {
			a = new_pos[0] + radius - rec->getX();
			b = new_pos[1] + radius - rec->getY() - rec->getHeight();
			c = sqrtf(a * a + b * b); //Norm of this vector
			// Collision on an corner (like a little sphere or a 45° plane ?)
			if (c < radius)
			{
				collision = true;
				std::cout << "Bottom left corner collision" << std::endl;
			}
	    }
		if (collision)
		{
			norm[0] += a / c;
			norm[1] += b / c;
			new_pos[0] += norm[0];
			new_pos[1] += norm[1];
			std::cout << norm[0] << "\t" << norm[1] << std::endl;
		}
	}

	if (collision)
	{
	    getTang(norm, tang);
	    new_rotZ = (2 * radius * new_rotZ - 5 * (new_cel[0] * tang[0] + new_cel[1] * tang[1])) / (7 * radius);
	    a = new_cel[0] * norm[0] + new_cel[1] * norm[1];
	    for (i = 0; i < 2; i++)
	    {
		new_pos[i] += norm[i];
		new_cel[i] = (-1) * BOUNCE_COEF * a * norm[i] - rotZ * radius * tang[i];
	    }
	}
    }

    // Bouncing against other balls
    for (unsigned int i = 0; i < circs.size(); i++)
    {
	if (circs[i] != this)
	{
	    other = circs[i];
	    massO = other->getMass();
	    radO = other->getRadius();
	    // Components of the vector from the ball to the other one :
	    a = new_pos[0] + radius - other->getX() - radO;
	    b = new_pos[1] + radius - other->getY() - radO;
	    c = sqrtf(a * a + b * b);		 //Norm of this vector
	    d = c - radius - other->getRadius(); // Depth of penetration of the two balls (negative value = penetration)
	    // If the 2 balls are colliding
	    if (d < 0)
	    {
		norm[0] = a / c;
		norm[1] = b / c;
		getTang(norm, tang);
		a = new_cel[0];
		b = new_cel[1];
		c = (mass - massO) / (mass + massO);
		d = 2 / (mass + massO);
		new_cel[0] = (c * new_cel[0] + massO * d * other->getCelX()) * BOUNCE_COEF;
		new_cel[1] = (c * new_cel[1] + massO * d * other->getCelY()) * BOUNCE_COEF;
		other->setCelX((-c * other->getCelX() + mass * d * a) * BOUNCE_COEF);
		other->setCelY((-c * other->getCelY() + mass * d * b) * BOUNCE_COEF);
		new_pos[0] += norm[0];
		new_pos[1] += norm[1];
		other->move(-norm[0], -norm[1]);
	    }
	}
    }

    // Nullify the celerity when too low
    for (i = 0; i < 2; i++)
    {
	if (new_cel[i] < CELERITY_LIM && new_cel[i] > -CELERITY_LIM)
	    new_cel[i] = 0;
    }

    // Actually update values
    cel[0] = new_cel[0];
    cel[1] = new_cel[1];
    pos[0] = new_pos[0];
    pos[1] = new_pos[1];
    rotZ = new_rotZ;
    //std::cout << pos[0] << "\t" << pos[1] << std::endl;
}
