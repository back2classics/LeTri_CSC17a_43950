/* 
 * File:   Procedure.h
 * Author: Tri
 *
 * Created on June 8, 2015, 12:51 PM
 */

#ifndef PROCEDURE_H
#define	PROCEDURE_H
#include <string>
using namespace std;
//Abstract Base Class
class Procedure{
protected:
    int condition; //Stores the win/loss condition and outputs it
public:
    Procedure(){ condition = 0; } //Default constructor
    Procedure(int c) { condition = c; } //Constructor
    //Mutator that will be redefined later on
    void setCondition() { condition = 0; }; 
    //Accessors && Pure Virtual Function
    virtual int getCondition() const = 0;
    
    //Will be redefined later on
    void begin() { cout << "The game will now begin!" << endl; }
    //Will be redefined later on
    void aftermath(string n){ 
        cout << n << " has won!" << endl;
        cout << "Game Over! Here are the results!" << endl;
    } 
    //Pure Virtual Functions
    virtual void beginP1() = 0;
    virtual void beginP2() = 0;
    virtual void placeEnd() = 0;
    virtual void p2End() = 0;
    //Polymorphic Function
    virtual void winOrLose(){
        cout << condition << " is the number of hits needed to win or lose!" << endl;
    }
    
};


#endif	/* PROCEDURE_H */

