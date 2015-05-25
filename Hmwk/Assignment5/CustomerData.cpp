/* 
 * File:   CustomerData.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 12:10 PM
 */
#include <iostream>
#include <cstdlib>
#include "CustomerData.h"
using namespace std;

CustomerData::CustomerData(){
    custNum = 0;
    mail = false;
}

void CustomerData::setCustNum(int n){
    custNum = n;
}

void CustomerData::setMail(bool m){
    mail = m;
}

