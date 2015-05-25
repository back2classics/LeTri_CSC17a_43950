/* 
 * File:   Employee.h
 * Author: Tri
 *
 * Created on May 22, 2015, 5:28 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int num;
    string date;
public:
    Employee();
    Employee(string, int, string);
    void setName(string);
    void setNum(int);
    void setDate(string);
    string getName() const { return name; }
    int getNum() const { return num; }
    string getDate() const { return date; }

};

#endif	/* EMPLOYEE_H */

