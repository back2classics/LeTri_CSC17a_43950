/* 
 * File:   Employee.h
 * Author: Tri Le
 *
 * Created on May 6, 2015, 6:45 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee {
private:
    string name;
    int idNum;
    string department;
    string position;
public:
    Employee::Employee(string n, int i, string d, string p)
    { name = n; idNum = i; department = d; position = p; }
    Employee::Employee(string n, int i)
    { name = n; idNum = i; department = ""; position = ""; }
    Employee::Employee()
    { name = ""; idNum = 0; department = ""; position = ""; }
    void setName(string);
    void setId(int);
    void setDepartment(string);
    void setPosition(string);
    string getName() const
    { return name; }
    int getId() const
    { return idNum; }
    string getDepartment() const
    { return department; }
    string getPosition() const
    { return position; }
};

#endif	/* EMPLOYEE_H */

