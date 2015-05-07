/* 
 * File:   main.cpp
 * Author: Tri Le
 * Ch. 13-14 Homework / Assignment 4
 * Created on May 6, 2015, 6:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
//Global Constants

//User Libraries
#include "Date.h"
#include "Employee.h"

//Function Prototypes
void number1();

//Execution begins here!
int main(int argc, char** argv) {

    
    
    return 0;
}

void number1(){
    int months, days, years;
    Date calendar;
    
    cout << "Enter a month: ";
    do{
        while(!(cin >> months)){
            cout << "Invalid input. Please enter again: ";
            cin.clear();
            cin.ignore();
        }
        if(!(months >= 1 && months <= 12)){
                cout << "Invalid input. Please enter again: ";
        }
    }while(!(months >= 1 && months <= 12));
    cout << endl;
    
    cout << "Enter a day: ";
    do{
        while(!(cin >> days)){
            cout << "Invalid input. Please enter again: ";
            cin.clear();
            cin.ignore();
        }
        if(!(days >= 1 && days <= 31)){
                cout << "Invalid input. Please enter again: ";
        }
    }while(!(days >= 1 && days <= 31));
    cout << endl;
    
    cout << "Enter a year: ";
    cin >> years;
    cout << endl;
    
    calendar.setMonth(months);
    calendar.setDay(days);
    calendar.setYear(years);
    
    cout << "Here are 3 formats of the dates you entered: " << endl;
    cout << calendar.getMonth() << '/' << calendar.getDay() << '/' <<
            calendar.getYear() << endl;
    cout << "December " << calendar.getDay() << ", " << calendar.getYear() << endl;
    cout << calendar.getDay() << " December " << calendar.getYear() << endl;
}
