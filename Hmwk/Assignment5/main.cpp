/* 
 * File:   main.cpp
 * Author: Tri
 *
 * Created on May 20, 2015, 2:54 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
//Global Variables

//User Libraries
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

int main(int argc, char** argv) {

    srand(time(0));
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
        default: def(inN);}
    }while(inN>=1&&inN<=5);

    
    return 0;
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
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
    string name, date;
    int idNum, shift;
    float pay;
    cin.ignore();
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
    cout << endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    cout << "Problem 2 is an extension of problem 1." << endl;
    string name, date;
    int idNum;
    float salary, bonus;
    cin.ignore();
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
    cout << "Shift supervisor's employee number: " << boss.getNum() << endl;
    cout << "Shift supervisor since: " << boss.getDate() << endl;
    cout << "Shift supervisor's annual salary: $" << boss.getSalary() << endl;
    cout << "Shift supervisor's annual bonus: $" << boss.getBonus() << endl;
    cout << endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    cout << "Problem 3 is an extension of problem 2." << endl;
    string name, date;
    int idNum, shift, bonus, hours, need;
    float pay;
    cin.ignore();
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
    if(hours > need){
        lead.calcBonus();
    }
    lead.setHours(hours);
    lead.setNeed(need);
    cout << "Team Leader's name: " << lead.getName() << endl;
    cout << "Team Leader's employee number: " << lead.getNum() << endl;
    cout << "Team Leader since: " << lead.getDate() << endl;
    if(lead.getShift() == 1){
        cout << "Team Leader's shift: A.M. shift" << endl;
    }
    else{
        cout << "Team Leader's shift: P.M. shift" << endl;
    }
    cout << "Team Leader's pay rate: $" << lead.getPay() << " per hour" << endl;
    if(lead.getHours() > lead.getNeed()){
        cout << "Team Leader's monthly bonus: $" << lead.getBonus() << endl;
    }
    else{
        cout << "Team Leader's training hour requirement not met. Bonus has not"
                " been awarded to " << lead.getName() << endl;
    }
    cout << "Team Leader's training hours: " << lead.getHours() << " hours" << endl;
    cout << "Team Leader's required training hours: " << lead.getNeed() << " hours" << endl;
    cout << endl;
}

void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    string fName, lName, address, city, state, zip, phone, num;
    int custNum = rand() % 99 + 1;
    bool mail = false;
    cout << "Enter your first name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter your city: ";
    cin >> city;
    cout << "Enter your state: ";
    cin >> state;
    cout << "Enter your zip code: ";
    cin >> zip;
    cout << "Enter your phone number: ";
    cin >> phone;
    cout << "Enter [1] if you would like to be on the mailing list, otherwise"
            " enter anything else: ";
    cin >> num;
    if(num == "1"){
        mail = true;
    }
    cout << endl;
    CustomerData customer;
    customer.setfName(fName);
    customer.setlName(lName);
    customer.setAddress(address);
    customer.setCity(city);
    customer.setState(state);
    customer.setZip(zip);
    customer.setPhone(phone);
    customer.setCustNum(custNum);
    customer.setMail(mail);
    
    cout << "Mailing List Details: " << endl;
    cout << "First name: " << customer.getfName() << endl;
    cout << "Last name: " << customer.getlName() << endl;
    cout << "Address: " << customer.getAddress() << endl;
    cout << "City: " << customer.getCity() << endl;
    cout << "State: " << customer.getState() << endl;
    cout << "Zip: " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer's unique number: " << customer.getCustNum() << endl;
    if(customer.getMail() == true){
        cout << "Customer has selected to continue being on the mailing list." << endl;
    }
    else{
        cout << "Customer has opted out of the mailing list." << endl;
    }
    cout << endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    cout << "Problem 5 is an extension of problem 4." << endl;
    string fName, lName, address, city, state, zip, phone, num;
    int custNum = rand() % 99 + 1;
    bool mail = false;
    float purchase, discount;
    cout << "Enter your first name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter your city: ";
    cin >> city;
    cout << "Enter your state: ";
    cin >> state;
    cout << "Enter your zip code: ";
    cin >> zip;
    cout << "Enter your phone number: ";
    cin >> phone;
    cout << "Enter [1] if you would like to be on the mailing list, otherwise"
            " enter anything else: ";
    cin >> num;
    if(num == "1"){
        mail = true;
    }
    cout << "Enter the total amount spent on mailing purchases: $";
    do{
        cin >> purchase;
    }while(!(purchase > 0));
    
    if(purchase >= 500.0 && purchase <= 999.9){
        discount = 5;
    }
    else if(purchase >= 1000.0 && purchase <= 1499.9){
        discount = 6;
    }
    else if(purchase >= 1500.0 && purchase <= 1999.9){
        discount = 7;
    }
    else if(purchase >= 2000.0){
        discount = 10;
    }
    else{
        discount = 0.0;
    }
    cout << endl;
    PreferredCustomer customer;
    customer.setfName(fName);
    customer.setlName(lName);
    customer.setAddress(address);
    customer.setCity(city);
    customer.setState(state);
    customer.setZip(zip);
    customer.setPhone(phone);
    customer.setCustNum(custNum);
    customer.setMail(mail);
    customer.setPurchase(purchase);
    customer.setDiscount(discount);
    
    cout << "Mailing List Details: " << endl;
    cout << "First name: " << customer.getfName() << endl;
    cout << "Last name: " << customer.getlName() << endl;
    cout << "Address: " << customer.getAddress() << endl;
    cout << "City: " << customer.getCity() << endl;
    cout << "State: " << customer.getState() << endl;
    cout << "Zip: " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer's unique number: " << customer.getCustNum() << endl;
    if(customer.getMail() == true){
        cout << "Customer has selected to continue being on the mailing list." << endl;
    }
    else{
        cout << "Customer has opted out of the mailing list." << endl;
    }
    cout << "Customer's total purchases: $" << customer.getPurchase() << endl;
    cout << "Customer's future discount: % " << customer.getDiscount() << endl;
    cout << endl;
}