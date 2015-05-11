/* 
 * File:   Retail.cpp
 * Author: Tri
 * 
 * Created on May 10, 2015, 1:01 PM
 */

#include <cstdlib>
#include "Retail.h"
using namespace std;

Retail::Retail(string d, int u, float p){
    descript = d; units = u; price = p;
}

void Retail::setDescript(string d){
    descript = d;
}

void Retail::setUnits(int u){
    units = u;
}

void Retail::setPrice(float p){
    price = p;
}

