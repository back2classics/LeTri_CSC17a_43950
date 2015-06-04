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
    boat = "BOATS";
    cruiser = "CRUISERS";
    sub = "SUBMARINES";
    ship = "SHIPS";
    carrier = "CARRIERS";
}
//Setters automatically set ship sizes to respective size according to ship #
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

int Ship::setFleet(int i){
    if(i == 0){
        cout << "The ship that is going to be placed is of size " << BOAT + 2 << "." << endl;
        return BOAT + 2;
    }
    else if(i == 1){
        cout << "The ship that is going to be placed is of size " << CRUISER + 2 << "." << endl;
        return CRUISER + 2;
    }
    else if(i == 2){
        cout << "The ship that is going to be placed is of size " << SUB + 1 << "." << endl;
        return SUB + 1;
    }
    else if(i == 3){
        cout << "The ship that is going to be placed is of size " << SHIP + 1 << "." << endl;
        return SHIP + 1;
    }
    else{
        cout << "The ship that is going to be placed is of size " << CARRIER + 1 << "." << endl;
        return CARRIER + 1;
    }
    cout << endl;
}

void Ship::shipInfo(){
    cout << "The 5 ship types are: " << endl;
    cout << boat << endl;
    cout << cruiser << endl;
    cout << sub << endl;
    cout << ship << endl;
    cout << carrier << endl;
}
