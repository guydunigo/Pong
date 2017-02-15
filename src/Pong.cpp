#include "Pong.h"
#include <iostream>

Pong::Pong(int _width, int _height, float _gravityX, float _gravityY): width(_width), height(_height), gravityX(_gravityX), gravityY(_gravityY) {

	for (int i = 0 ; i < NB_BALLS ; i++)
		addCirc(new Circle(std::rand()%500,0,10+std::rand()%30,std::rand()%255,std::rand()%255,std::rand()%255,std::rand()%100,std::rand()%100, std::rand()%20 - 10));

	addRect(new Rectangle(10,100,10,100,255,0,0,0,10, false));
	addRect(new Rectangle(width - 20,100,10,100,255,0,0,0,10, false));

	// Walls (Left,Top,Right,Bottom)
	//addRect(new Rectangle(-100,0,110,height,255,0,0, rand()%100, rand()%100));
	//addRect(new Rectangle(0,-100,width,110,255,0,0, rand()%100, rand()%100));
	//addRect(new Rectangle(width-10,0,100,height,255,0,0, rand()%100, rand()%100));
	//addRect(new Rectangle(0,height-10,width,100,255,0,0, rand()%100, rand()%100));

	addTrig(new Triangle(30,500,100,255,255,255,0,0, true));
}

Pong::~Pong(void) {
	for (unsigned int i = 0 ; i < shapes.size() ; i++)
		delete shapes[i];
}

unsigned int Pong::getWidth(void) const {
	return width;
}
void Pong::setWidth(unsigned int val) {
	width = val;
}
unsigned int Pong::getHeight(void) const {
	return height;
}
void Pong::setHeight(unsigned int val) {
	height = val;
}
float Pong::getGravityX(void) const {
	return gravityX;
}
float Pong::getGravityY(void) const {
	return gravityY;
}
void Pong::setGravityX(float val) {
	gravityX = val;
}
void Pong::setGravityY(float val) {
	gravityY = val;
}

void Pong::moveAll(float dx, float dy) {
	for (unsigned int i = 0 ; i < shapes.size() ; i++)
		shapes[i]->move(dx, dy);
}

void Pong::drawAll(sf::RenderWindow *win) const {
	for (unsigned int i = 0 ; i < shapes.size() ; i++)
		shapes[i]->draw(win);
}

void Pong::addRect(Rectangle* rect) {
	rects.push_back(rect);
	shapes.push_back(rect);
}

void Pong::addCirc(Circle* circ) {
	circs.push_back(circ);
	shapes.push_back(circ);
}

void Pong::addTrig(Triangle* trig) {
	trigs.push_back(trig);
	shapes.push_back(trig);
}

void Pong::step(float dt) {
	for (unsigned int i = 0 ; i < shapes.size() ; i++)
		shapes[i]->step(dt, gravityX, gravityY, rects, circs, trigs, width, height);
}
