#include <iostream>
#include "svg.h"
#include "spider.h"
#include "head.h"
#include "body.h"
#include "leg.h"
#include "abdomen.h"
#include "frame1.h"
using namespace std;
//G³óówna funkcja programu
int main()
{//Generowanie klatek w danym pliku z paj¹kiem,
 //którego nogi i g³owa odchylone s¹ o dany wspó³czynik
    drawFrame("0.svg", 0);
    drawFrame("1.svg", 1);
    drawFrame("2.svg", 2);
    drawFrame("3.svg", 3);
    drawFrame("4.svg", 4);
    drawFrame("5.svg", 5);
    drawFrame("6.svg", 6);
    drawFrame("7.svg", 5);
    drawFrame("8.svg", 4);
    drawFrame("9.svg", 3);
    drawFrame("10.svg", 2);
    drawFrame("11.svg", 1);
    drawFrame("12.svg", 0);
    drawFrame("13.svg", -1);
    drawFrame("14.svg", -2);
    drawFrame("15.svg", -3);
    drawFrame("16.svg", -4);
    drawFrame("17.svg", -5);
    drawFrame("18.svg", -6);
    drawFrame("19.svg", -5);
    drawFrame("20.svg", -4);
    drawFrame("21.svg", -3);
    drawFrame("22.svg", -2);
    drawFrame("23.svg", -1);
	return 0;
}
