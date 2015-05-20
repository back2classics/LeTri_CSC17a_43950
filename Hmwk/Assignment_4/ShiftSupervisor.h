/* 
 * File:   ShiftSupervisor.h
 * Author: rcc
 *
 * Created on May 20, 2015, 3:32 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H
#include "Employee.h"
using namespace std;

class ShiftSupervisor : public Employee {
private:
    float salary;
    float bonus;
public:
    ShiftSupervisor();
    ShiftSupervisor(float, float);
    void setSalary(float);
    void setBonus(float);
    float getSalary() const { return salary; }
    float getBonus() const { return bonus; }
    void calcBonus();
};

#endif	/* SHIFTSUPERVISOR_H */

