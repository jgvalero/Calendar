#include <iostream>
#include "appointment.h"

using std::string;

// Getters
string Appointment::getStartTime() {
    return startTime;
}

string Appointment::getEndTime() {
    return endTime;
}

// Setters
void Appointment::setStartTime(string newStartTime) {
    startTime = newStartTime;
}

void Appointment::setEndTime(string newEndTime) {
    endTime = newEndTime;
}

// Overwrite parent toString
string Appointment::toString() {
    return "Appointment: - " + startTime + " - " + endTime + " - " + getReminderNote();
}