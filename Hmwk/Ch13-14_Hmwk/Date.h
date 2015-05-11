/* 
 * File:   Date.h
 * Author: Tri Le
 *
 * Created on May 6, 2015, 6:13 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date {
private:
    int month;
    int day;
    int year;
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const
    { return month; }
    int getDay() const
    { return day; }
    int getYear() const
    { return year; }

};

#endif	/* DATE_H */

