#include "day.h"

// Add an errand using vector push back
void Day::addErrand(Reminder* errand) {
    errandList.push_back(errand);
}

// Remove an errand using vector erase
void Day::removeErrand(int errandNum) {
    errandList.erase(errandList.begin() + errandNum - 1);
}

// return toString
string Day::toString() {
    string output = std::to_string(number) + " - " + dayOfWeek + ":";
    for (int i = 0; i < (int (errandList.size())); i++) {
        output = output + "\n\t" + to_string(i+1) + ". " + errandList[i]->toString();
    }
    return output;
}