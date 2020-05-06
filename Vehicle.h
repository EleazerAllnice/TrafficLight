#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include "VehicleBase.h"

/*
 *Vehicle class
 */
class Vehicle : public VehicleBase{

//private member variables
private:
    int gridSize;
    Turn getRandomTurn(double straight_prob);
    int row;
    int col;

//public methods and constructors.
public:
    Vehicle();
    ~Vehicle();
    int getGridSize();
    int getRow();
    void setRow(int r);
    int getCol();
    void setCol(int c);

};
#endif
