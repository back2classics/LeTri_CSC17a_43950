/* 
 * File: Board.h
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
    int winLose; //Win or lose condition for either side
    char pos; //orientation of ship, either horizontal or vertical
    int hit; //Stores any hits of either side
    bool overlap; //Used for checking if ships overlap
public:
    class NegativeX { }; //Exception class for negative X axis
    class NegativeY { }; //Exception class for negative Y axis
    Board(); //Default constructor fills board with '.''s
    Board(int); //Overloaded constructor
    Board(int, int); //Overloaded constructor
    Board(const Board &); //Copy constructor
    virtual ~Board(); //Destructor; Deletes 2D array
    
    //Mutators set the X and Y axis of ship's and positioning of ship
    void setXaxis(int);
    void setYaxis(int);
    void setPos(char);
    void setXaxis();
    void setYaxis();
    void setWinLose();
    void setPos();
    void setHit(string);
    
    //Accessors return X and Y axis and win/lose condition, along with position and overlap boolean
    int getXaxis() const { return xaxis; }
    int getYaxis() const { return yaxis; }
    int getWinLose() const { return winLose; }
    virtual char getPos() const { return pos; } //Overridden getPos function 
    int getHit() const { return hit; } 
    bool getOverlap() const { return overlap; }
    
    //Main Board functions
    void checkPos(int); //Checks validity of coordinates and orientation of ships
    void checkE(int); //Checks enemy's validity of coordinates and orientation of ships
    void setShip(int); //Places the ships on the board
    void spawnE(int); //Places enemy's ships on respective board
    void isOverlap(int); //Checks if ships are overlapping on the board
    bool sink(int, string); //Checks for a win on either side
    bool checkWin(bool); //Declares win on either side
    bool startAI(); //Starts the AI that will chase the player's ship
    void smartAI(int); //AI that will chase the player's ship
    bool writeStat(); //Checks for signal to write to binary file
    void output(); //Prints the board
    virtual void shipInfo(); //Polymorphism
    
    static const int ROW = 10; //Used for the board's row size
    static const int COL = 10; //Used for the board's column size
};

#endif	/* BOARD_H */

