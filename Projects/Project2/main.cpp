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
    srand(time(0)); //Used for randomly spawning enemy's board
    //Variables
    Board player, enemy;
    int temp; //Stores ship size used in for-loop
    int xTemp, yTemp; //Stores X and Y coords for enemy
    int tempPos; //Stores 0 or 1 to determine position for enemy
    char posTemp; //Stores the actual position in enemy private member
    string sailor, pirate; //Player and Enemy name
    string valid; //For yes or no questions
    
    cout << "===============Welcome to Battleships!===============" << endl;
    do{
    cout << "Enter your SAILOR name! : ";
    cin >> sailor;
    cout << "Now then, tell me the name of the PIRATE you will sink! : ";
    cin >> pirate;
    player.setName(sailor);
    enemy.setName(pirate);
    cout << "Sailor! Your name is " << player.getName() << ", and your enemy's"
            " name is " << enemy.getName() << "." << endl;
    cout << "Is this correct? Enter [y] or [n]: ";
    cin >> valid;
    }while(tolower(valid[0] == 'n'));
    cout << endl;
    cout << player.getName() << ", give your crew orders!" << endl;
    cout << player.getName() << "'s turn will now begin." << endl;
    cout << endl;
    cout << "This is what your board looks like! Plan accordingly!" << endl;
    player.output(); //Board preview before ship placement
    //Player's ship placement begins here
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
        cout << endl;
        cout << "The ship that is going to be placed is of size " << temp << "." << endl;
        player.setYaxis();
        player.setXaxis();
        player.setPos();
        player.checkPos(temp);
        player.isOverlap(temp);
        if(player.getOverlap() == true){
            do{
                cout << endl;
                cout << "The coordinates chosen will make the ship overlap with"
                        " another ship." << endl;
                player.setYaxis();
                player.setXaxis();
                player.setPos();
                player.checkPos(temp);
                player.isOverlap(temp);
            }while(player.getOverlap() == true);
        }
        player.setShip(temp);
        cout << endl;
        cout << "The ship has been placed! Your updated board looks like this!" << endl;
        player.output();
    }
    cout << endl;
    cout << player.getName() << "'s battle preparations have been complete!" << endl;
    cout << "Here is your board after all the ships have been placed!" << endl;
    player.output();
    cout << endl;
    cout << player.getName() << "'s crew is ready and prepared for battle!" << endl;
    cout << player.getName() << "'s turn has ended." << endl;
    cout << endl;
    //Enemy's ship placement starts here!
    cout << "Scallywag " << enemy.getName() << " has begun giving his/her orders!" << endl;
    cout << enemy.getName() << "'s turn will now begin." << endl;
    cout << endl;
    for(int i=0; i<5; i++){
        cout << "Generating enemy battlefield..." << endl;
        if(i == 0){
            temp = enemy.getShip1();
        }
        else if(i == 1){
            temp = enemy.getShip2();
        }
        else if(i == 2){
            temp = enemy.getShip3();
        }
        else if(i == 3){
            temp = enemy.getShip4();
        }
        else{
            temp = enemy.getShip5();
        }
        enemy.setYaxis(rand() % 10); //Stores yTemp in enemy private member
        enemy.setXaxis(rand() % 10); //Stores xTemp in enemy private member
        tempPos = rand() % 2;
        if(tempPos == 0)
        {
            posTemp = 'h';
            enemy.setPos(posTemp);
        }
        else
        {
            posTemp = 'v';
            enemy.setPos(posTemp);
        }
        enemy.checkE(temp); //If rand() fails then check reassigns private members
        enemy.isOverlap(temp); //Should always be passed on first loop
        //if block runs if a ship is overlapping with another ship and randomizes again
        if(enemy.getOverlap() == true){
            do{
                enemy.setYaxis(rand() % 10); 
                enemy.setXaxis(rand() % 10); 
                tempPos = rand() % 2;
                if(tempPos == 0)
                {
                    posTemp = 'h';
                    enemy.setPos(posTemp);
                }
                else
                {
                    posTemp = 'v';
                    enemy.setPos(posTemp);
                }
                enemy.checkE(temp); 
                enemy.isOverlap(temp); 
            }while(enemy.getOverlap() == true);
        }
        enemy.checkE(temp);
        enemy.spawnE(temp);
    }
    cout << endl;
    cout << enemy.getName() << "'s crew is ready and prepared for battle!" << endl;
    cout << endl;
    cout << "For testing purposes!" << endl;
    enemy.output();
    player.setWinLose();
    enemy.setWinLose();
    cout << endl;
    cout << player.getName() << "'s win/lose condition is if " << player.getWinLose() << " ships sink!" << endl;
    cout << enemy.getName() << "'s win/lose condition is if " << enemy.getWinLose() << " ships sink!" << endl;
    cout << endl;
    do{
        //Player's turn to fire at enemy begins here!
        cout << player.getName() << ", it is your turn!" << endl;
        cout << player.getName() << ", you can fire at the enemy once!" << endl;
        cout << "Choose your shot coordinate now!" << endl;
        enemy.setYaxis(); //Using enemy's Y to set coords to hit ships on the enemy's board
        enemy.setXaxis(); //Using enemy's X to set coords to hit ships on the enemy's board
        enemy.setHit(player.getName()); //Places any hits or prompts for misses with player's name
        enemy.sink(player.getWinLose(), player.getName()); //Checks if win condition has been meet
        enemy.checkWin(enemy.getSink()); //Declares win and ends the game
        //Enemy's turn to fire at enemy begins here!
        cout << "It is " << enemy.getName() << "'s turn now!" << endl;
        cout << enemy.getName() << " can fire at you once!" << endl;
        player.setYaxis(rand() % 10); //Random coords chosen to fire at player
        player.setXaxis(rand() % 10);
        player.setHit(enemy.getName()); //Places any hits that landed
        player.sink(enemy.getWinLose(), enemy.getName()); //Checks if player has sunk
        player.checkWin(player.getSink()); //Checks if enemy has won
        cout << "Here is your board after the enemy fired!" << endl;
        player.output();
        cout << endl;
        cout << "Here is the enemy's board after you fired!" << endl;
        enemy.output();
        cout << endl;
    }while(enemy.getWin() == false || player.getWin() == false); //Ends game after either condition was met
    
    return 0;
}