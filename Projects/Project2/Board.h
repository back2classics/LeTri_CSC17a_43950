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
public:
    Board();
    ~Board();
    void output(); //output board
    static const int ROW = 10;
    static const int COL = 10;
};

#endif	/* BOARD_H */

