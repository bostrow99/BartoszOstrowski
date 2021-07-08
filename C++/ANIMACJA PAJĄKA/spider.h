#pragma once
#include <string>
#include <iostream>
using namespace std;
//Klasa abstrakcyjna z czystymi metodami
//Niezbêdne do polimorfizmu dynamicznego
class Spider{

public:
	virtual void draw(string)=0;
	virtual int getSize()=0;
    virtual int getPosition_x1()=0;
    virtual int getPosition_y1()=0;
    virtual int getPosition_x2()=0;
    virtual int getPosition_y2()=0;
	virtual int getRotation()=0;
	virtual int getThickness()=0;
};
