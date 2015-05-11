/* 
 * File:   Contact.cpp
 * Author: Tri
 * 
 * Created on May 10, 2015, 12:24 PM
 */

#include <cstdlib>
#include "Contact.h"
using namespace std;

Contact::Contact(){
    name = ""; address = ""; age = 0; phone = 0;
}

void Contact::setName(string n){
    name = n;
}

void Contact::setAddress(string a){
    address = a;
}

void Contact::setAge(int num){
    age = num;
}

void Contact::setPhone(int p){
    phone = p;
}

