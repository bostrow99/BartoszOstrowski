#include <iostream>
#include "svg.h"
#include "spider.h"
#include "head.h"
#include "body.h"
#include "leg.h"
#include "abdomen.h"
#include <string>

using namespace std;

//Funkcja rysuje klatkê w pliku file
void drawFrame(string file, int k){
	Spider *spider[11];//Tablica wsaŸników typu Spider
    for(int i=0; i<11; i++){
        spider[i]=NULL;
    };//Przypisanie elementom tablicy wartoœci NULL
    //alokacja i przypisanie obiektów do tablicy wskaŸników
    spider[0] = new Leg(790,410,600,500,5,k);
    spider[1] = new Leg(790,405,580,435,5,-k);
    spider[2] = new Leg(790,395,580,365,5,k);
    spider[3] = new Leg(790,390,600,300,5,-k);
    spider[4] = new Leg(810,410,1000,500,5,k);
    spider[5] = new Leg(810,405,1020,435,5,-k);
    spider[6] = new Leg(810,395,1020,365,5,k);
    spider[7] = new Leg(810,390,1000,300,5,-k);
    spider[8] = new Body(800,400,120,2,0);
    spider[9] = new Head(800,430,15,2,10*k);
    spider[10] = new Abdomen(800,300,300,2,0);
	makeSVG(file);//Utworzenie pliku SVG
    for(int i=0; i<11; i++){
    if(spider[i]!=NULL)spider[i]->draw(file);
    };//Dla niepustych elementów tablicy nastêpuje rysowanie obiektów

	closeSVG(file); //Zamkniêcie pliku SVG
    delete [] spider; //Usuniêcie zaalokowanych obiektów
}
