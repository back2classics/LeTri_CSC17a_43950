/* 
 * File:   Board.h
 * Author: Tri
 *
 * Created on May 25, 2015, 2:43 PM
 */

#ifndef BOARD_H
#define	BOARD_H
#include <string>
#include "Ship.h"
using namespace std;
//Board class inherited from Ship class
class Board : public Ship {
private:
    char **board; //2D Dynamic array
    int xaxis, yaxis; //x and y axis for ship placement
    char pos; //orientation of ship, either horizontal or vertical
    bool overlap; //Used for checking if ships overlap
    string name; //Player or enemy name
public:
    Board(); //Default constructor fills board with '.''s
    ~Board(); //Destructor; Deletes 2D array
    
    //Setters set the X and Y axis of ship's and positioning of ship along with name
    void setName(string);
    void setXaxis(int);
    void setYaxis(int);
    void setPos(char);
    void setXaxis();
    void setYaxis();
    void setPos();
    
    //Getters return X and Y axis, along with position and overlap boolean
    string getName() const { return name; }
    int getXaxis() const { return xaxis; }
    int getYaxis() const { return yaxis; }
    char getPos() const { return pos; }
    bool getOverlap() const { return overlap; }
    
    void checkPos(int); //Checks validity of coordinates and orientation of ships
    void checkE(int); //Checks enemy's validity of coordinates and orientation of ships
    void setShip(int); //Places the ships on the board
    void spawnE(int); //Places enemy's ships on respective board
    void isOverlap(int); //Checks if ships are overlapping on the board
    void output(); //Prints the board
    
    static const int ROW = 10; //Used for the board's row size
    static const int COL = 10; //Used for the board's column size
};

#endif	/* BOARD_H */

