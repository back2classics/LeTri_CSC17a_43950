/* 
 * File:   TeamLeader.cpp
 * Author: Tri
 * 
 * Created on May 22, 2015, 5:46 PM
 */

#include <iostream>
#include <cstdlib>
#include "TeamLeader.h"
using namespace std;

TeamLeader::TeamLeader(){
    bonus = 0;
    hours = 0;
    need = 0;
}

TeamLeader::TeamLeader(float b, int h, int n){
    bonus = b;
    hours = h;
    need = n;
}

void TeamLeader::setBonus(float b){
    bonus = b;
}

void TeamLeader::setHours(int h){
    hours = h;
}

void TeamLeader::setNeed(int n){
    need = n;
}

void TeamLeader::calcBonus(){
    bonus = pay * .05 * 250;
}

