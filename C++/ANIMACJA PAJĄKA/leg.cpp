#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "leg.h"

using namespace std;

Leg::Leg(int position_x1, int position_y1 ,int position_x2, int position_y2, int thickness_, int angle_){
    pos[0] = position_x1;
    pos[1] = position_y1;
    pos[2] = position_x2;
    pos[3] = position_y2;
    thickness = thickness_;
    angle=angle_;
}//Konstruktor parametrowy

int Leg::getPosition_x1(){
    return pos[0];
}//Getter pozycji horyzontalnej

int Leg::getPosition_y1(){
    return pos[1];
}//Getter pozycji wertykalnej

int Leg::getPosition_x2(){
    return pos[2];
}//Getter pozycji drugiej pozycji horyzontalnej(drugi pkt odcinka)

int Leg::getPosition_y2(){
    return pos[3];
}//Getter pozycji drugiej pozycji wertkalnej(drugi pkt odcinka)

int Leg::getSize(){
    float temp = sqrt((pos[0]-pos[2])*(pos[0]-pos[2])+(pos[1]-pos[3])*(pos[1]-pos[3]));
    lenght = (int)(temp);
    return lenght;
}//Getter rozmiaru, zwracja policzon¹ ze wzoru pitagorasa d³ugoœæ odcinka

int Leg::getThickness(){
    return thickness;
}//Getter gruboœci krawêdzi

int Leg::getRotation(){
	return angle;
}//Getter k¹tu nachylenia

void Leg::draw(string file){
    ofstream svg;
    svg.open(file.c_str(),std::ios::app);
    svg << "<line x1=\""<<pos[0]<<"\" y1=\""<<pos[1]<<"\" x2=\""<<pos[2]<<"\" y2=\""<<pos[3]
    <<"\" stroke=\"black\" stroke-width=\""<<thickness
    <<"\" transform=\"rotate("<<angle<<" "<<pos[0]<<','<<pos[1]<<")\"/>"<<endl;
}//Rysowanie odcinka od punktu pos[0],pos[1] do pos[2],pos[3]
