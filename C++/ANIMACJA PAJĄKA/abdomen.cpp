#include <fstream>
#include <string>
#include <fstream>
#include "abdomen.h"
#include <iostream>
using namespace std;
//Konstruktor parametrowy
Abdomen::Abdomen(int position_x1, int position_y1, int size_, int thickness_, int angle_){
    pos[0] = position_x1;
    pos[1] = position_y1;
    size = size_;
    thickness = thickness_;
    angle = angle_;
}

int Abdomen::getSize(){
    return size;
}//Getter rozmiaru

int Abdomen::getPosition_x1(){
    return pos[0];
}//Getter pozycji horyzontalnej

int Abdomen::getPosition_y1(){
    return pos[1];
}//Getter pozycji wertykalnej

int Abdomen::getPosition_x2(){
    return pos[2];
}//Getter pozycji drugiej pozycji horyzontalnej(neipotrzebny)

int Abdomen::getPosition_y2(){
    return 0;
}//Getter pozycji drugiej pozycji wertykalnej(neipotrzebny)

int Abdomen::getThickness(){
    return thickness;
}//Getter gruboœci krawêdzi

int Abdomen::getRotation(){
    return angle;
}//Getter k¹tu nachylenia

void Abdomen::draw(string file){
    ofstream svg;
    svg.open(file.c_str(),std::ios::app);
    svg<< "<ellipse cx=\""<<pos[0]<<"\" cy=\""<<pos[1]<<"\" rx=\""<<size/5<<"\" ry=\""<<size/4
    <<"\" fill=\"#3f2810\" stroke=\"black\" stroke-width=\""<<thickness
	<<"\" transform=\"rotate("<<angle<<" "<<pos[0]<<" "<<pos[1]<<")\" /> "<<endl;
}//Rysowanie w pliku svg elipsy o proporcji promieni 5:4.
