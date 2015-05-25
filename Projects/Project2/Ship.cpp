/* 
 * File:   Ship.cpp
 * Author: Tri
 * 
 * Created on May 25, 2015, 2:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "Ship.h"
using namespace std;

//Default constructor
Ship::Ship(){
    ship1 = BOAT + 2; //size = 2
    ship2 = CRUISER + 2; //size = 3
    ship3 = SUB + 1; //size = 3
    ship4 = SHIP + 1; //size = 4
    ship5 = CARRIER + 1; //size = 5
}

void Ship::setShip1(){
    ship1 = BOAT + 2;
}

void Ship::setShip2(){
    ship2 = CRUISER + 2;
}

void Ship::setShip3(){
    ship3 = SUB + 1;
}

void Ship::setShip4(){
    ship4 = SHIP + 1;
}

void Ship::setShip5(){
    ship5 = CARRIER + 1;
}


