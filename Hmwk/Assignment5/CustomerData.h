/* 
 * File:   CustomerData.h
 * Author: Tri
 *
 * Created on May 22, 2015, 12:10 PM
 */

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H
#include "PersonData.h"
using namespace std;

class CustomerData : public PersonData {
protected:
    int custNum;
    bool mail;
public:
    CustomerData();
    void setCustNum(int);
    void setMail(bool);
    int getCustNum() const { return custNum; }
    bool getMail() const { return mail; }

};

#endif	/* CUSTOMERDATA_H */

