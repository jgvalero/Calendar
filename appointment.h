#pragma once

#include <iostream>
#include "reminder.h"

using std::string;

class Appointment: public Reminder {
    private:
    string startTime;
    string endTime;

    public:
    string getStartTime();
    string getEndTime();
    void setStartTime(string newStartTime);
    void setEndTime(string newEndTime);
    string toString();
};