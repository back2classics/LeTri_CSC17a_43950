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
#include "shoot.h"

//Function Prototypes
char **fill(char **, int, int); //fills the board with "water"
void outputP(char **, int, int); //shows the player's side w/ or w/o ships and damages done
void outputE(char **, int, int); //shows the enemy's side AFTER game ends
int setPosX(int, bool); //used to set the X coordinate of ship placement
int setPosY(int, bool); //used to set the Y coordinate of ship placement
int checkPos(int, char, int &, int &); //checks if ship will go off the board
void setShip(char **, int, char, int, int); //places ships on the board
int checkE(int, char, int &, int &); //spawns enemy's battlefield
void spawnE(char **, int, char, int, int);
int winLose(char **, int, int, int); //condition for winning or losing the game
int myShots(char **, int, int, int &); //counts how many shots have hit eShips
void hitEnemy(char **, int, int); //places shots on the enemy's board
bool eSink(char **, int, int); //checks if player has won

//Execution begins here!
int main(int argc, char** argv) {

    srand(time(0)); //used for randomly spawning enemy's board
    const int ROW = 10; //represents the x-axis of the board
    const int COL = 10; //represents the y-axis of the board
    enum shipSize {BOAT, CRUISER, SUB, SHIP, CARRIER}; //used for each unique ship's size
    //string name, eName; //player's name && enemy's name
    char **player; //player's board
    char **enemy; //enemy's board
    Ship playerS[5]; //structure array of player's ships
    Ship enemyS[5]; //structure array of enemy's ships
    int boat = BOAT + 2; //boat size = 2 spaces
    int cruiser = CRUISER + 2; //cruiser size = 3 spaces
    int sub = SUB + 1; //submarine size = 3 spaces
    int ship = SHIP + 1; //battleship size = 4 spaces
    int carrier = CARRIER + 1; //aircraft carrier size = 5 spaces
    int temp; //temp will store the next ship size because of irregular sized ships
    bool coord = false; //checks if ship coordinate chosen is true/false
    
    cout << "===============Welcome to Battleships!===============" << endl;
    //cout << "Enter your SAILOR name!: ";
    //cin >> name;
    //cout << "Now enter the name of the PIRATE you will crush!: ";
    //cin >> eName;
    //cout << name << ", give your crew orders!" << endl;
    //cout << name << "'s turn will now begin." << endl;
    player = fill(player, ROW, COL); //fills player's board with "water"
    enemy = fill(enemy, ROW, COL); //fills enemy's board with "water"
    //Ship placement starts here!
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
        playerS[i].yaxis = setPosY(playerS[i].yaxis, coord); //player's ship axis is stored
        playerS[i].xaxis = setPosX(playerS[i].xaxis, coord); //player's ship axis is stored
        cout << "Enter the desired orientation of the ship, where [v] is vertical"
                " and [h] is horizontal: ";
        while(playerS[i].set != 'v' && playerS[i].set != 'h'){
            cin >> playerS[i].set;
            if(playerS[i].set != 'v' && playerS[i].set != 'h'){
                cout << "Invalid input. Please enter again: ";
            }
        }
        cout << endl;
        checkPos(playerS[i].size, playerS[i].set, playerS[i].yaxis,
                playerS[i].xaxis); //checks for valid ship coordinates
        setShip(player, playerS[i].size, playerS[i].set, playerS[i].yaxis,
                playerS[i].xaxis); //places the ships on the board
    }
    //cout << name << "'s crew is ready and prepared to battle!" << endl;
    //cout << name << "'s turn has ended." << endl;
    //Enemy's ship placement starts here!
    //cout << "Scumbag " << eName << " has begun giving their orders!" << endl;
    //cout << eName << "'s turn will now begin." << endl;
    int eShip, pos; //eShip holds enemy ship size and pos holds orientation of ship
    for(int i=0; i<CARRIER + 1; i++){
        cout << "Generating enemy battlefield..." << endl;
        if(i == 0){
            eShip = boat;
        }
        else if(i == 1){
            eShip = cruiser;
        }
        else if(i == 2){
            eShip = sub;
        }
        else if(i == 3){
            eShip = ship;
        }
        else{
            eShip = carrier;
        }
        enemyS[i].size = eShip;
        enemyS[i].xaxis = rand() % 10;
        enemyS[i].yaxis = rand() % 10;
        pos = rand() % 2;
        if(pos == 0)
        {
            enemyS[i].set = 'h';
        }
        else
        {
            enemyS[i].set = 'v';
        }
        checkE(enemyS[i].size, enemyS[i].set, enemyS[i].yaxis, enemyS[i].xaxis);
        spawnE(enemy, enemyS[i].size, enemyS[i].set, enemyS[i].yaxis, enemyS[i].xaxis);
    }
    //cout << eName << " and their crew are ready and prepared for battle!" << endl;
    
    int pWinLose = 0;
    int eWinLose = 0;
    pWinLose = winLose(player, ROW, COL, pWinLose);
    eWinLose = winLose(enemy, ROW, COL, eWinLose);
    cout << "Player's win/lose condition is if " << pWinLose << " ships sink!" << endl;
    cout << "Enemy's win/lose condition is if " << eWinLose << " ships sink!" << endl;
    cout << endl;
    //Player's turn to fire at enemy begins here!
    Shoot pShots[5];
    Shoot eShots[5];
    int myHit = 0;
    bool check = false;
    outputE(enemy, ROW, COL); //for testing purposes
    cout << "You can fire at the enemy 5 times!" << endl;
    cout << "Choose your shot coordinates now!" << endl;
    for(int i=0; i<5; i++){
        pShots[i].shootY = setPosY(pShots[i].shootY, coord);
        pShots[i].shootX = setPosX(pShots[i].shootX, coord);
        myHit = myShots(enemy, pShots[i].shootY, pShots[i].shootX, myHit);
        hitEnemy(enemy, pShots[i].shootY, pShots[i].shootX);
        check = eSink(enemy, myHit, pWinLose);
        if(check == true){
            cout << "You successfully sank all of the enemy ships!" << endl;
        }
        else{
            cout << "Initiating next phase..." << endl;
        }
    }
    
    outputE(enemy, ROW, COL); //for testing purposes
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
int checkPos(int size, char place, int &yaxis, int &xaxis){
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
void setShip(char **player, int size, char place, int yaxis, int xaxis){
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

int checkE(int eShip, char ePlace, int &enemyY, int &enemyX){
    if(tolower(ePlace == 'h')){
        for(int i=0; i<eShip; i++){
            if((enemyX + i) > 9){
                while((enemyX + i) > 9){
                    enemyX = rand() % 10;
                }
            }
        }
    }
    else{
        for(int i = 0; i < eShip; i++){
            if((enemyY + i) > 9){
                while((enemyY + i) > 9){
                    enemyY = rand() % 10;
                }
            }
        }
    }
    return enemyY;
    return enemyX;
}

void spawnE(char **enemy, int eShip, char ePlace, int enemyY, int enemyX){
    if(tolower(ePlace == 'h')){
        for(int i=0; i<eShip; i++){
            enemy[enemyY][enemyX + i] = '#'; // horizontal ship position
        }
    }
    else{
        for(int i=0; i<eShip; i++){
            enemy[enemyY + i][enemyX] = '#'; // vertical ship position
        }
    }
}

int winLose(char **array, int ROW, int COL, int count){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(array[i][j] == '#'){
                count++;
            }
        }
    }
    return count;
}

int myShots(char **enemy, int shootY, int shootX, int &myHit){
    if(enemy[shootY][shootX] == '#'){
        cout << "Your shot hit an enemy ship!" << endl;
        myHit++;
    }
    else{
        cout << "Your shot missed!" << endl;
    }
    return myHit;
}

void hitEnemy(char **enemy, int shootY, int shootX){
    if(enemy[shootY][shootX] == '#'){
        enemy[shootY][shootX] = 'X';
    }
}

bool eSink(char **enemy, int myHit, int pWinLose){
    if(myHit == pWinLose){
        cout << "All enemy ships are down! You win!" << endl;
        return true;
    }
    else{
        return false;
    }
}