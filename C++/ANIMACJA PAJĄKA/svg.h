#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void makeSVG(string file) //Funkcja tworzenia pliku SVG o nazwie file
{
	ofstream svg; //Utworzenie strumienia zapisu 
	svg.open(file.c_str()); //Otwarcie pliku
	svg << "<svg version=\"1.1\"" <<endl<<
    "baseProfile=\"full\" "<<endl<<
    "width=\"1920\" height=\"1080\""<<endl<< //Utworzenie płutna o wymiarach FullHD
    "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
}

void closeSVG(string file){ //Funkcja zamayka plik SVG
	ofstream svg;
	svg.open(file.c_str(),std::ios::app);
	svg << "</svg>\n";
	svg.close();
}
