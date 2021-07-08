#pragma once
using namespace std;

bool loadTasks(string filename, vector<string> & table);

    class Load
    {
    vector<string> NeverHaveIEver;
    vector<string> Truth;
    vector<string> Dare;
    vector<string> WhoIsMostLikelyTo;
    vector<string> Action;
    vector<string> ActionPersonal;
    public:
        bool LoadNeverHaveIEver(string fileName);
        bool LoadTruth(string fileName);
        bool LoadDare(string fileName);
        bool LoadWhoIsMostLikelyTo(string fileName);
        bool LoadAction(string fileName);
        bool LoadActionPersonal(string fileName);
        int getTruthLength();
        int getDareLength();
        int getNeverHaveIEverLength();
        int getWhoIsMostLikelyToLength();
        int getActionLength();
        int getActionPersonalLength();
        string getTruth(long long unsigned int number);
        string getDare(long long unsigned int number);
        string getNeverHaveIEver(long long unsigned int number);
        string getWhoIsMostLikelyTo(long long unsigned int number);
        string getAction(long long unsigned int number);
        string getActionPersonal(long long unsigned int number);
        bool TruthEmpty();
        bool DareEmpty();
        bool NeverHaveIEverEmpty();
        bool WhoIsMostLikelyToEmpty();
        bool ActionEmpty();
        bool ActionPersonalEmpty();
        bool AllEmpty();
        void TruthErase(int number);
        void DareErase(int number);
        void NeverHaveIEverErase(int number);
        void WhoIsMostLikelyToErase(int number);
        void ActionErase(int number);
        void ActionPersonalErase(int number);
    };

