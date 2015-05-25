/* 
 * File:   PreferredCustomer.h
 * Author: Tri
 *
 * Created on May 22, 2015, 12:44 PM
 */

#ifndef PREFERREDCUSTOMER_H
#define	PREFERREDCUSTOMER_H
#include "CustomerData.h"
using namespace std;

class PreferredCustomer : public CustomerData {
private:
    float purchase, discount;
public:
    PreferredCustomer();
    void setPurchase(float);
    void setDiscount(float);
    float getPurchase() const { return purchase; }
    float getDiscount() const { return discount; }

};

#endif	/* PREFERREDCUSTOMER_H */

