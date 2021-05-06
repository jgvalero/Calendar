#include <iostream>
#include "reminder.h"

using std::string;

// Getter
string Reminder::getReminderNote() {
    return reminderNote;
}

// Setter
void Reminder::setReminderNote(string newReminderNote) {
    reminderNote = newReminderNote;
}

// Return toString
string Reminder::toString() {
    return "Reminder - " + getReminderNote();
}