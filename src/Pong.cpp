#include "Pong.h"
#include <iostream>

Pong::Pong(int _width, int _height, float _gravityX, float _gravityY): width(_width), height(_height), gravityX(_gravityX), gravityY(_gravityY) {

	for (int i = 0 ; i < NB_BALLS ; i++)
		addCirc(new Circle(std::rand()%500,0,10+std::rand()%30,std::rand()%255,std::rand()%255,std::rand()%255,std::rand()%100,std::rand()%100, std::rand()%20 - 10));

	addRect(new Rectangle(20,500,100,100,255,0,0, rand()%100, rand()%100));
}

Pong::~Pong(void) {
	for (unsigned int i = 0 ; i < rects.size() ; i++)
		delete rects[i];
	for (unsigned int i = 0 ; i < circs.size() ; i++)
		delete circs[i];
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
	for (unsigned int i = 0 ; i < rects.size() ; i++)
		rects[i]->move(dx, dy);
	for (unsigned int i = 0 ; i < circs.size() ; i++)
		circs[i]->move(dx, dy);
}

void Pong::drawAll(sf::RenderWindow *win) const {
	for (unsigned int i = 0 ; i < rects.size() ; i++)
		rects[i]->draw(win);
	for (unsigned int i = 0 ; i < circs.size() ; i++)
		circs[i]->draw(win);
}

void Pong::addRect(Rectangle* rect) {
	rects.push_back(rect);
}

void Pong::addCirc(Circle* circ) {
	circs.push_back(circ);
}

void Pong::step(float dt) {
	for (unsigned int i = 0 ; i < circs.size() ; i++)
		circs[i]->step(dt, gravityX, gravityY, rects, circs, width, height);
}
