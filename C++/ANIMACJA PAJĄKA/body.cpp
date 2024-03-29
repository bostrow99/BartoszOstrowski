#include <string>
#include <fstream>
#include "body.h"
#include <iostream>
using namespace std;
//Konstruktor parametrowy
Body::Body(int position_x1, int position_y1, int size_, int thickness_, int angle_){
    pos[0] = position_x1;
    pos[1] = position_y1;
    size = size_;
    thickness = thickness_;
    angle = angle_;
}

int Body::getSize(){
    return size;
}//Getter rozmiaru
int Body::getPosition_x1(){
    return pos[0];
}//Getter pozycji horyzontalnej

int Body::getPosition_y1(){
    return pos[1];
}//Getter pozycji wertykalnej

int Body::getPosition_x2(){
    return 0;
}//Getter pozycji drugiej pozycji horyzontalnej(neipotrzebny)

int Body::getPosition_y2(){
    return 0;
}//Getter pozycji drugiej pozycji wertykalnej(neipotrzebny)

int Body::getThickness(){
    return thickness;
}//Getter grubo�ci kraw�dzi

int Body::getRotation(){
    return angle;
}//Getter k�tu nachylenia

void Body::draw(string file){
    ofstream svg;
    svg.open(file.c_str(),std::ios::app);
    svg<< "<ellipse cx=\""<<pos[0]<<"\" cy=\""<<pos[1]<<"\" rx=\""<<size/5<<"\" ry=\""<<size/4
    <<"\" fill=\"#3f2810\" stroke=\"black\" stroke-width=\""<<thickness
	<<"\" transform=\"rotate("<<angle<<" "<<pos[0]<<" "<<pos[1]<<")\" /> "<<endl;
}//Rysowanie w pliku svg elipsy o proporcji promieni 5:4.
