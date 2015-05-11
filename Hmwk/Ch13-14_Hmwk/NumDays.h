/* 
 * File:   NumDays.h
 * Author: rcc
 *
 * Created on May 11, 2015, 2:16 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
private:
    int hour;
    float day;
public:
    NumDays();
    NumDays(int);
    void setHour(int);
    
    int getHour() const { return hour; }
    float getDay() const { return day; }
    void calc(int);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);

};

#endif	/* NUMDAYS_H */

