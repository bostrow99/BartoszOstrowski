#include <fstream>
#include <string>
#include <fstream>
#include "head.h"
#include <iostream>
using namespace std;

Head::Head(int position_x1, int position_y1, int radius_, int thickness_, int angle_){
    pos[0] = position_x1;
    pos[1] = position_y1;
    radius = radius_;
    thickness = thickness_;
    angle = angle_;
}//Konstruktor parametrowy

int Head::getSize(){
    return radius;
}//Getter rozmiaru, zwraca promieñ
int Head::getPosition_x1(){
    return pos[0];
}//Getter pozycji horyzontalnej

int Head::getPosition_y1(){
    return pos[1];
}//Getter pozycji wertykalnej

int Head::getPosition_x2(){
    return pos[2];
}//Getter pozycji drugiej pozycji horyzontalnej(neipotrzebny)

int Head::getPosition_y2(){
    return 0;
}//Getter pozycji drugiej pozycji wertykalnej(neipotrzebny)

int Head::getRotation(){
    return angle;
}//Getter k¹tu nachylenia

int Head::getThickness(){
    return thickness;
}//Getter gruboœci krawêdzi

void Head::draw(string file){
    ofstream svg;
    svg.open(file.c_str(),std::ios::app);
    svg << "<circle cx=\""<<pos[0]<<"\" cy=\""<<pos[1]<<"\" r=\""<<radius
    <<"\" fill=\"#3f2810\" stroke=\"black\" stroke-width=\""<<thickness
    <<"\" transform=\"rotate("<<angle<<" "<<pos[0]<<" "<<pos[1]-(radius/2)<<")\" /> "<<endl;
}//Rysowanie w pliku ko³a o promienu radius. Obrót wokó³ pukntu: pos[0], pos[1]-(radius/2)
