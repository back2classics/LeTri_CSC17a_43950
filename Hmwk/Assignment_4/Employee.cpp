/* 
 * File:   Employee.cpp
 * Author: rcc
 * 
 * Created on May 20, 2015, 11:44 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(){
    name = "";
    num = 0;
    date = "";
}

Employee::Employee(string n, int numb, string d){
    name = n;
    num = numb;
    date = d;
}

void Employee::setName(string n){
    name = n;
}

void Employee::setNum(int numb){
    num = numb;
}

void Employee::setDate(string d){
    date = d;
}

