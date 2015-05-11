/* 
 * File:   Month.cpp
 * Author: rcc
 * 
 * Created on May 11, 2015, 2:37 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Month.h"
using namespace std;

string Month::months[12] = { "January", "February", "March", "April",
"May", "June", "July", "August", "September", "October", "November", "December"};

Month::Month(){
    name = "January";
    monthNum = 1;
}

Month::Month(string m){
    if(m == months[0]){monthNum = 1;}
    else if(m == months[1]){monthNum = 2;}
    else if(m == months[2]){monthNum = 3;}
    else if(m == months[3]){monthNum = 4;}
    else if(m == months[4]){monthNum = 5;}
    else if(m == months[5]){monthNum = 6;}
    else if(m == months[6]){monthNum = 7;}
    else if(m == months[7]){monthNum = 8;}
    else if(m == months[8]){monthNum = 9;}
    else if(m == months[9]){monthNum = 10;}
    else if(m == months[10]){monthNum = 11;}
    else{monthNum = 12;}
}

Month::Month(int mN){
    if(mN == 1){name = months[0];}
    else if(mN == 2){name = months[1];}
    else if(mN == 3){name = months[2];}
    else if(mN == 4){name = months[3];}
    else if(mN == 5){name = months[4];}
    else if(mN == 6){name = months[5];}
    else if(mN == 7){name = months[6];}
    else if(mN == 8){name = months[7];}
    else if(mN == 9){name = months[8];}
    else if(mN == 10){name = months[9];}
    else if(mN == 11){name = months[10];}
    else{name = months[11];}
}

void Month::setName(string n){
    name = n;
}

void Month::setMonthNum(int m){
    monthNum = m;
}

Month Month::operator ++(){
    if(monthNum == 12){
        monthNum = 1;
        name = months[0];
    }
    else{
        ++monthNum;
        name = months[monthNum - 1];
    }
    return *this;
}

Month Month::operator++(int){
    Month temp(monthNum);
    if(monthNum == 12){
        monthNum = 1;
        name = months[0];
    }
    else{
        monthNum++;
        name = months[monthNum - 1];
    }
    return temp;
}

Month Month::operator --(){
    if(monthNum == 1){
        monthNum = 12;
        name = months[11];
    }
    else{
        --monthNum;
        name = months[monthNum - 1];
    }
    return *this;
}

Month Month::operator --(int){
    Month temp(monthNum);
    if(monthNum == 1){
        monthNum = 12;
        name = months[11];
    }
    else{
        --monthNum;
        name = months[monthNum - 1];
    }
    return temp;
}

