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

//Execution begins here!
int main(int argc, char** argv) {

    srand(time(0)); //used for randomly spawning enemy's board
    const int ROW = 10; //represents the x-axis of the board
    const int COL = 10; //represents the y-axis of the board
    enum axis {A, B, C, D, E, F, G, H , I, J}; //used when choosing where to fire
    enum shipSize {SMALL, MEDIUM, LARGE, XLARGE, XXLARGE}; //used for each unique ship's size
    
    char **player; //player's board
    char **enemy; //enemy's board
    Ship playerS[5]; //structure array of player's ships
    Ship enemyS[5]; //structure array of enemy's ships
    bool size = false; //checks if ship size chosen is true/false
    string pick; //used for player's selection of ship size
    
    //cout << "===============Welcome to Battleships!===============" << endl;
    player = fill(player, ROW, COL); //fills player's board with "water"
    enemy = fill(enemy, ROW, COL); //fills enemy's board with "water"
    for(int i = 0; i < XXLARGE + 1; i++){ //selecting size and placement of player's ships
        cout << "Enter the size of the ship you would like to place,"
                " small = [S], medium = [M], large = [L], x-large = [X],"
                " xx-large = [XXL]: ";
        cin >> pick;
        if(toupper(pick[0]) == 'S'){
            playerS[i].size = SMALL + 1; 
        }
        else if(toupper(pick[0]) == 'M'){
            playerS[i].size = MEDIUM + 1;
        }
        else if(toupper(pick[0]) == 'L'){
            playerS[i].size = LARGE + 1;
        }
        else if(toupper(pick[0]) == 'X'){
            playerS[i].size = XLARGE + 1;
        }
        else{
            playerS[i].size = XXLARGE + 1;
        }
    }
    
    //outputP(player, ROW, COL); //shows the player's board AFTER ships have been placed
    
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

