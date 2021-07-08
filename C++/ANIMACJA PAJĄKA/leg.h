#pragma once
#include <iostream>
#include <string>
#include "spider.h"
using namespace std;

class Leg: public Spider{

public:
    Leg(int, int, int, int, int, int);
    virtual int getPosition_x1();
    virtual int getPosition_y1();
    virtual int getPosition_x2();
    virtual int getPosition_y2();
    virtual int getSize();
    virtual int getThickness();
    virtual int getRotation();
    virtual void draw(string);



private:
    int pos[4];
    int lenght;
    int thickness;
    int angle;

};
