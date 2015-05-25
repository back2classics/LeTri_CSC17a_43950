/* 
 * File:   ProductionWorker.h
 * Author: Tri
 *
 * Created on May 22, 2015, 5:43 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee {
protected:
    int shift;
    float pay;
public:
    ProductionWorker();
    ProductionWorker(int, float);
    void setShift(int);
    void setPay(float);
    int getShift() const { return shift; }
    float getPay() const { return pay; }
};

#endif	/* PRODUCTIONWORKER_H */

