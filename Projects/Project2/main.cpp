/* 
 * File:   main.cpp
 * Author: Tri
 * Project 2
 * Created on May 25, 2015, 2:01 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//Global Variables

//User Libraries
#include "Ship.h"
#include "Board.h"

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {

    //Testing everything to see if it works
    Board player, enemy;
    player.setXaxis();
    player.setYaxis();
    player.setPos();
    cout << player.getXaxis() << endl;
    cout << player.getYaxis() << endl;
    cout << player.getPos() << endl;
    
    return 0;
}

