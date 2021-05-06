#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "reminder.h"

using namespace std;
using std::string;

class Day {
    public:
    int number;
    string dayOfWeek;
    vector<Reminder*> errandList;

    void addErrand(Reminder* errand);
    void removeErrand(int errandNum);
    string toString();
};