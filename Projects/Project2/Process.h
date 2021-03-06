/* 
 * File: Process.h
 * Author: Tri
 *
 * Created on June 1, 2015, 2:30 PM
 */

#ifndef PROCESS_H
#define	PROCESS_H
#include <string>
#include "Procedure.h"
using namespace std;
//This class is mainly used for Player vs. Player game mode
class Process : public Procedure {
private:
    string pName, eName, valid;
public:
    Process();
    //Mutators
    void setCondition(); //Redefining Base Class Function
    void setPName(string);
    void setEName(string);
    //Accessors
    virtual int getCondition() const { return condition; }
    string getPName() const { return pName; }
    string getEName() const { return eName; }
    //Main class functions
    void begin(); //Start up of the game used in Player vs AI
    void willOverlap(); //Prompts that ships will overlap
    void updateBoard(); //Prompts user that board has been updated   
    void enemyBegin(); //Prompts that enemy has began placing ships   
    void enemyEnd(); //Prompts that enemy has finished placing ships
    void playerShot(); //Prompts user that they can fire once at the enemy
    void enemyShot(); //Prompts user that enemy will fire at you once
    void player2Shot(); //Prompts player 2 that they can fire at Player 1 once
    void aftermath(string); //Prompts user what the aftermath of the turn was
    void pvpAftermath(string); //Prompts what the aftermath of the turn was
    //Overridden Functions from Abstract Base Class
    virtual void beginP1(); //Start up of the game used in Player vs. Player for Player 1
    virtual void placeEnd(); //Prompts user that ship placement has ended
    virtual void beginP2(); //Player 2 begins setting ships
    virtual void p2End(); //Prompts that Player 2's turn has ended
    //Polymorphic Function
    virtual void winOrLose(); //Prompts user the win/lose conditions of the game
};

#endif	/* PROCESS_H */

