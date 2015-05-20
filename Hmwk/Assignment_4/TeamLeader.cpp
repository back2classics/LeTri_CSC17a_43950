/* 
 * File:   TeamLeader.cpp
 * Author: rcc
 * 
 * Created on May 20, 2015, 4:02 PM
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

TeamLeader::TeamLeader(int b, int h, int n){
    bonus = b;
    hours = h;
    need = n;
}

void TeamLeader::setBonus(int b){
    bonus = b;
}

void TeamLeader::setHours(int h){
    hours = h;
}

void TeamLeader::setNeed(int n){
    need = n;
}

void TeamLeader::calcBonus(){
    bonus = pay * .05;
}