/* 
 * File:   ProductionWorker.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 5:43 PM
 */

#include <iostream>
#include <cstdlib>
#include "ProductionWorker.h"
using namespace std;

ProductionWorker::ProductionWorker(){
    shift = 0;
    pay = 0.0;
}

ProductionWorker::ProductionWorker(int s, float p){
    shift = s;
    pay = p;
}

void ProductionWorker::setShift(int s){
    shift = s;
}

void ProductionWorker::setPay(float p){
    pay = p;
}

