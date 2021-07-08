#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Interface.h"
#include "game.h"
#include "Load.h"
#include <time.h>
#include <cstdio>
#include <cstring>

#pragma once


using namespace std;



void settings::displaySettings(){
    cout<<"------------SETTINGS-------------"<<endl<<endl;
    cout<<"----------Use-in-game:-----------"<<endl<<endl;
    cout<<"[1] Truth: ";
    if(settings::SwitchTruth==false){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    cout<<"[2] Dare: ";
    if(settings::SwitchDare==false){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    cout<<"[3] Never have I ever: ";
    if(settings::SwitchNeverHaveIEver==false){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    cout<<"[4] Who is most likely to: ";
    if(settings::SwitchWhoIsMostLikelyTo==false){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;

    cout<<"[5] Action: ";
    if(settings::SwitchAction==false){
        cout<<"NO"<<endl<<endl;
    }
    else cout<<"YES"<<endl<<endl;
    cout<<settings::PlayerCount<<" Players"<<endl<<endl;
    if(settings::PlayerCount!=8)cout<<"[6] Increase number of players"<<endl;
    if(settings::PlayerCount!=2)cout<<"[7] Decrease number of players"<<endl;
    cout<<"[0] Return to menu"<<endl<<endl;
    cout<<"---------------------------------"<<endl<<endl;

}

void settings::SetSettings(){
    int button=999;
    while(button!=0){

        system("cls");
        settings::displaySettings();

        cin>>button;
        if(button==1){
            if(settings::SwitchTruth==true)settings::SwitchTruth=false;
            else settings::SwitchTruth=true;
        }
        if(button==2){
            if(settings::SwitchDare==true)settings::SwitchDare=false;
            else settings::SwitchDare=true;
        }
        if(button==3){
            if(settings::SwitchNeverHaveIEver==true)settings::SwitchNeverHaveIEver=false;
            else settings::SwitchNeverHaveIEver=true;
        }
        if(button==4){
            if(settings::SwitchWhoIsMostLikelyTo==true)settings::SwitchWhoIsMostLikelyTo=false;
            else settings::SwitchWhoIsMostLikelyTo=true;
        }
        if(button==5){
            if(settings::SwitchAction==true)settings::SwitchAction=false;
            else settings::SwitchAction=true;
        }
        if(button==6){
            if(PlayerCount!=8)settings::PlayerCount++;
        }
        if(button==7){
            if(PlayerCount!=2)settings::PlayerCount--;

        }

        system("cls");
        settings::displaySettings();

    }
    system("cls");
    button=999;
}

bool settings::getSwitchTruth(){
    return settings::SwitchTruth;
}
bool settings::getSwitchDare(){
    return settings::SwitchDare;
}
bool settings::getSwitchNeverHaveIEver(){
    return settings::SwitchNeverHaveIEver;
}
bool settings::getSwitchWhoIsMostLikelyTo(){
    return settings::SwitchWhoIsMostLikelyTo;
}
bool settings::getSwitchAction(){
    return settings::SwitchAction;
}
int settings::getPlayerCount(){
    return settings::PlayerCount;
};

void menu::DisplayMenu(){
    cout<<"-----------PARTY GAME------------"<<endl<<endl;
    cout<<"[1] Play"<<endl;
    cout<<"[2] Settings"<<endl;
    cout<<"[3] Load Tasks"<<endl;
    cout<<"[4] Instruction"<<endl<<endl;
    cout<<"[0] Quit"<<endl;
}

void menu::SwitchMenu(){

    int button=999;
    while (button!=0){

        menu::DisplayMenu();
        cin>>button;
        system("cls");
        switch (button)
        {
            case 1:
                menu::goPlay();
                break;
            case 2:
                menu::settings1.SetSettings();
                break;
            case 3:
                menu::goLoad();
                break;

        }
    }
}

void menu::goPlay(){
            system("cls");
 int button=999;
 vector<string> PlayerNames;
        if(workTest()==true&&Load1.AllEmpty()==false){
        PlayerNames=InputNames(settings1);
        }
        else cout<<"---------No Task Loaded!---------\n"<<endl;
        while(workTest()==true&&Load1.AllEmpty()==false)
    {
        system("cls");
        cout<<"Player List: "<<endl;
        for(auto &a : PlayerNames)cout<<a<<", ";
        cout<<endl<<endl;;
        cout<<randomTask(settings1,Load1,PlayerNames)<<endl;
        cout<<"\n\n\n\n[0] Exit Game";
        cin.clear();
        cin.sync();
        button=getchar();
        if(button==0)break;
        system("cls");
    }
}

void menu::goLoad(){

    cout<<"Loading files...\n\n";
    menu::Load1.LoadTruth("truth.txt");
    menu::Load1.LoadDare("dare.txt");
    menu::Load1.LoadNeverHaveIEver("neverhaveiever.txt");
    menu::Load1.LoadWhoIsMostLikelyTo("whoismostlikelyto.txt");
    menu::Load1.LoadAction("action.txt");
    menu::Load1.LoadActionPersonal("actionpersonal.txt");
    cout<<"\n\n";
};

bool menu::workTest(){
    if(menu::settings1.getSwitchTruth()==true && menu::Load1.TruthEmpty()==false)return true;
    if(menu::settings1.getSwitchDare()==true && menu::Load1.DareEmpty()==false)return true;
    if(menu::settings1.getSwitchNeverHaveIEver()==true && menu::Load1.NeverHaveIEverEmpty()==false)return true;
    if(menu::settings1.getSwitchWhoIsMostLikelyTo()==true && menu::Load1.WhoIsMostLikelyToEmpty()==false)return true;
    if(menu::settings1.getSwitchAction()==true && menu::Load1.ActionEmpty()==false)return true;
    if(menu::settings1.getSwitchAction()==true && menu::Load1.ActionPersonalEmpty()==false)return true;
    else return false;
};

