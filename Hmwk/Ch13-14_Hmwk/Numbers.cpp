/* 
 * File:   Numbers.cpp
 * Author: Tri
 * 
 * Created on May 10, 2015, 5:56 PM
 */

#include <cstdlib>
#include <iostream>
#include "Numbers.h"
using namespace std;

string Numbers::lessThan20[20] = { "zero", "one", "two", "three", "four"
, "five", "six" , "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen"
, "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::twentyP[8] = { "twenty", "thirty", "forty", "fifty", "sixty",
"seventy", "eighty", "ninety"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int n){
    number = n;
}

void Numbers::setNumber(int n){
    number = n;
}

void Numbers::print(int w, int x, int y, int z){
    a = w;
    b = x;
    c = y;
    d = z;
    
    if(a != 0){
        cout << lessThan20[a] << " " << thousand << " ";
    }
    if(b != 0){
        cout << lessThan20[b] << " " << hundred << " ";
    }
    if(c != 0 && c != 1){
        if(c == 2){ cout << twentyP[0] << " "; }
        else if(c == 3){ cout << twentyP[1] << " "; }
        else if(c == 4){ cout << twentyP[2] << " "; }
        else if(c == 5){ cout << twentyP[3] << " "; }
        else if(c == 6){ cout << twentyP[4] << " "; }
        else if(c == 7){ cout << twentyP[5] << " "; }
        else if(c == 8){ cout << twentyP[6] << " "; }
        else{ cout << twentyP[7] << " "; }
    }
    if(c == 1){
        cout << lessThan20[d + 10];
    }
    if(c != 1 && d != 0){
        cout << lessThan20[d];
    }
    if(d == 0){
        cout << lessThan20[0];
    }
    cout << endl;
}

