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

void DayOfYear::print(int n){
    if(n >= 1 && n <= 31){cout << month[0] << " ";} //Jan
    else if(n >= 32 && n<= 59){cout << month[1] << " ";} //Feb
    else if(n >= 60 && n <= 90){cout << month[2] << " ";} //Mar
    else if(n >= 91 && n <= 120){cout << month[3] << " ";} //April
    else if(n >= 121 && n <= 151){cout << month[4] << " ";} //May
    else if(n >= 152 && n <= 181){cout << month[5] << " ";} //June
    else if(n >= 182 && n <= 212){cout << month[6] << " ";} //July
    else if(n >= 213 && n <= 243){cout << month[7] << " ";} //August
    else if(n >= 244 && n <= 273){cout << month[8] << " ";} //Sept
    else if(n >= 274 && n <= 304){cout << month[9] << " ";} //Oct
    else if(n >= 305 && n <= 334){cout << month[10] << " ";} //Nov
    else{cout << month[11] << " ";} //Dec
    
    if(n >= 1 && n <= 31){cout << n;} //Jan
    else if(n >= 32 && n<= 59){cout << n - 31;} //Feb
    else if(n >= 60 && n <= 90){cout << n - 59;} //Mar
    else if(n >= 91 && n <= 120){cout << n - 90;} //April
    else if(n >= 121 && n <= 151){cout << n - 120;} //May
    else if(n >= 152 && n <= 181){cout << n - 151;} //June
    else if(n >= 182 && n <= 212){cout << n - 181;} //July
    else if(n >= 213 && n <= 243){cout << n - 212;} //August
    else if(n >= 244 && n <= 273){cout << n - 243;} //Sept
    else if(n >= 274 && n <= 304){cout << n - 273;} //Oct
    else if(n >= 305 && n <= 334){cout << n - 304;} //Nov
    else{cout << n - 334;} //Dec
    cout << endl;
}

