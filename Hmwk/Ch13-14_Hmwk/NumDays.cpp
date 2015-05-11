/* 
 * File:   NumDays.cpp
 * Author: rcc
 * 
 * Created on May 11, 2015, 2:16 PM
 */

#include "NumDays.h"

NumDays::NumDays(){
    hour = 0;
    day = 0;
}

NumDays::NumDays(int h){
    hour = h;
}

void NumDays::setHour(int h){
    hour = h;
}

void NumDays::calc(int h){
    day = h / 8.0;
}

NumDays NumDays::operator ++(){
    ++hour;
    return *this;
}

NumDays NumDays::operator ++(int){
    NumDays temp(hour);
    hour++;
    return temp;
}

NumDays NumDays::operator --(){
    --hour;
    return *this;
}

NumDays NumDays::operator --(int){
    NumDays temp(hour);
    hour--;
    return temp;
}

NumDays NumDays::operator +(const NumDays &right){
    NumDays temp;
    temp.hour = hour + right.hour;
    return temp;
}

NumDays NumDays::operator -(const NumDays &right){
    NumDays temp;
    temp.hour = hour - right.hour;
    return temp;
}

