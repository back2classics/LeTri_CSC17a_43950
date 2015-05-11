/* 
 * File:   DayOfYear.cpp
 * Author: Tri
 * 
 * Created on May 10, 2015, 7:59 PM
 */

#include <cstdlib>
#include <iostream>
#include "DayOfYear.h"
using namespace std;

string DayOfYear::month[12] = { "January", "February", "March", "April",
"May", "June", "July", "August", "September", "October", "November", "December"};

DayOfYear::DayOfYear(int d){
    day = d;
}

int getDay(int d){
    return d;
}

void DayOfYear::print(){
    if(day >= 1 && day <= 31){cout << month[0] << " ";} //Jan
    else if(day >= 32 && day<= 59){cout << month[1] << " ";} //Feb
    else if(day >= 60 && day <= 90){cout << month[2] << " ";} //Mar
    else if(day >= 91 && day <= 120){cout << month[3] << " ";} //April
    else if(day >= 121 && day <= 151){cout << month[4] << " ";} //May
    else if(day >= 152 && day <= 181){cout << month[5] << " ";} //June
    else if(day >= 182 && day <= 212){cout << month[6] << " ";} //July
    else if(day >= 213 && day <= 243){cout << month[7] << " ";} //August
    else if(day >= 244 && day <= 273){cout << month[8] << " ";} //Sept
    else if(day >= 274 && day <= 304){cout << month[9] << " ";} //Oct
    else if(day >= 305 && day <= 334){cout << month[10] << " ";} //Nov
    else{cout << month[11] << " ";} //Dec
    
    if(day >= 1 && day <= 31){cout << day;} //Jan
    else if(day >= 32 && day<= 59){cout << day - 31;} //Feb
    else if(day >= 60 && day <= 90){cout << day - 59;} //Mar
    else if(day >= 91 && day <= 120){cout << day - 90;} //April
    else if(day >= 121 && day <= 151){cout << day - 120;} //May
    else if(day >= 152 && day <= 181){cout << day - 151;} //June
    else if(day >= 182 && day <= 212){cout << day - 181;} //July
    else if(day >= 213 && day <= 243){cout << day - 212;} //August
    else if(day >= 244 && day <= 273){cout << day - 243;} //Sept
    else if(day >= 274 && day <= 304){cout << day - 273;} //Oct
    else if(day >= 305 && day <= 334){cout << day - 304;} //Nov
    else{cout << day - 334;} //Dec
    cout << endl;
}

DayOfYear DayOfYear::operator++(){
    if(day == 365){
        day = 1;
    }
    else{
        ++day;
    }
    return *this;
}

DayOfYear DayOfYear::operator++(int){
    DayOfYear temp(day);
    if(day == 365){
        day = 1;
    }
    else{
        day++;
    }
    return temp;
}

DayOfYear DayOfYear::operator--(){
    if(day == 1){
        day = 365;
    }
    else{
        --day;
    }
    return *this;
}

DayOfYear DayOfYear::operator--(int){
    DayOfYear temp(day);
    if(day == 1){
        day = 365;
    }
    else{
        day--;
    }
    return temp;
}
