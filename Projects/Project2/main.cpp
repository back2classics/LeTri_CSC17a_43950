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
#include "Process.h"

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {

    srand(time(0)); //Used for randomly spawning enemy's board
    //Variables && Objects
    Board player, enemy;
    Process game;
    int temp; //Stores ship size used in for-loop
    int tempPos; //Stores 0 or 1 to determine position for enemy
    char posTemp; //Stores the actual position in enemy private member
    bool sink = false, eSink = false;
    bool win = false;
    
    game.begin(); //Game starts here!
    player.output(); //Board preview before ship placement
    //Player's ship placement begins here
    for(int i=0;i<5;i++){
        temp = player.setFleet(i);
        player.setYaxis();
        player.setXaxis();
        player.setPos();
        player.checkPos(temp);
        player.isOverlap(temp);
        if(player.getOverlap() == true){
            do{
                game.willOverlap();
                player.setYaxis();
                player.setXaxis();
                player.setPos();
                player.checkPos(temp);
                player.isOverlap(temp);
            }while(player.getOverlap() == true);
        }
        player.setShip(temp);
        game.updateBoard();
        player.output();
    }
    game.placeEnd();
    player.output();
    //Enemy's ship placement starts here!
    game.enemyBegin();
    for(int i=0; i<5; i++){
        temp = enemy.setFleet(i);
        enemy.setYaxis(rand() % 10); 
        enemy.setXaxis(rand() % 10); 
        tempPos = rand() % 2;
        if(tempPos == 0){
            posTemp = 'h';
            enemy.setPos(posTemp);
        }
        else{
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
                if(tempPos == 0){
                    posTemp = 'h';
                    enemy.setPos(posTemp);
                }
                else{
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
    game.enemyEnd();
    cout << "For testing purposes!" << endl;
    enemy.output();
    player.setWinLose();
    enemy.setWinLose();
    game.winOrLose();
    do{
        //Player's turn to fire at enemy begins here!
        game.playerShot();
        enemy.setYaxis(); //Using enemy's Y to set coords to hit ships on the enemy's board
        enemy.setXaxis(); //Using enemy's X to set coords to hit ships on the enemy's board
        enemy.setHit(game.getPName()); //Places any hits or prompts for misses with player's name
        sink = enemy.sink(player.getWinLose(), game.getPName()); //Checks if win condition has been meet
        win = enemy.checkWin(sink); //Declares win and ends the game
        //Enemy's turn to fire at enemy begins here!
        if(!win){
            game.enemyShot();
            player.setYaxis(rand() % 10); //Random coords chosen to fire at player
            player.setXaxis(rand() % 10);
            player.setHit(game.getEName()); //Places any hits that landed
            eSink = player.sink(enemy.getWinLose(), game.getEName()); //Checks if player has sunk
            win = player.checkWin(eSink); //Checks if enemy has won
            game.aftermath(game.getPName());
            player.output();
            cout << endl;
            game.aftermath(game.getEName());
            enemy.output();
            cout << endl;
        }
    }while(!win); //Ends game after either condition was met
    
    return 0;
}