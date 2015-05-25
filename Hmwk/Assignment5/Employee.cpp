/* 
 * File:   Employee.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 5:28 PM
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

