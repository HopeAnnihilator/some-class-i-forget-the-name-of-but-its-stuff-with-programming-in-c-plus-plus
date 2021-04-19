// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 11
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
Date::Date () {
    month = 1;
    day = 1;
    year = 1900;
}

Date::Date (int initMonth, int initDay, int initYear) {
    day = initDay;
    month = initMonth;
    year = initYear;
}

Date::Date(int initMonth, int initYear) {
    year = initYear;
    month = initMonth;
    day = 1;
}

// ************** TRANSFORMERS **************
void Date::SetDate (int m, int d, int y) {
    month = m;
    day = d;
    year = y;
    return;
}

void Date::IncrementDate () {
    int totalDays;
    switch (month) {
        case 1: totalDays = 31; break; 
        case 2: totalDays = 28; break; 
        case 3: totalDays = 31; break;
        case 4: totalDays = 30; break;  
        case 5: totalDays = 31; break;
        case 6: totalDays = 30; break;
        case 7: totalDays = 31; break;
        case 8: totalDays = 31; break; 
        case 9: totalDays = 30; break;
        case 10: totalDays = 31; break;
        case 11: totalDays = 30; break;
        case 12: totalDays = 31; break;
        default: break;
    }
    if (day >= totalDays) {
        month += 1;
        day = 0;
    }
    if (month > 12) {
        year += 1;
        month = 1;
    }
    day += 1;
    return;
}

// ************** OBSERVERS *******************
void Date::WriteNumberFormat () const {
    if (month < 10) {
        cout << '0';
    }
    cout << month << "/";
    if (day < 10) {
        cout << '0';
    }
    cout << day << "/";
    cout << year << endl;
    return;
}

void Date::WriteNameFormat () const {
    switch (month) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
        default: break;
    }
    cout << " " << day << ", " << year << endl;
    return;
}

bool Date::SameDate(Date otherDate) const {
    return (day == otherDate.day && month == otherDate.month && year == otherDate.year);
}
bool Date::BeforeDate(Date otherDate) const {
    if (year < otherDate.year) {
        return true;
    } else if (year == otherDate.year && month < otherDate.month) {
        return true;
    } else if (year == otherDate.year && month == otherDate.month && day < otherDate.day) {
        return true;
    } else {
        return false;
    }
}
bool Date::AfterDate(Date otherDate) const {
    if (year > otherDate.year) {
        return true;
    } else if (year == otherDate.year && month > otherDate.month) {
        return true;
    } else if (year == otherDate.year && month == otherDate.month && day > otherDate.day) {
        return true;
    } else {
        return false;
    }
}