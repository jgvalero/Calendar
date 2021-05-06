#pragma once

#include <iostream>

using namespace std;
using std::string;

class Reminder {
    private:
    string reminderNote;

    public:
    string getReminderNote();
    void setReminderNote(string newReminderNote);
    virtual string toString();

};