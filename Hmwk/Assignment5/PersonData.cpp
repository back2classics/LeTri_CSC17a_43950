/* 
 * File:   PersonData.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 11:55 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "PersonData.h"
using namespace std;

PersonData::PersonData(){
    fName = "";
    lName = "";
    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";
}

void PersonData::setfName(string f){
    fName = f;
}

void PersonData::setlName(string l){
    lName = l;
}

void PersonData::setAddress(string a){
    address = a;
}

void PersonData::setCity(string c){
    city = c;
}

void PersonData::setState(string s){
    state = s;
}

void PersonData::setZip(string z){
    zip = z;
}

void PersonData::setPhone(string p){
    phone = p;
}