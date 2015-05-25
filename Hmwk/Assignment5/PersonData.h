/* 
 * File:   PersonData.h
 * Author: Tri
 *
 * Created on May 22, 2015, 11:55 AM
 */

#ifndef PERSONDATA_H
#define	PERSONDATA_H
#include <string>
using namespace std;

class PersonData {
protected:
    string fName, lName, address, city, state, zip, phone;
public:
    PersonData();
    void setfName(string);
    void setlName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setPhone(string);
    string getfName() const { return fName; }
    string getlName() const { return lName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }

};

#endif	/* PERSONDATA_H */

