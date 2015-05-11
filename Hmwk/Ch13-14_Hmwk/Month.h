/* 
 * File:   Month.h
 * Author: rcc
 *
 * Created on May 11, 2015, 2:37 PM
 */

#ifndef MONTH_H
#define	MONTH_H
#include <string>
using namespace std;

class Month {
private:
    string name;
    int monthNum;
    static string months[12];
public:
    Month();
    Month(string);
    Month(int);
    void setName(string);
    void setMonthNum(int);
    string getName() const
    { return name; }
    int getMonthNum() const
    { return monthNum; }
    Month operator++();
    Month operator++(int);
    Month operator--();
    Month operator--(int);

};

#endif	/* MONTH_H */

