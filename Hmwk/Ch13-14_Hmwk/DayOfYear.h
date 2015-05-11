/* 
 * File:   DayOfYear.h
 * Author: Tri
 *
 * Created on May 10, 2015, 7:59 PM
 */

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H
#include <string>
using namespace std;

class DayOfYear {
private:
    int day;
    static string month[12];
public:
    DayOfYear(int);
    void print();
    int getDay(int);
    DayOfYear operator++();
    DayOfYear operator++(int);
    DayOfYear operator--();
    DayOfYear operator--(int);

};

#endif	/* DAYOFYEAR_H */

