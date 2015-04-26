/* 
 * File:   main.cpp
 * Author: Tri Le
 * Project 1 - CSC17a - Battleships
 * Created on April 22, 2015, 5:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

//Global Constants

//User Libraries
#include "ship.h"

//Function Prototypes
char **fill(char **, int, int); //fills the board with "water"
void outputP(char **, int, int); //shows the player's side w/ or w/o ships and damages done
void outputE(char **, int, int); //shows the enemy's side AFTER game ends
int setPosX(int, bool); //used to set the X coordinate of ship placement
int setPosY(int, bool); //used to set the Y coordinate of ship placement
int checkPos(int, char, int &, int &); //checks if ship can be placed on board
void setShip(char **, int, char, int, int); //places the ships on the board

//Execution begins here!
int main(int argc, char** argv) {

    srand(time(0)); //used for randomly spawning enemy's board
    const int ROW = 10; //represents the x-axis of the board
    const int COL = 10; //represents the y-axis of the board
    enum axis {A, B, C, D, E, F, G, H , I, J}; //used when choosing where to fire
    enum shipSize {BOAT, CRUISER, SUB, SHIP, CARRIER}; //used for each unique ship's size
    
    char **player; //player's board
    char **enemy; //enemy's board
    Ship playerS[5]; //structure array of player's ships
    Ship enemyS[5]; //structure array of enemy's ships
    int boat = BOAT + 2; //boat size = 2 spaces
    int cruiser = CRUISER + 2; //cruiser size = 3 spaces
    int sub = SUB + 1; //submarine size = 3 spaces
    int ship = SHIP + 1; //battleship size = 4 spaces
    int carrier = CARRIER + 1; //aircraft carrier size = 5 spaces
    int xaxis, yaxis; //x/y coordinates of ship placement
    bool coord = false; //checks if ship coordinate chosen is true/false
    char place; //used to store ship's orientation to be passed into function
    
    //cout << "===============Welcome to Battleships!===============" << endl;
    player = fill(player, ROW, COL); //fills player's board with "water"
    enemy = fill(enemy, ROW, COL); //fills enemy's board with "water"
    //Ship placement starts here!
    int temp; //temp will store the next ship size because of irregular sized ships
    for(int i=0; i<CARRIER + 1; i++){
        if(i == 0){
            temp = boat;
        }
        else if(i == 1){
            temp = cruiser;
        }
        else if(i == 2){
            temp = sub;
        }
        else if(i == 3){
            temp = ship;
        }
        else{
            temp = carrier;
        }
        playerS[i].size = temp; //player's first ship size is stored in structure
        cout << "The ship that is going to be placed is of size " << temp << "." << endl;
        playerS[i].yaxis = setPosY(yaxis, coord); //player's ship axis is stored
        yaxis = playerS[i].yaxis;
        cout << endl;
        playerS[i].xaxis = setPosX(xaxis, coord); //player's ship axis is stored
        xaxis = playerS[i].xaxis;
        cout << endl;
        cout << "Enter the desired orientation of the ship, where [v] is vertical"
                " and [h] is horizontal: ";
        while(playerS[i].set != 'v' && playerS[i].set != 'h'){
            cin >> playerS[i].set;
            if(playerS[i].set != 'v' && playerS[i].set != 'h'){
                cout << "Invalid input. Please enter again: ";
            }
        }
        place = playerS[i].set;
        checkPos(temp, place, yaxis, xaxis); //checks for valid ship coordinates
        playerS[i].xaxis = xaxis; //if changes were made to coordinates
        playerS[i].yaxis = yaxis; //they are restored into structure again
        setShip(player, temp, place, yaxis, xaxis); //places the ships on the board
    }
    
    outputP(player, ROW, COL); //shows the player's board AFTER ships have been placed
    
    for(int i=0; i<ROW; i++){ //deallocating the player's board
        delete [] player[i]; //internal memory deallocated first
    }
    delete [] player; //deleting 2D dynamic array now
    
    for(int i=0; i<ROW; i++){ //deallocating the enemy's board
        delete [] enemy[i]; //internal memory deallocated first
    }
    delete [] enemy; //deleting 2D dynamic array now
    
    return 0;
}

char **fill(char **a, int ROW, int COL){ //fills the board with "water"
    a = new char*[ROW];
    for(int i=0; i<ROW; i++){
        a[i] = new char[COL];
        for(int j=0; j<COL; j++){
            a[i][j] = '.';
        }
    }
    return a;
}

void outputP(char **player, int ROW, int COL){ //shows player's side AFTER turn ended
    cout << "A B C D E F G H I J  " << endl;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << player[i][j] << " ";
        }
        cout << i << endl;
    }
}

void outputE(char **enemy, int ROW, int COL){ //shows the enemy's side AFTER game ends
    cout << "A B C D E F G H I J  " << endl;
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            cout << enemy[i][j] << " ";
        }
        cout << i << endl;
    }
}

int setPosX(int xaxis, bool coord){ //sets and validates the x-coordinate of ship
    cout << "Enter the coordinates of the X-axis from 0-9, if invalid you will"
            " be asked to enter again: ";
    while(coord == false){
        cin >> xaxis;
        if(xaxis <= 9){
            coord = true;
        }
        else{
            cout << "Invalid input for X coordinate. Please enter again: ";
            coord = false;
        }
    }
    return xaxis;
}

int setPosY(int yaxis, bool coord){ //sets and validates the y-coordinate of ship
    cout << "Enter the coordinates of the Y-axis from 0-9, if invalid you will"
            " be asked to enter again: ";
    while(coord == false){
        cin >> yaxis;
        if(yaxis <= 9){
            coord = true;
        }
        else{
            cout << "Invalid input for Y coordinate. Please enter again: ";
            coord = false;
        }
    }
    return yaxis;
}
//checks validity of coordinates and orientation of the ships
int checkPos(int size, char place, int &yaxis, int &xaxis)
{
    if(tolower(place == 'h')){
        for(int i=0; i<size; i++){
            if((xaxis + i) > 9){
                while((xaxis + i) > 9){
                    cout << "The X coordinate you chose will make the ship go off"
                            " of the game board, please enter a new valid X coordinate: ";
                    cin >> xaxis;
                }
            }
        }
    }
    else{
        for(int i=0; i<size; i++){
            if((yaxis + i) > 9){
                while((yaxis + i) > 9){
                    cout << "The Y coordinate you chose will make the ship go off"
                            " of the game board, please enter a new valid Y coordinate: ";
                    cin >> yaxis;
                }
            }
        }
    }
    return xaxis;
    return yaxis;
}
//places the ships on the board according to the orientation selected
void setShip(char **player, int size, char place, int yaxis, int xaxis)
{
    if(tolower(place == 'h')){
        for(int i=0; i<size; i++){
            player[yaxis][xaxis + i] = '#'; // horizontal ship position
        }
    }
    else{
        for(int i=0; i<size; i++){
            player[yaxis + i][xaxis] = '#'; // vertical ship position
        }
    }
}