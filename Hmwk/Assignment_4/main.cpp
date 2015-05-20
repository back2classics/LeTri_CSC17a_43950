/* 
 * File: main.cpp
 * Author: Tri Le
 * Assignment 5 - Ch. 15 5 Problems
 * Created on May 20, 2015, 11:40 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
//Global Variables

//User Libraries
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

//Function Prototypes
void problem1();
void problem2();
void problem3(); //Continue this problem!!! Not finished yet!!!

int main(int argc, char** argv) {

    problem3();
    
    return 0;
}

void problem1(){
    string name, date;
    int idNum, shift;
    float pay;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your employee number: ";
    cin >> idNum;
    cin.ignore();
    cout << "Enter the date you started working: ";
    getline(cin, date);
    cout << "Enter [1] if you work A.M. shift or [2] if you work P.M. shift: ";
    while(!(cin >> shift)){
        if(shift != 1 && shift != 2){
            cout << "Invalid input. Please enter again." << endl;
        }
    }
    cin.ignore();
    cout << "Enter your pay rate in $/hr: $";
    cin >> pay;
    
    cout << endl;
    
    ProductionWorker person;
    person.setName(name);
    person.setNum(idNum);
    person.setDate(date);
    person.setShift(shift);
    person.setPay(pay);
    
    cout << "Employee's name: " << person.getName() << endl;
    cout << "Employee's number: " << person.getNum() << endl;
    cout << "Employee since: " << person.getDate() << endl;
    if(person.getShift() == 1){
        cout << "Employee's shift: A.M. shift" << endl;
    }
    else{
        cout << "Employee's shift: P.M. shift" << endl;
    }
    cout << "Employee's pay rate: $" << person.getPay() << " an hour." << endl;
}

void problem2(){
    string name, date;
    int idNum;
    float salary, bonus;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your employee number: ";
    cin >> idNum;
    cin.ignore();
    cout << "Enter the date you started working: ";
    getline(cin, date);
    cout << "Enter your annual salary: $";
    cin >> salary;
    cin.ignore();
    
    cout << endl;
    
    ShiftSupervisor boss;
    boss.setName(name);
    boss.setNum(idNum);
    boss.setDate(date);
    boss.setSalary(salary);
    boss.calcBonus();
    
    cout << "Shift supervisor's name: " << boss.getName() << endl;
    cout << "Shift supervisor's number: " << boss.getNum() << endl;
    cout << "Shift supervisor since: " << boss.getDate() << endl;
    cout << "Shift supervisor's annual salary: $" << boss.getSalary() << endl;
    cout << "Shift supervisor's bonus: $" << boss.getBonus() << endl;
}

void problem3(){
    string name, date;
    int idNum, shift, bonus, hours, need;
    float pay;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your employee number: ";
    cin >> idNum;
    cin.ignore();
    cout << "Enter the date you started working: ";
    getline(cin, date);
    cout << "Enter [1] if you work A.M. shift or [2] if you work P.M. shift: ";
    while(!(cin >> shift)){
        if(shift != 1 && shift != 2){
            cout << "Invalid input. Please enter again." << endl;
        }
    }
    cin.ignore();
    cout << "Enter your pay rate in $/hr: $";
    cin >> pay;
    cout << "Enter total number of hours spent at training sessions: ";
    cin >> hours;
    cout << "Enter total number of training session hours needed: ";
    cin >> need;
    
    cout << endl;
    
    TeamLeader lead;
    lead.setName(name);
    lead.setNum(idNum);
    lead.setDate(date);
    lead.setShift(shift);
    lead.setPay(pay);
    lead.calcBonus();
    lead.setHours(hours);
    lead.setNeed(need);
    
    //Start here!!!
    //Not finished yet!!!
    cout << lead.getBonus() << endl;
    cout << lead.getHours() << endl;
    cout << lead.getNeed() << endl;
    
}