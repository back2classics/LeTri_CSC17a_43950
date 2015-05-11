/* 
 * File:   Numbers.h
 * Author: Tri
 *
 * Created on May 10, 2015, 5:56 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H
#include <string>
using namespace std;

class Numbers {
private:
    int number;
    int a,b,c,d; //stores each portion of the number
    static string lessThan20[20];
    static string twentyP[8];
    static string hundred;
    static string thousand;
public:
    Numbers(int);
    void setNumber(int);
    int getNumber() const
    { return number; }
    void print(int, int, int, int);

};

#endif	/* NUMBERS_H */

