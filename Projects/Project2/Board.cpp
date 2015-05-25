/* 
 * File:   Board.cpp
 * Author: Tri
 * 
 * Created on May 25, 2015, 2:43 PM
 */

#include <cstdlib>
#include <iostream>
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