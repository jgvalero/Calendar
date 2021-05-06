#include <iostream>
#include "calendar.h"

using namespace std;

// Default Constructor
Calendar::Calendar() {
    title = "Calendar";
    numDays = new Day[30];
    startDay = 1;
    for (int i = 0; i < 30; i++) {
        numDays[i].number = i + 1;
        if ((startDay + i) % 7 == 1) {
            numDays[i].dayOfWeek = "Monday";
        }
        else if ((startDay + i) % 7 == 2) {
            numDays[i].dayOfWeek = "Tuesday";
        }
        else if ((startDay + i) % 7 == 3) {
            numDays[i].dayOfWeek = "Wednesday";
        }
        else if ((startDay + i) % 7 == 4) {
            numDays[i].dayOfWeek = "Thursday";
        }
        else if ((startDay + i) % 7 == 5) {
            numDays[i].dayOfWeek = "Friday";
        }
        else if ((startDay + i) % 7 == 6) {
            numDays[i].dayOfWeek = "Saturday";
        }
        else if ((startDay + i) % 7 == 0) {
            numDays[i].dayOfWeek = "Sunday";
        }
    }
}

// Specific Constructor
Calendar::Calendar(string name, int num, int start) {
    title = name;
    numDays = new Day[num];
    // Loop to determine day number and day name
    for (int i = 0; i < num; i++) {
        numDays[i].number = i + 1;
        if ((start + i) % 7 == 1) {
            numDays[i].dayOfWeek = "Monday";
        }
        else if ((start + i) % 7 == 2) {
            numDays[i].dayOfWeek = "Tuesday";
        }
        else if ((start + i) % 7 == 3) {
            numDays[i].dayOfWeek = "Wednesday";
        }
        else if ((start + i) % 7 == 4) {
            numDays[i].dayOfWeek = "Thursday";
        }
        else if ((start + i) % 7 == 5) {
            numDays[i].dayOfWeek = "Friday";
        }
        else if ((start + i) % 7 == 6) {
            numDays[i].dayOfWeek = "Saturday";
        }
        else if ((start + i) % 7 == 0) {
            numDays[i].dayOfWeek = "Sunday";
        }
    }
    startDay = start;
}

// Display Entire Calendar
void Calendar::dispCalendar(int num) {
    cout << "Calendar \"" << title << "\"" << endl;
    // Loop through each day, outputting # of errands for each
    for (int i = 0; i < num; i++) {
        cout << numDays[i].number << " - " << numDays[i].dayOfWeek << ": " << numDays[i].errandList.size() << " Errands" << endl;
    }
}

// Display a day
void Calendar::dispDay(int date) {
    // Display specific day
    cout << numDays[date].toString() << endl;
}

// Output Calendar to a file
void Calendar::outputCalendar(string fileName, int num) {
    // Output calendar to file
    ofstream myfile (fileName + ".txt");
    myfile << title << endl;
    myfile << "----------" << endl;
    // Loop through each day, outting errands for each
    for (int i = 0; i < num; i++) {
        myfile << numDays[i].toString() << endl;
        myfile << endl;
    }
    myfile.close();
}

// Fetch and return Day
Day* Calendar::fetchDayArray() {
    return numDays;
}