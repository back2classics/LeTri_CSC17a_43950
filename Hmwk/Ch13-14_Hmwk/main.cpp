/* 
 * File:   main.cpp
 * Author: Tri
 * Ch. 13-14 Homework 
 * Created on May 6, 2015, 3:15 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
//Global Constants

//User Libraries
#include "Car.h"
#include "Contact.h"
#include "Date.h"
#include "DayOfYear.h"
#include "Employee.h"
#include "NumDays.h"
#include "Numbers.h"
#include "Retail.h"
#include "Month.h"

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution begins here!
int main(int argc, char** argv) {

    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
        case 3: problem3();break;
        case 4: problem4();break;
        case 5: problem5();break;
        case 6: problem6();break;
        case 7: problem7();break;
        case 8: problem8();break;
        case 9: problem9();break;
        case 10: problem10();break;
        default: def(inN);}
    }while(inN>=1&&inN<=10);

    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 4"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type 8 for problem 8"<<endl;
    cout<<"Type 9 for problem 9"<<endl;
    cout<<"Type 10 for problem 10"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
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
    cout << endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    string name1 = "Susan Meyers", name2 = "Mark Jones", name3 = "Joy Rogers",
           depart1 = "Accounting", depart2 = "IT", depart3 = "Manufacturing",
            pos1 = "Vice President", pos2 = "Programmer", pos3 = "Engineer";
    int id1 = 47899, id2 = 39119, id3 = 81774;
    Employee person1(name1, id1, depart1, pos1);
    Employee person2(name2, id2, depart2, pos2);
    Employee person3(name3, id3, depart3, pos3);
    
    cout << "___________________________________________________________________"
            "_________" << endl;
    cout << "Name: " << person1.getName() << " " << "ID: " << person1.getId() << " " << 
            "Department: " << person1.getDepartment() << " " << "Position: " <<
             person1.getPosition() << endl;
    cout << "Name: " << person2.getName() << " " << "ID: " << person2.getId() << " " << 
            "Department: " << person2.getDepartment() << " " << "Position: " <<
             person2.getPosition() << endl;
    cout << "Name: " << person3.getName() << " " << "ID: " << person3.getId() << " " << 
            "Department: " << person3.getDepartment() << " " << "Position: " <<
             person3.getPosition() << endl;
    cout << "___________________________________________________________________"
            "_________" << endl;
    
    cout << endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    int year, mph;
    string model;

    cout << "Enter the year model of the car: ";
    cin >> year;
    cout << "Enter the make of the car: ";
    cin >> model;
    cout << "Enter the current speed of the car: ";
    cin >> mph;
    
    Car mustang(year, model);
    
    mustang.setSpeed(mph);
    
    cout << "The car is starting to accelerate!" << endl;
    for(int i=0;i<5;i++){
        mustang.acccelerate();
        cout << "The current speed of the car is: " << mustang.getSpeed() << endl;
    }
    
    cout << endl;
    
    cout << "The car is starting to brake!" << endl;
    for(int i=0;i<5; i++){
        mustang.brake();
        cout << "The current speed of the car is: " << mustang.getSpeed() << endl;
    }
    cout << endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    string names, addrs;
    int ages, teles;
    Contact you, buddy, family;
    
    cout << "Enter your name: ";
    getline(cin, names);
    cout << "Enter your address: ";
    getline(cin, addrs);
    cout << "Enter your age: ";
    cin >> ages;
    cout << "Enter your phone number: ";
    cin >> teles;
    cout << endl;
    you.setName(names);
    you.setAddress(addrs);
    you.setAge(ages);
    you.setPhone(teles);
    
    cout << "Here is your information: " << endl;
    cout << you.getName() << endl;
    cout << you.getAddress() << endl;
    cout << you.getAge() << endl;
    cout << you.getPhone() << endl;
    cout << endl;
    
    cin.ignore();
    
    cout << "Enter your family member's name: ";
    getline(cin, names);
    cout << "Enter your family member's address: ";
    getline(cin, addrs);
    cout << "Enter your family member's age: ";
    cin >> ages;
    cout << "Enter your family member's phone number: ";
    cin >> teles;
    cout << endl;
    family.setName(names);
    family.setAddress(addrs);
    family.setAge(ages);
    family.setPhone(teles);
    
    cout << "Here is your family member's information: " << endl;
    cout << family.getName() << endl;
    cout << family.getAddress() << endl;
    cout << family.getAge() << endl;
    cout << family.getPhone() << endl;
    cout << endl;
    
    cin.ignore();
    
    cout << "Enter your friend's name: ";
    getline(cin, names);
    cout << "Enter your friend's address: ";
    getline(cin, addrs);
    cout << "Enter your friend's age: ";
    cin >> ages;
    cout << "Enter your friend's phone number: ";
    cin >> teles;
    cout << endl;
    buddy.setName(names);
    buddy.setAddress(addrs);
    buddy.setAge(ages);
    buddy.setPhone(teles);
    
    cout << "Here is your friend's information: " << endl;
    cout << buddy.getName() << endl;
    cout << buddy.getAddress() << endl;
    cout << buddy.getAge() << endl;
    cout << buddy.getPhone() << endl;
    cout << endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    string store;
    string item1 = "Jacket"; string item2 = "Designer Jeans";
    string item3 = "Shirt";
    int unit1 = 12; int unit2 = 40; int unit3 = 20;
    float price1 = 59.95; float price2 = 34.95; float price3 = 24.95;
    Retail product1(item1, unit1, price1);
    Retail product2(item2, unit2, price2);
    Retail product3(item3, unit3, price3);
    
    cout << "Enter a store name: ";
    cin >> store;
    cout << endl;
    cout << "Here are 3 products sold at " << store << ": " << endl;
    cout << "________________________________________________________________" << endl;
    cout << product1.getDescript() << 's' << " which costs $" << product1.getPrice()
            << "." << " There are " << product1.getUnits() << " units in stock." << endl;
    cout << product2.getDescript() << " which costs $" << product2.getPrice()
            << "." << " There are " << product2.getUnits() << " units in stock." << endl;
    cout << product3.getDescript() << 's' << " which costs $" << product3.getPrice()
            << "." << " There are " << product3.getUnits() << " units in stock." << endl;
    cout << endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    int w,x,y,z;
    int num;
    cout << "Enter any number from 0-9999: ";
    do{
        cin >> num;
    }
    while(!(num >= 0 && num <= 9999));
    w = num / 1000 % 10;
    x = num / 100 % 10;
    y = num / 10 % 10;
    z = num % 10;
    Numbers money(num);
    money.print(w,x,y,z);
    cout << "Here is the number that was inputted: " << money.getNumber();
    
    cout << endl;
}

void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    int num;
    cout << "Enter any number from 1-365: ";
    do{
        cin >> num;
    }while(!(num >= 1 && num <= 365));
    cout << "You entered: " << num << endl;
    DayOfYear months(num);
    months.print();
    
    cout << endl;
}

void problem8(){
    cout<<"In problem # 8"<<endl<<endl;
    int num;
    cout << "Enter any number from 1-365: ";
    do{
        cin >> num;
    }while(!(num >= 1 && num <= 365));
    cout << "You entered: " << num << endl;
    cout << "The date is: ";
    DayOfYear months(num);
    months.print();
    cout << "The overload operator++ has been implemented." << endl;
    cout << "The new date is: ";
    months++;
    months.print();
    cout << endl;
}

void problem9(){
    cout<<"In problem # 9"<<endl<<endl;
    
    int hours;
    
    cout << "Enter the amount of hours worked: ";
    cin >> hours;
    NumDays week;
    week.setHour(hours);
    week.calc(hours);
    cout << week.getHour() << " hours is equal to " << week.getDay() << 
            " working days" << endl;
    cout << endl;
}

void problem10(){
    cout<<"In problem # 10"<<endl<<endl;
    
    string nMonth;
    int monthN;
    
    cout << "Enter the name of a month: ";
    cin >> nMonth;
    nMonth[0] = toupper(nMonth[0]);
    
    Month school(nMonth);
    cout << "You entered: " << nMonth << endl;
    cout << nMonth << " is equivalent to the number " << school.getMonthNum() << endl;
    
    cout << "Now enter a number from 1-12: ";
    cin >> monthN;
    
    Month college(monthN);
    cout << "You entered: " << monthN << endl;
    cout << monthN << " is equivalent to the month: " << college.getName() << endl;
    
    cout << endl;
}