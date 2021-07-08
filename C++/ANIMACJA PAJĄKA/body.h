#pragma once
#include <string>
#include "spider.h"
#include <iostream>
using namespace std;

class Body: public Spider{

public:
	Body(int, int, int, int, int);
	virtual int getSize();
	virtual int getPosition_x1();
	virtual int getPosition_y1();
	virtual int getPosition_x2();
    virtual int getPosition_y2();
    virtual int getThickness();
	virtual int getRotation();
	virtual void draw(string);

private:
	int size;
	int pos[2];
	int thickness;
	int angle;
};
