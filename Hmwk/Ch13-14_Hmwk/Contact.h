/* 
 * File:   Contact.h
 * Author: Tri
 *
 * Created on May 10, 2015, 12:24 PM
 */

#ifndef CONTACT_H
#define	CONTACT_H
#include <string>

class Contact {
private:
    std::string name;
    std::string address;
    int age;
    int phone;
public:
    Contact();
    void setName(std::string);
    void setAddress(std::string);
    void setAge(int);
    void setPhone(int);
    std::string getName() const
    { return name; }
    std::string getAddress() const
    { return address; }
    int getAge() const
    { return age; }
    int getPhone() const
    { return phone; }
};

#endif	/* CONTACT_H */

