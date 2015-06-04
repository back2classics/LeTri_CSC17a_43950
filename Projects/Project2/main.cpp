/* 
 * File: main.cpp
 * Author: Tri
 * Project 2 - CSC17a
 * Created on May 25, 2015, 2:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//Global Variables

//User Libraries
#include "Ship.h"
#include "Board.h"
#include "Process.h"
#include "VectorFileIO.h"

//Function Prototypes
void playerVsAI(); //Player vs. AI game mode
void playerVsPlayer(); //Player vs. Player game mode
void getInfo(Ship &); //Polymorphic function

//Execution begins here
int main(int argc, char** argv) {

    srand(time(0)); //Used for randomly spawning enemy's board
    playerVsAI();
    //playerVsPlayer();
    
    return 0;
}

void playerVsAI(){
    //Variables && Objects
    Board player, enemy;
    Process game;
    fstream datFile; //Used for binary file IO
    int temp; //Stores ship size used in for-loop
    int tempPos; //Stores 0 or 1 to determine position for enemy
    int forChase; //Used to determine direction of chase
    int size = 0; //Vector size, is later incremented
    int holdX, holdY; //Used to hold the addresses of X and Y axis coords for File IO
    char posTemp; //Stores the actual position in enemy private member
    bool sink = false, eSink = false; //Used to determine if player/enemy sunk
    bool chase = false; //Used to determine if enemy will chase player
    bool win = false; //Ends the game if true
    bool yesWrite = false; //Checks for signal to write to file
    
    game.begin(); //Game starts here!
    player.output(); //Board preview before ship placement
    //Player's ship placement begins here
    for(int i=0;i<5;i++){
        temp = player.setFleet(i);
        try{
            player.setYaxis();
        }
        catch(Board::NegativeY){
            cout << "ERROR: Cannot input negative values for the Y axis." << endl;
        }
        try{
            player.setXaxis();
        }
        catch(Board::NegativeX){
            cout << "ERROR: Cannot input negative values for the X axis." << endl;
        }
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
    //datFile.open("data.txt", ios::out | ios::binary); //write to binary file
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
            if(chase == false){
                player.setYaxis(rand() % 10); //Random coords chosen to fire at player
                player.setXaxis(rand() % 10);
            }
            else{
                forChase = rand() % 2;
                player.smartAI(forChase);
            }
            holdX = player.getXaxis();
            holdY = player.getYaxis();
            player.setHit(game.getEName()); //Places any hits that landed
            yesWrite = player.writeStat(); //Signals to write to file
//            if(yesWrite == true){
//                size += 2;
//                datFile.write(reinterpret_cast<char *>(&holdY), sizeof(int));
//                datFile.write(reinterpret_cast<char *>(&holdX), sizeof(int));
//            }
            chase = player.startAI();
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
    //datFile.close(); //Close binary file
    //VectorFileIO<int> stats(size);
    //datFile.open("data.txt", ios::in | ios::binary); //read in binary to vector
//    for(int i=0;i<size;i++){
//        datFile.read(reinterpret_cast<char *>(&stats), sizeof(stats));
//    }
    //stats.push(size);
    //datFile.close();
//    cout << "The game is now over, here are the results!" << endl;
//    cout << "These are all of the shots that " << game.getEName() << " landed on your ships" << endl;
//    for(int i=0;i<size;i++){
//        cout << '(';
//        cout << stats[i];
//        cout << ',';
//        cout << stats[i + 1];
//        cout << ')' << " ";
//    }
}

void playerVsPlayer(){
    //Variables && Objects
    Board player1, player2;
    Process game;
    int temp; //Stores ship size used in for-loop
    bool sink = false, eSink = false; //Used to determine if Player 1/2 has sunk
    bool win = false; //Ends the game if true
    
    //Player 1's ship placement begins here
    game.beginP1(); //Player 1 starts here
    getInfo(player1);
    player1.output(); //Board preview before ship placement
    for(int i=0;i<5;i++){
        temp = player1.setFleet(i);
        try{
            player1.setYaxis();
        }
        catch(Board::NegativeY){
            cout << "ERROR: Cannot input negative values for the Y axis." << endl;
        }
        try{
            player1.setXaxis();
        }
        catch(Board::NegativeX){
            cout << "ERROR: Cannot input negative values for the X axis." << endl;
        }
        player1.setPos();
        player1.checkPos(temp);
        player1.isOverlap(temp);
        if(player1.getOverlap() == true){
            do{
                game.willOverlap();
                player1.setYaxis();
                player1.setXaxis();
                player1.setPos();
                player1.checkPos(temp);
                player1.isOverlap(temp);
            }while(player1.getOverlap() == true);
        }
        player1.setShip(temp);
        game.updateBoard();
        player1.output();
    }
    game.placeEnd();
    player1.output();
    //Player 2's ship placement starts here!
    game.beginP2(); //Player 2 starts here
    player2.output();
    for(int i=0;i<5;i++){
        temp = player2.setFleet(i);
        try{
            player2.setYaxis();
        }
        catch(Board::NegativeY){
            cout << "ERROR: Cannot input negative values for the Y axis." << endl;
        }
        try{
            player2.setXaxis();
        }
        catch(Board::NegativeX){
            cout << "ERROR: Cannot input negative values for the X axis." << endl;
        }
        player2.setPos();
        player2.checkPos(temp);
        player2.isOverlap(temp);
        if(player2.getOverlap() == true){
            do{
                game.willOverlap();
                player2.setYaxis();
                player2.setXaxis();
                player2.setPos();
                player2.checkPos(temp);
                player2.isOverlap(temp);
            }while(player2.getOverlap() == true);
        }
        player2.setShip(temp);
        game.updateBoard();
        player2.output();
    }
    game.p2End();
    player2.output();
    player1.setWinLose();
    player2.setWinLose();
    game.winOrLose();
    //Players take turns firing at each other here
    do{
        //Player 1 starts firing here
        game.playerShot();
        player2.setYaxis(); //Using Player 2's Y to set coords to hit ships on Player 2's board
        player2.setXaxis(); //Using Player 2's X to set coords to hit ships on Player 2's board
        player2.setHit(game.getPName()); //Places any hits or prompts for misses with player's name
        sink = player2.sink(player1.getWinLose(), game.getPName()); //Checks if win condition has been meet
        win = player2.checkWin(sink); //Declares win and ends the game
        //Player 2 starts firing here
        if(!win){
            game.player2Shot();
            player1.setYaxis(); //Using Player 2's Y to set coords to hit ships on Player 2's board
            player1.setXaxis(); //Using Player 2's X to set coords to hit ships on Player 2's board
            player1.setHit(game.getEName()); //Places any hits or prompts for misses with player's name
            eSink = player1.sink(player2.getWinLose(), game.getEName()); //Checks if win condition has been meet
            win = player1.checkWin(eSink); //Declares win and ends the game
            game.pvpAftermath(game.getPName());
            player1.output();
            cout << endl;
            game.pvpAftermath(game.getEName());
            player2.output();
            cout << endl;
        }
    }while(!win); //Ends game after either condition was met
}
//Used for polymorphism 
void getInfo(Ship &obj){
    obj.shipInfo();
}