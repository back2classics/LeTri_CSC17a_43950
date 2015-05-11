/* 
 * File:   Car.cpp
 * Author: Tri
 * 
 * Created on May 10, 2015, 11:17 AM
 */



#include <cstdlib>
#include "Car.h"
using namespace std;

Car::Car(int year, string model){
    yearModel = year; make = model; speed = 0;
}

void Car::setYearModel(int year){
    yearModel = year;
}

void Car::setMake(string model){
    make = model;
}

void Car::setSpeed(int fast){
    speed = fast;
}

void Car::acccelerate(){
    speed += 5;
}

void Car::brake(){
    speed -= 5;
}