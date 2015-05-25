/* 
 * File:   TeamLeader.h
 * Author: Tri
 *
 * Created on May 22, 2015, 5:46 PM
 */

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H
#include "ProductionWorker.h"
using namespace std;

class TeamLeader : public ProductionWorker {
private:
    float bonus;
    int hours;
    int need;
public:
    TeamLeader();
    TeamLeader(float, int, int);
    void setBonus(float);
    void setHours(int);
    void setNeed(int);
    float getBonus() const { return bonus; }
    int getHours() const { return hours; }
    int getNeed() const { return need; }
    void calcBonus();
};

#endif	/* TEAMLEADER_H */

