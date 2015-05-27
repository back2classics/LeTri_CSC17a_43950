/* 
 * File:   Board.h
 * Author: Tri
 *
 * Created on May 25, 2015, 2:43 PM
 */

#ifndef BOARD_H
#define	BOARD_H
#include "Ship.h"
using namespace std;
//Board class inherited from Ship class
class Board : public Ship {
private:
    char **board; //2D Dynamic array
    int xaxis, yaxis; //x and y axis for ship placement
    char pos; //orientation of ship, either horizontal or vertical
public:
    Board(); //Default constructor fills board with '.''s
    ~Board(); //Destructor; Deletes 2D array
    //Setters set the X and Y axis of ship's and positioning of ship
    void setXaxis();
    void setYaxis();
    void setPos();
    //Getters return X and Y axis, along with position
    int getXaxis() const { return xaxis; }
    int getYaxis() const { return yaxis; }
    char getPos() const { return pos; }
    void output(); //Prints the board
    static const int ROW = 10; //Used for the board's row size
    static const int COL = 10; //Used for the board's column size
};

#endif	/* BOARD_H */

