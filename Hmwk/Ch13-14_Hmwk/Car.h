/* 
 * File:   Car.h
 * Author: Tri
 *
 * Created on May 10, 2015, 11:17 AM
 */

#ifndef CAR_H
#define	CAR_H
#include <string>

class Car {
private:
    int yearModel;
    std::string make;
    int speed;
public:
    Car(int,std::string);
    void setYearModel(int);
    void setMake(std::string);
    void setSpeed(int);
    int getYearModel() const
    { return yearModel; }
    std::string getMake() const
    { return make; }
    int getSpeed() const
    { return speed; }
    void acccelerate();
    void brake();
};

#endif	/* CAR_H */

