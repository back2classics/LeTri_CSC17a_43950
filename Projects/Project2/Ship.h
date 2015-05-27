/* 
 * File:   Ship.h
 * Author: Tri
 *
 * Created on May 25, 2015, 2:19 PM
 */

#ifndef SHIP_H
#define	SHIP_H
using namespace std;

class Ship {
protected: //Protected for inheritance
    int ship1, ship2, ship3, ship4, ship5;
public:
    Ship(); //Default constructor sets all values to respective sizes
    //Setters set ship size
    void setShip1();
    void setShip2();
    void setShip3();
    void setShip4();
    void setShip5();
    //Getters return ship size
    int getShip1() const { return ship1; }
    int getShip2() const { return ship2; }
    int getShip3() const { return ship3; }
    int getShip4() const { return ship4; }
    int getShip5() const { return ship5; }
    enum shipSize {BOAT, CRUISER, SUB, SHIP, CARRIER}; //ship sizes
};

#endif	/* SHIP_H */

