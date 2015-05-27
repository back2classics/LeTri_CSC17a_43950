/* 
 * File:   Board.cpp
 * Author: Tri
 * 
 * Created on May 25, 2015, 2:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Board.h"
using namespace std;
//Default constructor
Board::Board() {
    board = new char*[COL];
    for(int i=0; i<COL; i++){
        board[i] = new char[ROW];
        for(int j=0; j<ROW; j++){
            board[i][j] = '.';
        }
    }
}
//Destructor deleting 2D array
Board::~Board() {
    for(int i=0; i<ROW; i++){
        delete [] board[i];
    }
    delete [] board;
}
//Selecting xaxis for ship 
void Board::setXaxis(){
    cout << "Enter the coordinates of the X-axis from 0-9, if invalid you will"
            " be asked to enter again: ";
    do{
        while(!(cin >> xaxis)){
            cout << "Invalid input for X coordinate. Please enter again: ";
            cin.clear();
            cin.ignore();
        }
        if(!(xaxis >= 0 && xaxis <= 9)){
            cout << "Invalid input for X coordinate. Please enter again: ";
        }
    }while(!(xaxis >= 0 && xaxis <= 9));
}
//Selecting yaxis for ship
void Board::setYaxis(){
    cout << "Enter the coordinates of the Y-axis from 0-9, if invalid you will"
            " be asked to enter again: ";
    do{
        while(!(cin >> yaxis)){
            cout << "Invalid input for Y coordinate. Please enter again: ";
            cin.clear();
            cin.ignore();
        }
        if(!(yaxis >= 0 && yaxis <= 9)){
            cout << "Invalid input for Y coordinate. Please enter again: ";
        }
    }while(!(yaxis >= 0 && yaxis <= 9));
}
//Selecting orientation of ship, horizontal or vertical
void Board::setPos(){
    cout << "Enter the desired orientation of the ship, where [v] is vertical"
            " and [h] is horizontal: ";
    while(pos != 'v' && pos != 'h'){
        cin >> pos;
        if(pos != 'v' && pos != 'h'){
            cout << "Invalid input. Please enter again: ";
        }
    }
}
//Checks if positioning and coordinates are valid
void Board::checkPos(){
    if(tolower(pos == 'h')){
        for(int i=0; i<ROW; i++){
            if((xaxis + i) > 9){
                while((xaxis + i) > 9){
                    cout << "The X coordinate you chose will make the ship go off"
                            " of the game board, please enter a new valid X coordinate: ";
                    do{
                        while(!(cin >> xaxis)){
                        cout << "Invalid input for X coordinate. Please enter again: ";
                        cin.clear();
                        cin.ignore();
                        }
                    }while(!(xaxis >= 0 && xaxis <= 9));
                }
            }
        }
    }
    else{
        for(int i=0; i<COL; i++){
            if((yaxis + i) > 9){
                while((yaxis + i) > 9){
                    cout << "The Y coordinate you chose will make the ship go off"
                            " of the game board, please enter a new valid Y coordinate: ";
                    do{
                        while(!(cin >> yaxis)){
                             cout << "Invalid input for Y coordinate. Please enter again: ";
                             cin.clear();
                             cin.ignore();
                        }
                    }while(!(yaxis >= 0 && yaxis <= 9));
                }
            }
        }
    }
}
//Places the ships on the board according to the orientation and coords selected
void Board::setShip(int size){
    if(tolower(pos == 'h')){
        for(int i=0; i<size; i++){
            board[yaxis][xaxis + i] = '#'; // horizontal ship position
        }
    }
    else{
        for(int i=0; i<size; i++){
            board[yaxis + i][xaxis] = '#'; // vertical ship position
        }
    }
}
//Output 2D array
void Board::output(){
    cout << "A B C D E F G H I J  " << endl;
    for(int i=0; i<COL; i++)
    {
        for(int j=0; j<ROW; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << i << endl;
    }
}