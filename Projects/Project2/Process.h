/* 
 * File:   Process.h
 * Author: Tri
 *
 * Created on June 1, 2015, 2:30 PM
 */

#ifndef PROCESS_H
#define	PROCESS_H
#include <string>
using namespace std;
//This class is mainly used for Player vs. Player game mode
class Process {
private:
    string pName, eName, valid;
public:
    Process();
    //Mutators
    void setPName(string);
    void setEName(string);
    //Accessors
    string getPName() const { return pName; }
    string getEName() const { return eName; }
    //Main class functions
    void begin(); //Start up of game
    void willOverlap(); //Prompts that ships will overlap
    void updateBoard(); //Prompts user that board has been updated
    void placeEnd(); //Prompts user that ship placement has ended
    void enemyBegin(); //Prompts that enemy has began placing ships
    void enemyEnd(); //Prompts that enemy has finished placing ships
    void winOrLose(); //Prompts user the win/lose conditions of the game
    void playerShot(); //Prompts user that they can fire once at the enemy
    void enemyShot(); //Prompts user that enemy will fire at you once
    void aftermath(string); //Prompts user what the aftermath of the game was

};

#endif	/* PROCESS_H */

