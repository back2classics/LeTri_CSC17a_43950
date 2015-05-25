/* 
 * File:   ShiftSupervisor.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 5:45 PM
 */
#include <iostream>
#include <cstdlib>
#include "ShiftSupervisor.h"
using namespace std;

ShiftSupervisor::ShiftSupervisor(){
    salary = 0.0;
    bonus = 0.0;
}

ShiftSupervisor::ShiftSupervisor(float s, float b){
    salary = s;
    bonus = b;
}

void ShiftSupervisor::setSalary(float s){
    salary = s;
}

void ShiftSupervisor::setBonus(float b){
    bonus = b;
}

void ShiftSupervisor::calcBonus(){
    bonus = salary * .10;
}
