/* 
 * File:   Process.cpp
 * Author: Tri
 * 
 * Created on June 1, 2015, 2:30 PM
 */

#include <cstdlib>
#include <iostream>
#include "Process.h"
using namespace std;
//This class is mainly used for Player vs. Player game mode
//Default Constructor sets name to null value
Process::Process(){
    pName = " ";
    eName = " ";
}
//Sets player's name
void Process::setPName(string p){
    pName = p;
}
//Sets enemy's name
void Process::setEName(string e){
    eName = e;
}
//Start up of game used in Player vs. AI
void Process::begin(){
    cout << "===============Welcome to Battleships!===============" << endl;
    do{
    cout << "Enter your SAILOR name! : ";
    cin >> pName;
    cout << "Now then, tell me the name of the PIRATE you will sink! : ";
    cin >> eName;
    cout << "Sailor! Your name is " << pName << ", and your enemy's"
            " name is " << eName << "." << endl;
    cout << "Is this correct? Enter [y] or [n]: ";
    cin >> valid;
    }while(tolower(valid[0] == 'n'));
    cout << endl;
    cout << pName << ", give your crew orders!" << endl;
    cout << pName << "'s turn will now begin." << endl;
    cout << endl;
    cout << "This is what your board looks like! Plan accordingly!" << endl;
}
//Start up of the game used in Player vs. Player for Player 1
void Process::beginP1(){
    cout << "===============Welcome to Battleships!===============" << endl;
    do{
    cout << "Player 1, enter your SAILOR name! : ";
    cin >> pName;
    cout << "Player 2, enter your SAILOR name! : ";
    cin >> eName;
    cout << "Player 1, your name is " << pName << ", and Player 2, your "
            " name is " << eName << "." << endl;
    cout << "Is this correct? Enter [y] or [n]: ";
    cin >> valid;
    }while(tolower(valid[0] == 'n'));
    cout << endl;
    cout << pName << ", give your crew orders!" << endl;
    cout << pName << "'s turn will now begin." << endl;
    cout << endl;
    cout << "This is what your board looks like! Plan accordingly!" << endl;
    cout << eName << " should now turn away while " << pName << " sets up "
            " his/her board!" << endl;
}
//Prompts user that ships will overlap
void Process::willOverlap(){
    cout << endl;
    cout << "The coordinates chosen will make the ship overlap with"
            " another ship." << endl;
}
//Prompts user that board has been updated
void Process::updateBoard(){
    cout << endl;
    cout << "The ship has been placed! Your updated board looks like this!" << endl;
}
//Prompts user that ship placement has ended
void Process::placeEnd(){
    cout << endl;
    cout << pName << "'s battle preparations have been complete!" << endl;
    cout << pName << "'s crew is ready and prepared for battle!" << endl;
    cout << pName << "'s turn has ended." << endl;
    cout << "Here is your board after all the ships have been placed!" << endl;
    cout << endl;
}
//Prompts that enemy has began placing ships in Player vs. AI
void Process::enemyBegin(){
    cout << endl;
    cout << "Scallywag " << eName << " has begun giving his/her orders!" << endl;
    cout << eName << "'s turn will now begin." << endl;
    cout << endl;
    for(int i=0;i<5;i++){
        cout << "Generating enemy battlefield..." << endl;
    }
}
//Player 2's turn to begin setting up
void Process::beginP2(){
    cout << endl;
    cout << eName << ", give your crew orders!" << endl;
    cout << eName << "'s turn will now begin." << endl;
    cout << endl;
    cout << "This is what your board looks like! Plan accordingly!" << endl;
    cout << pName << " should now turn away while " << eName << " sets up "
            "his/her board!" << endl;
}
//Prompts that enemy has finished placing ships
void Process::enemyEnd(){
    cout << endl;
    cout << eName << "'s crew is ready and prepared for battle!" << endl;
    cout << endl;
}
//Prompts that Player 2's turn has ended
void Process::p2End(){
    cout << endl;
    cout << eName << "'s battle preparations have been complete!" << endl;
    cout << eName << "'s crew is ready and prepared for battle!" << endl;
    cout << eName << "'s turn has ended." << endl;
    cout << "Here is your board after all the ships have been placed!" << endl;
    cout << endl;
}
//Prompts the user the win or lose conditions of the game
void Process::winOrLose(){
    cout << endl;
    cout << pName << "'s win/lose condition is if 17 ships sink!" << endl;
    cout << eName << "'s win/lose condition is if 17 ships sink!" << endl;
    cout << endl;
}
//Prompts user that they can fire once at the enemy
void Process::playerShot(){
    cout << pName << ", it is your turn!" << endl;
    cout << pName << ", you can fire at the enemy once!" << endl;
    cout << endl;
    cout << "Choose your shot coordinate now!" << endl;
}
//Prompts user that enemy will fire at user once
void Process::enemyShot(){
    cout << endl;
    cout << "It is " << eName << "'s turn now!" << endl;
    cout << eName << " can fire at you once!" << endl;
}
//Prompts user the aftermath of the game
void Process::aftermath(string n){
    if(n == pName){
        cout << endl;
        cout << "Here is your board after the enemy fired!" << endl;
    }
    else{
        cout << "Here is the enemy's board after you fired!" << endl;
    }
}