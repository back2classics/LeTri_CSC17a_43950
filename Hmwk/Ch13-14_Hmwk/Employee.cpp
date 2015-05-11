/* 
 * File:   Employee.cpp
 * Author: Tri Le
 * 
 * Created on May 6, 2015, 6:45 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Employee.h"
using namespace std;

void Employee::setName(string n){
    name = n;
}

void Employee::setId(int i){
    idNum = i;
}

void Employee::setDepartment(string d){
    department = d;
}

void Employee::setPosition(string p){
    position = p;
}

