/* 
 * File:   PreferredCustomer.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 12:44 PM
 */
#include <iostream>
#include <cstdlib>
#include "PreferredCustomer.h"
using namespace std;

PreferredCustomer::PreferredCustomer(){
    purchase = 0.0;
    discount = 0.0;
}

void PreferredCustomer::setPurchase(float p){
    purchase = p;
}

void PreferredCustomer::setDiscount(float d){
    discount = d;
}


