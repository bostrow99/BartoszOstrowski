#include "Load.h"
#include "interface.h"
#include <vector>
#pragma once
using namespace std;

bool currentCategoryEmpty(int whichCategory_, Load Load_);
string randomTask(settings settings_, Load &Load_, vector<string> Names_);
void deleteCurrentTask(int whichCategory_, int whichTask_, Load &Load_);
vector<string> InputNames(settings settings_);

