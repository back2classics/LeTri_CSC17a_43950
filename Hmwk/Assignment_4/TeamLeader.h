/* 
 * File:   TeamLeader.h
 * Author: rcc
 *
 * Created on May 20, 2015, 4:02 PM
 */

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H
#include "ProductionWorker.h"
using namespace std;

class TeamLeader : public ProductionWorker {
private:
    int bonus;
    int hours;
    int need;
public:
    TeamLeader();
    TeamLeader(int, int, int);
    void setBonus(int);
    void setHours(int);
    void setNeed(int);
    int getBonus() const { return bonus; }
    int getHours() const { return hours; }
    int getNeed() const { return need; }
    void calcBonus();
};

#endif	/* TEAMLEADER_H */

