#ifndef __ROADWAY_H__
#define __ROADWAY_H__
#include "Vehicle.h"
#include <list>
#include "TrafficLight.h"
#include <vector>
#include <iostream>
#include "Parameters.h"

struct intersection{
  int row;
  int col;
};

class Roadway
{
  private:
    TrafficLight ewLight = TrafficLight(LightColor::green, Parameters::getGreenEastWest(), "EW");
    TrafficLight nsLight = TrafficLight(LightColor::red, Parameters::getRedNorthSouth(), "NS");
    int row;
    int col;
    std::vector<std::vector<Vehicle*>> lanes;
    std::list<Vehicle*> carList;
    //void newCars();

  public:
    Roadway(int row, int col);
    ~Roadway();
    void addVehicle(Vehicle* vehicle);
    void moveCars(int time);
    TrafficLight getNSlight();
    TrafficLight getEWlight();
    bool isNextMoveIntersection(Vehicle* vehicle, int row, int col);
    std::vector<VehicleBase*> getNorthbound();
    std::vector<VehicleBase*> getSouthbound();
    std::vector<VehicleBase*> getWestbound();
    std::vector<VehicleBase*> getEastbound();






};

#endif
