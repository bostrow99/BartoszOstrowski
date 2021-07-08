#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "game.h"
#include "Load.h"
#include "interface.h"
#include <time.h>
#include <sstream>

using namespace std;
int PlayerQueue=0;
bool currentCategoryEmpty(int whichCategory_, Load Load_){
    switch (whichCategory_){
    case 0:
        if(Load_.TruthEmpty()==false)return false;
        else return true;
    break;
    case 1:
        if(Load_.DareEmpty()==false)return false;
        else return true;
    break;
    case 2:
        if(Load_.NeverHaveIEverEmpty()==false)return false;
        else return true;
    break;
    case 3:
        if(Load_.WhoIsMostLikelyToEmpty()==false)return false;
        else return true;
    break;
    case 4:
        if(Load_.ActionEmpty()==false)return false;
        else return true;
    break;
    case 5:
        if(Load_.ActionPersonalEmpty()==false)return false;
        else return true;
    break;
    }
}
void deleteCurrentTask(int whichCategory_, int whichTask_, Load &Load_){
    switch (whichCategory_){
    case 0:
        Load_.TruthErase(whichTask_);
    break;
    case 1:
        Load_.DareErase(whichTask_);
    break;
    case 2:
        Load_.NeverHaveIEverErase(whichTask_);
    break;
    case 3:
        Load_.WhoIsMostLikelyToErase(whichTask_);
    break;
    case 4:
        Load_.ActionErase(whichTask_);
    break;
    case 5:
        Load_.ActionPersonalErase(whichTask_);
    break;
    }
}
string getCurrentTask(int whichCategory_, int whichTask_, Load Load_){
    switch (whichCategory_){
    case 0:
        return Load_.getTruth(whichTask_);
    break;
    case 1:
        return Load_.getDare(whichTask_);
    break;
    case 2:
        return Load_.getNeverHaveIEver(whichTask_);
    break;
    case 3:
        return Load_.getWhoIsMostLikelyTo(whichTask_);
    break;
    case 4:
        return Load_.getAction(whichTask_);
    break;
    case 5:
        return Load_.getActionPersonal(whichTask_);
    break;
    }
}
long long unsigned int getLengthCategory(int whichCategory_, Load Load_){

    switch (whichCategory_){
    case 0:
        return Load_.getTruthLength();
    break;
    case 1:
        return Load_.getDareLength();
    break;
    case 2:
        return Load_.getNeverHaveIEverLength();
    break;
    case 3:
         return Load_.getWhoIsMostLikelyToLength();
    break;
    case 4:
        return Load_.getActionLength();
    break;
    case 5:
        return Load_.getActionPersonalLength();
    break;
    }
}
vector<string> InputNames(settings settings_){

vector<string> PlayerNames;

    string bufor="";
    for(int i=0; i<settings_.getPlayerCount(); i++)
    {
        cin.clear();
        cin.sync();
        cout<<"Enter "<<i+1<<" player name: ";

        getline(cin, bufor);

        while(bufor.size()<=0){


            cout<<"Wrong name!\n"<<endl;
            cout<<"Enter "<<i+1<<" player name: ";
            getline(cin, bufor);
        }
        PlayerNames.push_back(bufor);
    }
    return PlayerNames;
}

string randomTask(settings settings_, Load &Load_, vector<string> Names_){

    srand (time(NULL));
    string bufor[5];
    int whichCategory;

    if(Load_.AllEmpty()==false){
        whichCategory=rand()%6;
        while(currentCategoryEmpty(whichCategory, Load_)==true)whichCategory=rand()%6;
        if(whichCategory==0||whichCategory==1||whichCategory==5)
        {
            bufor[1]="Player: ";
            bufor[2]=Names_[PlayerQueue];
            if(PlayerQueue!=(settings_.getPlayerCount()-1))PlayerQueue++;
            else PlayerQueue=0;
        }
        else
        {
            bufor[1]="";
            bufor[2]="";
        }
        int whichTask=rand()%getLengthCategory(whichCategory, Load_);
        switch(whichCategory){
        case 0:
            bufor[3]="\nTruth: \n\n\n";
        break;
        case 1:
            bufor[3]="\nDare: \n\n\n";
        break;
        case 2:
            bufor[3]="\nNever Have I Ever: \n\n\n";
        break;
        case 3:
            bufor[3]="\n Who is most likely to: \n\n\n";
        break;
        case 4:
            bufor[3]="\nAction:\n\n\n";
        break;
        case 5:
            bufor[3]="\nAction:\n\n\n";
        break;
        }
        bufor[4]=getCurrentTask(whichCategory, whichTask, Load_);
        bufor[0]=bufor[1]+bufor[2]+bufor[3]+bufor[4];

        deleteCurrentTask(whichCategory,whichTask,Load_);

    }
    else bufor[0]="\nNo more Tasks!\n\n";
    return bufor[0];
}
