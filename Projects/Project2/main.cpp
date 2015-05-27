/* 
 * File:   main.cpp
 * Author: Tri
 * Project 2
 * Created on May 25, 2015, 2:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//Global Variables

//User Libraries
#include "Ship.h"
#include "Board.h"

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {

    //Testing everything to see if it works
    //NOTE: Y COMES BEFORE X!!!
    Board player, enemy;
    int temp;
    for(int i=0;i<5;i++){
        if(i == 0){
            temp = player.getShip1();
        }
        else if(i == 1){
            temp = player.getShip2();
        }
        else if(i == 2){
            temp = player.getShip3();
        }
        else if(i == 3){
            temp = player.getShip4();
        }
        else{
            temp = player.getShip5();
        }
        player.setYaxis();
        player.setXaxis();
        player.setPos();
        player.checkPos(temp);
        player.setShip(temp);
    }
    
    player.output();
    
    return 0;
}