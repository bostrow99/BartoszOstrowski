#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Load.h"

using namespace std;


bool loadTasks(string fileName, vector<string> & table){

    ifstream in(fileName.c_str());
    if(!in)
    {
        cout<<"Cannot open file: "<<fileName<<endl;
        return false;
    }
    else
    {
        std::string str;
        while (getline(in, str))
        {
            // Line contains string of length > 0 then save it in vector
            if(str.size() > 0)
                table.push_back(str);
        }
        //Close The File
        in.close();
        cout<<"File: "<<fileName<<" has been loaded correctly"<<endl;
        return true;
    }
};



bool Load::LoadNeverHaveIEver(string fileName){
    return loadTasks(fileName, Load::NeverHaveIEver);
};
bool Load::LoadTruth(string fileName){
    return loadTasks(fileName, Load::Truth);
};
bool Load::LoadDare(string fileName){
    return loadTasks(fileName, Load::Dare);
};
bool Load::LoadWhoIsMostLikelyTo(string fileName){
    return loadTasks(fileName, Load::WhoIsMostLikelyTo);
};
bool Load::LoadAction(string fileName){
    return loadTasks(fileName, Load::Action);
}
bool Load::LoadActionPersonal(string fileName){
    return loadTasks(fileName, Load::ActionPersonal);
};


int Load::getTruthLength(){
    return Load::Truth.size();
};
int Load::getDareLength(){
    return Load::Dare.size();
};
int Load::getNeverHaveIEverLength(){
    return Load::NeverHaveIEver.size();
};
int Load::getWhoIsMostLikelyToLength(){
    return Load::WhoIsMostLikelyTo.size();
};
int Load::getActionLength(){
    return Load::Action.size();
};
int Load::getActionPersonalLength(){
    return Load::ActionPersonal.size();
};

string Load::getTruth(long long unsigned int number){
    if(number<=Load::Truth.size()){
        return Load::Truth[number];
    }
    else return "bad reading try again";
};
string Load::getDare(long long unsigned int number){
    if(number<=Load::Dare.size()){
        return Load::Dare[number];
    }
    else return "bad reading try again";
};
string Load::getNeverHaveIEver(long long unsigned int number){
    if(number<=Load::NeverHaveIEver.size()){
        return Load::NeverHaveIEver[number];
    }
    else return "bad reading try again";
};
string Load::getWhoIsMostLikelyTo(long long unsigned int number){
    if(number<=Load::WhoIsMostLikelyTo.size()){
        return Load::WhoIsMostLikelyTo[number];
    }
    else return "bad reading try again";
};
string Load::getAction(long long unsigned int number){
    if(number<=Load::Action.size()){
        return Load::Action[number];
    }
    else return "bad reading try again";
};
string Load::getActionPersonal(long long unsigned int number){
    if(number<=Load::ActionPersonal.size()){
        return Load::ActionPersonal[number];
    }
    else return "bad reading try again";
};

bool Load::TruthEmpty(){
    return Load::Truth.empty();
};
bool Load::DareEmpty(){
    return Load::Dare.empty();
};
bool Load::NeverHaveIEverEmpty(){
    return Load::NeverHaveIEver.empty();
};
bool Load::WhoIsMostLikelyToEmpty(){
    return Load::WhoIsMostLikelyTo.empty();
};
bool Load::ActionEmpty(){
    return Load::Action.empty();
};
bool Load::ActionPersonalEmpty(){
    return Load::ActionPersonal.empty();
};

bool Load::AllEmpty(){
    if(Load::TruthEmpty()==false||Load::DareEmpty()==false||Load::NeverHaveIEverEmpty()==false||Load::WhoIsMostLikelyToEmpty()==false||Load::ActionEmpty()==false||ActionPersonalEmpty()==false)
    {
        return false;
    }
    else return true;
}

void Load::TruthErase(int number){
    Load::Truth.erase(Load::Truth.begin()+(number));
};
void Load::DareErase(int number){
    Load::Dare.erase(Load::Dare.begin()+(number));
};
void Load::NeverHaveIEverErase(int number){
    Load::NeverHaveIEver.erase(Load::NeverHaveIEver.begin()+(number));
};
void Load::WhoIsMostLikelyToErase(int number){
    Load::WhoIsMostLikelyTo.erase(Load::WhoIsMostLikelyTo.begin()+(number));
};
void Load::ActionErase(int number){
    Load::Action.erase(Load::Action.begin()+(number));
};
void Load::ActionPersonalErase(int number){
    Load::ActionPersonal.erase(Load::ActionPersonal.begin()+(number));
};
