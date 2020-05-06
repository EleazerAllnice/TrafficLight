#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__
/*
* Vehicle.cpp file
*/
#include <random>
#include "Vehicle.h"
#include "random.h"
#include "Parameters.h"

//constructor
Vehicle::Vehicle()
{
    //calls the constructor base
    VehicleBase();


    double rand1 = Random::getRandomDouble(0,1);
    // Vehicle will come from the North
    if (rand1 <= Parameters::getProbNewVehicleNorthbound())
    {
      vehicleDirection = Direction::north;
    }

    // Vehicle will come from the South
    else if (rand1 <= Parameters::getProbNewVehicleSouthbound()
    + Parameters::getProbNewVehicleNorthbound() )
    {
      vehicleDirection = Direction::south;
    }

    //Vehicle will come from the East
    else if (rand1 <= Parameters::getProbNewVehicleEastbound() +
    Parameters::getProbNewVehicleSouthbound() + Parameters::getProbNewVehicleNorthbound() )
    {
      vehicleDirection = Direction::west;
    }

     //Vehicle will come from the West
     else
     {
      vehicleDirection = Direction::east;
     }

    // Radom number to generate the type of vehicle
     double randNum = Random::getRandomDouble(0,1);

     //Vehicle will be a Car
     if (randNum <= Parameters::getProportionOfCars())
     {
       vehicleType = VehicleType::car;
       vehicleTurn = getRandomTurn(Parameters::getProportionOfRightTurnCars());
        // input var
     }

     //Vehicle will be an SUV
     else if (randNum <= Parameters::getProportionOfCars())
     {
       vehicleType = VehicleType::suv;
       vehicleTurn = getRandomTurn(Parameters::getProportionOfRightTurnSUVs()); // input var
     }

    // Vehicle will be a Truck
     else
     {
        // input var
        vehicleType = VehicleType::truck;
        vehicleTurn = getRandomTurn(Parameters::getProportionOfRightTurnTrucks());
     }

     // set vehicle gridSize.
    if(vehicleType == VehicleType::car)
    {
        gridSize = 2;
    }
    else if (vehicleType == VehicleType::suv)
    {
        gridSize = 3;
    }
    else
    {
        gridSize = 4;
    }

}

//Destructor
Vehicle::~Vehicle(){
}

// get Grid Size
int Vehicle::getGridSize()
{
    return gridSize;
}

Turn Vehicle::getRandomTurn(double probRight)
{
    double rand = Random::getRandomDouble(0,1);

    if (rand <= probRight)
        return Turn::right;
    else
        return Turn::straight;
}
int Vehicle::getRow()
{
    return row;
}
void Vehicle::setRow(int r)
{
  this->row = r;
}
int Vehicle::getCol()
{
    return col;
}
void Vehicle::setCol(int c)
{
  this->col = c;
}




#endif
