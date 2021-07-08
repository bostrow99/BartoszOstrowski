#include "Load.h"
#include <time.h>
#pragma once
using namespace std;
class settings{

    bool SwitchNeverHaveIEver;
    bool SwitchTruth;
    bool SwitchDare;
    bool SwitchWhoIsMostLikelyTo;
    bool SwitchAction;
    int PlayerCount;


    public:


    void displaySettings();
    void SetSettings();

        settings(){
            SwitchNeverHaveIEver=1;
            SwitchTruth=1;
            SwitchDare=1;
            SwitchWhoIsMostLikelyTo=1;
            SwitchAction=1;
            PlayerCount=2;
        }
    bool getSwitchNeverHaveIEver();
    bool getSwitchTruth();
    bool getSwitchDare();
    bool getSwitchWhoIsMostLikelyTo();
    bool getSwitchAction();
    int getPlayerCount();


};
class menu{
    public:
        void DisplayMenu();
        void SwitchMenu();
        void goPlay();
        void goInstruction();
        void goLoad();
        settings settings1;
        Load Load1;
        bool workTest();
        menu() = default;
};

