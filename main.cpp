/*
Description: This program creates a calendar with reminders
Usage: make --> ./calendar
        (make clean to clear .o files)
*/

#include <iostream>
#include <vector>
#include "calendar.h"
#include "day.h"
#include "reminder.h"
#include "appointment.h"

using namespace std;
using std::string;

int main() {
    // Initialize Variables
    int menuInput1;
    int menuInput2;
    // Calendar Creation Variables
    string title;
    int daysTotal;
    int startDate;
    // Selection/Creation Variables
    int selectDay;
    int selectErrand;
    string reminderText;
    int appointmentStartH;
    int appointmentStartM;
    int appointmentEndH;
    int appointmentEndM;
    Reminder* errand;
    // File Output Variables
    string saveToFile;

    Calendar calendar1;

    // Print first menu and ask for input
    cout << "Welcome to CSE240 Calendar" << endl << endl;
    cout << "1. Build a new Calendar" << endl;
    cout << "2. Exit" << endl;
    cout << ">> ";
    while (!(cin >> menuInput1)) {
        cout << "Incorrect input!\n>> ";
        cin.clear();
        cin.ignore();
    }

    // Calendar Creation (ask for input for each variable)
    switch(menuInput1) {
        case 1: {
                // Ask user for inputs
                cout << "\nBuilding a new calendar" << endl;
                cout << "Give your calendar a title: ";
                cin.ignore();
                std::getline(std::cin, title);
                cout << "\nHow many days does your calendar have? ";
                while (!(cin >> daysTotal)) {
                    cout << "Incorrect input!\n>> ";
                    cin.clear();
                    cin.ignore();
                }
                if (daysTotal <= 0) {
                    cout << "Days must be > 0 (Set to default: 30)" << endl;
                    daysTotal = 30;
                }
                cout << "\nWhat day does your calendar start on?" << endl;
                cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday" << endl;
                cout << ">> ";
                while (!(cin >> startDate)) {
                    cout << "Incorrect input!\n>> ";
                    cin.clear();
                    cin.ignore();
                }

                // Create Calendar
                calendar1 = Calendar(title, daysTotal, startDate);
                cout << "\nYour Calendar has been created." << endl << endl;
            }
            break;
        case 2:
            cout << "Deuces! " << endl;
            exit(0);
            break;
        default:
            cout << "Incorrect Input" << endl << endl;
            break;
    }

    // Loop and print second menu
    do {
        // Print Menu
        cout << "What would you like to do?" << endl;
        cout << "1. Display Whole Calendar" << endl;
        cout << "2. Display a Single Day" << endl;
        cout << "3. Add an Errand" << endl;
        cout << "4. Delete an Errand" << endl;
        cout << "5. Save to a file" << endl;
        cout << "0. Exit" << endl;
        cout << ">> ";
        cin >> menuInput2;

        switch(menuInput2) {
            // Case 1: Display Whole Calendar
            case 1:
                cout << endl;
                // Display Calendar
                calendar1.dispCalendar(daysTotal);
                cout << endl;
                break;
            // Case 2: Display a single day
            case 2:
                // Ask for specific day
                cout << "\nSelect which day to display:" << endl;
                cout << "Day (1 - " << daysTotal << ") (0 - Back to main menu)" << endl;
                cout << ">> ";
                cin >> selectDay;
                cout << endl;

                // Display Day
                calendar1.dispDay(selectDay - 1);
                cout << endl;
                break;
            // Case 3: Add an Errand
            case 3:
                // Display Calendar and ask for user inputs
                cout << endl;
                calendar1.dispCalendar(daysTotal);
                cout << "\nAdd an Errand" << endl;
                cout << "Select which day you want to add an Errand to:" << endl;
                cout << "Day (1 - " << daysTotal << ") >> ";
                cin >> selectDay;
                cout << "\nWhat type of Errand?" << endl;
                cout << "1. Reminder\n2. Appointment\n0. Back to main menu" << endl;
                cout << ">> ";
                cin >> selectErrand;

                switch (selectErrand) {
                    // Case 1: Reminder
                    case 1: {
                        cout << "\nEnter reminder text: ";
                        cin.ignore();
                        std::getline(std::cin, reminderText);
                        cout << endl;

                        // Add reminder to day
                        errand = new Reminder();
                        errand->setReminderNote(reminderText);
                        calendar1.fetchDayArray()[selectDay -1].addErrand(errand);

                        break;
                    }
                    // Case 2: Appointment
                    case 2: {
                        cout << "\nEnter start time hour (24 hour clock): ";
                        cin >> appointmentStartH;
                        cout << "Enter start time minutes: ";
                        cin >> appointmentStartM;
                        cout << "Enter end time hours (24 hour clock): ";
                        cin >> appointmentEndH;
                        cout << "Enter end time minutes: ";
                        cin >> appointmentEndM;
                        cout << "Enter reminder text: ";
                        cin.ignore();
                        std::getline(std::cin, reminderText);
                        cout << endl;

                        // Add appointment to day
                        Appointment* a1 = new Appointment();
                        errand = a1;
                        a1->setStartTime(to_string(appointmentStartH) + ":" + to_string(appointmentStartM));
                        a1->setEndTime(to_string(appointmentEndH) + ":" + to_string(appointmentEndM));
                        a1->setReminderNote(reminderText);
                        calendar1.fetchDayArray()[selectDay -1].addErrand(errand);

                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Incorrect Input" << endl << endl;
                        break;
                }
                break;
            // Case 4: Delete an Errand
            case 4:
                // Display Calendar and ask for user inputs
                cout << endl;
                calendar1.dispCalendar(daysTotal);
                cout << "\nRemove an Errand" << endl;
                cout << "Select which day you want to add remove Errand to:" << endl;
                cout << "Day (1 - " << daysTotal << ")" << endl;
                cout << ">> ";
                cin >> selectDay;
                cout << endl;

                cout << "You have chosen ";
                calendar1.dispDay(selectDay - 1);

                cout << "Which would you like to delete?" << endl;
                cout << ">> ";
                cin >> selectErrand;

                // Delete errand from day
                calendar1.fetchDayArray()[selectDay - 1].removeErrand(selectErrand);
                cout << "Errand " << selectDay << " Deleted" << endl << endl;
                
                break;
            // Case 5: Save to a file
            case 5: 
                // Ask for user input
                cout << "\nSave Calendar to file" << endl;
                cout << "Please enter the filename to store to (do not include .txt): ";
                cin >> saveToFile;

                // Output calendar to file
                calendar1.outputCalendar(saveToFile, daysTotal);
                cout << "Calendar saved to " << saveToFile << ".txt!" << endl << endl;
                break;
            // Case 0: Exit
            case 0:
                // Free
                free (errand);
                cout << "\nPeace Out" << endl;
                break;
            default:
                cout << "Incorrect Input" << endl << endl;
                break;
        }
    } while (menuInput2 != 0);
}
