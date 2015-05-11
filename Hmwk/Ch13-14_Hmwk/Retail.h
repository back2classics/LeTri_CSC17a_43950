/* 
 * File:   Retail.h
 * Author: Tri
 *
 * Created on May 10, 2015, 1:01 PM
 */

#ifndef RETAIL_H
#define	RETAIL_H
#include <string>

class Retail {
private:
    std::string descript;
    int units;
    float price;
public:
    Retail(std::string, int, float);
    void setDescript(std::string);
    void setUnits(int);
    void setPrice(float);
    std::string getDescript() const
    { return descript; }
    int getUnits() const
    { return units; }
    float getPrice() const
    { return price; }
};

#endif	/* RETAIL_H */

