#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Load.h"
#include "interface.h"



using namespace std;

int main()
{    

    Load pytania;
    vector<string> test;
    menu menu1=menu{};
    menu1.SwitchMenu();
    pytania.LoadAction("1.txt");

    cout <<pytania.LoadAction("2.txt")<< endl;

    return 0;
}
