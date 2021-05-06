#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "day.h"

using std::string;

class Calendar {
    public:
    string title;
    Day* numDays;
    int startDay;

    //public:
    Calendar();
    Calendar(string name, int num, int start);
    void dispCalendar(int num);
    void dispDay(int date);
    void outputCalendar(string fileName, int num);
    Day* fetchDayArray();
};